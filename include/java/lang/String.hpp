#ifndef LIBMCJAVACPP_JAVA_LANG_STRING_H
#define LIBMCJAVACPP_JAVA_LANG_STRING_H

#include "java.hpp"
#include <string>

namespace java
{
std::u16string encode16(const std::string& s);
std::string decode16(const std::u16string& s);
jint hashcode16(const std::u16string& s);
}

#endif /* LIBMCJAVACPP_JAVA_LANG_STRING_H */
