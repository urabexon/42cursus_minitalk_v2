/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr_unsigned.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:17:06 by hurabe            #+#    #+#             */
/*   Updated: 2024/06/01 20:16:20 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlength_unsigned(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		i = 1;
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa_unsigned(unsigned int nbr)
{
	char			*str;
	int				len;

	len = ft_numlength_unsigned(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr == 0)
		str[0] = '0';
	while (nbr != 0)
	{
		str[--len] = '0' + (nbr % 10);
		nbr /= 10;
	}
	return (str);
}

int	ft_printf_nbr_unsigned(unsigned int n)
{
	char	*num_str;
	int		len;

	num_str = ft_itoa_unsigned(n);
	if (!num_str)
		return (0);
	len = ft_strlen(num_str);
	ft_putstr_fd(num_str, 1);
	free(num_str);
	return (len);
}
