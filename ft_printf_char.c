/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:44:46 by hutzig            #+#    #+#             */
/*   Updated: 2024/05/13 17:55:29 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* The function is protected from failure and return -1 on error. */

int	ft_printf_char(char c)
{
	return (write(1, &c, 1));
}
