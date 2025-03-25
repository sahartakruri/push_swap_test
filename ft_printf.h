/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satakrur <satakrur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:21:13 by satakrur          #+#    #+#             */
/*   Updated: 2025/01/14 17:40:16 by satakrur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_printchar(const char c);
int		ft_printstr(const char *str);
int		ft_printptr(void *ptr);
int		ft_printint(int n);
int		ft_printunsnum(unsigned int ud);
int		ft_printhex(unsigned int hex);
int		ft_printhexc(unsigned int hex);
int		ft_printuint(unsigned int u);

#endif
