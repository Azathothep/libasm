#include "../libasm.h"
#include "test.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int	intcmp(int *a, int *b) {
	if (*a < *b)
		return -1;
	if (*a > *b)
		return 1;
	return 0;
}

int	compare_list_datas_int(t_list *lst, int *datas) {
	while (lst != NULL) {
		if (intcmp(lst->data, datas) != 0)
			return -1;

		lst = lst->next;
		datas++;
	}

	return 0;
}

int	test_list_sort() {
	t_list **begin_list = malloc(sizeof(t_list**));
	if (begin_list == NULL) {
		char *err_s = "list_sort : no memory available\n";
		write(1, err_s, strlen(err_s));
		return 1;
	}

	*begin_list = NULL;

	int a = 2;
	ft_list_push_front(begin_list, &a);
	ft_list_sort(begin_list, &intcmp);
	int datas_1[1] = { 2 };
	assert(compare_list_datas_int(*begin_list, datas_1) == 0);

	int b = 4;
	ft_list_push_front(begin_list, &b);
	ft_list_sort(begin_list, &intcmp);
	int datas_2[2] = { 2, 4 };
	assert(compare_list_datas_int(*begin_list, datas_2) == 0);

	int c = 1;
	int d = 3;
	int e = 0;
	int f = 3;
	ft_list_push_front(begin_list, &c);
	ft_list_push_front(begin_list, &d);
	ft_list_push_front(begin_list, &e);
	ft_list_push_front(begin_list, &f);
	
	ft_list_sort(begin_list, &intcmp); 

	int datas_3[6] = { 0, 1, 2, 3, 3, 4 };
	assert(compare_list_datas_int(*begin_list, datas_3) == 0);
	
	free_list(*begin_list, &free_stack_data);
	*begin_list = NULL;

	free(begin_list);
	
	return 0;
}
