#include "ft_printf.h"

int	proc_s(char *arg, t_list cur_list)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		write(1, &arg[i], 1);
		i++;
	}
	return (i);
}