Name = cub3d
CC = CC
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
RM = rm -f
INC = cub3d.h
SRC =  mandatory/main.c

OBJ = $(SRC:.c=.o)

all: $(Name)

$(Name): $(OBJ)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJ) -o $(Name)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(Name)

re: fclean all

.PHONY: all clean fclean re
