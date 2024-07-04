# --------------------------------
# -------- MAIN VARIABLE  --------
# --------------------------------

NAME 		=	philo

CC			=	gcc

CFLAGS 		:= -g -Wall -Wextra -Werror -pthread #-fsanitize=thread

RM			=	rm -rf

# ---------------------------------
# ---------- SRC & OBJS -----------
# ---------------------------------
INCLUDE		=	./include

SRC_DIR 	:= src

SRCS 		:=	main.c\
				initialize_params.c validation.c\
				thread.c actions.c actions2.c print.c\
				utils.c

SRCS 		:= $(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR 	:= .obj

OBJS 		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

DEPS 		:= $(OBJS:.o=.d)

CPPFLAGS 	:= $(addprefix -I,$(INCLUDE)) -MMD -MP

DIR_DUP 	= mkdir -p $(@D)

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
# Rules ----------------------------------------------------------------------->

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			@echo " /\\_/\\"
			@echo "  o.o "
			@echo " > ^ < "
			@echo $(START)
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			@echo $(DONE)

$(BUILD_DIR)/%.o	:	$(SRC_DIR)/%.c
						@$(DIR_DUP)
						@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

-include $(DEPS)

clean	:
			@echo $(CLEAN)
			@$(RM) $(BUILD_DIR)
			@echo $(CLEAN_DONE)

fclean	:	clean
			@$(RM) $(NAME)
			@$(RM) philo

leaks	: 	$(OBJS)
			@echo $(VALGRIND)
			@echo $(LEAKS)
			valgrind --leak-check=full ./philo 2 200 20 20 2

races	: 	$(OBJS)
			@echo $(VALGRIND)
			@echo $(DATA_RACES)
			valgrind --tool=helgrind ./philo 2 100 20 20 2

.PHONY	:	all fclean re clean

re		:	fclean all
