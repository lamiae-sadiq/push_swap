/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 01:10:28 by lsadiq            #+#    #+#             */
/*   Updated: 2023/04/09 23:13:44 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    stack_to_arr(t_push **stack, int *array)
{
    int i;
    int j;
    (void)stack;
    (void)array;
    // int k = 0;
    //int tmp;
    
    j = 0;
    t_push *head = *stack;
    
    i = ft_lstsizee(stack);
    //printf("%d << \n", i);
    // array = malloc(sizeof(int) * (i));
    // convert stack to array
    while (head)
    {
        array[j] = head->num;
        j++;
        head = head->next;
    }
    // now we sort the array
    sort_arr(array, i);
}

void    sort_arr(int *arr, int size)
{
    int i;
    int tmp;

    i = 1;
    while (i < size)
    {
        if(arr[i] < arr[i - 1])
        {
            tmp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = tmp;
            i = 1;
        }
        else
            i++;
    }
    // i = 0;
    // while(i < size)
    // {
    //     printf("index >> %d value : [%d]\n", i, arr[i]);
    //     i++;
    // }
    // exit(0);
}
void	ft_assignn_index(t_push **lst, int *arr)
{
    (void)arr;
	t_push *temp = *lst;
	int index = 0;
	while(temp)
	{
        while(index < ft_lstsizee(lst))
        {
            if (temp->num == arr[index])
                temp->index = index;
            index++;   
        }
		temp = temp->next;
        index = 0;
	}
}

void    sort_big_numbers(t_push **stack1, t_push **stack2, int *array)
{
    int size = ft_lstsizee(stack1);
	stack_to_arr(stack1, array);
	ft_assignn_index(stack1, array);
    move_to_stack_b(stack1, stack2, size, 15);
}

void    move_to_stack_b(t_push **stack1, t_push **stack2, int size, int chunk)
{
    int curr = 0;
    
    size = ft_lstsizee(stack1);
    while(*stack1)
    {
        // printf("num = %d <> index = %d\n", (*stack1)->num, (*stack1)->index);
        if ((*stack1)->index <= curr && curr > 1)
        {
			// printf("[%d]\n", (*stack1)->index);
            move_pb(stack1, stack2);
			move_rb(stack2);
			//printf("weirdo\n");
            curr++;
        }
        else if ((*stack1)->index <= (curr + chunk))
        {
            // printf("%d--->\n", (curr + chunk));
			// printf("[[%d]]\n", (*stack1)->index);
			move_pb(stack1, stack2);
			curr++;
        }
        else if ((*stack1)->index >= curr)
			{
				// printf("[[[%d]]]\n", (*stack1)->index);
				move_ra(stack1);
			}
	// printf("%d>>>\n", (*stack1)->index);
    }
	back_to_a(stack1, stack2, size);
    
}

int     find_position(t_push **stack, int i)
{
	t_push	*new;
	int j;

	j = 0;
	new = *stack;
	while (new)
	{
		if (new->index == i)
			break;
		new = new->next;
		j++;
	}
    return (j);
}
void    back_to_a(t_push **stack1, t_push **stack2, int size)
{
    int max_idx = size - 1;
    int position;
    int midlle;
    while(*stack2)
    {
		midlle = (max_idx + 1) / 2;
        position = find_position(stack2, max_idx);
		// printf("%d>>>\n", midlle);
		if ((*stack2)->index == max_idx)
		{
			move_pa(stack2, stack1);
			max_idx--;
		}
		else if (position <= midlle)
			move_rb(stack2);
		else if (position > midlle)
			move_rrb(stack2);
    } 
}