/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexadecimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:45:09 by hutzig            #+#    #+#             */
/*   Updated: 2024/05/13 17:54:44 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* The return value is total lenght of printed output. Printing the hexadecimal
 * number is done by converting the any number < 10 into char and printing it
 * and calculating the corresponding hexadecimal digit from the numbers 10 - 16.
 * The conversion is done by subtracting 10 (since letters start from 10 in
 * hexadecimal) and adding it to the character 'a' or 'A'. */

int	ft_printf_hexadecimal(unsigned int n, const char format, int total_length)
{
	int	cp;

	cp = total_length;
	if (n >= 16)
	{
		total_length = ft_printf_hexadecimal(n / 16, format, total_length);
		if (cp > total_length)
			return (-1);
		total_length = ft_printf_hexadecimal(n % 16, format, total_length);
	}
	else if (n < 10)
		total_length += ft_printf_char(n + 48);
	else
	{
		if (format == 'x')
			total_length += ft_printf_char(n - 10 + 'a');
		if (format == 'X')
			total_length += ft_printf_char(n - 10 + 'A');
	}
	if (cp > total_length)
		return (-1);
	return (total_length);
}
