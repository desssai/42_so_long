SRCS	=	mandatory/so_long.c \
			mandatory/so_long_utils.c \
			mandatory/so_long_utils2.c \
			mandatory/so_long_events.c \
			mandatory/so_long_visuals.c \
			mandatory/so_long_mapcheck.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \

B_SRCS	=	bonus/so_long_bonus.c \
			bonus/so_long_utils_bonus.c \
			bonus/so_long_utils2_bonus.c \
			bonus/so_long_events_bonus.c \
			bonus/so_long_enemies_bonus.c \
			bonus/so_long_visuals_bonus.c \
			bonus/so_long_visuals2_bonus.c \
			bonus/so_long_mapcheck_bonus.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \

OBJS	=	$(SRCS:.c=.o)

B_OBJS	=	$(B_SRCS:.c=.o)

HEADS	=	./

NAME	=	so_long

B_NAME	=	so_long_bonus

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

$(B_NAME): $(B_OBJS)
	$(MAKE) -C libft all
	$(MAKE) -C mlx all
	$(GCC) $(B_OBJS) $(LNAME) $(MLBNAME) -lz -framework OpenGL -framework AppKit -o $(B_NAME)

all:	$(NAME)

bonus:	$(B_NAME)
	
clean:
		$(MAKE) -C libft clean
		$(MAKE) -C mlx clean
		$(RM) $(OBJS) $(B_OBJS)

fclean: clean
		$(RM) $(LNAME)
		$(RM) $(NAME)
		$(RM) $(B_NAME)
		$(RM) $(MLBNAME)

re:		fclean all