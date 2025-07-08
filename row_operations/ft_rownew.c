/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rownew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:09:19 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/07/08 13:18:11 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_row	*ft_rownew(int x, int y, int z, int color)
{
	t_row	*row;

	row = (t_row *)malloc(sizeof(t_row));
	if (!row)
		return (NULL);
	row->x = x;
	row->y = y;
	row->z = z;
	row->color = color;
	row->next = NULL;
	return (row);
}
