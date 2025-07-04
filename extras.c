/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:26:57 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/02/07 17:19:22 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	return (write (1, &c, 1));
}

int	ft_printstr(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int	ft_printnbr(long n)
{
	char	zero;
	int		len;

	len = 0;
	zero = '0';
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_printnbr(-n) + 1);
	}
	if (n < 10)
	{
		zero += n;
		return (write(1, &zero, 1));
	}
	len += ft_printnbr(n / 10);
	zero += n % 10;
	write (1, &zero, 1);
	len++;
	return (len);
}

int	ft_print_hex(unsigned long n, int up)
{
	char	*set;

	set = "ABCDEF";
	if (n < 10)
		return (ft_printnbr(n));
	else if (up == 0)
		return (ft_printchar(set[n - 10] + 32));
	return (ft_printchar(set[n - 10]));
}

int	ft_print_x(unsigned long n, int up)
{
	if (n < 16)
		return (ft_print_hex(n, up));
	return (ft_print_x(n / 16, up) + ft_print_hex(n % 16, up));
}
