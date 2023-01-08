# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/04 21:18:25 by oelshare          #+#    #+#              #
#    Updated: 2023/01/01 20:42:34 by oelshare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = libftprintf.a

CC = gcc
CCFLAGS = -Wall -Wextra -Werror
LIBFT = libft/

# Source files
SRCS = ft_hex.c ft_print_sdip.c ft_printf.c ft_ptr.c ft_unsign.c

OBJS = $(SRCS:.c=.o)

%.o : %.c 
		$(CC) $(CCFLAGS) -c $< -o $@

$(NAME): $(OBJS) 
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	@make clean -C $(LIBFT)
	rm -rf $(OBJS)

fclean: clean
	rm -f $(LIBFT)/libft.a
	rm -f $(NAME)

re: fclean all

	


		