# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 09:35:37 by dde-oliv          #+#    #+#              #
#    Updated: 2022/03/07 14:18:26 by dde-oliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	clang
SRC_PATH	=	src
SRC_FILES 	= 	$(SRC_PATH)/main.c \
				$(SRC_PATH)/init_check.c
OBJS_PATH	=	objs
OBJS 		=	$(addprefix $(OBJS_PATH)/,$(notdir $(SRC_FILES:.c=.o))) \
				$(addprefix $(OBJS_PATH)/,$(notdir $(UTILS_FILES:.c=.o)))
FLAGS 		= 	-Wall -Wextra -Werror
NAME 		=	push_swap
RM 			=	rm -f
FSANITIZE	=	-fsanitize=address
PRINTF_PATH	= 	.dependencies/printf
PRINTF		=	$(PRINTF_PATH)/libftprintf.a
LIBFT_PATH	= 	.dependencies/libft
LIBFT		=	$(LIBFT_PATH)/libft.a

###################################################################

all: $(OBJS_PATH) $(NAME)

$(OBJS_PATH):
				mkdir -p $(OBJS_PATH)
				
$(NAME):	$(OBJS) $(PRINTF) $(LIBFT)
				$(CC) $(FLAGS) $(FSANITIZE) $(OBJS) $(PRINTF) $(LIBFT) -o $(NAME)

$(OBJS_PATH)/%.o:	$(SRC_PATH)/%.c 
				$(CC) -c $(FLAGS) $< -o $(addsuffix .o, $(OBJS_PATH)/$(basename $(@F)))
				
$(PRINTF):
				@make -C $(PRINTF_PATH)

$(LIBFT):
				@make -C $(LIBFT_PATH)
				
clean:
				@$(RM) $(OBJS)

fclean:		clean
				@$(RM) $(NAME)
				@make fclean -C $(PRINTF_PATH)
				@make fclean -C $(LIBFT_PATH)

re:			fclean all

.PHONY:		all clean fclean re
