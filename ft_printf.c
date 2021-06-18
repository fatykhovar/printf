#include "ft_printf.h"

int	var_process(const char *str, int *count, va_list ap)
{
	t_list	cur;
	int		i;

	i = 0;
	if (str[i] == 'c')
		*count += proc_c(va_arg(ap, int));
	if (str[i] == 's')
		*count += proc_s(va_arg(ap, char *));
	if (str[i] == 'p')
		*count += proc_p(va_arg(ap, unsigned int));
	if (str[i] == 'd' || str[i] == 'i')
		*count += proc_di(va_arg(ap, int));
	if (str[i] == 'u')
		*count += proc_u(va_arg(ap, unsigned int));
	if (str[i] == 'x' || str[i] == 'X')
		*count += proc_x(va_arg(ap, unsigned int), str[i]);
	if (str[i] == '\0')
		return (i);
	//flags
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			count++;
		}
		else
		{
			i++;
			if (str[i] == '%')
				write(1, "%", 1);
			else
			{
				i = var_process(&str[i], &count, ap);
			}
		}
		i++;
	}
	va_end(ap);
	return (count);
}
