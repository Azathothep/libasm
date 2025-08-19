#include "../libasm.h"
#include <string.h>
#include <assert.h>

int	sign(int a) {
	if (a < 0)
		return -1;
	else if (a > 0)
		return 1;

	return 0;
}

void	unit_test_strcmp(char *s1, char *s2) {
	int cmp = strcmp(s1, s2);
	int ft_cmp = ft_strcmp(s1, s2);

	assert(sign(ft_cmp) == sign(cmp));
}

int	test_strcmp() {

	unit_test_strcmp("", "");
	unit_test_strcmp("", "Heoqizjd");
	unit_test_strcmp("Hello\n", "");
	unit_test_strcmp("Hello", "Hello");
	unit_test_strcmp("Hello", "Hell");
	unit_test_strcmp("Hell", "Hello");
	unit_test_strcmp("Heyo", "Heyu");
	unit_test_strcmp("Heyu", "Heyo");

	return 0;
}
