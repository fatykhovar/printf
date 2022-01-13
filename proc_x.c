#include "ft_printf.h"

int	hex_symb_count(size_t nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 16;
		count++;
	}
	return (count);
}

void	hex_print(size_t arg, char reg, int *count)
{
	char	c;

	if (arg == 0)
		return ;
	if (arg % 16 < 10)
		c = arg % 16 + '0';
	else
		c = reg - ('x' - 'a') + arg % 16 - 10;
	hex_print(arg / 16, reg, count);
	write (1, &c, 1);
	(*count)++;
}

int	minus_x(unsigned int arg, char reg, int count, t_list cur_list)
{
	int	symbols;

	symbols = hex_symb_count(arg);
	while (count < cur_list.accur - symbols)
		count = write_zero(count);
	if (arg == 0 && cur_list.accur != 0)
		count = write_zero(count);
	else
		hex_print(arg, reg, &count);
	while (count < cur_list.width)
		count = write_space(count);
	return (count);
}

int	not_minus_x(unsigned int arg, char reg, int count, t_list cur_list)
{
	int	symbols;
	int	max_symb_accur;
	int	max_width_accur;

	symbols = hex_symb_count(arg);
	if (cur_list.accur == 0 && arg == 0)
		symbols = 0;
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
	if (arg == 0 && cur_list.accur != 0)
		count = write_zero(count);
	else
		hex_print(arg, reg, &count);
	return (count);
}

int	proc_x(unsigned int arg, char reg, t_list cur_list)
{
	int	count;
	int	symbols;
	int	max_symb_accur;
	int	max_width_accur;

	count = 0;
	symbols = hex_symb_count(arg);
	max_symb_accur = max_number(symbols, cur_list.accur);
	max_width_accur = max_number(cur_list.width, cur_list.accur);
	if (cur_list.minus == 1)
		count = minus_x(arg, reg, count, cur_list);
	else
		count = not_minus_x(arg, reg, count, cur_list);
	return (count);
}
