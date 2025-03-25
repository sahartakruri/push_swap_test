/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satakrur <satakrur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:42:26 by satakrur          #+#    #+#             */
/*   Updated: 2025/01/13 15:46:25 by satakrur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexptr(unsigned long long ptr)
{
	size_t	i;
	char	str[18];
	char	*hex_chars;
	size_t	j;

	hex_chars = "0123456789abcdef";
	if (ptr == 0)
		return (ft_printstr("0"));
	i = 0;
	while (ptr > 0)
	{
		str[i] = hex_chars[ptr % 16];
		ptr = ptr / 16;
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

int	ft_printptr(void *ptr)
{
	int	i;

	if (ptr == NULL)
	{
		write(1, "0x0", 3);
		return (3);
	}
	write(1, "0x", 2);
	i = ft_printhexptr((unsigned long long)ptr);
	return (i + 2);
}
