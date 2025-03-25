/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satakrur <satakrur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:41:51 by satakrur          #+#    #+#             */
/*   Updated: 2025/01/13 16:17:21 by satakrur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexc(unsigned int hex)
{
	size_t	i;
	char	str[18];
	char	*hex_chars;
	size_t	j;

	hex_chars = "0123456789ABCDEF";
	if (hex == 0)
		return (ft_printstr("0"));
	i = 0;
	while (hex > 0)
	{
		str[i] = hex_chars[hex % 16];
		hex = hex / 16;
		i++;
	}
	i--;
	j = 0;
	while (i >= j)
	{
		write(1, &str[i - j], 1);
		j++;
	}
	return (j);
}
