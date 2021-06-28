#include "ft_printf.h"

int	proc_c(char arg, t_list cur_list)
{
	int	count;

	count = 1;
	if (cur_list.minus == 1)
	{
		write(1, &arg, 1);
		while (count <= cur_list.width)
		{
			write (1, " ", 1);
			count++;
		}
	}
	else
	{
		while (count <= cur_list.width - 1)
		{
			write (1, " ", 1);
			count++;
		}
		write(1, &arg, 1);
	}
	return (count);
}
