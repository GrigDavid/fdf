/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:01:18 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/07/28 13:48:44 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_pointadd_back(t_point **point, t_point *new)
{
	if (!new)
		return ;
	if (!point)
		point = &new;
	if (!*point)
		*point = new;
	else
		ft_pointlast(*point)->next = new;
}
