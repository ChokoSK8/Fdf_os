NAME		= fdf

LIB_MLX		= libmlx.a

SRCS		= main.c close_window.c free_param.c init_param.c init_param_utils.c ../Gnl/get_next_line_utils.c ../Gnl/get_next_line.c display.c get_mat_pos.c char_to_int.c erase_inside.c print_diamonds_utils.c get_pt_perp.c get_pt_perp_utils.c tools.c tools_2.c check_errors.c

OBJS		= $(SRCS:.c=.o)

FLAGS		= -Wall -Werror -Wextra

RM			= rm -rf

INC			= -I includes/ -Imlx

%.o: %.c
			cc $(FLAGS) $(INC) -o $@ -c $?

all:	$(NAME)

mlx:	$(LIB_MLX)

lib:
		make -C ../Libft

mlx_t:
		make -C ../Minilibx-os

$(NAME):	lib mlx_t $(OBJS)
			gcc $(FLAGS) -framework OpenGL -framework AppKit ../Libft/libft.a ../Minilibx-os/$(LIB_MLX) $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS)
		make clean -C ../Libft
		make clean -C ../Minilibx-os

fclean:		clean
			$(RM) $(NAME)
			make fclean -C ../Libft

re:			fclean all

.PHONY:		all clean fclean re
