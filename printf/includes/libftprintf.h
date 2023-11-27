/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoulasr <imad.oulasri@1337.student.ma>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:41:05 by imoulasr          #+#    #+#             */
/*   Updated: 2023/11/21 13:27:58 by imoulasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <limits.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_numlen(int num);
void	ft_putnbr(int num);
int		ft_printint(int num, int flag);
int		ft_putadress(unsigned long int n);
int		ft_print_char(char c);
int		ft_print_hexa(unsigned long int n, char *hex);
int		ft_hexlen(unsigned long int n);
int		ft_puthex(unsigned long int n, int flag, char hex);
int		ft_putunsignedint(unsigned int n);

#endif /* LIBFTPRINTF_H */