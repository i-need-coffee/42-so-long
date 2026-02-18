# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjolliet <sjolliet@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/06 11:01:29 by sjolliet          #+#    #+#              #
#    Updated: 2026/02/18 11:58:15 by sjolliet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -Iinclude -Ilibft/include -Iminilibx

SRC_DIR		= src
SRCS		= \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/misc.c \
	$(SRC_DIR)/parsing.c \
	$(SRC_DIR)/path_validation.c \
	$(SRC_DIR)/events.c \
	$(SRC_DIR)/display.c \
	$(SRC_DIR)/map.c

OBJ_DIR		= obj
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

MLX_DIR		= minilibx
MLX			= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -lXext -lX11 -lm -lbsd

# **************************************************************************** #

all: $(NAME)

$(LIBFT):
	@echo "📚 Building Libft..."
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(MLX):
	@echo "🖼️  Building MiniLibX..."
	@$(MAKE) -C $(MLX_DIR) --no-print-directory

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)
	@echo "🚀 So_long compiled successfully!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@$(MAKE) -C $(MLX_DIR) clean --no-print-directory

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re
