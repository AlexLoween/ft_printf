NAME= libftprintf.a

CC= gcc
CFLAGS= -Wall -Wextra -Werror
RM= rm -f

SRCS = main.c \
    utils1.c \
    utils2.c
								
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	@ar crs $(NAME) $(OBJS)

all: $(NAME)

clean:
	@$(RM) $(OBJS)
fclean: clean
	@rm -f $(NAME)
re: fclean all
.PHONY: all re clean fclean