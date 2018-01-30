#include "doctest.h"
#include "java.hpp"
#include "java/util/Random.hpp"
#include <vector>

using std::vector;

TEST_CASE("java/util/Random")
{
	Random random(1337);
	vector<sjbyte> bytes(10, 0);
	REQUIRE(random.nextInt() == -1460590454);
	REQUIRE(random.nextInt() == 747279288);
	REQUIRE(random.nextInt() == -1334692577);
	REQUIRE(random.nextInt(16) == 13);
	REQUIRE(random.nextInt(23) == 21);
	REQUIRE(random.nextInt(42) == 22);
	REQUIRE(random.nextLong() == -1872204974168004231);
	REQUIRE(random.nextLong() == 3220239582190571319);
	REQUIRE(random.nextLong() == -1070728836061345714);
	REQUIRE(random.nextBoolean() == false);
	REQUIRE(random.nextBoolean() == false);
	REQUIRE(random.nextBoolean() == false);
	REQUIRE(random.nextFloat() == doctest::Approx(0.9862866));
	REQUIRE(random.nextFloat() == doctest::Approx(0.81301254));
	REQUIRE(random.nextFloat() == doctest::Approx(0.10291344));
	REQUIRE(random.nextDouble() == doctest::Approx(0.6367885304489944));
	REQUIRE(random.nextDouble() == doctest::Approx(0.19570252190931603));
	REQUIRE(random.nextDouble() == doctest::Approx(0.49526296435984674));
	REQUIRE(random.nextGaussian() == doctest::Approx(-0.13845685856090853));
	REQUIRE(random.nextGaussian() == doctest::Approx(-0.08646506780044372));
	REQUIRE(random.nextGaussian() == doctest::Approx(0.16206735648530174));
	random.setSeed(1911);
	REQUIRE(random.nextInt() == -1679897327);
	REQUIRE(random.nextInt() == -2051475999);
	REQUIRE(random.nextInt() == 1415400229);
	REQUIRE(random.nextInt(16) == 7);
	REQUIRE(random.nextInt(23) == 2);
	REQUIRE(random.nextInt(42) == 28);
	REQUIRE(random.nextLong() == -3723853027765071947);
	REQUIRE(random.nextLong() == 3590193954583674072);
	REQUIRE(random.nextLong() == 9117555462562552271);
	REQUIRE(random.nextBoolean() == true);
	REQUIRE(random.nextBoolean() == true);
	REQUIRE(random.nextBoolean() == true);
	REQUIRE(random.nextFloat() == doctest::Approx(0.60038024));
	REQUIRE(random.nextFloat() == doctest::Approx(0.58007824));
	REQUIRE(random.nextFloat() == doctest::Approx(0.18803829));
	REQUIRE(random.nextDouble() == doctest::Approx(0.2615772071434289));
	REQUIRE(random.nextDouble() == doctest::Approx(0.8613099085182472));
	REQUIRE(random.nextDouble() == doctest::Approx(0.10917028780017057));
	REQUIRE(random.nextGaussian() == doctest::Approx(-0.7662020597776251));
	REQUIRE(random.nextGaussian() == doctest::Approx(0.3851396457317901));
	REQUIRE(random.nextGaussian() == doctest::Approx(-1.4687538228667334));
	random.nextBytes(bytes);
	REQUIRE(bytes[0] == -57);
	REQUIRE(bytes[1] == 26);
	REQUIRE(bytes[2] == 17);
	REQUIRE(bytes[3] == 30);
	REQUIRE(bytes[4] == 37);
	REQUIRE(bytes[5] == 118);
	REQUIRE(bytes[6] == -49);
	REQUIRE(bytes[7] == 57);
	REQUIRE(bytes[8] == 106);
	REQUIRE(bytes[9] == 103);
}
