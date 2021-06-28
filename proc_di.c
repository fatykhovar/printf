#include "ft_printf.h"

int	print_neg(int count, int arg)
{
	if (arg != -2147483648)
		dec_print(-1 * arg, &count);
	else
	{
		write(1, "2147483648", 10);
		count += 10;
	}
	return (count);
}

int	minus_pos(int count, int symbols, int arg, t_list cur_list)
{
	while (count < cur_list.accur - symbols)
		count = write_zero(count);
	if (arg != 0)
		dec_print(arg, &count);
	else if (cur_list.accur != 0)
		count = write_zero(count);
	while (count < cur_list.width)
		count = write_space(count);
	return (count);
}

int	neg(int count, int symbols, int arg, t_list cur_list)
{
	int	max_symb_accur;
	int	max_width_accur;

	max_symb_accur = max_number(symbols, cur_list.accur);
	max_width_accur = max_number(cur_list.width, cur_list.accur);
	if (cur_list.zero == 1 && cur_list.accur <= 0)
	{
		write(1, "-", 1);
		count++;
		while (count < cur_list.width - max_symb_accur)
			count = write_zero(count);
	}
	else
	{
		while (count < cur_list.width - max_symb_accur - 1)
			count = write_space(count);
		write(1, "-", 1);
		count++;
		while (cur_list.accur > 0 && ((cur_list.width > cur_list.accur
					&& count < max_width_accur - symbols)
				|| (cur_list.width <= cur_list.accur
					&& count < max_width_accur - symbols + 1)))
			count = write_zero(count);
	}
	return (print_neg(count, arg));
}

int	pos(int count, int symbols, int arg, t_list cur_list)
{
	int	max_symb_accur;
	int	max_width_accur;

	max_symb_accur = max_number(symbols, cur_list.accur);
	max_width_accur = max_number(cur_list.width, cur_list.accur);
	//printf("%d\n", cur_list.accur);
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
	if (arg != 0)
		dec_print(arg, &count);
	else if (cur_list.accur != 0)
		count = write_zero(count);
	return (count);
}

int	proc_di(int arg, t_list cur_list)
{
	int	count;
	int	symbols;

	count = 0;
	symbols = symb_count(arg, cur_list);
	if (cur_list.minus == 1)
	{
		if (arg < 0)
		{
			write(1, "-", 1);
			count++;
			while (count - 1 < cur_list.accur - symbols)
				count = write_zero(count);
			count = print_neg(count, arg);
			while (count < cur_list.width)
				count = write_space(count);
		}
		else
			count = minus_pos(count, symbols, arg, cur_list);
	}
	else if (arg < 0)
		count = neg(count, symbols, arg, cur_list);
	else
		count = pos(count, symbols, arg, cur_list);
	return (count);
}
