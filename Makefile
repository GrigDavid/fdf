# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/29 15:57:21 by dgrigor2          #+#    #+#              #
#    Updated: 2025/07/29 18:31:29 by dgrigor2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC  = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft
NAME = fdf
DEPS = fdf.h
SRCS = fdf.c parser.c row_operations/ft_rowadd_back.c \
row_operations/ft_rowclear.c \
row_operations/ft_rowlast.c row_operations/ft_rownew.c \
 draw_line.c get_point.c extras.c
OBJS = $(SRCS:.c=.o)
LIBDIR = ./libft
LIBMAKE = $(LIBDIR)/libft.a

all: $(NAME) 

$(NAME) : $(OBJS) $(LIBMAKE)
	$(CC) $(CFLAGS) $(OBJS) -Lminilibx-linux -lmlx -lXext -lX11 -lm $(LIBMAKE) -o $(NAME)

$(LIBMAKE):
	make -C $(LIBDIR)
	make -C ./minilibx-linux

%.o : %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBDIR)
	make clean -C ./minilibx-linux
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBDIR)
	rm -f  $(NAME)

re: fclean all

.PHONY: all clean fclean re
