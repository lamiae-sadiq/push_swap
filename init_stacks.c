#include "push_swap.h"

t_push *new_node()
{
    t_push *stack;

    if (!(stack = (t_push*)malloc(sizeof(t_push))))
        return (NULL);
    stack->num = 0;
    stack->next = NULL;
    return (stack);
}

t_push *fill_stack(int ac, char **av)
{
    t_push *stack;
    t_push *tmp;
    int i;

    stack = new_node();
    i = ac - 1;
    tmp = stack;
    while (i >= 0)
    {
        tmp->num = ft_atoi(av[i]);
        if (i != 0)
            tmp->next = new_node();
        tmp = tmp->next;
        i--;
    }
    return (stack);
}

int main(int ac, char **av)
{
    t_push *stack_a;
    t_push *stack_b;

    stack_a = fill_stack(ac, av);

    stack_b = new_node();
    printf("a\t\tb\n");
    while (stack_a || stack_b)
    {
        if(stack_a)
        {
            printf("%d", stack_a->num);
            stack_a = stack_a->next;
            printf("\t\n");
        }
        if (stack_b)
        {
            printf("%d", stack_b->num);
            stack_b = stack_b->next;
        }
    }
    printf("----------      ----------\n");
    return (0);
}
