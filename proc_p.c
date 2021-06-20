#include "ft_printf.h"

int	proc_p(unsigned int arg, t_list cur_list)
{
	int	count;

	count = 2;
	write(1, "0x", 2);
	hex_print(arg, 'A', &count);
	return (count);
}
