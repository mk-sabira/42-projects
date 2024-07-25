// // // #include <stdio.h>
// // // #include <unistd.h>
// // // #include <stdlib.h>

// // // typedef struct s_stack {
// // //     int nb;
// // //     struct s_stack *next;
// // //     struct s_stack *prev;
// // // } t_stack;

// // // void ft_rotate(t_stack **stack)
// // // {
// // //     if (*stack == NULL || (*stack)->next == *stack) {
// // //         return; // No need to rotate if list is empty or has one element
// // //     }

// // //     t_stack *first = *stack;
// // //     t_stack *second = (*stack)->next;
// // //     t_stack *last = first->prev; // Get the last node

// // //     // Adjust pointers for the rotation
// // //     first->prev = last;
// // //     first->next = second;
// // //     second->prev = first;
// // //     last->next = first;

// // //     // Update the head pointer to point to the new first node
// // //     *stack = second;
// // // }

// // // void ft_reverse_rotate(t_stack **stack) 
// // // {
// // //     if (*stack == NULL || (*stack)->next == *stack) 
// // //         return;
// // //     *stack = (*stack)->prev;
// // // }

// // // // Function to create a new node
// // // t_stack *new_node(int value)
// // // {
// // //     t_stack *node = malloc(sizeof(t_stack));
// // //     if (!node)
// // //     {
// // //         write(1, "error allocating memory\n", 24);
// // //         exit(1);
// // //     }
// // //     node->nb = value;
// // //     node->next = node;
// // //     node->prev = node;
// // //     return node;
// // // }

// // // void add_node(t_stack **head, int value)
// // // {
// // //     t_stack *node = new_node(value);
// // //     if (*head == NULL)
// // //     {
// // //         *head = node;
// // //     }
// // //     else
// // //     {
// // //         t_stack *last = (*head)->prev;
// // //         last->next = node;
// // //         node->prev = last;
// // //         node->next = *head;
// // //         (*head)->prev = node;
// // //     }
// // // }

// // // void ft_push(t_stack **src, t_stack **dest)
// // // {
// // //     if (*src == NULL)
// // //         return;

// // //     t_stack *temp = *src;

// // //     // Update the source stack
// // //     if (*src == (*src)->next) // Check if the source list had only one element
// // //         *src = NULL;
// // //     else
// // //     {
// // //         *src = (*src)->next;
// // //         (*src)->prev = temp->prev;
// // //         temp->prev->next = *src;
// // //     }

// // //     // Update the destination stack
// // //     if (*dest == NULL) // If destination is empty
// // //     {
// // //         temp->next = temp;
// // //         temp->prev = temp;
// // //     }
// // //     else
// // //     {
// // //         temp->next = *dest;
// // //         temp->prev = (*dest)->prev;
// // //         (*dest)->prev->next = temp;
// // //         (*dest)->prev = temp;
// // //     }

// // //     *dest = temp;
// // // }

// // // // Function to print the list
// // // void print_stack2(t_stack *stack, const char *name)
// // // {
// // //     if (stack == NULL)
// // //     {
// // //         printf("%s Empty\n", name);
// // //         return;
// // //     }

// // //     t_stack *current = stack;
// // //     printf("%s", name);

// // //     // Print the first node
// // //     printf(" %d", current->nb);

// // //     // Move to the next node and continue until we reach the start node
// // //     current = current->next;
// // //     while (current != stack)
// // //     {
// // //         printf(" %d", current->nb);
// // //         current = current->next;
// // //     }

// // //     printf("\n");
// // // }

// // // void ft_swap(t_stack **stack)
// // // {
// // //     int	temp;

// // // 	temp = (*stack)->nb;
// // // 	(*stack)->nb = (*stack)->next->nb;
// // // 	(*stack)->next->nb = temp;
// // // }

// // // void	ft_ss(t_stack **stack_a, t_stack **stack_b)
// // // {
// // // 	ft_swap(stack_a);
// // // 	ft_swap(stack_b);
// // // 	write(1, "ss\n", 3);
// // // }

