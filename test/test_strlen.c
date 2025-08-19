#include "../libasm.h"
#include <unistd.h>
#include <string.h>
#include <assert.h>

void	unit_test_strlen(char *s) {
	int len = strlen(s);
	int ftlen = ft_strlen(s);

	assert(ftlen == len);
}

int	test_strlen() {

	unit_test_strlen("Hello\n");
	unit_test_strlen("");
	unit_test_strlen("\n");
	unit_test_strlen("qozid  qzdoij\t\n");

	return 0;
}
