#include "fdf.h"

void	ft_free_mat(char **arr)
{
	int	j;

	j = 0;
	while (arr[j])
	{
		free(arr[j]);
		j++;
	}
	free(arr);
}

int	is_zero(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str != 0)
		return (0);
	return (1);
}

int	ft_atoh(char *str)
{
	// int	res;
	// int	i;

	if (!ft_strchr(str, ','))
		return (0xffffff); ///////////////////here will be coloring function in the future
	return (0xffffff);     ///////////////////here will be str to hex converting function
}

t_row	*gen_row(char **mat)
{
	int	len;
	int	*height;
	int	*color;
	int	i;

	len = 0;
	while (mat[len])
		len++;
	height = (int *)malloc(len * sizeof(int));
	if (!height)
		return (NULL);
	color = (int *)malloc(len * sizeof(int));
	if (!color)
		return (free(height), NULL);
	i = 0;
	while (i < len)
	{
		height[i] = ft_atoi(mat[i]); //for now, I'm not checking wether the map is valid, if its not, the element is just set to 0 
		color[i] = ft_atoh(mat[i]);  //this function is not done and for now just returns white
		i++;
	}
	return (ft_rownew(height, color, len));
}

t_row	*parser(char *name)
{
	int		fd;
	t_row	*res;
	t_row	*row;
	char	*tmp;
	char	**mat;

	res = NULL;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	tmp = get_next_line(fd);
	if (!tmp)
		return (NULL);
	while (tmp)
	{
		mat = ft_split(tmp, ' ');
		free(tmp);
		if (!mat)
			return (ft_rowclear(&res), NULL);
		row = gen_row(mat);
		if (!row)
			return (ft_rowclear(&res), NULL);
		ft_rowadd_back(&res, row);
		tmp = get_next_line(fd);
	}
	close (fd);
	return (res);
}

/*

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
}*/