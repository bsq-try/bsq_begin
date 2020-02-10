/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   y_sol.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:34:44 by youlee            #+#    #+#             */
/*   Updated: 2020/02/10 21:04:42 by junkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

void	checkmax(int row, int col, int val, t_map_info *info)
{
	if (val > info->val)
	{
		info->row = row;
		info->col = col;
		info->val = val;
	}
}

int		minn(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

void	dynamic(int (*map)[10], t_map_info *info)
{
	int idx;
	int idx2;

	idx = 1;
	idx2 = 1;
	while (idx < info->max_row)
	{
		while (idx2 < info->max_col)
		{
			if (map[idx][idx2] != 0)
			{
				map[idx][idx2] = minn(map[idx - 1][idx2], map[idx][idx2 - 1]);
				map[idx][idx2] = minn(map[idx][idx2], map[idx - 1][idx2 - 1]);
				map[idx][idx2]++;
			}
			checkmax(idx, idx2, map[idx][idx2], info);
			idx2++;
		}
		idx2 = 1;
		idx++;
	}
}
