SRC = main.c \
		utils.c
OBJS = $(SRC:.c=.o)

CC = gcc
GFLAGS = -Wall -Wextra -Werror
RM_RF = rm -rf
NAME = libftprintf.a

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)
all : $(NAME)

clean :
	$(RM_RF) $(OBJS)
fclean : clean 
	$(RM_RF) $(NAME) $(OBJS)
re : fclean  all

.PHONY : all clean fclean re 