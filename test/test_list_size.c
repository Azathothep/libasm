#include "../libasm.h"
#include "test.h"
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>

int	test_list_size() {

	t_list **begin_list = malloc(sizeof(t_list**));
	if (begin_list == NULL) {
		char *err_s = "list_size : no memory available\n";
		write(1, err_s, strlen(err_s));
		return 1;
	}

	*begin_list = NULL;

	// assert(ft_list_size(*begin_list) == 0);

	ft_list_push_front(begin_list, "1");
	ft_list_push_front(begin_list, "2");
	ft_list_push_front(begin_list, "3");

	assert(ft_list_size(*begin_list) == 3);

	free_list(*begin_list, &free_stack_data);
	
	free(begin_list);	

	return 0;
}
