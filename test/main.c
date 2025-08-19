#include "test.h"
#include <stdio.h>

#define ANSI_COLOR_RED		"\x1b[31m"
#define	ANSI_COLOR_GREEN	"\x1b[32m"
#define ANSI_COLOR_RESET	"\x1b[0m"

void	print_test_result(int result, char* test_name) {
	char* output = ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET;
	if (result != 0)
		output = ANSI_COLOR_RED "KO" ANSI_COLOR_RESET;

	printf("%s : %s\n", test_name, output);
}

int main(int argc, char** argv) {
	(void)argc;
	(void)argv;

	print_test_result(test_write(), "FT_WRITE");
	print_test_result(test_read(), "FT_READ");
	print_test_result(test_strlen(), "FT_STRLEN");
	print_test_result(test_strcmp(), "FT_STRCMP");
	print_test_result(test_strcpy(), "FT_STRCPY");
	print_test_result(test_strdup(), "FT_STRDUP");
	print_test_result(test_atoi_base(), "FT_ATOI_BASE");
	print_test_result(test_list_push_front(), "FT_LIST_PUSH_FRONT");
	print_test_result(test_list_size(), "FT_LIST_SIZE");
	print_test_result(test_list_sort(), "FT_LIST_SORT");
	print_test_result(test_list_remove_if(), "FT_LIST_REMOVE_IF");

	return 0;
}
