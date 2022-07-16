/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:17:20 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/03/07 14:19:06 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_CHECK_H
# define INIT_CHECK_H
# include "../.dependencies/libft/libft.h"
# include "../.dependencies/printf/ft_printf.h"

# ifndef NO_ARGS
#  define NO_ARGS -1
# endif

# ifndef INIT_ERROR
#  define INIT_ERROR -1
# endif

# ifndef INIT_SUCCESS
#  define INIT_SUCCESS 1
# endif

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

int init_stack(int argc, char **argv, t_list **stack);

#endif