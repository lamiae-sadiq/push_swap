#include "push_swap.h"

void	fill_stack(int ac, char **av, t_push **stack)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		ft_stackadd_back(stack, ft_stacknew(ft_atoi(av[i])));
		i++;
	}
}

int main(int ac, char **av)
{
	t_push	*stack_a;
	t_push *stack_b;
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
		fill_stack(ac, av, &stack_a);
		printf("a\tb\n");
		while (stack_a || stack_b)
		{
			if(stack_a)
			{
				printf("%d", stack_a->num);
				stack_a = stack_a->next;
				printf("\n");
			}
			if (stack_b)
			{
			    printf("%d", stack_b->num);
			    stack_b = stack_b->next;
				printf("\t\n");
			}
		}
		printf("--      --\n");
		if(check_double(stack_a) == 0)
		{
			printf("mook\n");
			exit(1);
		}
	}
}
