# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjolliet <sjolliet@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/06 11:01:29 by sjolliet          #+#    #+#              #
#    Updated: 2026/02/21 18:56:53 by sjolliet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long
NAME_BONUS		= so_long_bonus

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g -Iinclude -Ilibft/include -Iminilibx

SRC_DIR			= src
SRCS			= \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/misc.c \
	$(SRC_DIR)/parsing.c \
	$(SRC_DIR)/path_validation.c \
	$(SRC_DIR)/events.c \
	$(SRC_DIR)/display.c \
	$(SRC_DIR)/map.c \
	$(SRC_DIR)/game.c
	
BONUS_DIR		= bonus/src
BONUS_SRCS		= \
	$(BONUS_DIR)/main_bonus.c \
	$(BONUS_DIR)/misc_bonus.c \
	$(BONUS_DIR)/parsing_bonus.c \
	$(BONUS_DIR)/path_validation_bonus.c \
	$(BONUS_DIR)/events_bonus.c \
	$(BONUS_DIR)/display_bonus.c \
	$(BONUS_DIR)/map_bonus.c \
	$(BONUS_DIR)/game_bonus.c

OBJ_DIR			= obj
OBJS			= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

BONUS_OBJ_DIR	= bonus/obj
BONUS_OBJS		= $(BONUS_SRCS:$(BONUS_DIR)/%.c=$(BONUS_OBJ_DIR)/%.o)

LIBFT_DIR		= libft
LIBFT			= $(LIBFT_DIR)/libft.a

MLX_DIR			= minilibx
MLX				= $(MLX_DIR)/libmlx.a
MLX_FLAGS		= -lXext -lX11 -lm -lbsd

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

$(NAME_BONUS): $(BONUS_OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME_BONUS)
	@echo "🚀 So_long bonus compiled successfully!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(BONUS_OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@$(MAKE) -C $(MLX_DIR) clean --no-print-directory

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all

bonus: $(NAME_BONUS)

.PHONY: all clean fclean re bonus
