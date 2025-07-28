#ifndef FDF_H
# define FDF_H

// typedef struct s_row
// {
// 	int				*height;
// 	int				*color;
// 	int				len;
// 	struct s_row	*next;
// }	t_row;

typedef struct s_params
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*address;
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
	int				x;
	int				y;
	int				color;
	struct s_point	*next;
}	t_point;

typedef struct s_row
{
	int	x;
	int	y;
	int	z;
	int	color;
	struct s_row	*next;
}	t_row;

# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include "./ft_printf/ft_printf.h"
# include <X11/keysym.h>

//t_point	*parser(char *name);

// void	ft_pointadd_back(t_point **point, t_point *new);
// void	ft_pointadd_front(t_point **point, t_point *new);
// void	ft_pointclear(t_point **point);
// void	ft_pointdelone(t_point *point);
// t_point	*ft_pointlast(t_point *point);
// t_point	*ft_pointnew(int x, int y, int color);
// int		ft_pointsize(t_point *point);
//should be deleted pretty soon
void	ft_rowadd_back(t_row **row, t_row *new);
void	ft_rowadd_front(t_row **row, t_row *new);
void	ft_rowclear(t_row **row);
void	ft_rowdelone(t_row *row);
t_row	*ft_rowlast(t_row *row);
t_row	*ft_rownew(int x, int y, int z, int color);
int		ft_rowsize(t_row *row);

t_row	*parser(char *name);
void	draw_line(t_params params, t_point a, t_point b);
t_point	get_point(t_params params, t_row p, int cal);


#endif
