# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 13:22:35 by ahaloui           #+#    #+#              #
#    Updated: 2023/02/24 12:56:54 by ahaloui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	push_swap

SRC			=	push_swap.c parsing.c lst_functions.c utils.c push_functions.c r_rotate_functions.c rotate_functions.c swap_functions.c \
				sort_functions.c

LIBFT		=	libft/libft.a

PRINTF		=   printf/libftprintf.a

OBJ			=	$(SRC:.c=.o)

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

$(NAME):	$(OBJ)
			make -C ./libft
			make -C ./printf
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF)

all:		$(NAME)

clean:
			make clean -C libft
			${RM} $(OBJ)

fclean: 	clean
			make fclean -C libft
			${RM} $(NAME) ${OBJ}

re:			fclean all