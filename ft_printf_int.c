/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:35:15 by hutzig            #+#    #+#             */
/*   Updated: 2024/05/13 17:54:10 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_int(int n, int total_length)
{
	int	cp;

	cp = total_length;
	if (n == -2147483648)
		return (ft_printf_string("-2147483648"));
	else if (n < 0)
	{
		total_length = ft_printf_char('-');
		if (cp > total_length)
			return (-1);
		total_length = ft_printf_int(-n, total_length);
	}
	else if (n > 9)
	{
		total_length = ft_printf_int(n / 10, total_length);
		if (cp > total_length)
			return (-1);
		total_length = ft_printf_int(n % 10, total_length);
	}
	else
		total_length += ft_printf_char(n + '0');
	if (cp > total_length)
		return (-1);
	return (total_length);
}
