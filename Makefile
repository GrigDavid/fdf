CC  = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft
NAME = fdf
DEPS = fdf.h
SRCS = fdf.c parser.c row_operations/ft_rowadd_back.c row_operations/ft_rowadd_front.c \
row_operations/ft_rowclear.c row_operations/ft_rowdelone.c \
row_operations/ft_rowlast.c row_operations/ft_rownew.c \
row_operations/ft_rowsize.c draw_line.c
OBJS = $(SRCS:.c=.o)
LIBDIR = ./libft
LIBMAKE = $(LIBDIR)/libft.a
PRNTDIR = ./ft_printf
PRNTMAKE = $(PRNTDIR)/libftprintf.a

all: $(NAME) 

$(NAME) : $(OBJS) $(LIBMAKE) $(PRNTMAKE)
	$(CC) $(CFLAGS) $(OBJS) -Lminilibx-linux -lmlx -lXext -lX11 -lm $(LIBMAKE) $(PRNTMAKE) -o $(NAME)

$(LIBMAKE):
	make -C $(LIBDIR)
	make -C ./minilibx-linux

$(PRNTMAKE):
	make -C $(PRNTDIR)

%.o : %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBDIR)
	make clean -C $(PRNTDIR)
	make clean -C ./minilibx-linux
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBDIR)
	make fclean -C $(PRNTDIR)
	rm -f  $(NAME)

re: fclean all

.PHONY: all clean fclean re
