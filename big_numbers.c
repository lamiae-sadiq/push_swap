/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 01:10:28 by lsadiq            #+#    #+#             */
/*   Updated: 2023/04/12 00:42:22 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_to_arr(t_push **stack, int *array)
{
	t_push	*head;
	int		i;
	int		j;

	j = 0;
	head = *stack;
	i = ft_lstsizee(stack);
	while (head)
	{
		array[j] = head->num;
		j++;
		head = head->next;
	}
	sort_arr(array, i);
}

void	sort_arr(int *arr, int size)
{
	int	i;
	int	tmp;

	i = 1;
	while (i < size)
	{
		if (arr[i] < arr[i - 1])
		{
			tmp = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = tmp;
			i = 1;
		}
		else
			i++;
	}
}

void	ft_assignn_index(t_push **lst, int *arr)
{
	t_push	*temp;
	int		index;

	temp = *lst;
	index = 0;
	while (temp)
	{
		while (index < ft_lstsizee(lst))
		{
			if (temp->num == arr[index])
				temp->index = index;
			index++;
		}
		temp = temp->next;
		index = 0;
	}
}

void	sort_big_numbers(t_push **stack1, t_push **stack2, int *array, int i)
{
	int	size;
	(void)stack2;
	(void)i;

	size = ft_lstsizee(stack1);
	stack_to_arr(stack1, array);
	ft_assignn_index(stack1, array);
	move_to_stack_b(stack1, stack2, size, i);
	back_to_a(stack1, stack2, size);
}

void	move_to_stack_b(t_push **stack1, t_push **stack2, int size, int chunk)
{
	int	curr;
	(void)stack2;
	(void)chunk;

	curr = 0;
	size = ft_lstsizee(stack1);
	while (*stack1)
	{
		if ((*stack1)->index <= curr && curr > 1)
		{
			move_pb(stack1, stack2, 1);
			move_rb(stack2, 1);
			curr++;
		}
		else if ((*stack1)->index <= (curr + chunk))
		{
			move_pb(stack1, stack2, 1);
			curr++;
		}
		else if ((*stack1)->index >= curr)
			move_ra(stack1, 1);
	}
}

int	find_position(t_push **stack, int i)
{
	t_push	*new;
	int		j;

	j = 0;
	new = *stack;
	while (new)
	{
		if (new->index == i)
			break ;
		new = new->next;
		j++;
	}
	return (j);
}

void	back_to_a(t_push **stack1, t_push **stack2, int size)
{
	int	max_idx;
	int	position;
	int	middle;

	max_idx = size - 1;
	while (*stack2)
	{
		middle = (max_idx + 1) / 2;
		position = find_position(stack2, max_idx);
		if ((*stack2)->index == max_idx)
		{
			move_pa(stack2, stack1, 1);
			max_idx--;
		}
		else if (position <= middle)
			move_rb(stack2, 1);
		else if (position > middle)
			move_rrb(stack2, 1);
	}
}
