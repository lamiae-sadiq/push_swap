/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:19:52 by lsadiq            #+#    #+#             */
/*   Updated: 2023/04/11 22:16:47 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "get_next_line.h"

void	fill_stack(int ac, char **av, t_push **stack)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		ft_stackadd_back(stack, ft_stacknew(ft_atoi(av[i])));
		i++;
	}
}

void	instractions(char *arr, t_push **stack1, t_push **stack2)
{
	if (!ft_strncmp(arr, "sa\n", 3))
		move_sa(stack1, 0);
	else if (!ft_strncmp(arr, "sb\n", 3))
		move_sb(stack2, 0);
	else if (!ft_strncmp(arr, "ss\n", 3))
		move_ss(stack1, stack2, 0);
	else if (!ft_strncmp(arr, "ra\n", 3))
		move_ra(stack1, 0);
	else if (!ft_strncmp(arr, "rb\n", 3))
		move_rb(stack2, 0);
	else if (!ft_strncmp(arr, "rr\n", 3))
		move_rr(stack1, stack2, 0);
	else if (!ft_strncmp(arr, "rra\n", 4))
		move_rra(stack1, 0);
	else if (!ft_strncmp(arr, "rrb\n", 4))
		move_rrb(stack2, 0);
	else if (!ft_strncmp(arr, "rrr\n", 4))
		move_rrr(stack1, stack2, 0);
	else if (!ft_strncmp(arr, "pa\n", 3))
		move_pa(stack2, stack1, 0);
	else if (!ft_strncmp(arr, "pb\n", 3))
		move_pb(stack1, stack2, 0);
	else
		exit(write(2, "wrong input\n", 13));
}

void	checker(t_push **stack1, t_push **stack2)
{
	char	*arr;

	while (1)
	{
		arr = get_next_line(0);
		if (!arr || arr[0] == '\n')
		{
			free(arr);
			break ;
		}
		instractions(arr, stack1, stack2);
		free(arr);
	}
	if (check_sort(stack1) == 1)
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_push	*stack_a;
	t_push	*stack_b;

	if (ac > 2)
	{
		if (check_int(av) == 0)
		{
			ft_putendl_fd("not int", 2);
			exit(1);
		}
		stack_a = NULL;
		stack_b = NULL;
		fill_stack(ac, av, &stack_a);
		if (check_double(stack_a) == 0)
		{
			ft_putendl_fd("Input contains dyplicate values", 2);
			exit(1);
		}
		if (check_sort(&stack_a) == 1)
		{
			ft_putendl_fd("is sorted", 1);
			exit(1);
		}
		checker(&stack_a, &stack_b);
	}
}
