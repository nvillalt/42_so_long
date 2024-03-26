# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 20:05:20 by nvillalt          #+#    #+#              #
#    Updated: 2024/03/26 20:00:42 by nvillalt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#···COLOURS·····#
BLU			= \033[0;34m
GRN			= \033[0;32m
RED			= \033[0;31m
PUR			= \033[0;35m
YLW			= \033[0;33m
RST			= \033[0m
END			= \e[0m

#···NAME········#
NAME = so_long

#···PATH········#
SRC_PATH = src/
OBJ_PATH = obj/
INC_PATH = inc/

#····CC + FLAGS ···#
CC = cc
CFLAGS = -Wall -Wextra -g3 #-Werror -g3
CFLAGS += -I $(INC_PATH) -I $(LIBFT_DIR) -I $(SRC_PATH) 
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

#···INC········#
INC = so_long.h

#···SRCS········#
SRC = main.c parse.c utils.c support_functions.c init.c validate_map.c graphs_init.c map_hooks.c movements.c
OBJ_NAME = $(SRC:%.c=%.o)
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

RM = rm -rf

#···LIBFT·······#
#LIBFT
LIBFT_DIR = libft
# search for .a in current directory
LDFLAGS = -L $(LIBFT_DIR)
# lib name
LDLIBS = -lft

#···RULES······#
.PHONY: all re clean fclean debug

all: $(NAME)
	@echo "\033[2K\r${GRN}[CREATED]\033[0m $(NAME)\n"
# $(MLX_FLAGS)  > AÑADIRLAS A $(NAME) RULE
$(NAME): $(OBJ)
	make -sC $(LIBFT_DIR)
	$(CC) $^ -o $@ $(CFLAGS) $(MLX_FLAGS) $(LDFLAGS) $(LDLIBS)
	@echo "\033[2K\r${PUR}[COMPILING LIBFT]${RST}'$<'\n"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC_PATH)/$(INC)
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[2K\r${BLU}[COMPILING SOURCES]${RST}'$<'\n"

debug: CFLAGS += -fsanitize=address -g3
debug: $(NAME)

clean:
	make fclean -sC $(LIBFT_DIR)
	$(RM) $(OBJ_PATH)
	@echo "\033[2K\r${RED}[CLEANED]\033[0m $(NAME)\n"

fclean: clean
	$(RM) $(NAME)
	@echo "\033[2K\r${RED}[FCLEANED]\033[0m $(NAME)\n"
	
re: fclean all