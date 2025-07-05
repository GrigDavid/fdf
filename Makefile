CC  = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft
NAME = fdf
DEPS = fdf.h
SRCS = fdf.c parser.c row_operations/ft_rowadd_back.c row_operations/ft_rowadd_front.c \
row_operations/ft_rowclear.c row_operations/ft_rowdelone.c \
row_operations/ft_rowlast.c row_operations/ft_rownew.c \
row_operations/ft_rowsize.c
OBJS = $(SRCS:.c=.o)
LIBDIR = ./libft
LIBMAKE = $(LIBDIR)/libft.a

all: $(NAME) 

$(NAME) : $(OBJS) $(LIBMAKE)
	$(CC) $(CFLAGS) $(OBJS) -Lmlx -lmlx -lXext -lX11 -lm $(LIBMAKE) -o $(NAME)

$(LIBMAKE):
	make -C $(LIBDIR)
	make -C ./mlx

%.o : %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBDIR)
	make clean -C ./mlx
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBDIR)
	rm -f  $(NAME)

re: fclean all

.PHONY: all clean fclean re
