SRCS	=	mandatory/so_long.c \
			mandatory/so_long_visuals.c \
			mandatory/so_long_utils.c \
			mandatory/so_long_events.c \
			mandatory/so_long_mapcheck.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \

OBJS	=	$(SRCS:.c=.o)

HEADS	=	./

NAME	=	so_long

LNAME	=	libft/libft.a

MLBNAME	=	mlx/libmlx.a

GCC		=	gcc

FLAGS	=	-Wall -Werror -Wextra -Imlx

RM		=	rm -f

%.o: %.c
	$(GCC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C libft all
	$(MAKE) -C mlx all
	$(GCC) $(OBJS) $(LNAME) $(MLBNAME) -lz -framework OpenGL -framework AppKit -o $(NAME)

all:	$(NAME)

clean:
		$(MAKE) -C libft clean
		$(MAKE) -C mlx clean
		$(RM) $(OBJS) $(B_OBJS)

fclean: clean
		$(RM) $(LNAME)
		$(RM) $(NAME)
		$(RM) $(MLBNAME)

re:		fclean all