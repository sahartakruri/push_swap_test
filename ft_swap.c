/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satakrur <satakrur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:36:42 by satakrur          #+#    #+#             */
/*   Updated: 2025/03/24 17:06:41 by satakrur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void ft_swap_a(int *stak, int n)
{
    int temp;

    if (n > 1)
    {
        temp = stak[0];
        stak[0] = stak[1];
        stak[1] = temp;
        write (1, "sa\n", 3);
    }
}
void ft_swap_b(int *stak_b, int size_b)
{
    int temp;

    if (size_b > 1)
    {
        temp = stak_b[0];
        stak_b[0] = stak_b[1];
        stak_b[1] = temp;
        write (1, "sb\n", 3);
    }
}
void ft_swap_a_and_b(int *stak_a, int size_a, int *stak_b, int size_b)
{
    int temp;

    if (size_a > 1)
    {
        temp = stak_a[0];
        stak_a[0] = stak_a[1];
        stak_a[1] = temp;
    }
    if (size_b > 1)
    {
        temp = stak_b[0];
        stak_b[0] = stak_b[1];
        stak_b[1] = temp;
    }
    write (1, "ss\n", 3);
}

void ft_push_a_to_b(int *stak_a, int *size_a, int *stak_b,int *size_b)
{
    int *temp;
    int i;
    int j;

    i = 0;
    j = 0;
    temp = (int*)malloc(sizeof(int) * (*size_b + 1));
    if (temp == NULL)
        return ;
    temp[0] = stak_a[0];
    while (j < *size_b)
    {
        temp[j + 1] = stak_b[j];
        j++;
    }
    while(i < *size_b + 1)
    {
        stak_b[i] = temp[i];
        i++;
    }
    free (temp);
    j = 0;
    while (j < *size_a - 1)
    {
        stak_a[j] = stak_a[j + 1];
        j++;
    }
    stak_a[j] = 0;
    write (1, "pb\n", 3);
    *size_a -= 1;
    *size_b += 1;
}

void ft_push_b_to_a(int *stak_a, int *size_a, int *stak_b,int *size_b)
{
    int *temp;
    int i;
    int j;

    i = 0;
    j = 0;
    temp = (int*)malloc(sizeof(int) * (*size_a + 1));
    if (temp == NULL)
        return ;
    temp[0] = stak_b[0];
    while (j < *size_a)
    {
        temp[j + 1] = stak_a[j];
        j++;
    }
    while(i < *size_a + 1)
    {
        stak_a[i] = temp[i];
        i++;
    }
    free (temp);
    j = 0;
    while (j < *size_b - 1)
    {
        stak_b[j] = stak_b[j + 1];
        j++;
    }
    stak_b[j] = 0;
    write (1, "pa\n", 3);
    *size_b -= 1;
    *size_a += 1;
}

void    ft_rotate_a(int *stak_a, int size)
{
    int temp;
    int j;

    j = 0;
    temp = stak_a[0];
    while (j < size - 1)
    {
        stak_a[j] = stak_a[j + 1];
        j++;
    }
    stak_a[size - 1] = temp;
    write (1, "ra\n", 3); 
}
void    ft_reverse_rotate_a(int *stak_a, int size)
{
    int temp;
    int i;

    i = size - 1;
    temp = stak_a[i];
    while (i > 0)
    {
        stak_a[i] = stak_a[i - 1];
        i--;
    }
    stak_a[i] = temp;
    write(1, "rra\n", 4);
}

void    ft_rotate_b(int *stak_b, int size)
{
    int temp;
    int j;

    j = 0;
    temp = stak_b[0];
    while (j < size - 1)
    {
        stak_b[j] = stak_b[j + 1];
        j++;
    }
    stak_b[size - 1] = temp;
    write (1, "rb\n", 3); 
}
void    ft_reverse_rotate_b(int *stak_b, int size)
{
    int temp;
    int i;

    i = size - 1;
    temp = stak_b[i];
    while (i > 0)
    {
        stak_b[i] = stak_b[i - 1];
        i--;
    }
    stak_b[i] = temp;
    write(1, "rrb\n", 4);
}

void    ft_rotate_a_and_b(int *stak_a, int size_a, int *stak_b, int size_b)
{
    int temp;
    int j;

    j = 0;
    temp = stak_a[0];
    while (j < size_a - 1)
    {
        stak_a[j] = stak_a[j + 1];
        j++;
    }
    stak_a[size_a - 1] = temp;
    j = 0;
    temp = stak_b[0];
    while (j < size_b - 1)
    {
        stak_b[j] = stak_b[j + 1];
        j++;
    }
    stak_b[size_b - 1] = temp;
    write (1, "rr\n", 3); 
}
void    ft_reverse_rotate_a_and_b(int *stak_a, int size_a, int *stak_b, int size_b)
{
    int temp;
    int i;

    i = size_a - 1;
    temp = stak_a[i];
    while (i > 0)
    {
        stak_a[i] = stak_a[i - 1];
        i--;
    }
    stak_a[i] = temp;
    i = size_b - 1;
    temp = stak_b[i];
    while (i > 0)
    {
        stak_b[i] = stak_b[i - 1];
        i--;
    }
    stak_b[i] = temp;
    write(1, "rrr\n", 4);
}
