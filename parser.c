#include "fdf.h"

char	*join_hopar(char *str1, char *str2)
{
	char	*tmp;

	if (!str1)
	{
		tmp = ft_strdup(str2);
		free(str2);
		return (tmp);
	}
	tmp = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	return (tmp);
}

int	hex_to_num(char *n)
{
	while ()
}

int	is_zero(char *str);
{
	while (*str == '-' || str == '+')
		str++;
	if (*str != 0)
		return (0);
	return (1);
}

char	**parser(char *name)
{
	int		fd;
	char	*str;
	char	**res;
	char	*tmp;
	char	**tmp_mat;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	tmp = get_next_line(fd);
	if (!tmp)
		return (NULL);
	while (tmp)
	{
		str = join_hopar(str, tmp);
		if (!str)
			return (NULL);
		tmp = get_next_line(fd);
	}
	
	res = ft_split(str, '\n');
	free(str);
	if (!res)
		return (NULL);
	tmp_mat = res;
	while (*tmp_mat)
	{
		if (!ft_atoi(*tmp_mat) && !is_zero(*tmp_mat))
			return (ft_free_mat(res), NULL);
		tmp_mat++;
	}
	return (res);
}