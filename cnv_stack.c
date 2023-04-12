/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnv_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 22:18:14 by lsadiq            #+#    #+#             */
/*   Updated: 2023/04/11 22:23:20 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void stack_to_arr(t_push **stack, int *array)
// {
//     t_push *head;
//     int i;
//     int j;

//     j = 0;
//     head = *stack;
//     i = ft_lstsizee(stack);
//     while (head)
//     {
//         array[j] = head->num;
//         j++;
//         head = head->next;
//     }
//     sort_arr(array, i);
// }

// void sort_arr(int *arr, int size)
// {
//     int i;
//     int tmp;

//     i = 1;
//     while (i < size)
//     {
//         if (arr[i] < arr[i - 1])
//         {
//             tmp = arr[i];
//             arr[i] = arr[i - 1];
//             arr[i - 1] = tmp;
//             i = 1;
//         }
//         else
//             i++;
//     }
// }

// void ft_assignn_index(t_push **lst, int *arr)
// {
//     t_push *temp;
//     int index;

//     temp = *lst;
//     index = 0;
//     while (temp)
//     {
//         while (index < ft_lstsizee(lst))
//         {
//             if (temp->num == arr[index])
//                 temp->index = index;
//             index++;
//         }
//         temp = temp->next;
//         index = 0;
//     }
// }