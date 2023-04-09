/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:08:34 by lsadiq            #+#    #+#             */
/*   Updated: 2023/04/09 22:01:42 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_push **stack)
{
	t_push *tmp;

	tmp = *stack;
	while(tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return(0);
		tmp = tmp->next;
	}
	return(1);
}

int	sorted_arr(int *a)
{
	int i;

	i = 1;
	while(i)
	{
		if(a[i] < a[i - 1])
			return(0);
		i++;
	}
	return(1);
}

void	sort_three(t_push **stack)
{
	t_push *new;

	new = *stack;
	int i = (*stack)->num;
	int j = (*stack)->next->num;
	int k = (*stack)->next->next->num;
	// 2  12  0  ==> 0 2 12
	if (i < j && j > k && i > k)
		move_rra(stack);
	// 12 2 0 ===> 2 12 0 ===> 0 2 12 
	if (i > k && i > j && j > k)
	{
		move_sa(stack, 1);
		move_rra(stack);
	}
	// 0 12 2 ==> 2 0 12 ===> 0 2 12
	if (i < j && i < k && j > k)
	{
		move_rra(stack);
		move_sa(stack, 1);
	}
	// 2 0 12 ==> 0 2 12
	if (i > j && j < k && k > i && k > j)
		move_sa(stack, 1);
	// 12 0 2 ==> 0 2 12
	if (i > j && i > k && j < k)
		move_ra(stack);
}

void	sort_four(t_push **stack1, t_push **stack2)
{
	t_push *new;
	int min;

	new = *stack1;
	min = find_smallest(stack1);
	while(new->next)
	{
		if (new->num == min)
		{
			move_pb(stack1, stack2);
			sort_three(stack1);
			move_pa(stack2, stack1);
			break;
		}
		else if (new->num != min)
			move_rra(stack1);
		new = *stack1;
	}
}

int		find_smallest(t_push **stack)
{
	t_push *head;
	int min;

	head = *stack;
	min = (*stack)->num;
	while(head)
	{
		if(head->num < min)
			min = head->num;
		head = head->next;			
	}
	return(min);
}

void	sort_five(t_push **stack1, t_push **stack2)
{
	t_push *new;
	int min;

	new = *stack1;
	min = find_smallest(stack1);
	while(new)
	{
		if (new->num == min)
		{
			move_pb(stack1, stack2);
			sort_four(stack1, stack2);
			move_pa(stack2, stack1);
			break;
		}
		else if (new->num != min)
			move_rra(stack1);
		new = *stack1;
	}
}

void	sorting(t_push **stack1, t_push **stack2, int ac)
{
	int *arr = malloc(sizeof(int) * (ac - 1));
	if (ac == 3)
		move_sa(stack1, 1);
	if (ac > 3)
	{
		if (ac == 4)
			sort_three(stack1);
		if (ac == 5)
			sort_four(stack1, stack2);
		if (ac == 6)
			sort_five(stack1, stack2);
		else if (ac > 6 && ac <= 101)
			sort_big_numbers(stack1, stack2, arr);
	}
}
//a      b
//1		 2
//23	 1
//2
//90
//100