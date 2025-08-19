#include "../libasm.h"
#include <unistd.h>
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

void	unit_test_write_fd(int fd_write, int fd_write_ft, int fd_read, int fd_read_ft, char *s, int len) {

	int res = write(fd_write, s, strlen(s));
	int err = errno;
	
	int res_ft = ft_write(fd_write_ft, s, strlen(s));
	int err_ft = errno;
	
	assert(res == res_ft);

	if (res < 0) {
		assert(err == err_ft);
		return;
	}
	
	char *buffer = calloc(len + 1, sizeof(char));
	char *buffer_ft = calloc(len + 1, sizeof(char));

	if (buffer == NULL || buffer_ft == NULL) {
		char *s_err = "write : no memory available\n";
		write(1, s_err, strlen(s_err));
		if (buffer) free(buffer);
		if (buffer_ft) free(buffer_ft);
		return;
	}

	read(fd_read, buffer, len);
	read(fd_read_ft, buffer_ft, len);

	assert(strcmp(buffer, buffer_ft) == 0);
	
	free(buffer);
	free(buffer_ft);
}

void	unit_test_write(char *s, int len) {
	char path_write_txt[] = "write.txt";
	char path_ft_write_txt[] = "ft_write.txt";

	int fd_write = open(path_write_txt, O_WRONLY | O_CREAT);
	int fd_write_ft = open(path_ft_write_txt, O_WRONLY | O_CREAT);
	int fd_read = open(path_write_txt, O_RDONLY);
	int fd_read_ft = open(path_ft_write_txt, O_RDONLY);

	if (fd_write < 0 || fd_write_ft < 0 || fd_read < 0 || fd_read_ft < 0)
	{
		char *err_s = "write : couldn't open file\n";
		write(1, err_s, strlen(err_s));
		close(fd_write);
		close(fd_write_ft);
		close(fd_read);
		close(fd_read_ft);
		return;
	}

	unit_test_write_fd(fd_write, fd_write_ft, fd_read, fd_read_ft, s, len);

	close(fd_write);
	close(fd_write_ft);
	close(fd_read);
	close(fd_read_ft);

	remove(path_write_txt);
	remove(path_ft_write_txt);
}

int	test_write() {
	unit_test_write("", 0);
	
	char *s = "Hello\n";
	int len = strlen(s);

	unit_test_write(s, len);
	unit_test_write(s, 0);
	unit_test_write(s, 100);

	unit_test_write_fd(10, 10, 10, 10, s, len);
	unit_test_write_fd(-1, -1, -1, -1, s, len);

	return 0;
}
