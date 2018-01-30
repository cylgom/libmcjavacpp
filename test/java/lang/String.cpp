#include "doctest.h"
#include "java.hpp"
#include "java/lang/String.hpp"
#include <string>

using java::hashcode16;
using std::u16string;

TEST_CASE("java/lang/String")
{
	u16string glass[9] =
	{
		uR"(काचं शक्नोम्यत्तुम् । नोपहिनस्ति माम् ॥)",
		uR"(ὕαλον ϕαγεῖν δύναμαι· τοῦτο οὔ με βλάπτει.)",
		uR"(Je peux manger du verre, ça ne me fait pas mal.)",
		uR"(᚛᚛ᚉᚑᚅᚔᚉᚉᚔᚋ ᚔᚈᚔ ᚍᚂᚐᚅᚑ ᚅᚔᚋᚌᚓᚅᚐ᚜)",
		uR"(ᛁᚳ᛫ᛗᚨᚷ᛫ᚷᛚᚨᛋ᛫ᛖᚩᛏᚪᚾ᛫ᚩᚾᛞ᛫ᚻᛁᛏ᛫ᚾᛖ᛫ᚻᛖᚪᚱᛗᛁᚪᚧ᛫ᛗᛖ᛬)",
		uR"(⠊⠀⠉⠁⠝⠀⠑⠁⠞⠀⠛⠇⠁⠎⠎⠀⠁⠝⠙⠀⠊⠞⠀⠙⠕⠑⠎⠝⠞⠀⠓⠥⠗⠞⠀⠍⠑)",
		uR"(Я могу есть стекло, оно мне не вредит.)",
		uR"(मैं काँच खा सकता हूँ और मुझे उससे कोई चोट नहीं पहुंचती.)",
		uR"(私はガラスを食べられます。それは私を傷つけません。)"
	};
	REQUIRE(hashcode16(glass[0]) == 773645184);
	REQUIRE(hashcode16(glass[1]) == 1491036382);
	REQUIRE(hashcode16(glass[2]) == -374943737);
	REQUIRE(hashcode16(glass[3]) == -1604655271);
	REQUIRE(hashcode16(glass[4]) == -1887663176);
	REQUIRE(hashcode16(glass[5]) == 1942043424);
	REQUIRE(hashcode16(glass[6]) == 142132582);
	REQUIRE(hashcode16(glass[7]) == 561182097);
	REQUIRE(hashcode16(glass[8]) == -302733627);
}
