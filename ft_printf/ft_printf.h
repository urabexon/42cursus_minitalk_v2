/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:48:42 by hurabe            #+#    #+#             */
/*   Updated: 2024/08/25 17:44:09 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//include
# include <stdarg.h>
# include <stdint.h>
# include "../libft/libft.h"

//hex
# define HEX_UPPER	"0123456789ABCDEF"
# define HEX_LOWER	"0123456789abcdef"

//prottype
int	ft_printf(const	char *format, ...);
int	ft_printf_char(char c); //%c
int	ft_printf_str(char *str); //%s
int	ft_printf_pointer(void *ptr); //%p
int	ft_printf_nbr(int n); //%d,%i
int	ft_printf_nbr_unsigned(unsigned int n); //%u
int	ft_printf_hex(unsigned int n, const char format); //%x,%X
int	ft_putstr_count(char *c); //%%

#endif