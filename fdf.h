/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:57:32 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/07/29 18:31:49 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <X11/keysym.h>

typedef struct s_params
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*add;
	int		pixel;
	int		row_len;
	int		endian;
	int		height;
	int		width;
	int		x_mid;
	int		y_mid;
	int		scale;
}	t_params;

typedef struct s_point
{
	int	x;
	int	y;
	int	color;
}	t_point;

typedef struct s_row
{
	int				x;
	int				y;
	int				z;
	int				color;
	struct s_row	*next;
}	t_row;

void	ft_rowadd_back(t_row **row, t_row *new);
void	ft_rowclear(t_row **row);
t_row	*ft_rowlast(t_row *row);
t_row	*ft_rownew(int x, int y, int z, int color);
t_row	*parser(char *name);
void	draw_line(t_params params, t_point a, t_point b);
t_point	get_point(t_params params, t_row p, int cal);
int		get_size(t_params *params, t_row *map);
void	get_neighbours(t_params params, t_row **map, t_row *point);

#endif
