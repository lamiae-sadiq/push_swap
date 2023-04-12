/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:27:18 by lsadiq            #+#    #+#             */
/*   Updated: 2023/04/11 21:16:14 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int ac, char **av)
{
	t_push	*stack_a;
	t_push	*stack_b;

	if (ac > 2)
	{
		if (check_int(av) == 0)
		{
			ft_putstr_fd("it s not an int\n", 2);
			exit(1);
		}
		stack_a = NULL;
		stack_b = NULL;
		fill_stack(ac, av, &stack_a);
		if (check_double(stack_a) == 0)
		{
			ft_putstr_fd("Input contains duplicate values\n", 2);
			exit(1);
		}
		if (check_sort(&stack_a) == 1)
		{
			ft_putstr_fd("is sorted !\n", 1);
			exit(1);
		}
		sorting(&stack_a, &stack_b, ac);
	}
}
