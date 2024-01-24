CC = cc -g -fsanitize=address

# CFLAGS = -Wall -Wextra -Werror

MAKE = make

NAME = cub3D

HEADER = ft_cub3d.h

# SRC_DIR = src

# OBJ_DIR = obj

SRC = ft_cube.c ft_hooks.c ft_map_player.c ft_generate_projection.c ft_rays_hit.c ft_rays.c read_map_file.c ft_new_full_map.c

OBJ = $(SRC:.c=.o)

# OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

GLFW = $(shell brew --prefix glfw)

LIB_GLFW = $(addprefix $(GLFW),/lib)

MLX42 = MLX42/build/libmlx42.a

LIBFT = libft/libft.a

all : libft $(NAME)

# $(MLX42) :
# 	@cmake -S MLX42 -B MLX42/build
# 	@make -C MLX42/build -j4


$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(LIBFT) $(MLX42) -L $(LIB_GLFW) -lglfw $^ -o $@

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# $(OBJ_DIR):
#     if [ -d $@ ]; then echo "obj directory exists."; else mkdir -p $(OBJ_DIR); echo "obj directory is created"; fi


clean :
	make -C libft clean
	$(RM) -rf $(OBJ)

fclean : clean
	make -C libft fclean
	rm -f $(NAME)

libft :
	@make -C libft

git : fclean
	git add .
	git commit -m "$m"
	git push -u origin

re : fclean all

.PHONY : all clean fclean re libft git
