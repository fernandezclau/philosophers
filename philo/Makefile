# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: claferna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 18:04:15 by claferna          #+#    #+#              #
#    Updated: 2024/06/10 18:04:28 by claferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --------------------------------
# -------- MAIN VARIABLE  --------
# --------------------------------

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

# ---------------------------------
# ---------- SRC & OBJS -----------
# ---------------------------------

SRC		=	./src/main.c \
			./src/initialize_params.c\
			./src/actions.c\
			./src/routine.c\
			./src/thread.c\
			./src/utils/print.c\
			./src/utils/utils.c\
			./src/utils/validation.c\

OBJS	=	$(SRC:.c=.o)

# ---------------------------------
# --------- FLOWER POWER ----------
# ---------------------------------

PINK = \033[38;5;217m
TURQUOISE = \033[38;5;80m
YELLOW = \033[38;5;229m
RESET = \033[0m

START = "$(PINK)Compiling $(YELLOW) program...$(RESET)"
DONE = "$(PINK)Compilation $(TURQUOISE)complete! 🐱$(RESET)"
VALGRIND = "$(PINK)Running Valgrind...$(RESET)"
LEAKS = "$(TURQUOISE)[Leak Mode]$(RESET)"
DATA_RACES = "$(TURQUOISE)[Data Races Mode]$(RESET)"
CLEAN = "$(PINK)Cleaning $(YELLOW)files...$(RESET)"
CLEAN_DONE = "$(PINK)Clean $(TURQUOISE)complete! 🐱$(RESET)"

# ---------------------------------
# ------------ RULES --------------
# ---------------------------------
all		:	$(OBJS)
			@echo " /\\_/\\"
			@echo "  o.o "
			@echo " > ^ < "
			@echo $(START)
			@$(CC) $(CFLAGS) $(SRC) -o philo
			@echo $(DONE)

clean	:
			@echo $(CLEAN)
			@$(RM) $(OBJS)
			@echo $(CLEAN_DONE)

fclean	:	clean
			@$(RM) $(NAME)
			@$(RM) philo

leaks	: 	$(OBJS_PHILO)
			@echo $(VALGRIND)
			@echo $(LEAKS)
			valgrind --leak-check=full ./philo 2 10 20 20 2

races	: 	$(OBJS_PHILO)
			@echo $(VALGRIND)
			@echo $(DATA_RACES)
			valgrind --tool=helgrind ./philo 2 10 20 20 2

.PHONY	:	all fclean re clean

re		:	fclean all

