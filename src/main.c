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

int main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	
	stack_b = NULL;
	if (init_stack(argc, argv, &stack_a) != 1)
		return (-1);
	ft_lstclear(&stack_a, &free);
}