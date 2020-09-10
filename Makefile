NAME = 	Cub3D
LIBS = cub3d.h
SRCS = 	files/cub3d.c					\
		files/exit.c					\
		files/read_file.c				\
		files/parse_file.c				\
		files/get_resolution.c			\
		files/get_textures.c			\
		files/utils_get_textures.c		\
		files/get_colors.c				\
		files/utils_get_colors.c		\
		files/parse_map.c				\
		files/utils_parse_map.c			\
		files/errors_map.c				\
		files/init_missing_values.c		\
		files/app.c						\
		files/init_textures.c			\
		files/render_frame.c			\
		files/raycast_wall_1.c			\
		files/raycast_wall_2.c			\
		files/raycast_sprite_1.c		\
		files/raycast_sprite_2.c		\
		files/keys.c					\
		files/movement_1.c				\
		files/movement_2.c				\
		files/screenshot.c
OBJS = 	$(SRCS:.c=.o)
FLAGS = -Wall -Werror -Wextra -g
FLAGS_LINUX = -lm -lbsd -lX11 -lXext
FLAGS_MAC = -framework OpenGL -framework Appkit

.c.o:
			@gcc -c $(FLAGS) $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) _libraries
			@gcc -o $(NAME) $(OBJS) $(shell find libft/ -name "*.a") \
			$(shell find minilibx_linux/ -name "*.a") $(FLAGS_LINUX)

_libraries:
			@make -C libft
			@make -C minilibx_linux
			#@make -C minilibx_mac

clean:
			@rm -f $(OBJS)
			@make clean -C libft
			@make clean -C minilibx_linux
			#@make clean -C minilibx_mac

fclean:		clean
			@rm -f $(NAME)
			@make fclean -C libft

re:			fclean all

.PHONY:		all _libraries clean fclean re
