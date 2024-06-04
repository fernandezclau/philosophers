# --------------------------------
# -------- MAIN VARIABLE  --------
# --------------------------------

NAME		=	philo.a

CC		=	gcc

CFLAGS		=	-Wall -Wextra -Werror

RM		=	rm -f

# ---------------------------------
# ---------- SRC & OBJS -----------
# ---------------------------------

SRC		=	./src/main.c \
			./src/arguments/*.c\
			./src/thread/*.c\
			./src/utils/*.c\

OBJS		=	$(SRC:.c=.o)

# ---------------------------------
# ------------ RULES --------------
# ---------------------------------

all		:
			$(CC) $(CFLAGS) $(SRC) -o philo

clean		:
			$(RM) $(OBJS) 

fclean		:	clean
			$(RM) $(NAME)
			$(RM) philo

re		:	fclean all

.PHONY		:	all fclean re clean
