/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:17:12 by hurabe            #+#    #+#             */
/*   Updated: 2024/06/06 17:17:57 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_pointer_hex(uintptr_t n)
{
	const char	*hex_num;
	char		space[16 + 1];
	int			start;
	int			index;

	hex_num = HEX_LOWER;
	index = 16;
	space[index--] = '\0';
	if (n == 0)
		space[index--] = '0';
	while (n != 0)
	{
		space[index--] = hex_num[n % 16];
		n /= 16;
	}
	start = index + 1;
	while (space[start])
	{
		ft_putchar_fd(space[start++], 1);
	}
	return (16 - index - 1);
}

int	ft_printf_pointer(void *ptr)
{
	uintptr_t	ptr_data;
	int			count;

	ptr_data = (uintptr_t)ptr;
	count = 2;
	write(1, "0x", 2);
	count += ft_printf_pointer_hex(ptr_data);
	return (count);
}
