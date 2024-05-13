/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:56:58 by hutzig            #+#    #+#             */
/*   Updated: 2024/05/10 19:00:46 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);

int	ft_printf_char(char c);
int	ft_printf_string(char *s);
int	ft_printf_int(int n, int total_length);
int	ft_printf_unsigned_int(unsigned int n, int total_length);
int	ft_printf_hexadecimal(unsigned int n, char format);
int	ft_printf_pointer(void *ptr);

#endif 
