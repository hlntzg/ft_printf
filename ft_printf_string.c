/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:47:41 by hutzig            #+#    #+#             */
/*   Updated: 2024/05/10 14:45:53 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printf_string(char *s)
{
	ssize_t	error;

	if (!s)
	{
		error = write(1, "(null)", 6);
		if (error == -1)
			return (-1);
		return (6);
	}
	else
		return (write(1, s, ft_strlen(s)));
}
