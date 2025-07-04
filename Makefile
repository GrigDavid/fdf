CC  = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft
NAME = fdf
DEPS = fdf.h
SRCS = fdf.c
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
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBDIR)
	rm -f  $(NAME)

re: fclean all

.PHONY: all clean fclean re
