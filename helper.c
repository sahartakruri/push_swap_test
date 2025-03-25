/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satakrur <satakrur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:25:35 by satakrur          #+#    #+#             */
/*   Updated: 2025/03/19 13:05:45 by satakrur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> 

int ft_len(char *str)
{
    int i;
    
    i = 0;
      while (str[i] != '\0')
        i++;
    return (i);
}

int ft_longest_digit(char **numbers, int size)
{
   int  i;
   int  temp;
   
   i = 1;
   temp = ft_len(numbers[1]);
   while (i < size + 1)
   {
    if (ft_len(numbers[i]) > temp)
       {
            temp = ft_len(numbers[i]);
            if (numbers[i][0] == '-')
                temp -= 1;
       }
    i++;
   } 
   return (temp);
}

void    ft_print(int *stak, int size)
{
   int  i;
   
   i = 0;
   while (i < size)
    {
        ft_printf("%d\n", stak[i]);
        i++;
    } 
}

static int	ft_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	ft_wordlength(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	*ft_wordcopy(char const *s, char c)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	len = ft_wordlength(s, c);
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	ft_free(char **splitted, size_t n)
{
	while (n--)
	{
		free(splitted[n]);
	}
	free(splitted);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	array = (char **)malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			array[j++] = ft_wordcopy(&s[i], c);
			if (!array[j - 1])
				return (ft_free(array, j), NULL);
			i += ft_wordlength(&s[i], c);
		}
	}
	array[j] = 0;
	return (array);
}
