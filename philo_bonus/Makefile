# --------------------------------
# -------- MAIN VARIABLE  --------
# --------------------------------

PROGRAM		=	philo_bonus

CC		=	gcc

CFLAGS		=	-Wall -Wextra -Werror

RM		=	rm -f

# ---------------------------------
# ---------- SRC & OBJS -----------
# ---------------------------------

SRC		=	./src/*.c \
			./src/utils/*.c\

OBJS		=	$(SRC:.c=.o)

# ---------------------------------
# ------------ RULES --------------
# ---------------------------------

all		:
			$(CC) $(CFLAGS) $(SRC) -o $(PROGRAM)

clean		:
			$(RM) $(OBJS) 

fclean		:	clean
			$(RM) $(NAME)
			$(RM) $(PROGRAM)

re		:	fclean all

.PHONY		:	all fclean re clean
