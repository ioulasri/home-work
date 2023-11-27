/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoulasr <imad.oulasri@1337.student.ma>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:43:03 by imoulasr          #+#    #+#             */
/*   Updated: 2023/11/27 18:45:26 by imoulasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	print_argument(const char *format, va_list ap, int *counter, int flag)
{
	if (*format == 's')
		*counter += ft_putstr(va_arg(ap, char *));
	else if (*format == 'c')
		*counter += ft_putchar(va_arg(ap, int));
	else if (*format == 'd' || *format == 'i')
		*counter += ft_printint(va_arg(ap, int), flag);
	else if (*format == 'p')
		*counter += ft_putadress(va_arg(ap, unsigned long int));
	else if (*format == 'x' || *format == 'X')
		*counter += ft_puthex(va_arg(ap, unsigned int), flag, *format);
	else if (*format == 'u')
		*counter += ft_putunsignedint(va_arg(ap, unsigned int));
	else if (*format == '%')
		*counter += write(1, "%", 1);
	else
	{
		*counter += write(1, "%", 1);
		if (flag == 2)
			*counter += write(1, " ", 1);
		*counter += write(1, format, 1);
	}
	(void)flag;
}

void	ft_check_flags(const char **format, int *flag)
{
	while (**format == ' ' || **format == '+' || **format == '#')
	{
		*flag = 1;
		if (**format == ' ')
			*flag = 2;
		(*format)++;
	}
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		flag;
	va_list	ap;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			flag = 0;
			ft_check_flags(&format, &flag);
			print_argument(format, ap, &count, flag);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}

