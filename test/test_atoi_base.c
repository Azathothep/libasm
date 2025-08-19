#include "../libasm.h"
#include <unistd.h>
#include <assert.h>

int	test_atoi_base() {
	int ret = ft_atoi_base("1", "");
	assert(ret == 0);

	ret = ft_atoi_base("", "0");
	assert(ret == 0);

	ret = ft_atoi_base("q", "01");
	assert(ret == 0);

	ret = ft_atoi_base("", "01\n");
	assert(ret == 0);

	ret = ft_atoi_base("", "011");
	assert(ret == 0);

	ret = ft_atoi_base("", "012");
	assert(ret == 0);

  	ret = ft_atoi_base("2", "012");
  	assert(ret == 2);

	ret = ft_atoi_base("+2", "012");
 	assert(ret == 2);

	ret = ft_atoi_base("-2", "012");
	assert(ret == -2);

	ret = ft_atoi_base("+-2", "012");
	assert(ret == -2);

	ret = ft_atoi_base("-+2", "012");
	assert(ret == -2);

	ret = ft_atoi_base("+--+-++-2", "012");
	assert(ret == 2);

	ret = ft_atoi_base("+-2---+", "012");
	assert(ret == -2);

	ret = ft_atoi_base("00101110", "01");
	assert(ret == 46);

	ret = ft_atoi_base("06AF2", "0123456789ABCDEF");
	assert(ret == 27378);

	return 0;
}
