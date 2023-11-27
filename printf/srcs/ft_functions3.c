/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoulasr <imad.oulasri@1337.student.ma>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:22:22 by imoulasr          #+#    #+#             */
/*   Updated: 2023/11/21 13:28:39 by imoulasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_putadress(unsigned long int n)
{
	if (!n)
		return (ft_putstr("(nil)"));
	return (ft_puthex(n, 1, 'x'));
}

int	unsigned_length(unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	ft_putunsignedint(unsigned int n)
{
	if (n > 9)
		ft_putunsignedint(n / 10);
	ft_putchar(n % 10 + 48);
	return (unsigned_length(n));
}
