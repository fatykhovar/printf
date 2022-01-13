#include "ft_printf.h"

int	proc_c(char arg, t_list cur_list)
{
	int	count;

	count = 1;
	if (cur_list.minus == 1)
	{
		write(1, &arg, 1);
		while (count < cur_list.width)
			count = write_space (count);
	}
	else
	{
		while (count < cur_list.width)
		{
			if (cur_list.zero == 1)
				count = write_zero(count);
			else
				count = write_space (count);
		}
		write(1, &arg, 1);
	}
	return (count);
}
