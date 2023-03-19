#include "push_swap.h"

t_push *new_node(int num)
{
    t_push *stack;

    if (!(stack = (t_push*)malloc(sizeof(t_push))))
        return (NULL);
    stack->num = num;
    stack->next = NULL;
    return (stack);
}

t_push *fill_stack(int ac, char **av)
{
    t_push *stack;
    t_push *tmp;
    int i;

    stack = NULL;
    i = 0;
    while (i < ac)
    {
        tmp = new_node(ft_atoi(av[i]));
        if (stack == NULL)
        {
            stack = tmp;
        }
        else
        {
            tmp->next = stack;
            stack = tmp;
        }
        i++;
    }
    if (stack == NULL)
    {
        return (NULL);
    }
    while (stack->next != NULL)
    {
        stack = stack->next;
    }
    stack->num = 0;
    return (stack);
}

int main(int ac, char **av)
{
    t_push *stack_a;
    t_push *stack_b;
    t_push *tmp;

    if (ac < 2)
        return (0);
    stack_a = fill_stack(ac, av);

    printf("a\t\tb\n");
    while (stack_a || stack_b)
    {
        if (stack_a)
        {
            printf("%d", stack_a->num);
            tmp = stack_a;
            stack_a = stack_a->next;
            free(tmp);
            printf("\t\n");
        }
        if (stack_b)
        {
            printf("%d", stack_b->num);
            tmp = stack_b;
            stack_b = stack_b->next;
            free(tmp);
        }
    }
    printf("----------\t----------\n");
    return (0);
}
