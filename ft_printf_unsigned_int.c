/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:51:20 by hutzig            #+#    #+#             */
/*   Updated: 2024/05/13 11:41:39 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_unsigned_int(unsigned int n, int total_length)
{
	if (n > 9)
	{
		total_length = ft_printf_unsigned_int(n / 10, total_length);
		if (total_length == -1)
			return (-1);
		total_length = ft_printf_unsigned_int(n % 10, total_length);
	}
	else
		total_length += ft_printf_char(n + '0');
	if (total_length == -1)
		return (-1);
	return (total_length);
}
