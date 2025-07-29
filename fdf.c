/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:57:35 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/07/29 18:27:23 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	thanos(t_params *params)
{
	mlx_destroy_image(params->mlx, params->img);
	mlx_destroy_window(params->mlx, params->win);
	mlx_destroy_display(params->mlx);
	free(params->mlx);
	exit(0);
	return (1);
}

static int	acoustic_thanos(t_params *params, int n)
{
	if (n >= 1)
		mlx_destroy_window(params->mlx, params->win);
	if (n >= 2)
		mlx_destroy_image(params->mlx, params->img);
	mlx_destroy_display(params->mlx);
	free(params->mlx);
	exit(0);
	return (1);
}

static int	press_esc(int keycode, t_params *params)
{
	if (keycode == XK_Escape)
		thanos(params);
	return (1);
}

static int	initialise(t_params *p, t_row *map)
{
	(*p).mlx = mlx_init();
	(*p).width = 1800;
	(*p).height = 1800;
	if (!map)
		return (acoustic_thanos(p, 0), 0);
	if (!(*p).mlx)
		return (ft_rowclear(&map), acoustic_thanos(p, 0), 0);
	if (!get_size(p, map))
		return (ft_rowclear(&map), acoustic_thanos(p, 0), 0);
	(*p).win = mlx_new_window((*p).mlx, (*p).width, (*p).height, "fdf");
	if (!(*p).win)
		return (ft_rowclear(&map), acoustic_thanos(p, 0), 0);
	(*p).img = mlx_new_image((*p).mlx, (*p).width, (*p).height);
	if (!(*p).img)
		return (ft_rowclear(&map), acoustic_thanos(p, 1), 0);
	(*p).add = mlx_get_data_addr((*p).img, &(*p).pixel,
			&(*p).row_len, &(*p).endian);
	if (!(*p).add)
		return (ft_rowclear(&map), acoustic_thanos(p, 2), 0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_params	params;
	t_row		*map;
	t_row		*tmp;

	if (argc != 2)
		return (0);
	map = parser(argv[1]);
	if (!initialise(&params, map))
		return (0);
	tmp = map;
	while (tmp)
	{
		get_neighbours(params, &map, tmp);
		tmp = tmp->next;
	}
	ft_rowclear(&map);
	mlx_put_image_to_window(params.mlx, params.win, params.img, 0, 0);
	mlx_hook(params.win, 2, 1L << 0, press_esc, &params);
	mlx_hook(params.win, 17, 0, thanos, &params);
	mlx_loop(params.mlx);
	return (0);
}
