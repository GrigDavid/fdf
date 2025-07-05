/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:09:19 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/07/05 15:47:47 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_row	*ft_rownew(int *height, int *color, int len)
{
	t_row	*row;

	row = (t_row *)malloc(sizeof(t_row));
	if (!row)
		return (NULL);
	row->height = height;
	row->color = color;
	row->len = len;
	row->next = NULL;
	return (row);
}
