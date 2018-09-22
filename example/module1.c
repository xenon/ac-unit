#include "module1.h"

int test_function(void) {
	return 42;
}

#ifdef AC_TESTING

TEST_DEF(test1) {
	TEST_INIT;
	TEST_assert(test_function() == 42);
	TEST_RET(RET_PASS);
	TEST_EXIT;
}


TEST_DEF(test2) {
	TEST_INIT;
	if(test_function() == 22)
		TEST_RET(RET_PASS);
	else
		TEST_RET(RET_FAIL);
	TEST_EXIT;
}

MODULE_DEF(module1) {
	MODULE_INIT;
	TEST_RUN(test1);
	TEST_RUN(test2);
	MODULE_EXIT;
}

MODULE_DEF(module1b) {
	MODULE_INIT;
	TEST_RUN(test2);
	MODULE_EXIT;
}

#endif
