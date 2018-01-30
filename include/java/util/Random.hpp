#ifndef LIBMCJAVACPP_JAVA_UTIL_RANDOM_H
#define LIBMCJAVACPP_JAVA_UTIL_RANDOM_H

#include "java.hpp"
#include <vector>

class Random
{
	public:
		Random();
		Random(const jlong userSeed);
		void setSeed(const jlong userSeed);
		void nextBytes(std::vector<sjbyte>& bytes);
		jint nextInt();
		jint nextInt(const jint bound);
		jlong nextLong();
		bool nextBoolean();
		double nextFloat();
		double nextDouble();
		double nextGaussian();

	protected:
		jint next(const jint bits);

	private:
		static jlong seedUniquifier;
		static const jlong multiplier;
		static const jlong addEnd;
		static const jlong mask;
		static const double doubleUnit;

		jlong seed;
		double nextNextGaussian;
		bool haveNextNextGaussian;

		jlong uniquifySeed();
		jlong initialScramble(const jlong userSeed);
};

#endif /* LIBMCJAVACPP_JAVA_UTIL_RANDOM_H */
