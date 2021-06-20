#include "ft_printf.h"

void	hex_print(unsigned int arg, char reg, int *count)
{
	char	c;

	if (arg < 0)
		return ;
	if (arg % 16 < 10)
		c = arg % 16 + '0';
	else
		c = reg + arg % 16 - 10;
	hex_print(arg / 16, reg, count);
	write (1, &c, 1);
	(*count)++;
}

int	proc_x(unsigned int arg, char reg, t_list cur_list)
{
	int	count;

	count = 0;
	if (reg == 'x')
		hex_print(arg, 'a', &count);
	if (reg == 'X')
		hex_print(arg, 'A', &count);
	return (count);
}