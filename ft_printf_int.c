/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:35:15 by hutzig            #+#    #+#             */
/*   Updated: 2024/05/13 12:23:41 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_int(int n, int total_length)
{
	if (n == -2147483648)
		return (ft_printf_string("-2147483648"));
	else if (n < 0)
	{
		total_length += ft_printf_char('-');
		if (total_length == -1)
			return (-1);
		total_length = ft_printf_int(-n, total_length);
	}
	else if (n > 9)
	{
		total_length = ft_printf_int(n / 10, total_length);
		if (total_length == -1)
			return (-1);
		total_length = ft_printf_int(n % 10, total_length);
	}
	else
		total_length += ft_printf_char(n + '0');
	if (total_length == -1)
		return (-1);
	return (total_length);
}
/* The return value is the length of the printed output of the signed integer
 * which is converted into characters using recursion. */
