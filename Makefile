NAME = 	Cub3D
LIBS = cub3d.h
SRCS = 	cub3d.c					\
		exit.c					\
		read_file.c				\
		parse_file.c			\
		get_resolution.c		\
		get_textures.c			\
		utils_get_textures.c	\
		get_colors.c			\
		utils_get_colors.c		\
		parse_map.c				\
		utils_parse_map.c		\
		errors_map.c			\
		init_missing_values.c	\
		app.c					\
		init_textures.c			\
		render_frame.c			\
		raycast_wall_1.c		\
		raycast_wall_2.c		\
		raycast_sprite_1.c		\
		raycast_sprite_2.c		\
		keys.c					\
		movement_1.c			\
		movement_2.c
OBJS = 	$(SRCS:.c=.o)
FLAGS = -g
FLAGS_LINUX = -lm -lbsd -lX11 -lXext
FLAGS_MAC = -framework OpenGL -framework Appkit

.c.o:
			@gcc -c $(FLAGS) $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) _libraries
			@gcc -o $(NAME) $(OBJS) $(shell find libft/ -name "*.a") $(shell find minilibx_mac/ -name "*.a") $(FLAGS_MAC)

_libraries:
			@make -C libft
			@make -C minilibx_linux
			@make -C minilibx_mac

clean:
			@rm -f $(OBJS)
			@make clean -C libft
			@make clean -C minilibx_linux
			@make clean -C minilibx_mac

fclean:		clean
			@rm -f $(NAME)
			@make fclean -C libft

re:			fclean all

.PHONY:		all _libraries clean fclean re
