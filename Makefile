# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 19:14:44 by oelshare          #+#    #+#              #
#    Updated: 2023/01/11 18:02:46 by oelshare         ###   ########.fr        #
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

SRC = src
CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

# Source files

CLIENT_SRC = $(SRC)/client.c
CLIENT_OBJ = $(CLIENT_SRC:.c=.o) 
SERVER_SRC = $(SRC)/server.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_BONUS_SRC = $(SRC)/client_bonus.c
CLIENT_BONUS_OBJ = $(CLIENT_BONUS_SRC:.c=.o) 
SERVER_BONUS_SRC = $(SRC)/server_bonus.c
SERVER_BONUS_OBJ = $(SERVER_BONUS_SRC:.c=.o) 

EXEC = ./a.out

# Rules

all: $(SERVER) $(CLIENT)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER): $(SERVER_OBJ) 
			cd ft_printf && make && mv libftprintf.a ../
			$(CC) $(SERVER_OBJ) $(FT_PRINTF_NAME) -o server

$(CLIENT): $(CLIENT_OBJ) 
			cd ft_printf && make && mv libftprintf.a ../
			$(CC) $(CLIENT_OBJ) $(FT_PRINTF_NAME) -o client

$(SERVER_BONUS): $(SERVER_BONUS_OBJ)
			cd ft_printf && make && mv libftprintf.a ../
			$(CC) $(SERVER_BONUS_OBJ) $(FT_PRINTF_NAME) -o server_bonus
			
$(CLIENT_BONUS): $(CLIENT_BONUS_OBJ)
			cd ft_printf && make && mv libftprintf.a ../
			$(CC) $(CLIENT_BONUS_OBJ) $(FT_PRINTF_NAME) -o client_bonus

%.o : %.c 
		$(CC) $(CCFLAGS) -c $< -o $@

clean:
	@make clean -C $(FT_PRINTF)
	@$(RM) $(CLIENT_OBJ) $(SERVER_OBJ)

cleanb: 
		@make clean -C $(FT_PRINTF)
		@$(RM) $(CLIENT_BONUS_OBJ) $(SERVER_BONUS_OBJ)

fclean: clean
	@$(RM) $(FT_PRINTF)/$(FT_PRINTF_NAME)
	@$(RM) $(CLIENT_OBJ) $(SERVER_OBJ)
	@$(RM) $(SERVER) $(CLIENT) $(FT_PRINTF_NAME)

fcleanb: clean
	@$(RM) $(FT_PRINTF)/$(FT_PRINTF_NAME)
	@$(RM) $(CLIENT_BONUS_OBJ) $(SERVER_BONUS_OBJ)
	@$(RM) $(SERVER_BONUS) $(CLIENT_BONUS) $(FT_PRINTF_NAME)

re: fclean all

reb: fclean bonus
