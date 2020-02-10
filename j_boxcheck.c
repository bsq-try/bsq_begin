/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_boxcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:13:05 by junkang           #+#    #+#             */
/*   Updated: 2020/02/10 18:30:47 by junkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		box_check(int i, int j, t_map_info info)
{
	int		i_min;
	int		i_max;
	int		j_min;
	int		j_max;

	i_min = info.row - info.val + 1;
	i_max = info.row;
	j_min = info.col - info.val + 1;
	j_max = info.col;
	if (i >= i_min && i <= i_max && j >= j_min && j <= j_max)
		return (1);
	return (0);
}
