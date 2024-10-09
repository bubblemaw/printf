# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maw <maw@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/24 17:01:35 by maw               #+#    #+#              #
#    Updated: 2024/10/08 16:10:35 by maw              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

SRCS =	ft_puthexa_fd.c \
		printf.c

OBJS := $(SRCS:%.c=%.o)

LIBFT = libft

FLAGS = -Wall -Werror -Wextra

RM = rm -f

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	cp $(LIBFT)/libft.a .
	mv libft.a $(NAME)
	gcc $(FLAGS) -c $(SRCS) -I ./
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean :
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)/libft.a

re: fclean all

