#include "fdf.h"


int	ft_atoh(char *str)
{
	// int	res;
	// int	i;

	if (!ft_strchr(str, ','))
		return (0xffffff); ///////////////////here will be coloring function in the future
	return (0xffffff);     ///////////////////here will be str to hex converting function
}

char	*jump(char *str)
{
	while ((*str != ' ' || *(str + 1) == ' ') && *str)
		str++;
	if (!*str)
		return (NULL);
	return (str + 1);
}

t_row	*parser(char *name)
{
	int		fd;
	int		x;
	int		y;
	char	*tmp;
	char	*tmp_cpy;
	t_row	*res;

	res = NULL;
	x = 0;
	y = 0;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	tmp = get_next_line(fd);
	if (!tmp)
		return (NULL);
	tmp_cpy = tmp;
	while (tmp)
	{
		ft_rowadd_back(&res, ft_rownew(x, y, ft_atoi(tmp), ft_atoh(tmp)));

		if (!jump(tmp))
		{
			y++;
			x = 0;
			tmp = get_next_line(fd);
		}
		else
		{
			x++;
			tmp = jump(tmp) + 1;
		}
	}
	//write(1, "nigga", 5);
	close (fd);
	return (res);
}
