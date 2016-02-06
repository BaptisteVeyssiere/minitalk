NAME_SERVER = server

NAME_CLIENT = client

ifeq ($(DEBUG), yes)
	CFLAGS = -W -Wextra -Wall -Werror -ansi -pedantic -I./include -g
else
	CFLAGS = -W -Wextra -Wall -Werror -ansi -pedantic -I./include
endif

CC = gcc

RM = rm -f

DEBUG = yes

SRCS_SERVER = server.c

SRCS_CLIENT = client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all: $(OBJS_SERVER)
	$(OBJS_CLIENT)
	$(CC) -o $(NAME_SERVER) $(OBJS_SERVER)
	$(CC) -o $(NAME_CLIENT) $(OBJS_CLIENT)
ifeq ($(DEBUG), yes)
	@echo "Génération en mode débug"
else
	@echo "Génération en mode release"
endif

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
