#ifndef ACTEST_H
#define ACTEST_H

#ifdef AC_TESTING

#include <stdio.h>
/* CONSTANTS */
#define AC_SEPERATE "################################\n"
#define AC_SEPERATE_WEAK "--------------------------------\n"
/* ENUM / STRUCT */

#define ACUnit_Codes 5
enum ACUnit_Code {
	RET_PASS,
	RET_FAIL,
	RET_SKIP,
	RET_CRASH,
	RET_UNDEF
};

static char* ACUnit_Code_Str[ACUnit_Codes] = { "Pass", "Fail", "Skip", "Crash", "Undefined" };

struct ACUnit_Results {
	long codes[ACUnit_Codes];
	const char* name;
};

/* UNIT TESTS  */
#define TEST_DEF(name) static void name(long* line, enum ACUnit_Code* exit)

#define TEST_INIT do { *line = -1; *exit = RET_UNDEF; } while(0)

#define TEST_EXIT return

#define TEST_RET(code) do {                   \
                            *line = __LINE__; \
                            *exit = code;     \
                            return;           \
                          } while(0)

#define TEST_RUN(name) do {                                          \
                            name(&lineno, &excode);               \
                            (res.codes[excode])++;                   \
                            printf(#name ": %s at line %d\n",        \
								   ACUnit_Code_Str[excode], lineno); \
                          } while(0)

/* MODULES */
#define MODULE_DEF(module_name) struct ACUnit_Results module_name(void)

#define MODULE_INIT long lineno;                                     \
	                enum ACUnit_Code excode;                         \
					struct ACUnit_Results res = { .codes = {0},      \
                                                  .name = __func__}; \
					printf(AC_SEPERATE "MODULE: %s in %s\n"          \
                           AC_SEPERATE_WEAK, __func__, __FILE__)

#define MODULE_EXIT printf(AC_SEPERATE_WEAK                            \
                           "%s: %d, %s: %d, %s: %d, %s: %d, %s: %d\n", \
						   ACUnit_Code_Str[0], res.codes[0],           \
						   ACUnit_Code_Str[1], res.codes[1],           \
						   ACUnit_Code_Str[2], res.codes[2],           \
						   ACUnit_Code_Str[3], res.codes[3],           \
						   ACUnit_Code_Str[4], res.codes[4]);          \
	                return res
// TODO, NOTE: PRINT MODULE RESULTS AT THE END HERE Eg: Pass: x, Fail: y, Skip: z, Crash: i, Undefined: j, Total: s
#define MODULE_RUN(module) module()
#define AC_DECLARE(module_name) extern struct ACUnit_Results module_name(void)

#define AC_INIT printf(AC_SEPERATE "Testing\n")
#define AC_EXIT printf(AC_SEPERATE "Testing Completed\n")
/* TESTING INITIALIZATION
 * 1. Initialize file at begin
 * 2. Pass file into each module
 * 3. Use fprintf on the file
 * 4. Close the file at AC_END
 * */
/*#define AC_BEGIN() FILE* ACUnit_output; ACUnit_output = fopen()
#define AC_END()
*/
/* ASSERTIONS */
#define TEST_assert(expr) do { if (!(expr)) TEST_RET(RET_FAIL); } while(0)
#define TEST_assert_not(expr) do { if (expr) TEST_RET(RET_FAIL); }  while(0)
#define TEST_assert_null(expr) do { if ((expr) != NULL) TEST_RET(RET_FAIL); } while(0)
#define TEST_assert_not_null(expr) do { if ((expr) == NULL) TEST_RET(RET_FAIL); } while(0)
#else /* AC_TESTING */
#define AC_INIT
#define AC_EXIT
#define AC_DECLARE(module_name)
#define MODULE_RUN(module_name)
#endif /* UNIT_TESTING */

#endif /* ACTEST_H */
