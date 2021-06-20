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

int	symb_count(int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
		nb = nb * (-1);
	if (nb == 0)
		count = 1;
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

// int	neg_print()
// {

// }

// int	pos_print()
// {

// }

int	max_number(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	proc_di(int arg, t_list cur_list)
{
	int	count;
	int	symbols;
	int	max_symb_accur;
	int	max_width_accur;

	count = 0;
	symbols = symb_count(arg);
	max_symb_accur = max_number(symbols, cur_list.accur);
	max_width_accur = max_number(cur_list.width, cur_list.accur);
	if (cur_list.minus == 1)
	{
		if (arg < 0)
		{
			write(1, "-", 1);
			count++;
			while (count - 1 < cur_list.accur - symbols)
			{
				write(1, "0", 1);
				count++;
			}
			if (arg != -2147483648)
				dec_print(-1 *arg, &count);
			else
			{
				write(1, "2147483648", 11);
				count += 11;
			}
			while (count < cur_list.width)
			{
				write(1, " ", 1);
				count++;
			}
		}
		else
		{
			while (count < cur_list.accur - symbols)
			{
				write(1, "0", 1);
				count++;
			}
			if (arg != 0)
				dec_print(arg, &count);
			else
			{
				write(1, "0", 1);
				count++;
			}
			while (count < cur_list.width)
			{
				write(1, " ", 1);
				count++;
			}
		}
	}
	else
	{
		if (arg < 0)
		{
			while ((count + max_symb_accur) < cur_list.width - 1)
			{
				write(1, " ", 1);
				count++;
			}
			write(1, "-", 1);
			count++;
			while (count < max_width_accur - symbols + 1)
			{
				// printf("%i\n", max_width_accur - symbols + 1);
				// return (0);
				write(1, "0", 1);
				count++;
			}
			if (arg != -2147483648)
				dec_print(-1 *arg, &count);
			else
			{
				write(1, "2147483648", 11);
				count += 11;
			}
		}
		else
		{
			while ((count + max_symb_accur) < cur_list.width)
			{
				write(1, " ", 1);
				count++;
			}
			while (count < max_width_accur - symbols)
			{
				write(1, "0", 1);
				count++;
			}
			if (arg != 0)
				dec_print(arg, &count);
			else
			{
				write(1, "0", 1);
				count++;
			}
		}
	}
	return (count);
}
