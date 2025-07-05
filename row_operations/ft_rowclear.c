/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:57:51 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/07/05 15:54:52 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_rowclear(t_row **row)
{
	t_row	*p;

	if (!*row)
		return ;
	while (*row)
	{
		p = (*row)->next;
		ft_rowdelone(*row);
		*row = p;
	}
	*row = NULL;
}
