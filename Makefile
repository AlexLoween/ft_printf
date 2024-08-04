COLOR_RESET = \033[0m
COLOR_GREEN = \033[32m
COLOR_YELLOW = \033[33m
COLOR_AZUL = \033[34m

SRC = main.c \
    utils1.c \
    utils2.c

OBJS = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM_RF = rm -rf
EJEC = libftprintf.a

all: $(EJEC)

$(EJEC): $(OBJS)
	@echo "$(COLOR_GREEN)Compilacion en 3, 2, 1 ...$(COLOR_RESET)"
	@$(CC) $(OBJS) -o $(EJEC)
	@echo "$(COLOR_YELLOW)¡Ya lo tenemos ALUCINA!$(COLOR_RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@echo "$(COLOR_YELLOW)Eliminando cositas...$(COLOR_RESET)"
	@$(RM_RF) $(OBJS)

fclean: clean
	@echo "$(COLOR_AZUL)Borrando todas las cositas...$(COLOR_RESET)"
	@$(RM_RF) $(EJEC)

re: fclean all

.PHONY: all clean fclean re
