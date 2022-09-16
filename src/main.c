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

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	t_list	*ptr_a;
	t_list	*ptr_b;

	ft_printf("\n");
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

int is_stack_ordered_by_n_elements(t_list *stack, int n)
{
	t_list	*ptr;
    int     i;
	
    ptr = stack;
    i = 1;
	while (ptr && ptr->next)
	{
		if ((i % n != 0) && get_stack_content(ptr) > get_stack_content(ptr->next))
			return (FALSE);
		ptr = ptr->next;
        i++;
	}
	return (TRUE);
}


int is_stack_ordered_until(t_list *stack, int ordered_until)
{
	t_list	*ptr;
    int     i;
	
    ptr = stack;
    i = 1;
	while (ptr && ptr->next && i < ordered_until)
	{
		if (get_stack_content(ptr) > get_stack_content(ptr->next))
			return (FALSE);
		ptr = ptr->next;
        i++;
	}
	return (TRUE);
}

int first_is_greater_than_next(t_list *stack)
{
    if (get_stack_content(stack) > get_stack_content((stack)->next))
        return TRUE;
    return FALSE;
}

int max(int nbr1, int nbr2){
    if (nbr1 > nbr2)
        return nbr1;
    return nbr2;
}

int min(int nbr1, int nbr2){
    if (nbr1 < nbr2)
        return nbr1;
    return nbr2;
}

void divide_with_stack_b(t_list **stack_a, t_list **stack_b)
{
    int size_stack_a = ft_lstsize(*stack_a);
    int i;

    i = 0; //max(BATCH_SIZE, size_stack_a / 2) - (size_stack_a % 2 == 0);
    while (i < size_stack_a / 2)
    {
        push(stack_a, stack_b);
        ft_printf("pb\n");
        i++;
    }
}


void order_tree_elements(t_list **stack_a, t_list **stack_b) {

    if (stack_a && *stack_a && (*stack_a)->next && first_is_greater_than_next(*stack_a))
    {
        swap(stack_a);
        if (stack_b && *stack_b && (*stack_b)->next && first_is_greater_than_next(*stack_b))
        {
            swap(stack_b);
            ft_printf("ss\n");
        }
        else
            ft_printf("sa\n");
    }
    else if (stack_b && *stack_b && (*stack_b)->next && first_is_greater_than_next(*stack_b))
    {
        swap(stack_b);
        ft_printf("sb\n");
    }
    else if (stack_a && *stack_a && (*stack_a)->next)
    {
        rotate(stack_a);
        swap(stack_a);
        reverse_rotate(stack_a);
		if (stack_b && *stack_b && (*stack_b)->next)
		{
			rotate(stack_b);
            swap(stack_b);
            reverse_rotate(stack_b);
			ft_printf("rr\n");	
            ft_printf("ss\n");
            ft_printf("rrr\n");		
		}
		else{
			ft_printf("ra\n");	
            ft_printf("sa\n");
            ft_printf("rra\n");	
        }
    }
    else if (stack_b && *stack_b && (*stack_b)->next){
	  
        rotate(stack_b);
        swap(stack_b);
        reverse_rotate(stack_b);
        ft_printf("rb\n");	
        ft_printf("sb\n");
        ft_printf("rrb\n");		
		
    }
}

int max_element_to_operate(t_list *stack, int batch_case, int count_n)
{
    int size_stack = ft_lstsize(stack);
    return min(batch_case, size_stack - (2 * count_n * batch_case));
}

void merge_elements_at_b(t_list **stack_a, t_list **stack_b, int *element_pushed, int *element_to_end, int max_element_to_end, int max_element_to_push)
{

    if (*stack_a && *stack_b && get_stack_content(*stack_a) > get_stack_content(*stack_b)
        && *element_to_end < max_element_to_end)
    {
        rotate(stack_b);
        ft_printf("rb\n");
        (*element_to_end)++;
    }
    else if (*stack_a && *element_pushed < max_element_to_push)
    {
        push(stack_a, stack_b);
        ft_printf("pb\n");
        rotate(stack_b);
        ft_printf("rb\n");
        (*element_pushed)++;
    }
    else if (*element_to_end < max_element_to_end)
    {
        rotate(stack_b);
        ft_printf("rb\n");
        (*element_to_end)++;
    }
}

void merge_elements_at_a(t_list **stack_a, t_list **stack_b, int *element_pushed, int *element_to_end, int max_element_to_end, int max_element_to_push)
{
    if (*stack_a && *stack_b && get_stack_content(*stack_a) < get_stack_content(*stack_b)
        && *element_to_end < max_element_to_end)
    {
        rotate(stack_a);
        ft_printf("ra\n");
        (*element_to_end)++;
    }
    else if (*stack_b && *element_pushed < max_element_to_push)
    {
        push(stack_b, stack_a);
        ft_printf("pa\n");
        rotate(stack_a);
        ft_printf("ra\n");
        (*element_pushed)++;
    }
    else if (*element_to_end < max_element_to_end)
    {
        rotate(stack_a);
        ft_printf("ra\n");
        (*element_to_end)++;
    }
}

