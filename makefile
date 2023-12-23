CC = cc -g #-fsanitize=address

# CFLAGS = -Wall -Wextra -Werror 

MAKE = make

NAME = cub3D

HEADER = cub3d.h

# SRC_DIR = src

# OBJ_DIR = obj

SRC = cube.c

OBJ = $(SRC:.c=.o)

# OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

GLFW = $(shell brew --prefix glfw)

LIB_GLFW = $(addprefix $(GLFW),/lib)

MLX42_HEADER = MLX42/include/MLX42/MLX42.h

MLX42 = MLX42/build/libmlx42.a

LIBFT = libft/libft.a

all : $(NAME)

$(MLX42) :
	@cmake -S MLX42 -B MLX42/build
	@make -C MLX42/build -j4


$(NAME) : $(OBJ) $(MLX42) $(LIBFT)
	$(CC) $(CFLAGS) -L $(LIB_GLFW) -lglfw $^ -o $@

$(LIBFT) : libft

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# $(OBJ_DIR):
#     if [ -d $@ ]; then echo "obj directory exists."; else mkdir -p $(OBJ_DIR); echo "obj directory is created"; fi


mlx_build : $(MLX42)
	cmake -S MLX42 -B build
	make -C MLX42/build -j4

mlx_clean :
	if [ -e "MLX42/build" ]; then make -C MLX42/build clean; fi

mlx_fclean :
	rm -rf MLX42/build

clean : mlx_clean
	make -C libft clean
	$(RM) -rf $(OBJ_DIR)/*.o

fclean : clean mlx_fclean
	make -C libft fclean
	rm -f $(NAME)

libft :
	@make -C libft

git : fclean
	git add .
	git commit -m "$m"
	git push -u origin

re : fclean all

.PHONY : all clean fclean re libft mlx_build mlx_clean mlx_fclean git
