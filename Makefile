# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlink <mlink@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 10:37:21 by mlink             #+#    #+#              #
#    Updated: 2023/02/04 14:34:13 by mlink            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	mlink.filler

SRC		=	main.c	get.c	read_input.c\
			free.c	solve.c	trim_piece.c\
			point_map.c		print_log.c
		
SRC_DIR	=	src
OBJ_DIR	=	objects
SRCC	=	$(addprefix $(SRC_DIR)/, $(SRC))

FLAGS	=	-Wall -Wextra -Werror

HEADER	=	-I includes
LIBFT_H	=	-I libft/includes
LIBFT	=	libft/libft.a

RESET	=	\033[0m
YELLOW	=	\033[0;33m
GREEN	=	\033[0;32m
B_BLUE	=	\033[1;34m

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)%.c
	@/bin/mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) -c $(LIBFT_H) $(HEADER) $< -o $@

$(NAME): $(SRCC)
	@echo "	$(GREEN)<<$(RESET)$(YELLOW)$(NAME) is compiling...$(GREEN)>>$(RESET)"
	@make -C libft
	@gcc $(FLAGS) -o $@ $^ $(LIBFT_H) $(HEADER) $(LIBFT) $(BONUS)
	@echo "	$(GREEN)<<$(RESET)$(B_BLUE)$(NAME) is ready to use$(GREEN)>>$(RESET)"

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make -C libft clean
	@echo "	$(GREEN)<<$(RESET)$(YELLOW)all $(NAME) .o files $(GREEN)>>$(RESET)"

fclean:
	@rm -rf filler.log
	@echo "	$(GREEN)<<$(RESET)$(YELLOW)filler.log deleted$(GREEN)>>$(RESET)"
	@rm -rf filler.trace
	@echo "	$(GREEN)<<$(RESET)$(YELLOW)filler.trace deleted$(GREEN)>>$(RESET)"
	@/bin/rm -rf $(OBJ_DIR)
	@/bin/rm -f $(NAME)
	@/bin/rm -f resources/trace_filler
	@/bin/rm -f resources/filler.log
	@/bin/rm -f resources/filler.trace
	@make -C libft fclean
	@echo "	$(GREEN)<<$(RESET)$(YELLOW)$(NAME) deleted$(GREEN)>>$(RESET)"

re: fclean all

norm:
	@norminette includes libft src

.PHONY: all clean fclean re norm