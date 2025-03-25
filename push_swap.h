/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satakrur <satakrur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:21:58 by satakrur          #+#    #+#             */
/*   Updated: 2025/03/25 11:30:14 by satakrur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
// # include <librarly libft.a"

int     ft_len(char *str);
int     ft_longest_digit(char **numbers, int size);
char    **split(char *string, char spacer);
void    ft_swap_a(int *stak, int n);
void    ft_swap_b(int *stak_b, int size_b);
void    ft_swap_a_and_b(int *stak_a, int size_a, int *stak_b, int size_b);
void    ft_push_a_to_b(int *stak_a, int *size_a, int *stak_b,int *size_b);
void    ft_push_b_to_a(int *stak_a, int *size_a, int *stak_b,int *size_b);
void    ft_rotate_a(int *stak_a, int size);
void    ft_rotate_b(int *stak_b, int size);
void    ft_rotate_a_and_b(int *stak_a, int size_a, int *stak_b, int size_b);
void    ft_reverse_rotate_a(int *stak_a, int size);
void    ft_reverse_rotate_b(int *stak_b, int size);
void    ft_reverse_rotate_a_and_b(int *stak_a, int size_a, int *stak_b, int size_b);
int     ft_cton(char *stak);
int     ft_double_check(int *stak_a, int size_a);
int     ft_check_sorted(int *stak_a, int size_a);
void    ft_stak_to_stak(int *stak_a, int *size_a, int *stak_b, int *size_b, int n);
void    ft_print(int *stak, int size);
int		ft_printf(const char *str, ...);
char	**ft_split(char const *s, char c);
int     ft_closest_node_a(int *stak_a, int stak_b, int *size_a);
void    ft_sort_a(int *stak_a, int *size_a, int *stak_b, int *size_b);

#endif