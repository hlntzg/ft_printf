/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:53:28 by hutzig            #+#    #+#             */
/*   Updated: 2024/05/13 17:55:43 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_hex(uintptr_t n, int total_length)
{
	int	cp;

	cp = total_length;
	if (n >= 16)
	{
		total_length = ft_ptr_hex(n / 16, total_length);
		if (cp > total_length)
			return (-1);
		total_length = ft_ptr_hex(n % 16, total_length);
	}
	else if (n < 10)
		total_length += ft_printf_char(n + 48);
	else
		total_length += ft_printf_char(n - 10 + 'a');
	if (cp > total_length)
		return (-1);
	return (total_length);
}

/* The 'uintptr_t' is designed to hold pointer values (and hold any pointer to
 * data without loss of information, so it's used to  guaranteed to have the
 * same size as a pointer */

int	ft_printf_pointer(void *ptr)
{
	uintptr_t	address;
	int			total_length;
	int			prefix_len;

	address = (uintptr_t) ptr;
	prefix_len = ft_printf_string("0x");
	if (prefix_len == -1)
		return (-1);
	total_length = ft_ptr_hex(address, 0);
	if (total_length == -1)
		return (-1);
	total_length += prefix_len;
	return (total_length);
}
