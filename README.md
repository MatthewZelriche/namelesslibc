# namelesslibc
In order to run the tests, you must run the namelesslibk_tests executable with "LD_PRELOAD=path_to_built_so"
This is so that this libc implementation be loaded prior to libc, allowing me to still rely on libc
printing functions for the unit tests instead of building as nostdlib