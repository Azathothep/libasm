#include "../libasm.h"
#include "test.h"
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>

int	test_list_remove_if() {
	t_list **begin_list = malloc(sizeof(t_list**));
	if (begin_list == NULL) {
		char *err_s = "list_remove_if : no memory available\n";
		write(1, err_s, strlen(err_s));
		return 1;
	}

	*begin_list = NULL;

	ft_list_remove_if(begin_list, "1", &strcmp, &free);	

	ft_list_push_front(begin_list, strdup("1"));
	ft_list_push_front(begin_list, strdup("1"));
	ft_list_remove_if(begin_list, "1", &strcmp, &free);	
	assert(compare_list_datas(*begin_list, NULL) == 0);

	ft_list_push_front(begin_list, strdup("3"));
	ft_list_push_front(begin_list, strdup("1"));
	ft_list_push_front(begin_list, strdup("3"));
	ft_list_push_front(begin_list, strdup("0"));
	ft_list_push_front(begin_list, strdup("3"));
	
	ft_list_remove_if(begin_list, "3", &strcmp, &free);
	char *datas_1[2] = { "0", "1" };
	assert(compare_list_datas(*begin_list, datas_1) == 0);

	free_list(*begin_list, &free);
	*begin_list = NULL;

	free(begin_list);
	return 0;
}
