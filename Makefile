# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/19 13:22:14 by ikozlov           #+#    #+#              #
#    Updated: 2018/03/12 19:31:07 by ikozlov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

# directories
OBJ_DIR = obj/
SRC_DIR = srcs/
INC_DIR = includes/
LIBFT_DIR = libft/
TEST_DIR = test/

# complier
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -O3 -march=native -pipe
DEBUG = -g 

# src & obj files
SRC_FILES = ft_printf.c args.c printer.c helper.c output.c widechar.c flags.c precision.c
OBJ_FILES = $(SRC_FILES:.c=.o)
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
TEST = a.out

# libraries
LIBFT = ft

INCLUDES = -I $(LIBFT_DIR)includes/ -I includes/ 

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ): $(SRC)
	@mkdir -p $(OBJ_DIR)
	gcc $(CFLAGS) $(INCLUDES) -c $^
	@mv -f *.o $(OBJ_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	@/bin/rm -rf $(OBJ_DIR)
	@echo "[INFO] Object folder removed"

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(TEST)
	# @/bin/rm -rf $(TEST).dSYM
	@echo "[INFO] Executable removed"

test: all
	gcc $(DEBUG) -w test/*.c -L . -l ftprintf $(INCLUDES) -o $(TEST)

re: fclean all

.PHONY: all clean fclean re $(NAME)