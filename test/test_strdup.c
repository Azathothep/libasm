#include "../libasm.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void	unit_test_strdup(char *s) {
	char *cpy = strdup(s);
	char *ft_cpy = ft_strdup(s);

	if (cpy == NULL || ft_cpy == NULL)
		return;

	assert(strcmp(cpy, ft_cpy) == 0);

	free(cpy);
	free(ft_cpy);
}

int	test_strdup() {

	unit_test_strdup("Hello\n");
	unit_test_strdup("");
	unit_test_strdup("qo \n \n      oqzidjji\0jjjjj\0");

	return 0;
}
