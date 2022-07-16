/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:18:59 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/04/05 22:14:00 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int get_stack_content(t_list *stack)
{
	return *((int *)(stack->content));
}

void	print_stack(t_list *stack)
{
	t_list	*ptr;

	ptr = stack;
	while (ptr)
	{
		ft_printf("%d\n", get_stack_content(ptr));
		ptr = ptr->next;
	}
}

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	t_list	*ptr_a;
	t_list	*ptr_b;

	ptr_a = stack_a;
	ptr_b = stack_b;
	while (ptr_a || ptr_b)
	{
		if (ptr_a && ptr_b)
		{
			ft_printf("%d\t%d\n", *((int *)(ptr_a->content)), *((int *)(ptr_b->content)));
			ptr_a = ptr_a->next;
			ptr_b = ptr_b->next;
		}
		else if (ptr_a)
		{
			ft_printf("%d\t\n",  *((int *)(ptr_a->content)));
			ptr_a = ptr_a->next;		
		}
		else
		{
			ft_printf("  \t%d\n",  *((int *)(ptr_b->content)));
			ptr_b = ptr_b->next;
		}		
	}
}

void first_order(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a &&  get_stack_content(*stack_a) > get_stack_content(ft_lstlast(*stack_a)))
	{
		rotate(stack_a);
		if (*stack_b && get_stack_content(*stack_b) < get_stack_content(ft_lstlast(*stack_b)))
		{
			rotate(stack_b);
			ft_printf("rr\n");			
		}
		else
			ft_printf("ra\n");
	}
	else if (*stack_a && (*stack_a)->next)
	{
		if (get_stack_content(*stack_a) > get_stack_content((*stack_a)->next))
		{
			swap(stack_a);
			if (*stack_b && (*stack_b)->next && get_stack_content(*stack_b) < get_stack_content((*stack_b)->next))
			{
				swap(stack_b);
				ft_printf("ss\n");
			}
			else
				ft_printf("sa\n");
		}
		else
		{
			if (*stack_b && get_stack_content(*stack_a) > get_stack_content(ft_lstlast(*stack_b))
			&& get_stack_content(*stack_a) < get_stack_content(*stack_b))
			{
				reverse_rotate(stack_b);
				ft_printf("rrb\n");
				push(stack_a, stack_b);
				ft_printf("pb\n");
				rotate(stack_b);
				ft_printf("rb\n");				
				rotate(stack_b);
				ft_printf("rb\n");
			}
			else {
				push(stack_a, stack_b);
				ft_printf("pb\n");
			}
			/*if (*stack_b && get_stack_content(*stack_b) < get_stack_content(ft_lstlast(*stack_b)))
			{
				rotate(stack_b);
				if (*stack_b && get_stack_content(*stack_a) > get_stack_content(ft_lstlast(*stack_a)))
				{
					rotate(stack_a);
					ft_printf("rr\n");	
				}
				else
					ft_printf("rb\n");
			}*/
		}
	}
}

void second_order(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a && *stack_b)
	{
		if ((*stack_a)->next && get_stack_content(*stack_a) < get_stack_content(*stack_b)
			&& get_stack_content((*stack_a)->next) > get_stack_content(*stack_b))
		{
			push(stack_b, stack_a);			
			ft_printf("pa\n");
			swap(stack_a);
			if (*stack_b && (*stack_b)->next && get_stack_content(*stack_b) < get_stack_content((*stack_b)->next))
			{
				swap(stack_b);
				ft_printf("ss\n");			
			}
			else
				ft_printf("sa\n");
		}
		else if (get_stack_content(*stack_a) < get_stack_content(*stack_b))
		{
			rotate(stack_a);
			ft_printf("ra\n");
		}
		else if (get_stack_content(*stack_a) > get_stack_content(*stack_b)
			&& get_stack_content(ft_lstlast(*stack_a)) < get_stack_content(*stack_b))
		{
			push(stack_b, stack_a);			
			ft_printf("pa\n");
		}
		else if (get_stack_content(ft_lstlast(*stack_a)) < get_stack_content(*stack_a)
			&& get_stack_content(ft_lstlast(*stack_a)) > get_stack_content(*stack_b))
		{
			reverse_rotate(stack_a);
			ft_printf("rra\n");
		}
		else if (get_stack_content(*stack_a) > get_stack_content(*stack_b))
		{
			push(stack_b, stack_a);
			ft_printf("pa\n");
		}
	}
}

void third_order(t_list **stack_a)
{
	if (*stack_a)
	{
		reverse_rotate(stack_a);
		ft_printf("rra\n");
	}	
}

int is_stack_ordered(t_list *stack)
{
	t_list	*ptr;

	ptr = stack;
	while (ptr && ptr->next)
	{
		if (get_stack_content(ptr) > get_stack_content(ptr->next))
			return (FALSE);
		ptr = ptr->next;
	}
	return (TRUE);
}

int main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	
	stack_b = NULL;
	if (init_stack(argc, argv, &stack_a) != INIT_SUCCESS)
		return (INIT_ERROR);
	//print_stacks(stack_a, stack_b);
	while(!is_stack_ordered(stack_a))
	{
		first_order(&stack_a, &stack_b);
		//ft_printf("\n");
		//print_stacks(stack_a, stack_b);
	}
	while(stack_b)
	{
		second_order(&stack_a, &stack_b);
		//ft_printf("\n");
		//print_stacks(stack_a, stack_b);
	}
	while(!is_stack_ordered(stack_a))
	{
		third_order(&stack_a);
	}	
	//ft_printf("\n");
	//print_stacks(stack_a, stack_b);
	ft_lstclear(&stack_a, &free);
	ft_lstclear(&stack_b, &free);
}