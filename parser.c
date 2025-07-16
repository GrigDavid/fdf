#include "fdf.h"

/*int	ft_print_hex(unsigned long n, int up)
{
	char	*set;

	set = "ABCDEF";
	if (n < 10)
		return (ft_printnbr(n));
	else if (up == 0)
		return (ft_printchar(set[n - 10] + 32));
	return (ft_printchar(set[n - 10]));
}

int	ft_print_x(unsigned long n, int up)
{
	if (n < 16)
		return (ft_print_hex(n, up));
	return (ft_print_x(n / 16, up) + ft_print_hex(n % 16, up));
}*/

int	ft_atoh(char *str, char *set)
{
	char	*tmp;

	tmp = ft_strchr(set, *str);
	if (!tmp)
		return (0xfffff);
	if (!*(str + 1))
		return (tmp - set);
	return ((tmp - set) * 10 + ft_atoh(str + 1, set));
}

int	get_hex(char *str)
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
/*
int	ft_atoh(char *str)
{
	// int	res;
	// int	i;

	if (!ft_strchr(str, ','))
		return (0xffffff); ///////////////////here will be coloring function in the future
	return (0xffffff);     ///////////////////here will be str to hex converting function
}*/

char	*jump(char *str)
{
	while (*str && (*str != ' ' || *(str + 1) == ' '))
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
	//char	*tmp_cpy;
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
	//ft_printf("yep... that's an issue");
	while (tmp)
	{
		ft_rowadd_back(&res, ft_rownew(x, y, ft_atoi(tmp), get_hex(tmp)));
		//ft_printf("inch ka%d - %d\n", x, y);
		if (!jump(tmp))
		{
			y++;
			x = 0;
			tmp = get_next_line(fd);
		}
		else
		{
			x++;
			tmp = jump(tmp);
		}
	}
	close (fd);
	return (res);
}
