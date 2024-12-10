NAME_CLIENT = client
NAME_SERVER = server

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

SRCDIR = srcs
OBJDIR = obj
LIBPATH = libft/

LIB = -L./libft -lft

RM = rm -rf

SRC_FILES_CLIENT = client.c
SRC_FILES_SERVER = server.c

SRC_CLIENT = $(addprefix $(SRCDIR)/, $(SRC_FILES_CLIENT))
SRC_SERVER = $(addprefix $(SRCDIR)/, $(SRC_FILES_SERVER))

OBJ_CLIENT = $(addprefix $(OBJDIR)/, $(SRC_FILES_CLIENT:.c=.o))
OBJ_SERVER = $(addprefix $(OBJDIR)/, $(SRC_FILES_SERVER:.c=.o))

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	make -C $(LIBPATH)
	$(CC) $(CFLAGS) $^ $(LIB) -o $@

$(NAME_SERVER): $(OBJ_SERVER)
	make -C $(LIBPATH)
	$(CC) $(CFLAGS) $^ $(LIB) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	make clean -C $(LIBPATH)
	$(RM) $(OBJDIR)

fclean: clean
	make fclean -C $(LIBPATH)
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re
