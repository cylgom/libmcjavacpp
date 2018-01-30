#include "java.hpp"
#include "java/lang/String.hpp"
#include <locale>
#include <codecvt>

using std::string;
using std::u16string;
using std::wstring_convert;
using std::codecvt_utf8_utf16;

typedef u16string::const_iterator u16str_citer;
wstring_convert<codecvt_utf8_utf16<char16_t>, char16_t> switchEncoding;

u16string java::encode16(const string& s)
{
	return switchEncoding.from_bytes(s);
}

string java::decode16(const u16string& s)
{
	return switchEncoding.to_bytes(s);
}

jint java::hashcode16(const u16string& s)
{
	u16str_citer str_end = s.end();
	jint h = 0;

	for(u16str_citer cit = s.begin(); cit != str_end; cit++)
	{
		h = 31 * h + (*cit);
	}

	return h;
}
