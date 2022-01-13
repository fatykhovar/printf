#include "ft_printf.h"

int	print_p(size_t arg, int count, t_list cur_list)
{
	write(1, "0x", 2);
	count += 2;
	if (arg == 0 && cur_list.accur != 0)
		count = write_zero(count);
	else
		hex_print(arg, 'x', &count);
	return (count);
}

int	proc_p(size_t arg, t_list cur_list)
{
	int	count;
	int	symbols;

	count = 0;
	symbols = hex_symb_count(arg);
	if (arg == 0 && cur_list.accur == 0)
		symbols = 0;
	if (cur_list.minus == 1)
	{
		count = print_p(arg, count, cur_list);
		while (count < cur_list.width)
			count = write_space(count);
	}
	else
	{
		while (count < cur_list.width - symbols - 2)
			count = write_space(count);
		count = print_p(arg, count, cur_list);
	}
	return (count);
}
