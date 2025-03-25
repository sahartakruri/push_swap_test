/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satakrur <satakrur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:35:57 by satakrur          #+#    #+#             */
/*   Updated: 2025/01/13 16:20:13 by satakrur         ###   ########.fr       */
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

static size_t	ft_count(int n)
{
	size_t	i;
	int		sign;

	i = 0;
	if (n < 0)
	{
		sign = -1;
		n *= sign;
	}
	else
		sign = 1;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	if (sign == -1)
		return (i + 1);
	return (i);
}

int	ft_printint(int n)
{
	size_t	i;
	char	*str;

	if (n == 0)
		return (ft_printchar('0'));
	if (n == -2147483648)
		return (ft_printstr("-2147483648"));
	i = ft_count(n);
	str = ft_memoall(i);
	if (str == NULL)
		return (0);
	str[i] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[--i] = (n % 10) + '0';
		n = n / 10;
	}
	i = ft_printstr(str);
	free(str);
	return (i);
}
