# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 20:43:10 by eweiberl          #+#    #+#              #
#    Updated: 2023/12/04 09:52:39 by adhaka           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmock.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCE = t_funcs.c

OBJS = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
