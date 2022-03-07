/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:21:03 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/03/07 15:25:52 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"

void swap(t_list **stack)
{
	void	*temp;

	if (!stack)
		return ;
	else if (*stack == NULL)
		return ;
	else if ((*stack)->next == NULL)
		return ;
	temp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp;
}

void reverse_rotate(t_list **stack)
{
	t_list	*ptr_last;
	t_list	*ptr_last_but_one;

	if (!stack)
		return ;
	else if (*stack == NULL)
		return ;
	else if ((*stack)->next == NULL)
		return ;
	ptr_last = *stack;
	while (ptr_last->next != NULL)
	{
		ptr_last_but_one = ptr_last;
		ptr_last = ptr_last->next;
	}
	ptr_last_but_one->next = NULL;
	ft_lstadd_front(stack, ptr_last);
}

void rotate(t_list **stack)
{
	t_list	*ptr_first;
	t_list	*ptr_last;

	if (!stack)
		return ;
	else if (*stack == NULL)
		return ;
	else if ((*stack)->next == NULL)
		return ;
	ptr_first = *stack;
	*stack = ptr_first->next;
	ptr_last = ft_lstlast(*stack);
	ptr_last->next = ptr_first;
	ptr_first->next = NULL;
}

void push(t_list **stack_out, t_list **stack_in)
{
	t_list *ptr;

	if (!stack_in || !stack_out)
		return ;
	else if (*stack_out == NULL)
		return ;
	ptr = (*stack_out)->next;
	ft_lstadd_front(stack_in, *stack_out);
	*stack_out = ptr;
}