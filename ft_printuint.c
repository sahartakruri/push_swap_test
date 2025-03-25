/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satakrur <satakrur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:02:22 by satakrur          #+#    #+#             */
/*   Updated: 2025/01/13 16:10:32 by satakrur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_memoall(size_t i)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	return (str);
}

static size_t	ft_count(unsigned int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_printuint(unsigned int u)
{
	size_t	i;
	char	*str;

	if (u == 0)
		return (ft_printchar('0'));
	i = ft_count(u);
	str = ft_memoall(i);
	if (str == NULL)
		return (0);
	str[i] = '\0';
	while (u > 0)
	{
		str[--i] = (u % 10) + '0';
		u = u / 10;
	}
	i = ft_printstr(str);
	free(str);
	return (i);
}
