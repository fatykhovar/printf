#include "ft_printf.h"

int	flags_accur(const char *str, int *count, t_list *cur_list, va_list ap)
{
	int	i;

	i = 0;
	if (str[i] == '.')
	{
		i++;
		while (str[i] && ((str[i] >= '0' && str[i] <= '9') || str[i] == '*'))
		{
			if (str[i] == '*')
			{
				cur_list->accur = va_arg(ap, int);
				i++;
				break ;
			}
			cur_list->accur = cur_list->accur * 10 + (str[i] - '0');
			i++;
		}
	}
	return (i);
}

int	flags(char *str, int *count, t_list *cur_list, va_list ap)
{
	int	i;

	i = 0;
	if (str[i] == '-')
	{
		cur_list->minus = 1;
		i++;
	}
	if (str[i] == '0')
	{
		cur_list->zero = 1;
		i++;
	}
	while (str[i] && ((str[i] >= '0' && str[i] <= '9') || str[i] == '*'))
	{
		if (str[i] == '*')
		{
			cur_list->width = va_arg(ap, int);
			i++;
			break ;
		}
		cur_list->width = cur_list->width * 10 + (str[i] - '0');
		i++;
	}
	printf("width: %d\n", cur_list->width);
	
	return (i += flags_accur(&str[i], count, cur_list, ap));
}

int	var_process(char *str, int *count, va_list ap)
{
	t_list	cur_list;
	int		i;

	cur_list.accur = 0;
	cur_list.minus = 0;
	cur_list.width = 0;
	cur_list.zero = 0;
	i = flags(str, count, &cur_list, ap);
	//printf("%s\n", str);
	if (str[i] == 'c')
		*count += proc_c(va_arg(ap, int), cur_list);
	if (str[i] == 's')
		*count += proc_s(va_arg(ap, char *), cur_list);
	if (str[i] == 'p')
		*count += proc_p(va_arg(ap, unsigned int), cur_list);
	if (str[i] == 'd' || str[i] == 'i')
		*count += proc_di(va_arg(ap, int), cur_list);
	if (str[i] == 'u')
		*count += proc_u(va_arg(ap, unsigned int), cur_list);
	if (str[i] == 'x' || str[i] == 'X')
		*count += proc_x(va_arg(ap, unsigned int), str[i], cur_list);
	if (str[i] == '\0')
		return (i);
	return (i);
}

void	main_cycle(va_list ap, char *str, int *count)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			(*count)++;
		}
		else
		{
			i++;
			if (str[i] == '%')
				write(1, "%", 1);
			else
			{
				i += var_process(&str[i], count, ap);
			}
		}
		i++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, str);
	main_cycle(ap, (char *)str, &count);
	va_end(ap);
	return (count);
}
