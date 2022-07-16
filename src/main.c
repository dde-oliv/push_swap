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

void	print_stack(t_list *stack)
{
	t_list	*ptr;

	ptr = stack;
	while (ptr)
	{
		ft_printf("%s\n", ptr->content);
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
			ft_printf("%s\t%s\n", ptr_a->content, ptr_b->content);
			ptr_a = ptr_a->next;
			ptr_b = ptr_b->next;
		}
		else if (ptr_a)
		{
			ft_printf("%s\t\n",  ptr_a->content);
			ptr_a = ptr_a->next;		
		}
		else
		{
			ft_printf("  \t%s\n",  ptr_b->content);
			ptr_b = ptr_b->next;
		}		
	}
}

void first_order(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a && ft_atoi((*stack_a)->content) > ft_atoi(ft_lstlast(*stack_a)->content))
	{
		rotate(stack_a);
		if (*stack_b && ft_atoi((*stack_b)->content) < ft_atoi(ft_lstlast(*stack_b)->content))
		{
			rotate(stack_b);
			ft_printf("rr\n");			
		}
		else
			ft_printf("ra\n");
	}
	else if (*stack_a && (*stack_a)->next)
	{
		if (ft_atoi((*stack_a)->content) > ft_atoi((*stack_a)->next->content))
		{
			swap(stack_a);
			if (*stack_b && (*stack_b)->next && ft_atoi((*stack_b)->content) < ft_atoi((*stack_b)->next->content))
			{
				swap(stack_b);
				ft_printf("ss\n");			
			}
			else
				ft_printf("sa\n");
		}
		else
		{
			push(stack_a, stack_b);
			ft_printf("pb\n");
			if (*stack_b && ft_atoi((*stack_b)->content) < ft_atoi(ft_lstlast(*stack_b)->content))
			{
				rotate(stack_b);
				if (*stack_b && ft_atoi((*stack_a)->content) > ft_atoi(ft_lstlast(*stack_a)->content))
				{
					rotate(stack_a);
					ft_printf("rr\n");	
				}
				else
					ft_printf("rb\n");
			}
		}
	}
}

void second_order(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a && *stack_b)
	{
		if ((*stack_a)->next && ft_atoi((*stack_a)->content) < ft_atoi((*stack_b)->content)
			&& ft_atoi(((*stack_a)->next)->content) > ft_atoi((*stack_b)->content))
		{
			push(stack_b, stack_a);			
			ft_printf("pa\n");
			swap(stack_a);
			if (*stack_b && (*stack_b)->next && ft_atoi((*stack_b)->content) < ft_atoi((*stack_b)->next->content))
			{
				swap(stack_b);
				ft_printf("ss\n");			
			}
			else
				ft_printf("sa\n");
		}
		else if (ft_atoi((*stack_a)->content) < ft_atoi((*stack_b)->content))
		{
			rotate(stack_a);
			ft_printf("ra\n");
		}
		else if (ft_atoi((*stack_a)->content) > ft_atoi((*stack_b)->content)
			&& ft_atoi(ft_lstlast(*stack_a)->content) < ft_atoi((*stack_b)->content))
		{
			push(stack_b, stack_a);			
			ft_printf("pa\n");
		}
		else if (ft_atoi(ft_lstlast(*stack_a)->content) < ft_atoi((*stack_a)->content)
			&& ft_atoi(ft_lstlast(*stack_a)->content) > ft_atoi((*stack_b)->content))
		{
			reverse_rotate(stack_a);
			ft_printf("rra\n");
		}
		else if (ft_atoi((*stack_a)->content) > ft_atoi((*stack_b)->content))
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
		if (ft_atoi(ptr->content) > ft_atoi(ptr->next->content))
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	
	stack_b = NULL;
	if (init_stack(argc, argv, &stack_a) != 1)
		return (-1);
//	print_stacks(stack_a, stack_b);
	while(!is_stack_ordered(stack_a))
	{
		first_order(&stack_a, &stack_b);
//		print_stacks(stack_a, stack_b);
	}
	while(stack_b)
	{
		second_order(&stack_a, &stack_b);
//		print_stacks(stack_a, stack_b);
	}
	while(!is_stack_ordered(stack_a))
	{
		third_order(&stack_a);
	}
	//print_stacks(stack_a, stack_b);
	ft_lstclear(&stack_a, &free);
	ft_lstclear(&stack_b, &free);
}