void merge_stacks(t_list **stack_a, t_list **stack_b, int batch_case, int *na_case,int *count_n_a, int *count_n_b){
    int element_pushed = 0;
    int element_to_end = 0;
    int max_element_to_operate_a =  max_element_to_operate(*stack_a, batch_case, *count_n_a);
    int max_element_to_operate_b =  max_element_to_operate(*stack_b, batch_case, *count_n_b);
    if (!*stack_b && !is_stack_ordered(*stack_a) && max_element_to_operate_a > 0)
    {
        push(stack_a, stack_b);
        ft_printf("pb\n");
        max_element_to_operate_a--;
        while(max_element_to_operate_a > 0)
        {
            push(stack_a, stack_b);
            ft_printf("pb\n");
            rotate(stack_b);
            ft_printf("rb\n");
            max_element_to_operate_a--;
        }
    }
    else if (*na_case){
        while((element_to_end < max_element_to_operate_a
                                    || element_pushed < max_element_to_operate_b))
            merge_elements_at_a(stack_a, stack_b, &element_pushed, &element_to_end, max_element_to_operate_a, max_element_to_operate_b);
    }
    else{
        while((element_to_end < max_element_to_operate_b
                                    || element_pushed < max_element_to_operate_a))
        {
            merge_elements_at_b(stack_a, stack_b, &element_pushed, &element_to_end, max_element_to_operate_b, max_element_to_operate_a);
        }
    }
    while (!*stack_b && !is_stack_ordered(*stack_a) && max_element_to_operate_a <= 0)
    {
        rotate(stack_a);
        ft_printf("ra C\n");
    }
    if (*na_case){
        *count_n_a += 1;
        *na_case = FALSE;
    }
    else{
        *count_n_b += 1;
        *na_case = TRUE;
    }
}

int ft_power(int nbr_to_power, int power)
{
    if (power == 0)
        return 1;
    return nbr_to_power * ft_power(nbr_to_power, power - 1);
}

int main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	
    stack_b = NULL;
    if (init_stack(argc, argv, &stack_a) != INIT_SUCCESS)
		return (INIT_ERROR);
    if (!is_stack_ordered(stack_a)){
        divide_with_stack_b(&stack_a, &stack_b);
    }
    int na_case=TRUE;
    int count_n_a = 0;
    int count_n_b = 0;
    while (!is_stack_ordered_by_n_elements(stack_a, BATCH_SIZE) || !is_stack_ordered_by_n_elements(stack_b, BATCH_SIZE)) {
        int max_element_to_operate_a =  max_element_to_operate(stack_a, BATCH_SIZE, count_n_a);
        int max_element_to_operate_b =  max_element_to_operate(stack_b, BATCH_SIZE, count_n_b);
        print_stacks(stack_a, stack_b);
        while(!is_stack_ordered_until(stack_a, max_element_to_operate_a)
            || !is_stack_ordered_until(stack_b, max_element_to_operate_b))
        {
            if (is_stack_ordered_until(stack_a, max_element_to_operate_a))
                order_tree_elements(NULL, &stack_b);
            else if (is_stack_ordered_until(stack_b, max_element_to_operate_b))
                order_tree_elements(&stack_a, NULL);
            else
                order_tree_elements(&stack_a, &stack_b);
        }
        print_stacks(stack_a, stack_b);
        merge_stacks(&stack_a, &stack_b, BATCH_SIZE * ft_power(2, 0),&na_case, &count_n_a, &count_n_b);
        /*int j = 0;
        while(j < BATCH_SIZE)
        {
            if (j < ft_lstsize(stack_a) - count_n && j <  ft_lstsize(stack_b) - count_n){
                rotate(&stack_a);
                rotate(&stack_b);
                ft_printf("rr\n");
            }
            else if (j <  ft_lstsize(stack_b)  - count_n){
               rotate(&stack_b);
               ft_printf("rb\n");
            }
            else if (j < ft_lstsize(stack_a) - count_n){
               rotate(&stack_a);
               ft_printf("ra\n");
            }
            j++;
        }*/
        //count_n += BATCH_SIZE;
    }
    int i = 1;
    while (!is_stack_ordered(stack_a) || stack_b)
    {
        na_case=TRUE;
        count_n_a = 0;
        count_n_b = 0;
        while (!is_stack_ordered_by_n_elements(stack_a, BATCH_SIZE * ft_power(2, i + 1)) 
                || !is_stack_ordered_by_n_elements(stack_b, BATCH_SIZE * ft_power(2, i + 1))
                || (ft_lstsize(stack_a) < BATCH_SIZE * ft_power(2, i + 1) && stack_b)) {
            print_stacks(stack_a, stack_b);
            merge_stacks(&stack_a, &stack_b, BATCH_SIZE * ft_power(2, i),&na_case, &count_n_a, &count_n_b);
        }
        i++;
    }
    print_stacks(stack_a, stack_b);
	ft_lstclear(&stack_a, &free);
	ft_lstclear(&stack_b, &free);
    //ft_printf("%d", is_stack_ordered_by_tree(stack_a) );
}