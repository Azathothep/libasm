#include "../libasm.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int	unit_test_strcpy(char *source) {
	int len = strlen(source);
	
	char *dest = malloc(len + 1);
	char *ft_dest = malloc(len + 1);
	if (dest == NULL || ft_dest == NULL) {
		char *errmsg = "strcpy : No available memory left\n";
		write(1, errmsg, strlen(errmsg));
		return 1;
	}

	char *cpy = strcpy(dest, source);
	ft_strcpy(ft_dest, source);
	(void)cpy;

	assert(strcmp(dest, ft_dest) == 0);

	char *ft_cpy = ft_strcpy(dest, source);
	(void)ft_cpy;
	assert(cpy == ft_cpy);

	free(dest);
	free(ft_dest);

	return 0;
}

int	test_strcpy() {
	if (	unit_test_strcpy("Hello\n")
		|| unit_test_strcpy("")
		|| unit_test_strcpy("qozuidj\n\t    jjqjjj"))
		return 0;		

	return 0;
}
