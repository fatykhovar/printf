#include "ft_printf.h"

int	unsign_symb_count(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

void	unsign_pos_print(unsigned int nb, int *count)
{
	char	c;

	c = nb % 10 + '0';
	if (nb <= 0)
	{
		return ;
	}
	unsign_pos_print(nb / 10, count);
	write(1, &c, 1);
	(*count)++;
}

int	unsigned_print(int count, unsigned int arg)
{
	if (arg != 0)
	{
		unsign_pos_print(arg, &count);
		return (count);
	}
	else
		count = write_zero(count);
	return (count);
}

int	not_minus_u(int count, t_list cur_list, int symbols, unsigned int arg)
{
	int	max_symb_accur;
	int	max_width_accur;

	max_symb_accur = max_number(symbols, cur_list.accur);
	max_width_accur = max_number(cur_list.width, cur_list.accur);
	if (cur_list.zero == 1 && cur_list.accur < 0)
		while (count < cur_list.width - max_symb_accur)
			count = write_zero(count);
	else
	{
		while (count < cur_list.width - max_symb_accur)
			count = write_space(count);
		while (count < max_width_accur - symbols)
			count = write_zero(count);
	}
	if (cur_list.accur != 0 || arg != 0)
		count = unsigned_print(count, arg);
	return (count);
}

int	proc_u(unsigned int arg, t_list cur_list)
{
	int	count;
	int	symbols;
	int	max_symb_accur;
	int	max_width_accur;

	count = 0;
	symbols = unsign_symb_count(arg);
	max_symb_accur = max_number(symbols, cur_list.accur);
	max_width_accur = max_number(cur_list.width, cur_list.accur);
	if (cur_list.accur == 0 && arg == 0)
		symbols = 0;
	if (cur_list.minus == 1)
	{
		while (count < cur_list.accur - symbols)
			count = write_zero(count);
		if (cur_list.accur != 0 || arg != 0)
			count = unsigned_print(count, arg);
		while (count < cur_list.width)
			count = write_space(count);
	}
	else
		count = not_minus_u(count, cur_list, symbols, arg);
	return (count);
}
