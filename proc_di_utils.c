#include "ft_printf.h"

void	dec_print(int nb, int *count)
{
	char	c;

	c = nb % 10 + '0';
	if (nb <= 0)
	{
		return ;
	}
	dec_print(nb / 10, count);
	write(1, &c, 1);
	(*count)++;
}

int	symb_count(int nb, t_list cur_list)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		return (10);
	if (nb < 0)
		nb = nb * (-1);
	if (nb == 0)
	{
		if (cur_list.accur == 0)
			return (0);
		return (1);
	}
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

int	max_number(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	write_zero(int count)
{
	write(1, "0", 1);
	count++;
	return (count);
}

int	write_space(int count)
{
	write(1, " ", 1);
	count++;
	return (count);
}