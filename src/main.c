/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:18:59 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/03/07 15:45:24 by dde-oliv         ###   ########.fr       */
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

int main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	
	stack_b = NULL;
	if (init_stack(argc, argv, &stack_a) != 1)
		return (-1);
	ft_lstclear(&stack_a, &free);
	ft_lstclear(&stack_b, &free);
}