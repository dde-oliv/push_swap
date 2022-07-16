/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:16:51 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/03/07 14:18:54 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/init_check.h"

static int is_integer(char *arg)
{
	int	i;
	size_t len;
	int minus_sign;

	minus_sign = (*arg == '-');
	len = ft_strlen(arg) - minus_sign;
	i = minus_sign;
	while(arg[i] != '\0')
	{
		if(!ft_isdigit(arg[i]))
			return(FALSE);
		i++;		
	}
	if ((len > 10)
			|| (*arg != '-' && len == 10 && ft_strcmp(arg, "2147483647") > 0)
			|| (*arg == '-' && len == 10 && ft_strcmp(arg, "-2147483648") > 0))
		return (FALSE);
	return(TRUE);
}

static int	is_already_on_list(t_list *lst, void *content)
{
	t_list	*ptr;

	ptr = lst;
	while (ptr)
	{
		if (*((int *)(ptr->content)) == ft_atoi(content))
		{
			ft_printf("%d %d\n", *((int *)(ptr->content)), ft_atoi(content));
			return (TRUE);
		}
		ptr = ptr->next;
	}
	return (FALSE);
}

int init_stack(int argc, char **argv, t_list **stack)
{
	int		i;
	int *nbr;
	
	i = 1;
	if (argc == 1)
		return (NO_ARGS);
	*stack = NULL;
	while(argv[i])
	{
		if (is_integer(argv[i]) && !is_already_on_list(*stack, argv[i]))
		{
			nbr = malloc(sizeof(int));
			*nbr = ft_atoi(argv[i]);
			ft_lstadd_back(stack, ft_lstnew(nbr));
		}
		else
		{
			ft_lstclear(stack, &free);
			ft_printf_fd(STDERR_FILENO,"Error\n");
			return (INIT_ERROR);	
		}
		i++;
	}
	return (INIT_SUCCESS);
}
