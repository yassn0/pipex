/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:14:28 by yfradj            #+#    #+#             */
/*   Updated: 2025/01/02 19:15:42 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_arg(char type, va_list arg)
{
	int	i;

	i = 0;
	if (type == 'c')
		i = ft_putchar(va_arg(arg, int));
	else if (type == 'd')
		i = ft_putnbr(va_arg(arg, long long));
	else if (type == 'x')
		i = ft_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (type == 'X')
		i = ft_putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (type == 'p')
		i = ft_putptr(va_arg(arg, void *));
	else if (type == 's')
		i = ft_putstr(va_arg(arg, char *));
	else if (type == 'u')
		i = ft_putunsigned_nbr(va_arg(arg, unsigned int));
	else if (type == 'i')
		i = ft_putnbr(va_arg(arg, int));
	else
		i = ft_putchar('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		j;

	len = 0;
	j = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[j])
	{
		if (str[j] == '%')
		{
			j++;
			if (str[j] == '%')
				len += ft_putchar('%');
			else
				len += print_arg(str[j], args);
		}
		else
			len += ft_putchar(str[j]);
		j++;
	}
	va_end(args);
	return (len);
}
