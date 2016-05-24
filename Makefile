# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/19 16:20:54 by ademenet          #+#    #+#              #
#    Updated: 2016/05/24 10:42:37 by ademenet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re norme

CC = gcc

FLAGS = -Wall -Wextra -Werror

CPP_FLAGS = -Iinclude

NAME = push_swap

SRC_PATH = ./src
LIB_PATH = ./lib
INC_PATH = ./include
OBJ_PATH = ./obj
OBJLIB_PATH = ./obj

SRC_NAME =	fpf_display.c\
			fpf_error.c\
			fpf_operations.c\
			fpf_optimization.c\
			fpf_parsing.c\
			fpf_sortmin.c\
			push_swap.c

LIB_NAME = 	fpf_atoi.c\
			fpf_isascending.c\
			fpf_isdescending.c\
			fpf_isdigit.c\
			fpf_issort.c\
			fpf_lstappend.c\
			fpf_lstnew.c

INC_NAME = fpf_printf.h

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJLIB_NAME = $(LIB_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJLIB = $(addprefix $(OBJLIB_PATH)/,$(OBJLIB_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(OBJLIB) $(fpf_PRINTF)
	@$(CC) -o $@ $^ fpf_printf/libftprintf.a
	@echo "\033[1;34mPush_swap\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -c -o $@ $<

$(OBJLIB_PATH)/%.o: $(LIB_PATH)/%.c
	@mkdir $(OBJLIB_PATH) 2> /dev/null || true
	@$(CC) -c -o $@ $<

$(fpf_PRINTF):
	@cd fpf_printf
	@make

clean:
	@rm -rf ./obj
	@echo "\033[1;34mPush_swap\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[1;34mPush_swap\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"

re: fclean all

norme:
	@norminette $(SRC) $(LIB) $(INC)
	@echo "\033[1;34mPush_swap\t\033[1;33mNorme\t\033[0;32m[OK]\033[0m"
