#include "checker_bonus.h"
#include "stdio.h"

void print_stack(t_stack *stack)
{
    t_stack *start = stack;

    if (!stack)
    {
        printf("Stack is empty.\n");
        return;
    }
    do
    {
        printf(" %d", stack->nb);
        stack = stack->next;
    } while (stack != start);
}

void    ft_apply_rest(t_stack **stack_a, t_stack **stack_b, char *get_op)
{
    if (get_op[2] == 'a')
        ft_rra(stack_a);
    else if (get_op[2] == 'b')
        ft_rrb(stack_b);
    else if (get_op[2] == 'r')
        ft_rrr(stack_a, stack_b);
}
char    *ft_apply_oper(t_stack **stack_a, t_stack **stack_b, char *get_op)
{
    if (get_op[0] == 's' && get_op[1] == 'a' && get_op[2] == '\n')
        ft_sa(stack_a);
    else if (get_op[0] == 's' && get_op[1] == 'b' && get_op[2] == '\n')
        ft_sb(stack_b);
    else if (get_op[0] == 's' && get_op[1] == 's' && get_op[2] == '\n')
        ft_ss(stack_a, stack_b);
    else if (get_op[0] == 'r' && get_op[1] == 'a' && get_op[2] == '\n')
        ft_ra(stack_a);
    else if (get_op[0] == 'r' && get_op[1] == 'b' && get_op[2] == '\n')
        ft_rb(stack_b);
    else if (get_op[0] == 'r' && get_op[1] == 'r' && get_op[2] == '\n')
        ft_rr(stack_a, stack_b);
    else if (get_op[0] == 'p' && get_op[1] == 'a' && get_op[2] == '\n')
        ft_pa(stack_b, stack_a);
    else if (get_op[0] == 'p' && get_op[1] == 'b' && get_op[2] == '\n')
        ft_pb(stack_a, stack_b);
    else if (get_op[0] == 'r' && get_op[1] == 'r' && get_op[3] == '\n')
        ft_apply_rest(stack_a, stack_b, get_op);
    else
    {
        write(1, "wrong op", 9);
        exit(1);
    }
    return (get_next_line(0));
}
void ft_read_oper(t_stack **stack_a, t_stack **stack_b, char *get_op)
{
    char *temp;

    while (get_op && *get_op != '\n')
    {
        temp = get_op;
        get_op = ft_apply_oper(stack_a, stack_b, get_op);
        free(temp);
    }
    if (*stack_b)
        write (1, "KO\n", 3);
    else if (!sorted_stack(*stack_a))
         write (1, "KO\n", 3);
    else
         write (1, "OK\n", 3);
    free(get_op);
}
int	main(int arc, char **arv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char    *read_op;

	stack_a = NULL;
	stack_b = NULL;
	if (arc > 1)
	{
		valid_and_init(arc, arv, &stack_a);
        read_op = get_next_line(0);
        if (!read_op && sorted_stack(stack_a))
            write(1, "OK\n", 3);
        else if (!read_op && !(sorted_stack(stack_a)))
            write(1, "KO\n", 3);
        else
        {
            ft_read_oper(&stack_a, &stack_b, read_op);
            if (!stack_b)
                write(1, "B is empty\n", 11);
            else
                write(1, "B is not empty\n", 15);
        }
	}
	return (0);
}