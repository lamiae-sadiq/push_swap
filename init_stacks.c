#include "push_swap.h"

// void	ft_assign_list_index(t_push **stack)
// {
	
// }


// void	ft_assign_index(t_push **lst)
// {
// 	t_push *temp = *lst;
// 	int index = 0;
// 	while(temp)
// 	{
// 		printf("{%d}\n", index);
// 		temp->index = index;
// 		temp = temp->next;
// 		index++;
// 	}
// }


void	fill_stack(int ac, char **av, t_push **stack)
{
	int		i;
	i = 1;

	while (i < ac)
	{
		ft_stackadd_back(stack, ft_stacknew(ft_atoi(av[i])));
		i++;
	}
	// ft_assign_index(stack);
}

int main(int ac, char **av)
{
	t_push	*stack_a;
	t_push	*stack_b;
	int cm;

	if(ac > 2)
	{
		cm = check_int(av);
		if(cm == 0 ){
			printf("%d\n", cm);
			printf("weirdo\n");
			exit(1);
		}
		stack_a = NULL;
		stack_b = NULL;
		fill_stack(ac, av, &stack_a);
		if(check_double(stack_a) == 0)
		{
			printf("Input contains duplicate values\n");
			exit(1);
		}
		if(check_sort(&stack_a) == 1)
		{
			printf("is sorted !\n");
			exit(1);
		}
		sorting(&stack_a, &stack_b, ac);
		// int *arr = 0;
		// arr = malloc(sizeof(int) * (ac - 1));
		// sort_big_numbers(&stack_a, &stack_b, arr);
		// stack_to_arr(&stack_a);
		// ft_assign_index(&stack_a);
		printf("a\tb\n");
		while (stack_a || stack_b)
		{
			if (stack_a)
			{
				printf("%d << value | index > %d\n", stack_a->num, stack_a->index);
				stack_a = stack_a->next;
				if (!stack_b)
					printf("\n");
			}
			if (stack_b)
			{
				printf ("\t");
			    printf("%d", stack_b->num);
			    stack_b = stack_b->next;
				printf("\t\n");
			}
		}
		printf("--      --\n");
	}
}
