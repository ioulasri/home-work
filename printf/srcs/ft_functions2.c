/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoulasr <imad.oulasri@1337.student.ma>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:23:53 by imoulasr          #+#    #+#             */
/*   Updated: 2023/11/21 13:28:18 by imoulasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_printint(int num, int flag)
{
	int	counter;

	counter = 0;
	if (flag == 1 && num > 0)
	{
		counter++;
		write(1, "+", 1);
	}
	else if (flag == 2 && num > 0)
	{
		counter++;
		write(1, " ", 1);
	}
	ft_putnbr(num);
	return (ft_numlen(num) + counter);
}


int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (0);
}

int	ft_print_hexa(unsigned long int n, char *hex)
{
	if (n > 15)
		ft_print_hexa(n / 16, hex);
	return (1 + ft_print_char(hex[n % 16]));
}

int	ft_hexlen(unsigned long int n)
{
	int	counter;

	counter = 1;
	if (n == 0)
		return (1);
	while (n > 15)
	{
		counter++;
		n /= 16;
	}
	return (counter);
}

int	ft_puthex(unsigned long int n, int flag, char hex)
{
	int	count;

	count = 0;
	if (flag == 1 && hex == 'x' && n)
		count += write(1, "0x", 2);
	else if (flag == 1 && hex == 'X' && n)
		count += write(1, "0X", 2);
	if (hex == 'x')
		ft_print_hexa(n, "0123456789abcdef");
	else
		ft_print_hexa(n, "0123456789ABCDEF");
	count += ft_hexlen(n);
	return (count);
}
