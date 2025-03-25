 
    i = 0;
    k = 0;
while ( n)
{
    k = 0;
    while (k < 10)
    {
        i = 0;
        while (i < size_a)
        {
            if ((stak_a[0]/(10 * n)) % 10 == k)
                {
                    ft_push_a_to_b(stak_a, &size_a, stak_b, &size_b);
                    i--;
                }
            else
                ft_rotate_a(stak_a, size_a);
            i++;
                      
        }
        k++;
    }
       i = 0;
    while (i < size_b + size_a)
    {
        ft_push_b_to_a(stak_a, &size_a, stak_b, &size_b);
        i++;
    }
    n++;
}


#include "push_swap.h"
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>

// int ft_len(char *str)
// {
//     int i;
    
//     i = 0;
//       while (str[i] != '\0')
//         i++;
//     return (i);
// }

// void ft_swap_a(int *stak, int n)
// {
//     int temp;

//     if (n > 1)
//     {
//         temp = stak[0];
//         stak[0] = stak[1];
//         stak[1] = temp;
//         write (1, "sa\n", 3);
//     }
// }
// void ft_swap_b(int *stak_b, int size_b)
// {
//     int temp;

//     if (size_b > 1)
//     {
//         temp = stak_b[0];
//         stak_b[0] = stak_b[1];
//         stak_b[1] = temp;
//         write (1, "sb\n", 3);
//     }
// }

// void ft_push_a_to_b(int *stak_a, int *size_a, int *stak_b,int *size_b)
// {
//     int *temp;
//     int i;
//     int j;

//     i = 0;
//     j = 0;
//     temp = (int*)malloc(sizeof(int) * (*size_b + 1));
//     if (temp == NULL)
//         return ;
//     temp[0] = stak_a[0];
//     while (j < *size_b + 1)
//     {
//         temp[j + 1] = stak_b[j];
//         j++;
//     }
//     while(i < *size_b + 1)
//     {
//         stak_b[i] = temp[i];
//         i++;
//     }
//     free (temp);
//     j = 0;
//     while (j < *size_a - 1)
//     {
//         stak_a[j] = stak_a[j + 1];
//         j++;
//     }
//     write (1, "pb\n", 3);
//     *size_a -= 1;
//     *size_b += 1;
// }

// void ft_push_b_to_a(int *stak_a, int *size_a, int *stak_b,int *size_b)
// {
//     int *temp;
//     int i;
//     int j;

//     i = 0;
//     j = 0;
//     temp = (int*)malloc(sizeof(int) * (*size_a + 1));
//     if (temp == NULL)
//         return ;
//     temp[0] = stak_b[0];
//     while (j < *size_a + 1)
//     {
//         temp[j + 1] = stak_a[j];
//         j++;
//     }
//     while(i < *size_a + 1)
//     {
//         stak_a[i] = temp[i];
//         i++;
//     }
//     free (temp);
//     j = 0;
//     while (j < *size_b - 1)
//     {
//         stak_b[j] = stak_b[j + 1];
//         j++;
//     }
//     write (1, "pa\n", 3);
//     *size_b -= 1;
//     *size_a += 1;
// }

// void    ft_rotate_a(int *stak_a, int size)
// {
//     int temp;
//     int j;

//     j = 0;
//     temp = stak_a[0];
//     while (j < size - 1)
//     {
//         stak_a[j] = stak_a[j + 1];
//         j++;
//     }
//     stak_a[size - 1] = temp;
//     write (1, "ra\n", 3); 
// }
// void    ft_reverse_rotate_a(int *stak_a, int size)
// {
//     int temp;
//     int i;

//     i = size - 1;
//     temp = stak_a[i];
//     while (i > 0)
//     {
//         stak_a[i] = stak_a[i - 1];
//         i--;
//     }
//     stak_a[i] = temp;
//     write(1, "rra\n", 4);
// }

