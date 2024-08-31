/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:08:45 by hurabe            #+#    #+#             */
/*   Updated: 2024/06/28 14:52:37 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_format(const char format, va_list args)
{
	int	print_char;

	print_char = 0;
	if (format == 'c')
		print_char += ft_printf_char(va_arg(args, int));
	else if (format == 's')
		print_char += ft_printf_str(va_arg(args, char *));
	else if (format == 'p')
		print_char += ft_printf_pointer(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		print_char += ft_printf_nbr(va_arg(args, int));
	else if (format == 'u')
		print_char += ft_printf_nbr_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_char += ft_printf_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_char += ft_putstr_count("%");
	return (print_char);
}

int	ft_printf(const	char *format, ...)
{
	va_list	args;
	size_t	count;

	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
			count += ft_printf_char(*format);
		else if (*format == '%' && *(format + 1))
			count += ft_printf_format(*(++format), args);
		if (*format)
			format++;
	}
	va_end(args);
	return (count);
}
