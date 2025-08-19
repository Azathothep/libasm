#include "../libasm.h"
#include "test.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <stdio.h>

int	test_list_push_front() {

	t_list **begin_list = malloc(sizeof(t_list**));
	if (begin_list == NULL) {
		char *err_s = "list_push_front : no memory available\n";
		write(1, err_s, strlen(err_s));
		return 1;
	}

	*begin_list = NULL;

	// ---

	ft_list_push_front(begin_list, "1");
	ft_list_push_front(begin_list, "2");
	ft_list_push_front(begin_list, "3");

	char *datas_1[3] = { "3", "2", "1" };
	assert(compare_list_datas(*begin_list, datas_1) == 0);

	free_list(*begin_list, &free_stack_data);
	
	*begin_list = NULL;
		
	// ---

	ft_list_push_front(begin_list, "78");

	char *datas_2[1] = { "78" };
	assert(compare_list_datas(*begin_list, datas_2) == 0);

	free_list(*begin_list, &free_stack_data);
	
	*begin_list = NULL;

	free(begin_list);

	return 0;
}
