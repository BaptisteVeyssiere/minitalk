##
## Makefile for minitalk in /home/ghost/rendu/Programmation_Shell/PSU_2015_minitalk
## 
## Made by Baptiste Veyssiere
## Login   <veyssi_b@epitech.net>
## 
## Started on  Sun Feb  7 22:37:48 2016 Baptiste Veyssiere
## Last update Mon Feb  8 21:24:42 2016 Baptiste Veyssiere
##

NAME_SERVER = server/server

NAME_CLIENT = client/client

DEBUG = no

ifeq ($(DEBUG), yes)
	CFLAGS = -W -Wextra -Wall -Werror -ansi -pedantic -I./include -g
else
	CFLAGS = -W -Wextra -Wall -Werror -ansi -pedantic -I./include
endif

CC = gcc

RM = rm -f

SRCS_SERVER = server/server.c	\
	server/my_put_posnbr.c

SRCS_CLIENT = client/client.c	\
	client/my_strlen.c		\
	client/my_getnbr.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all: $(NAME_SERVER) $(NAME_CLIENT)
ifeq ($(DEBUG), yes)
	@echo "Génération en mode débug"
else
	@echo "Génération en mode release"
endif

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) -o $(NAME_SERVER) $(OBJS_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) -o $(NAME_CLIENT) $(OBJS_CLIENT)

clean:
	$(RM) $(OBJS_SERVER)
	$(RM) $(OBJS_CLIENT)

fclean: clean
	$(RM) $(NAME_SERVER)
	$(RM) $(NAME_CLIENT)

re: fclean all
