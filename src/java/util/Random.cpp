#include "java.hpp"
#include "java/util/Random.hpp"
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <ctime>
#include <cmath>

using std::vector;
using std::min;
using std::out_of_range;

typedef vector<jbyte>::size_type vec_sz;

jlong Random::seedUniquifier = 8682522807148012;
const jlong Random::multiplier = 0x5DEECE66D;
const jlong Random::addEnd = 0xB;
const jlong Random::mask = ((jlong)1 << 48) - 1;
const double Random::doubleUnit = 1.0 / ((jlong)1 << 53);

Random::Random() :
	seed(0),
	nextNextGaussian(0),
	haveNextNextGaussian(false)
{
	static jlong nanotime;
#if defined(__UNIX__)
	static timespec time;
	clock_gettime(CLOCK_REALTIME, &time);
	nanotime = time.tv_sec * ((jlong)1000000000) + time.tv_nsec;
#endif
	setSeed(uniquifySeed() ^ nanotime);
}

Random::Random(const jlong userSeed) :
	seed(0),
	nextNextGaussian(0),
	haveNextNextGaussian(false)
{
	setSeed(userSeed);
}

void Random::setSeed(const jlong userSeed)
{
	seed = initialScramble(userSeed);
	haveNextNextGaussian = false;
}

void Random::nextBytes(vector<sjbyte>& bytes)
{
	vec_sz i;
	vec_sz len;
	jint rnd;
	jint n;
	i = 0;
	len = bytes.size();

	while(i < len)
	{
		rnd = nextInt();
		n = min(len - i, (vec_sz)4);

		while(n > 0)
		{
			bytes[i] = (sjbyte)rnd;
			rnd >>= 8;
			++i;
			--n;
		}
	}
}

jint Random::nextInt()
{
	return next(32);
}

jint Random::nextInt(const jint bound)
{
	if(bound <= 0)
	{
		throw out_of_range("bound must be positive");
	}

	jint u;
	jint r;
	jint m = bound - 1;

	if((bound & m) == 0)
	{
		u = next(31);
		r = (jint)((bound * (jlong)u) >> 31);
	}
	else
	{
		do
		{
			u = next(31);
			r = u % bound;
		}
		while((u - r + m) < 0);
	}

	return r;
}

jlong Random::nextLong()
{
	return ((jlong)(next(32)) << 32) + next(32);
}

bool Random::nextBoolean()
{
	return next(1) != 0;
}

double Random::nextFloat()
{
	return next(24) / (double)(1 << 24);
}

double Random::nextDouble()
{
	return (((jlong)(next(26)) << 27) + next(27)) * doubleUnit;
}

double Random::nextGaussian()
{
	double factor;
	double v1;
	double v2;
	double s;

	if(haveNextNextGaussian)
	{
		haveNextNextGaussian = false;
		return nextNextGaussian;
	}
	else
	{
		do
		{
			v1 = 2 * nextDouble() - 1;
			v2 = 2 * nextDouble() - 1;
			s = v1 * v1 + v2 * v2;
		}
		while(s >= 1 || s == 0);

		factor = sqrt(-2 * log(s) / s);
		nextNextGaussian = v2 * factor;
		haveNextNextGaussian = true;
		return v1 * factor;
	}
}

jint Random::next(const jint bits)
{
	seed = (seed * multiplier + addEnd) & mask;
	return (jint)((ujlong)(seed) >> (48 - bits));
}

jlong Random::uniquifySeed()
{
	seedUniquifier *= 181783497276652981;
	return seedUniquifier;
}

jlong Random::initialScramble(const jlong userSeed)
{
	return (userSeed ^ multiplier) & mask;
}
