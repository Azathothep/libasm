#include "../libasm.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <stdio.h>

int	compare_list_datas(t_list *list, char* datas[]) {
	
	int i = 0;
	while (list != NULL) 
	{
		if (strcmp(list->data, datas[i]) != 0)
			return -1;

		list = list->next;
		i++;
	}

	return 0;
}

void	free_list(t_list *list, void (*free_data)(void *)) {
	if (list == NULL)
		return;

	free_data(list->data);
	free_list(list->next, free_data);
	free(list);
	list = NULL;
}

void	free_stack_data(void *data) {
	(void)data;
}

void	print_list_datas(t_list *list) {
	while (list != NULL) {
		printf("List data : %s\n", (char *)(list->data));
		list = list->next;
	}
}
