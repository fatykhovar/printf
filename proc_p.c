#include "ft_printf.h"

int	proc_p(unsigned long long arg, t_list cur_list)
{
	int	count;
	int	symbols;

	if (cur_list.accur == -1)
		cur_list.accur = 0;
	count = 0;
	symbols = hex_symb_count(arg);
	if (cur_list.minus == 1)
	{
		write(1, "0x", 2);
		count += 2;
		hex_print(arg, 'x', &count);
		while (count < cur_list.width)
			count = write_space(count);
	}
	else
	{
		while (count < cur_list.width - symbols)
			count = write_space(count);
		write(1, "0x", 2);
		count += 2;
		hex_print(arg, 'x', &count);
	}
	return (count);
}
