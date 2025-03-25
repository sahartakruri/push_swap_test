/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satakrur <satakrur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:04:17 by satakrur          #+#    #+#             */
/*   Updated: 2025/03/25 13:57:06 by satakrur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "printf.h"
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>

int ft_cton(char *stak)
{
    int i;
    long int number;
    int sign;
    
    sign = 1;
    number = 0;
    i = 0;
    if (stak[0] == '-')
    {
        sign = sign * -1;
        i++;
    }
    if (stak[0] == '+')
        i++;
    while (stak[i] >= '0' && stak[i] <= '9')
    {
        number = (number * 10) + (stak[i] - '0');
        if (number >= 9223372036854775807 && sign == -1)
            return (0);
        if (number >= 9223372036854775807)
            return (-1);
        i++;
    }
        return (number * sign);
    
}
int    ft_double_check(int *stak_a, int size_a)
{
    int i;
    int k;
    
    i = 0;
    while (i < size_a)
    {
        k = i + 1;
        while(k < size_a)
        {
            if (stak_a[i] == stak_a[k])
                return (1);
            k++;
        }
        i++;
    }
    return (0);
}

void    ft_arrange(int *stak_a, int *size_a, int *stak_b, int *size_b, int r)
{
     int    i;
     int    k;
     
     k = 0;
        while (k < 10)
        {
            i = 0;
            while (i < *size_a)
            {
                // if (((stak_a[0] * -1)/ r)% 10 == (-k / r) % 10)
                //     printf("it entered the loop %d\n", k);
                if ((stak_a[0] / r) % 10 == k || stak_a[0]< 0)
                    {
                        ft_push_a_to_b(stak_a, size_a, stak_b, size_b);
                        i--;
                    }
                else
                    ft_rotate_a(stak_a, *size_a);
                i++;      
            }
            k++;
        }
        // printf("size_b = %d\n size_a= %d\n", size_b, size_a);//
        i = 0;
        while (i++ < *size_b + *size_a)
            ft_push_b_to_a(stak_a, size_a, stak_b, size_b);
}
void    ft_arrange_n(int *stak_a, int *size_a, int *stak_b, int *size_b, int r)
{
     int    i;
     int    k;
     
     k = 0;
        while (k < 10)
        {
            // printf("size_a = %d\n",*size_a);
            i = 0;
            while (i < *size_a)
            {
                if (stak_a[0] < 0)
                {
                    printf("it entered the outerloop ******%d\n", k);
                    if (((stak_a[0] * -1)/ r)% 10 == (-k / r) % 10)
                    {
                        printf("it entered the loop %d\n", k);
                        ft_push_a_to_b(stak_a, size_a, stak_b, size_b);
                        i--;
                    }
                    else
                    ft_rotate_a(stak_a, *size_a);
                }
                else
                {
                    ft_push_a_to_b(stak_a, size_a, stak_b, size_b);
                    i--;
                }
                i++;      
            }
            k++;
        }
        // printf("size_b = %d\n size_a= %d\n", size_b, size_a);//
        printf("stak_b[0] %d\n size_b= %d\n", stak_b[0], *size_b);//
        i = 0;
        while (i < *size_b)
        {
            ft_push_b_to_a(stak_a, size_a, stak_b, size_b);
        }
}

int ft_neg_no(int *stak_a, int  size_a)
{
    int i;
    int no;
    
    i = 0;
    no = 0;
    while (i < size_a)
    {
        if (stak_a[i] < 0)
            no++;
        i++;
    }
    return (no);
}
void    ft_flip_neg(int *stak_a, int *size_a, int *stak_b, int *size_b, int neg)
{
    int i;

    i = 0;
    while (i <neg)
    {
        ft_reverse_rotate_a(stak_a, *size_a);
        ft_push_a_to_b(stak_a, size_a, stak_b, size_b);
        i++;;
    }
    while (i)
    {
        ft_push_b_to_a(stak_a, size_a, stak_b, size_b);
        i--;
    }
     printf("size_b = %d\n size_a= %d\n number of negative = %d\n stak_b[0]%d\n", *size_b, *size_a, neg, stak_b[0]);//
}

void    ft_stak_to_stak(int *stak_a, int *size_a, int *stak_b, int *size_b, int n)
{
    int m;
    int r;
    int neg;
    
    neg = ft_neg_no(stak_a, *size_a);
    m = n;
    r = 1;
    while (n)
    {
        ft_arrange(stak_a, size_a, stak_b, size_b, r);
        r *= 10;
        n--;
    }
    r = 1;
    while (m)
    {
        ft_arrange_n(stak_a, size_a, stak_b, size_b, r);
        r *= 10;
        m--;
    }
    if (neg > 0)
        ft_flip_neg(stak_a, size_a, stak_b, size_b, neg);
    printf("size_b = %d\n size_a= %d\n number of negative = %d\n", *size_b, *size_a, neg);//
}

int ft_check_sorted(int *stak_a, int size_a)
{
    int i;

    i = 0;
    while (i < size_a - 1)
    {
        if (stak_a[i] > stak_a[i + 1])
            return (0);
        i++;
    }
    return (1);
}

void    ft_3_elements_sort(int *stak_a, int size_a)
{
    if (size_a == 2)
    {
        if (stak_a[1] < stak_a[0])
        ft_swap_a(stak_a, size_a); 
    }
    else
    {
        if (stak_a[1] < stak_a[0])
            ft_swap_a(stak_a, size_a);
        if (stak_a[2] < stak_a[0])
            ft_reverse_rotate_a(stak_a, size_a); 
        if (stak_a[2] < stak_a[1])
        {
            ft_reverse_rotate_a(stak_a, size_a);
            ft_swap_a(stak_a, size_a);
        }
    }
}
int ft_closest_node(int stak_a, int *stak_b, int *size_b)
{
    int deff;
    int position;
    int i;
    
    i = 0;
    position = -1;
    deff = 2147483647;  // Int max value for comparison
    while (i < *size_b)
    {
        if (stak_a > stak_b[i])
        {
            if ( stak_a - stak_b[i] < deff)
            {
                deff = stak_a - stak_b[i];
                position = i;
            }
        } 
        i++;
    }
    if (position == -1)
    {
        i = 0;
        //deff = stak_b[0];
        while (i < *size_b)
        {
            if (stak_b[i] > deff)
            {
                deff = stak_b[i];
                position = i;
            } 
            i++;
        }
    }
    return (position);
}
int ft_push_cost(int position_a, int size_a, int closest_node, int size_b)
{
     int    a_op;
     int    b_op;
     int    push_cost;
     
    //  while (position_a < *size_a)
    //     {
            if (position_a > size_a / 2)
                a_op = size_a - position_a;
            else
                a_op = position_a;      
            // closest_node =  ft_closest_node(stak_a[0], stak_b, size_b);   // position in b
             if (closest_node > size_b / 2)
                b_op = size_b - closest_node;
            else
                b_op = closest_node;  
            push_cost = a_op + b_op;       
        //     position_a++;
        // }
        return (push_cost);
}
void    ft_bring_to_top(int *stak_a, int *size_a, int *stak_b, int *size_b, int position_a, int closest_node)
{
    int a_op;
    int b_op;
    int i;

    i = 0;
    printf("position_a = %d\n closeset_node = %d\n", position_a, closest_node);
    if (position_a > *size_a / 2 && closest_node > *size_b / 2)
    {
        a_op = *size_a - position_a;
         b_op = *size_b - closest_node;
        if (a_op == b_op)
        {
            while (i++ < a_op)
                ft_reverse_rotate_a_and_b(stak_a, *size_a, stak_b, *size_b);
        }
        else
        {
            while (i < a_op)
            {
                ft_reverse_rotate_a(stak_a, *size_a);
                i++;
            }
            while (i < b_op)
            {
                ft_reverse_rotate_b(stak_b, *size_b);
                i++;
            }
        }
    }
    else if (position_a < *size_a / 2 && closest_node < *size_b / 2 )
    {
        a_op = position_a;
        b_op = closest_node;  
        if (a_op == b_op)
        {
            while (i++ < a_op)
                ft_rotate_a_and_b(stak_a, *size_a, stak_b, *size_b);
        }
        else
            while (i < a_op)
            {
                ft_rotate_a(stak_a, *size_a);
                i++;
            } 
            while (i < b_op)
            {
                ft_rotate_b(stak_b, *size_b);
                i++;
            }
    }
    else
    {
        if (position_a > *size_a / 2)
        {
            a_op = *size_a - position_a;
            while (i < a_op)
            {
                ft_reverse_rotate_a(stak_a, *size_a);
                i++;
            }
        }
       else
       {
            a_op = position_a;
            while (i < a_op)
            {
                ft_rotate_a(stak_a, *size_a);
                i++;
            }
        }
        i = 0;
        if (closest_node > *size_b / 2)
        {
            b_op = *size_b - closest_node;
            while (i < b_op)
            {
                ft_reverse_rotate_b(stak_b, *size_b);
                i++;
            }
        }
        else
        {
            b_op = closest_node;  
            while (i < b_op)
            {
                ft_rotate_b(stak_b, *size_b);
                i++;
            }
        }
        write(1, "stak a\n", 7);
        ft_print(stak_a, *size_a); // needs to be modified
        write(1, "stak b\n", 7);
        ft_print(stak_b, *size_b);
    // printf("a_op = %d \n b_op = %d \n push_cost = %d \n", a_op, b_op, push_cost);
    // position_a++;
    }
}
int ft_closest_node_a(int *stak_a, int stak_b, int *size_a)
{
    int deff;
    int position;
    int i;
    
    i = 0;
    position = -1;
    deff = 2147483647;  // Int max value for comparison
    while (i < *size_a)
    {
        if (stak_b < stak_a[i])
        {
            if (stak_a[i] - stak_b < deff)
            {
                deff = stak_a[i] - stak_b;
                position = i;
            }
        } 
        i++;
    }
    if (position == -1)
    {
        i = 0;
        deff = stak_a[0];// maximum number
        while (i < *size_a)
        {
            if (stak_a[i] > deff)
            {
                deff = stak_a[i];
                position = i;
            } 
            i++;
        }
    }
    return (position);
}
int ft_push_cost_a(int position_b, int size_b, int closest_node_a, int size_a)
{
     int    a_op;
     int    b_op;
     int    push_cost;
     
    //  while (position_a < *size_a)
    //     {
            if (position_b > size_b / 2)
                b_op = size_b - position_b;
            else
                b_op = position_b;      
            // closest_node =  ft_closest_node(stak_a[0], stak_b, size_b);   // position in b
            if (closest_node_a > size_a / 2)
                a_op = size_a - closest_node_a;
            else
                a_op = closest_node_a;  
            push_cost = a_op + b_op;       
        //     position_a++;
        // }
        return (push_cost);
}
void    ft_sort_a(int *stak_a, int *size_a, int *stak_b, int *size_b)
{

    int closest_node_a;
    int push_cost;
    int position_b;
    int temp;
    int i;
    int j;
     
    position_b = 0;
    temp = *size_a + *size_b;
    while (*size_b > 0)
    {
    //  printf("closest node_a = %d \n",ft_closest_node_a(stak_a[0], stak_b, size_b));
       while (position_b < *size_b)
        {
            closest_node_a =  ft_closest_node_a(stak_a, stak_b[position_b], size_b);
            // printf("closest node = %d \n",closest_node);
            // printf("position_a= %d\n", position_a);
            push_cost = ft_push_cost_a(position_b, *size_b, closest_node_a, *size_a);
            // printf("push_cost = %d \n", push_cost);
            if (push_cost < temp)
            {
                temp = push_cost;
                i = position_b; 
                j = closest_node_a; 
                printf("temp = %d \nj = %d\n i = %d\n", temp, j,i);                  
            }
            position_b++;
        }
        ft_bring_to_top(stak_a, size_a, stak_b, size_b, j, i);  // if (position_a > *size_a / 2)
          
        
       ft_push_b_to_a(stak_a, size_a, stak_b, size_b);
    }      
}

void    ft_sort(int *stak_a, int *size_a, int *stak_b, int *size_b)
{

    int closest_node;
    // int a_op;
    // int b_op;
    int push_cost;
    int position_a;
    int temp;
    int i;
    int j;
     
    // while (!ft_check_sorted(stak_a, *size_a))
    // {
    ft_push_a_to_b(stak_a, size_a, stak_b, size_b);
    ft_push_a_to_b(stak_a, size_a, stak_b, size_b);
    if (stak_b[0] > stak_b[1])
        ft_swap_b(stak_b, *size_b);
    printf("is the b sorted? %d\n", ft_check_sorted(stak_b, *size_b));
    position_a = 0;
    temp = *size_a + *size_b;
    while (*size_a > 3)
    {
    //  printf("closest node = %d \n",ft_closest_node(stak_a[0], stak_b, size_b));
       while (position_a++ < *size_a)
        {
            closest_node =  ft_closest_node(stak_a[position_a], stak_b, size_b);
            // printf("closest node = %d \n",closest_node);
            // printf("position_a= %d\n", position_a);
            push_cost = ft_push_cost(position_a, *size_a, closest_node, *size_b);
            // printf("push_cost = %d \n", push_cost);
            if (push_cost < temp)
            {
                temp = push_cost;
                i = position_a; 
                j = closest_node; 
                printf("temp = %d \nj = %d\n i = %d\n", temp, j,i); 
                // printf("temp = %d \nj = %d\n", temp, j);                  
            }
            printf("position_a = %d \n", position_a);
        }
        ft_bring_to_top(stak_a, size_a, stak_b, size_b, i, j);  // if (position_a > *size_a / 2)
            //     a_op = *size_a - position_a;
            // else
            //     a_op = position_a;      
            // closest_node =  ft_closest_node(stak_a[0], stak_b, size_b);   // position in b
            //  if (closest_node > *size_b / 2)
            //     b_op = *size_b - closest_node;
            // else
            //     b_op = closest_node;  
            // push_cost = a_op + b_op;
            // printf("a_op = %d \n b_op = %d \n push_cost = %d \n", a_op, b_op, push_cost);
            // position_a++;
        
        // printf("number position in a = %d", i);
        
       ft_push_a_to_b(stak_a, size_a, stak_b, size_b);
    }      
    ft_3_elements_sort(stak_a, *size_a); 
    printf("is the a sorted? %d\n", ft_check_sorted(stak_a, *size_a));
   ft_sort_a(stak_a, size_a, stak_b, size_b);
   printf("is the a sorted? %d\n", ft_check_sorted(stak_a, *size_a));
}
// }


int main(int arc, char **argv)
{
    int     stak_a[100];
    int     stak_b[100];
    int     size_a = 0;
    int     size_b = 0;
    char    **arr;
    int     n;
    int     i = 1;
    int     j = 0;
    int     k;
    n = ft_longest_digit(argv, size_a);
    printf("n= %d\n", n);
    if (arc == 1 || (arc == 2 && !argv[1][0]))
        return (1); 
    if (arc >= 2)
    {
        while (argv[i] != NULL)
        {
            k = 0;
            arr = ft_split(argv[i], ' ');
            while (arr[k])
            {
                stak_a[j] = ft_cton(arr[k]);
                if (stak_a[j] <= -2147483648 || stak_a[j] >= 2147483647)
                {
                    write (1, "error out of integer limit\n", 27);
                    return (0);
                }
                j++;
                k++;
            }
            i++;
        }
        size_a = j;
    }
    if (ft_double_check(stak_a, size_a) == 1)
    {
        write (1, "error doubles found\n", 20);
        return (0);
    }
    if ( size_a == 2 || size_a == 3)
    {
        if (ft_check_sorted(stak_a, size_a) == 0)
            ft_3_elements_sort(stak_a, size_a);
       // write (1, "3 or less\n", 10);
    }
    else if (ft_check_sorted(stak_a, size_a) == 0)
    {
    //    i = 10;
    //     while (!ft_check_sorted(stak_a, size_a))
    //     {
        ft_sort(stak_a, &size_a, stak_b, &size_b);
   //     ft_stak_to_stak(stak_a, &size_a, stak_b, &size_b, n);
        // i--;
        // }
    }
    write(1, "stak a final\n", 13);
    ft_print(stak_a, size_a); // needs to be modified
    write(1, "stak b final\n", 13);
    ft_print(stak_b, size_b);
    // free (stak_a);
    // free (stak_b);
    return (0);
}
