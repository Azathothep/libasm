#include "../libasm.h"
#include <unistd.h>
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

void	unit_test_read_fd(int fd_write, int fd_read, int fd_read_ft, char *s, int len) {
	
	write(fd_write, s, strlen(s));

	char *buffer = calloc(len + 1, 1);
	char *buffer_ft = calloc(len + 1, 1);

	if (buffer == NULL || buffer_ft == NULL) {
		char *s_err = "read : no memory available\n";
		write(1, s_err, strlen(s_err));
		if (buffer) free(buffer);
		if (buffer_ft) free(buffer_ft);
		return;
	}

	int res = read(fd_read, buffer, len + 1);
	int err = errno;

	int res_ft = ft_read(fd_read_ft, buffer_ft, len + 1);
	int err_ft = errno;

	assert(res == res_ft);
	
	if (res < 0) {
		assert(err == err_ft);
	} else if (len > 0){
		assert(strcmp(buffer, buffer_ft) == 0);
	}	

	free(buffer);
	free(buffer_ft);
}

void	unit_test_read(char *s, int len) {
	char path_read_txt[] = "read.txt";

	int fd_write = open(path_read_txt, O_WRONLY | O_CREAT);
	int fd_read = open(path_read_txt, O_RDONLY);
	int fd_read_ft = open(path_read_txt, O_RDONLY);	

	if (fd_write < 0 || fd_read < 0 || fd_read_ft < 0) {
		char *err_s = "read : couldn't open file\n";
		write(1, err_s, strlen(err_s));
		close(fd_write);
		close(fd_read);
		close(fd_read_ft);
		return;
	}

	unit_test_read_fd(fd_write, fd_read, fd_read_ft, s, len);

	close(fd_write);
	close(fd_read);
	close(fd_read_ft);

	remove(path_read_txt);
}

int	test_read() {
	unit_test_read("", 0);
	unit_test_read("", 15);
	
	char *s = "Hello\n";
	int len = strlen(s);

	unit_test_read(s, len);
	unit_test_read(s, 0);
	unit_test_read(s, 100);

	unit_test_read_fd(10, 10, 10, s, len);
	unit_test_read_fd(-1, -1, -1, s, len);

	return 0;
}
