NAME_SERVER = server

NAME_CLIENT = client

DEBUG = no

ifeq ($(DEBUG), yes)
	CFLAGS = -W -Wextra -Wall -Werror -ansi -pedantic -I./include -g
else
	CFLAGS = -W -Wextra -Wall -Werror -ansi -pedantic -I./include
endif

CC = gcc

RM = rm -f

SRCS_SERVER = src/server.c

SRCS_CLIENT = src/client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) -o $(NAME_SERVER) $(OBJS_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) -o $(NAME_CLIENT) $(OBJS_CLIENT)


all: $(NAME_SERVER) $(NAME_CLIENT)
ifeq ($(DEBUG), yes)
	@echo "Génération en mode débug"
else
	@echo "Génération en mode release"
endif

clean:
	$(RM) $(OBJS_SERVER)
	$(RM) $(OBJS_CLIENT)

fclean: clean
	$(RM) $(NAME_SERVER)
	$(RM) $(NAME_CLIENT)

re: fclean all
