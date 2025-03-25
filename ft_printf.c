/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satakrur <satakrur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:21:06 by satakrur          #+#    #+#             */
/*   Updated: 2025/01/14 16:16:50 by satakrur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printoptions(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_printchar(va_arg(args, int));
	else if (c == 's')
		len = ft_printstr(va_arg(args, char *));
	else if (c == 'p')
		len = ft_printptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		len = ft_printint(va_arg(args, int));
	else if (c == 'u')
		len = ft_printuint(va_arg(args, unsigned int));
	else if (c == 'x')
		len = ft_printhex(va_arg(args, unsigned int));
	else if (c == 'X')
		len = ft_printhexc(va_arg(args, unsigned int));
	else if (c == '%')
		len = ft_printchar('%');
	else if (c != ' ')
		len = ft_printchar(c);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	va_start(args, str);
	i = 0;
	len = 0;
	if (str == NULL || (str[i] == '%' && str[i + 1] == '\0'))
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_printoptions(str[i], args);
		}
		else
		{
			ft_printchar(str[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
