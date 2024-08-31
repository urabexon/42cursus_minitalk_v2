/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:17:04 by hurabe            #+#    #+#             */
/*   Updated: 2024/06/03 20:30:15 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hex(unsigned int n, const char format)
{
	const char	*hex_num;
	int			count;

	count = 0;
	if (format == 'x')
		hex_num = HEX_LOWER;
	else if (format == 'X')
		hex_num = HEX_UPPER;
	else
		return (-1);
	if (n >= 16)
		count += ft_printf_hex(n / 16, format);
	ft_putchar_fd(hex_num[n % 16], 1);
	return (count + 1);
}
