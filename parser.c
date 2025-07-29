/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:57:16 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/07/29 18:28:31 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_atoh(char *str, char *set)
{
	char	*tmp;

	tmp = ft_strchr(set, *str);
	if (!tmp)
		return (0xfffff);
	if (!*(str + 1))
		return (tmp - set);
	return ((tmp - set) * 10 + ft_atoh(str + 1, set));
}

static int	get_hex(char *str)
{
	if (*str != ',')
		return (0xffffff);
	str++;
	if (*str != '0')
		return (0xffffff);
	str++;
	if (*str == 'x')
		return (ft_atoh(str, "0123456789abcdef"));
	else if (*str == 'X')
		return (ft_atoh(str, "0123456789ABCDEF"));
	return (0xffffff);
}

static char	*jump(char *str)
{
	while (*str && (*str != ' ' || *(str + 1) == ' '))
		str++;
	if (!*str)
		return (NULL);
	return (str + 1);
}

static t_row	*i_hate_norminette(char *tmp, t_row	*res, char	*cpy, int fd)
{
	int		x;
	int		y;
	t_row	*new;

	x = 0;
	y = 0;
	cpy = tmp;
	while (tmp)
	{
		new = ft_rownew(x++, y, ft_atoi(tmp), get_hex(tmp));
		if (!new)
			return (ft_rowclear(&res), NULL);
		ft_rowadd_back(&res, new);
		if (!jump(tmp))
		{
			free(cpy);
			y++;
			x = 0;
			tmp = get_next_line(fd);
			cpy = tmp;
		}
		else
			tmp = jump(tmp);
	}
	return (close (fd), res);
}

t_row	*parser(char *name)
{
	int		fd;
	int		x;
	int		y;
	char	*tmp;
	t_row	*res;

	res = NULL;
	x = 0;
	y = 0;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	tmp = get_next_line(fd);
	return (i_hate_norminette(tmp, res, name, fd));
}
