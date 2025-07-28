/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:57:51 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/07/28 13:51:01 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_pointclear(t_point **point)
{
	t_point	*p;

	if (!*point)
		return ;
	while (*point)
	{
		p = (*point)->next;
		ft_pointdelone(*point);
		*point = p;
	}
	*point = NULL;
}
