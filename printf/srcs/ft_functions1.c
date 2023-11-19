/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoulasr <imad.oulasri@1337.student.ma>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:21:05 by imoulasr          #+#    #+#             */
/*   Updated: 2023/11/16 15:53:25 by imoulasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_numlen(int num)
{
	int	i;

	i = 0;
	if (num < 0)
	{
		i++;
		num = -num;
	}
	if (num == 0)
		return (1);
	while (num > 0)
	{
		i++;
		num /= 10;
	}
	return (i);
}

void	ft_putnbr(int num)
{
	long	number;

	number = num;
	if (num < 0)
	{
		ft_putchar('-');
		number = -number;
	}
	if (number > 9)
		ft_putnbr(number / 10);
	ft_putchar(number % 10 + 48);
}