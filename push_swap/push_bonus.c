
#include "checker_bonus.h"

void	ft_temp(t_stack *temp)
{
	temp->next = temp;
    temp->prev = temp;
}
void ft_push(t_stack **src, t_stack **dest)
{
    t_stack *temp;

    if (*src == NULL)
        return ;
    temp = *src;
    if ((*src)->next == *src)
        *src = NULL;
    else
    {
        *src = (*src)->next;
        (*src)->prev = temp->prev;
        temp->prev->next = *src;
    }
    if (*dest == NULL)
		ft_temp(temp);
    else
    {
        temp->next = *dest;
        temp->prev = (*dest)->prev;
        (*dest)->prev->next = temp;
        (*dest)->prev = temp;
    }
    *dest = temp;
}

void	ft_pa(t_stack **stack_b, t_stack **stack_a)
{
	ft_push(stack_b, stack_a);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
}