// // // int size(t_stack *stack)
// // // {
// // //     if (stack == NULL)
// // //         return 0;

// // //     t_stack *current = stack;
// // //     t_stack *start = stack; // Keep reference to the start node
// // //     int count = 0;

// // //     while (current != NULL) 
// // //     {
// // //         count++;
// // //         current = current->next;
// // //         if (current == start) {
// // //             break;
// // //         }
// // //     }
// // //     return (count);
// // // }
// // // int main(void)
// // // {
// // //     t_stack *stack_a = NULL; // Source stack
// // //     t_stack *stack_b = NULL; // Destination stack

// // //     // Adding nodes to stack_a
// // //     add_node(&stack_a, 1);
// // //     add_node(&stack_a, 2);
// // //     add_node(&stack_a, 3);
// // //     add_node(&stack_a, 4);

// // //     printf("Initial stack_a:\n");
// // //     print_stack2(stack_a, "A:");
    
// // //     printf("Initial stack_b:\n");
// // //     print_stack2(stack_b, "begining");

// // //    while (stack_a != NULL && stack_a->next != stack_a)
// // //     {
// // //         printf("\nPushing from stack_a to stack_b:\n");
// // //         ft_push(&stack_a, &stack_b);
// // //         printf("stack_a after push:\n");
// // //         print_stack2(stack_a, "a:");
// // //         printf("stack_b after push:\n");
// // //         print_stack2(stack_b,"B:");
// // //         printf("loop:first nb:%d last nb:%d\n", stack_b->nb, stack_b->prev->nb);

// // //     }
// // //     ft_reverse_rotate(&stack_b);
// // //     printf("After reverse rotate:\n");
// // //     print_stack2(stack_b, "B:");
// // //     printf("First nb: %d, Last nb: %d\n", stack_b->nb, stack_b->prev->nb);
// // //     print_stack2(stack_b,"B:");
// // //     ft_push(&stack_b, &stack_a);
// // //      print_stack2(stack_b,"B:");
// // //      print_stack2(stack_a,"A:");
// // //     // ft_ss(&stack_a, &stack_b);
// // //     ft_ss(&stack_a, &stack_b);
// // //     print_stack2(stack_a,"after swap A:");
// // //     print_stack2(stack_b,"after swap:");
// // //     printf("%d\n", size(stack_a));


// // //     return 0;
// // // }
// // // nt ft_rot_sort(t_stack *stack_a, t_meta *meta, int sort)
// // // {
// // //     int     i;
// // //     t_stack *current;
// // //     i = 0;
// // //     current = stack_a;
// // //     while (1)
// // //     {
// // //         if (current->nbr == meta->a_min)
// // //             break ;
// // //         else
// // //         {
// // //             current = current->next;
// // //             i++;
// // //         }
// // //     }
// // //     if (ft_check_sorted(current) == 1 && sort == 1)
// // //     {
// // //         ft_sort_rot_sort(i, meta);
// // //         return (2);
// // //     }
// // //     else if (ft_check_sorted(current) == 1)
// // //         return (1);
// // //     else
// // //         return (0);
// // // }

// // // void    ft_sort_rot_sort(int i, t_meta *meta)
// // // {
// // //     if (i <= (meta->a_size / 2))
// // //         ft_print_op("ra", i);
// // //     else
// // //         ft_print_op("rra", meta->a_size - i);
// // // }

// // //  void push_to_b(t_stack **stack_a, t_stack **stack_b, t_data *data)
// // // {
// // //     data->size_a = ft_count_size(*stack_a);
// // //     data->size_b = ft_count_size(*stack_b);

// // //     while (data->size_a > 3)
// // //     {
// // //         data->max_b = max_nb(*stack_b);
// // //         data->min_b = min_nb(*stack_b);

