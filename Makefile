# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 19:14:44 by oelshare          #+#    #+#              #
#    Updated: 2023/01/08 16:16:32 by oelshare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors

RED = "\033[0m"
GREEN = "\033[32;1m"
C_OFF = "\033[0m"

# Variables

CC = gcc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

FT_PRINTF = ft_printf/
FT_PRINTF_NAME = libftprintf.a
LIBFT = ft_printf/libft
LIBFT_NAME = libft.a

CLIENT = client
SERVER = server

# Source files
CLIENT_SRC = client.c
CLIENT_OBJ = $(CLIENT_SRC:.c=.o) 
SERVER_SRC = server.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)

EXEC = ./a.out

# Rules

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJ) 
			cd ft_printf && make && mv libftprintf.a ../
			$(CC) $(SERVER_OBJ) $(FT_PRINTF_NAME) -o server

$(CLIENT): $(CLIENT_OBJ) 
			cd ft_printf && make && mv libftprintf.a ../
			$(CC) $(CLIENT_OBJ) $(FT_PRINTF_NAME) -o client

%.o : %.c 
		$(CC) $(CCFLAGS) -c $< -o $@

clean:
	@make clean -C $(FT_PRINTF)
	@$(RM) $(CLIENT_OBJ) $(SERVER_OBJ)

fclean: clean
	@$(RM) $(FT_PRINTF)/$(FT_PRINTF_NAME)
	@$(RM) $(CLIENT_OBJ) $(SERVER_OBJ)

re: fclean all
