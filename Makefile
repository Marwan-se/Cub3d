Name = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
RM = rm -f
INC = mandatory/raycasting/cub3d.h
SRC =  mandatory/main.c mandatory/parsing/check_syntax.c mandatory/utils/utils.c mandatory/utils/utils1.c mandatory/utils/utils2.c mandatory/parsing/read_map.c \
		mandatory/parsing/check_directions.c mandatory/parsing/parsing.c mandatory/parsing/map_handling.c mandatory/parsing/closed_map.c\
		mandatory/parsing/floor_cieling.c mandatory/parsing/new_full_map.c \
		mandatory/raycasting/ft_generate_projection.c mandatory/raycasting/ft_map_player.c \
		mandatory/raycasting/ft_hooks.c mandatory/raycasting/ft_rays_hit.c mandatory/raycasting/ft_rays.c\
		mandatory/utils/utils3.c mandatory/parsing/errors_chk.c 

OBJ = $(SRC:.c=.o)

GLFW = $(shell brew --prefix glfw)

LIB_GLFW = $(addprefix $(GLFW),/lib)

MLX42 = libmlx42.a

LIBFT = mandatory/libft/libft.a

all: libft $(Name)

$(Name) : $(OBJ)
	$(CC) $(CFLAGS) $(LIBFT) $(MLX42) -L $(LIB_GLFW) -lglfw $^ -o $@

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@


clean :
	make -C mandatory/libft clean
	$(RM) -rf $(OBJ)

fclean : clean
	make -C mandatory/libft fclean
	rm -f $(Name)

libft :
	@make -C mandatory/libft


re: fclean all

.PHONY: all clean fclean re
