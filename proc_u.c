#include "ft_printf.h"

void	unsign_print(int nb, int *count)
{
	char	c;

	c = nb % 10 + '0';
	if (nb <= 0)
	{
		return ;
	}
	unsign_print(nb / 10, count);
	write(1, &c, 1);
	(*count)++;
}

int	proc_u(unsigned int arg, t_list cur_list)
{
	int	count;

	count = 0;
	if (arg == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		unsign_print(arg, &count);
		return (count);
	}
}