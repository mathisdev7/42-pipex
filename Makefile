# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 20:31:32 by mazeghou          #+#    #+#              #
#    Updated: 2024/12/11 20:31:32 by mazeghou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
UTILS_DIR = $(SRC_DIR)/utils
INC_DIR = include
LIBFT_DIR = lib/libft

SRC_FILES = $(SRC_DIR)/pipex.c \
			$(UTILS_DIR)/main.c
OBJ_FILES = $(SRC_FILES:.c=.o)

NAME = pipex

LIBFT = $(LIBFT_DIR)/libft.a

INC = -I$(INC_DIR) -I$(LIBFT_DIR)

all: $(LIBFT) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ_FILES)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
