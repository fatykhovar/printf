#include "ft_printf.h"

int	min_number(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	s_count(char *arg)
{
	int	i;

	i = 0;
	if (arg == 0)
		return (i);
	while (arg[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	write_s(char *arg, t_list cur_list)
{
	int	i;

	i = 0;
	if (arg == 0)
		return (i);
	while ((arg[i] != '\0' && cur_list.accur < 0)
		|| (arg[i] != '\0' && i < cur_list.accur))
	{
		write(1, &arg[i], 1);
		i++;
	}
	return (i);
}

int	proc_s(char *arg, t_list cur_list)
{
	int	count;
	int	min_arg_accur;
	int	arg_count;

	count = 0;
	arg_count = s_count(arg);
	min_arg_accur = min_number(arg_count, cur_list.accur);
	if (cur_list.accur < 0)
		min_arg_accur = arg_count;
	if (cur_list.minus == 1)
	{
		if (cur_list.accur != 0)
			count += write_s(arg, cur_list);
		while (count < cur_list.width)
			count = write_space(count);
	}
	else
	{
		while (cur_list.width > arg_count
			&& count < cur_list.width - min_arg_accur)
			count = write_space(count);
		if (cur_list.accur != 0)
			count += write_s(arg, cur_list);
	}
	return (count);
}
