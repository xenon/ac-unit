#include "module1.h"

int main(int argc, char** argv) {
	AC_INIT;
	MODULE_RUN(module1);
	MODULE_RUN(module1b);
	AC_EXIT;
	return 0;
}
