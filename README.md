# libmcjavacpp
libmcjavacpp is a project of C++ library implementing the JVM mechanisms
Minecraft depends on. Only very specific code will be reproduced, like
the pseudo-random class "java/util/Random" and the string hashcode
function from "java/lang/String", for example.

## running tests
Remember to prefix your command with the library path upon testing:
```
LD_LIBRARY_PATH="/home/user/path/to/dir/libmcjavacpp/build"
```