int ft_cton(char *stak)
{
    int i;
    int number;
    int sign;
    
    sign = 1;
    number = 0;
    i = 0;
    if (stak[0] == '-')
    {
        sign = sign * -1;
        i++;
    }
    while (stak[i] != '\0')
    {
        number = (number * 10) + (stak[i] - '0');
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

void    ft_stak_to_stak(int *stak_a, int size_a, int *stak_b, int size_b, int n)
{
    int i;
    int k;
    int r;
    
    i = 0;
    k = 0;
    r = 1;
    while (n)
    {
        k = 0;
        while (k < 10)
        {
            i = 0;
            while (i < size_a)
            {
                if ((stak_a[0]/ (r)) % 10 == k)
                    {
                        ft_push_a_to_b(stak_a, &size_a, stak_b, &size_b);
                        i--;
                    }
                else
                    ft_rotate_a(stak_a, size_a);
                i++;      
            }
            k++;
        }
        r *= 10;
        n--;
        printf("r = %d\n", r);
         printf("n = %d\n", n);
        i = 0;
        while (i < size_b + size_a)
        {
            ft_push_b_to_a(stak_a, &size_a, stak_b, &size_b);
            i++;
        }
    }
}

int main(int arc, char **argv)
{
    int stak_a[arc - 1];
    int stak_b[arc - 1];
    int size_a = arc -1;
    int size_b = 0;
    int n;
    int i = 1;
  //  int r;
    // int k;
    n = ft_longest_digit(argv, size_a);
    printf("n= %d\n", n);
    while (i < arc)
    {
        stak_a[i - 1] = ft_cton(argv[i]);
        i++;
    }
    if (ft_double_check(stak_a, size_a) == 1)
    {
        write (1, "error doubles found", 19);
        return (0);
    }
    i = 0;
    // k = 0;
    // while (k < 10)
    // {
    //     i = 0;
    //     while (i < size_a)
    //     {
    //         if (stak_a[0] % 10 == k)
    //             {
    //                 ft_push_a_to_b(stak_a, &size_a, stak_b, &size_b);
    //                 i--;
    //             }
    //         else
    //             ft_rotate_a(stak_a, size_a);
    //         i++;
                      
    //     }
    //     k++;
    // }
    // i = 0;
    // while (i < size_b + size_a)
    // {
    //     ft_push_b_to_a(stak_a, &size_a, stak_b, &size_b);
    //     i++;
    // }
   ft_stak_to_stak(stak_a, size_a, stak_b, size_b, n);
    // r = 1;
    // while (n)
    // {
    //     k = 0;
    //     while (k < 10)
    //     {
    //         i = 0;
    //         while (i < size_a)
    //         {
    //             if ((stak_a[0] / r) % 10 == k)
    //                 {
    //                     ft_push_a_to_b(stak_a, &size_a, stak_b, &size_b);
    //                     i--;
    //                 }
    //             else
    //                 ft_rotate_a(stak_a, size_a);
    //             i++;             
    //         }
    //         k++;
    //     }
    //     r *= 10;
    //     n--;
    //     i = 0;
    //     while (i < size_b + size_a)
    //     {
    //         ft_push_b_to_a(stak_a, &size_a, stak_b, &size_b);
    //         i++;
    //     }
    // }
    printf("size_a = %d\n size_b = %d\n", size_a, size_b);
    i = 0;
    // while (i < size_b + size_a)
    // {
    //     ft_push_b_to_a(stak_a, &size_a, stak_b, &size_b);
    //     i++;
    // }
    //    printf("b length = %d\n", size_b);
       printf("a length = %d\n", size_a);
    write(1, "stak a\n", 7);
    ft_print(stak_a, size_a);
    write(1, "stak b\n", 7);
   ft_print(stak_b, size_b);
    return (0);
}




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
            // closest_node =  ft_closest_node(stak_a, stak_b[i], size_a);   // position in a
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
    while (*size_a > 0)
    {
    //  printf("closest node_a = %d \n",ft_closest_node_a(stak_a[0], stak_b, size_b));
       while (position_b < *size_b)
        {
            closest_node_a =  ft_closest_node_a(stak_a, stak_b[position_b], size_b);
            // printf("closest node = %d \n",closest_node);
            // printf("position_a= %d\n", position_a);
            push_cost = ft_push_cost(position_a, *size_a, closest_node_a, *size_a);
            // printf("push_cost = %d \n", push_cost);
            if (push_cost < temp)
            {
                temp = push_cost;
                i = position_b; 
                j = closest_node_a; 
                // printf("temp = %d \nj = %d\n", temp, j);                  
            }
            position_b++;
        }
        ft_bring_to_top(stak_a, size_a, stak_b, size_b, j, i);  // if (position_a > *size_a / 2)
          
        
       ft_push_b_to_a(stak_a, size_a, stak_b, size_b);
    }      
}



void    ft_bring_to_top(int *stak_a, int *size_a, int *stak_b, int *size_b, int position_a, int closest_node)
{
    int a_op;
    int b_op;
    int i;

    i = 0;
    // printf("position_a = %d\n closeset_node = %d\n", position_a, closest_node);
    if (position_a > *size_a / 2 && closest_node > *size_b / 2)
    {
        a_op = *size_a - position_a;
         b_op = *size_b - closest_node;
        if (a_op == b_op)
        {
            while (i++ < a_op)
                ft_reverse_rotate_a_and_b(stak_a, *size_a, stak_b, *size_b);
        }
        // else
        // {
        //     while (i < a_op)
        //     {
        //         ft_reverse_rotate_a(stak_a, *size_a);
        //         i++;
        //     }
        //     while (i < b_op)
        //     {
        //         ft_reverse_rotate_b(stak_b, *size_b);
        //         i++;
        //     }
        // }
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
        // else
        //     while (i < a_op)
        //     {
        //         ft_rotate_a(stak_a, *size_a);
        //         i++;
        //     } 
        //     while (i < b_op)
        //     {
        //         ft_rotate_b(stak_b, *size_b);
        //         i++;
        //     }
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
    // printf("a_op = %d \n b_op = %d \n push_cost = %d \n", a_op, b_op, push_cost);
    // position_a++;
    }
}