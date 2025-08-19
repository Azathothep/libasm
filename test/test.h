#ifndef TESTS_H
# define TESTS_H

#include "../libasm.h"

int	test_write();
int	test_read();
int	test_strlen();
int	test_strcmp();
int	test_strcpy();
int	test_strdup();
int	test_atoi_base();
int	test_list_push_front();
int	test_list_size();
int	test_list_sort();
int	test_list_remove_if();

int	compare_list_datas(t_list *list, char *datas[]);
void	free_list(t_list *list, void (*free_data)(void *));
void	free_stack_data(void *data);
void	print_list_datas(t_list *list);

#endif
