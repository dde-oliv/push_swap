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
	int	i = 0;
	size_t len;

	len = ft_strlen(arg);
	if(*arg == '-')
	{
		len--;
		i++;
	}
	while(arg[i] != '\0')
	{
		if(!ft_isdigit(arg[i]))
			return(0);
		i++;		
	}
	if (len > 10)
		return (0);
	else if (*arg != '-' && len == 10 && ft_strcmp(arg, "2147483647") > 0)
		return (0);
	else if (*arg == '-' && len == 10 && ft_strcmp(arg, "-2147483648") > 0)
		return (0);
	return(1);
}

static int	is_already_on_list(t_list *lst, void *content)
{
	t_list	*ptr;

	ptr = lst;
	while (ptr)
	{
		if (ft_strcmp(ptr->content, content) == 0)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

int init_stack(int argc, char **argv, t_list **stack)
{
	int		i;

	i = 1;
	if (argc == 1)
		return (0);
	*stack = NULL;
	while(argv[i])
	{
		if (is_integer(argv[i]) && !is_already_on_list(*stack, argv[i]))
			ft_lstadd_back(stack, ft_lstnew(ft_strdup(argv[i])));
		else
		{
			ft_lstclear(stack, &free);
			ft_printf_fd(STDERR_FILENO,"Error\n");
			return (0);	
		}
		i++;
	}
	return (1);
}
