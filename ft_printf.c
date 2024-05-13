/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:31:49 by hutzig            #+#    #+#             */
/*   Updated: 2024/05/10 19:03:00 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	ft_format_eval(va_list ap, const char *cs)
{
	int	len;

	len = 0;
	if (*cs == 'c')
		len += ft_printf_char(va_arg(ap, int));
	else if (*cs == '%')
		len += ft_printf_char('%');
	else if (*cs == 's')
		len += ft_printf_string(va_arg(ap, char *));
	else if (*cs == 'd' || *cs == 'i')
		len += ft_printf_int(va_arg(ap, int), 0);
	else if (*cs == 'u')
		len += ft_printf_unsigned_int(va_arg(ap, unsigned int), 0);
	else if (*cs == 'p')
		len += ft_printf_pointer(va_arg(ap, void *));
	else if (*cs == 'x')
		len += ft_printf_hexadecimal(va_arg(ap, unsigned int), 'x');
	else if (*cs == 'X')
		len += ft_printf_hexadecimal(va_arg(ap, unsigned int), 'X');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		success;
	int		total_length;

	i = 0;
	success = 0;
	total_length = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[++i]))
			success = ft_format_eval(ap, &format[i]);
		else
			success = ft_printf_char(format[i]);
		if (success == -1)
			return (-1);
		i++;
		total_length += success;
	}
	va_end(ap);
	return (total_length);
}
