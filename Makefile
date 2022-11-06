# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 12:54:12 by dilopez-          #+#    #+#              #
#    Updated: 2022/09/03 15:40:18 by dilopez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ========== VARIABLES ==========
NAME			=	philo
SRC_DIR			=	src
OBJ_DIR 		=	obj
INC_DIR			=	includes
CC				=	gcc
CFLAGS			=	-I $(INC_DIR) -Wall -Werror -Wextra

SRCS			=	$(SRC_DIR)/philo.c				\
					$(SRC_DIR)/philo_utils.c		\
					$(SRC_DIR)/ft_get_args.c		\
					$(SRC_DIR)/ft_get_philos.c		\
					$(SRC_DIR)/ft_philo_states.c	\

OBJS			=	$(SRCS:.c=.o)
PREFIXED		=	$(addprefix $(OBJ_DIR)/, $(OBJS))

GREEN			=	"\\x1b[32m"
RED				=	"\\x1b[31m"
YELLOW			=	"\\x1b[33m"
RESET			=	"\\x1b[37m"

# ========== RULES ==========

$(NAME):		print $(PREFIXED)
	@$(CC) $(CFLAGS) $(PREFIXED) -o $(NAME)
	@echo "\n${GREEN}---------- Mandatory part compiled! ----------${RESET}\n"

$(OBJ_DIR)/%.o:	%.c
	@mkdir -p $(OBJ_DIR)/src
	@echo "$(CC) $(CFLAGS) : \t $<"
	@$(CC) $(CFLAGS) -c $< -o $@

# ========== FUNCTIONS ==========

print:
	@echo "\n$(YELLOW)---------- Compiling project's files ---------$(RESET)\n"

all:	$(NAME)

clean:
	@rm -rf $(OBJS) $(OBJ_DIR) philo.dSYM
	@echo "\n${GREEN}------------------ Cleaned! ------------------${RESET}\n"

fclean:	clean
	@rm -rf $(NAME)

re:		fclean all

.PHONY: all clean fclean re print bonus