// // //         if (data->size_b >= 2)
// // //         {
// // //             // Determine optimal rotation
// // //             int rotation_count = ft_rot_sort(*stack_a, data, 0);
// // //             if (rotation_count > 0)
// // //             {
// // //                 // Perform the optimal rotations and then push to stack_b
// // //                 if (rotation_count <= (data->size_a / 2))
// // //                 {
// // //                     for (int i = 0; i < rotation_count; i++)
// // //                         ft_ra(stack_a);
// // //                 }
// // //                 else
// // //                 {
// // //                     for (int i = 0; i < data->size_a - rotation_count; i++)
// // //                         ft_rra(stack_a);
// // //                 }
// // //                 ft_pb(stack_a, stack_b);
// // //             }
// // //         }
// // //         else
// // //         {
// // //             ft_pb(stack_a, stack_b);
// // //         }

// // //         data->size_a--;
// // //         data->size_b++;
// // //     }
// // // }
// // // void ft_sort_rot_sort(int i, t_data *data)
// // // {
// // //     if (i <= (data->size_a / 2))
// // //         for (int j = 0; j < i; j++)
// // //             ft_ra(data->stack_a);
// // //     else
// // //         for (int j = 0; j < (data->size_a - i); j++)
// // //             ft_rra(data->stack_a);
// // // }
// int ft_cheapest_rb(t_meta *meta, int a_nbr, t_stack *stack_b)
// {
//     int j;
//     int rb;
//     j = 0;
//     if ((a_nbr > meta->b_max) || (a_nbr < meta->b_min))
//     {
//         while (stack_b->nbr != meta->b_max)
//         {
//             stack_b = stack_b->next;
//             j++;
//         }
//     }
//     else
//     {
//         while (!(a_nbr > stack_b->nbr && a_nbr < stack_b->prev->nbr))
//         {
//             // printf("LLL: l_nb:%d nb:%d nb_a:%d\n", stack_b->prev->nbr, stack_b->nbr, a_nbr);
//             stack_b = stack_b->next;
//             j++;
//         }
//     }
//     // printf("moves_b i:%d size_b:%d\n", j, meta->b_size);
//     if (j <= meta->b_size / 2)
//         rb = j;
//     else
//         rb = -(meta->b_size - j);
//         // printf("moves_b i:%d size_b:%d rb:%d\n", j, meta->b_size, rb);
//     return (rb);
// }
// int ft_combine_steps_r(int *ra, int *rb)
// {
//     int joint;
//     joint = 0;
//     if (*ra <= *rb)
//         joint = *ra;
//     else
//         joint = *rb;
//     *ra -= joint;
//     *rb -= joint;
//     return (joint);
// }
// int ft_combine_steps_rr(int *ra, int *rb)
// {
//     int joint;
//     joint = 0;
//     if (*ra >= *rb)
//         joint = -*ra;
//     else
//         joint = -*rb;
//     *ra += joint;
//     *rb += joint;
//     return (joint);
// }
// int ft_combine_steps(int ra, int rb)
// {
//     int steps;
//     int joint;
//     steps = 0;
//     joint = 0;
//     if (ra > 0 && rb > 0)
//         joint = ft_combine_steps_r(&ra, &rb);
//     else if (ra < 0 && rb < 0)
//         joint = ft_combine_steps_rr(&ra, &rb);
//     steps = joint;
//     if (ra != 0)
//         steps += ft_abs(ra);
//     if (rb != 0)
//         steps += ft_abs(rb);
//     return (steps);
// }
// void    ft_cheap_pb(t_meta **meta, t_stack *stack_a, t_stack *stack_b)
// {
//     int i;
//     int ra;
//     int rb;
//     int steps;
//     i = 0;
//     while (i < (*meta)->a_size)
//     {
//         if (i <= (*meta)->a_size / 2)
//             ra = i;
//         else
//             ra = -((*meta)->a_size - i);
//         rb = ft_cheapest_rb(*meta, stack_a->nbr, stack_b);
//         steps = ft_combine_steps(ra, rb);
//         if (steps < (*meta)->steps)
//         {
//             (*meta)->steps = steps;
//             (*meta)->ra = ra;
//             (*meta)->rb = rb;
//         }
//         if (steps == 0)
//             return ;
//         i++;
//         stack_a = stack_a->next;
//     }
// }