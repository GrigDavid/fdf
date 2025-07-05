/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rowadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:01:18 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/07/05 17:12:33 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_rowadd_back(t_row **row, t_row *new)
{
	if (!new)
		return ;
	if (!*row)
		*row = new;
	else
		ft_rowlast(*row)->next = new;
}
