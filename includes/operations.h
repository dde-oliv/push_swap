/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:21:45 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/03/07 15:11:51 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "../.dependencies/libft/libft.h"
# include "../.dependencies/printf/ft_printf.h"

void swap(t_list **stack);

void rotate(t_list **stack);

void reverse_rotate(t_list **stack);

void push(t_list **stack_out, t_list **stack_in);

#endif