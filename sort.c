/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:08:34 by lsadiq            #+#    #+#             */
/*   Updated: 2023/04/11 16:24:33 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_push **stack)
{
	t_push	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	sorted_arr(int *a)
{
	int	i;

	i = 1;
	while (i)
	{
		if (a[i] < a[i - 1])
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief 
 * 
 * @param stack1 
 * @param stack2 
 * @param ac 
 */

void	sorting(t_push **stack1, t_push **stack2, int ac)
{
	int	*arr;

	arr = malloc(sizeof(int) * (ac - 1));
	if (!arr)
	{
		ft_putendl_fd("allo Err", 2);
		exit(1);
	}
	if (ac == 3)
		move_sa(stack1, 1);
	if (ac > 3)
	{
		if (ac == 4)
			sort_three(stack1);
		else if (ac == 5)
			sort_four(stack1, stack2);
		else if (ac == 6)
			sort_five(stack1, stack2);
		else if (ac > 6 && ac <= 101)
			sort_big_numbers(stack1, stack2, arr, 12);
		else if (ac > 6 && ac <= 501)
			sort_big_numbers(stack1, stack2, arr, 20);
	}
	free(arr);
}
