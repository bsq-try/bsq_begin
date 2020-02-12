/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   y_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:04:50 by youlee            #+#    #+#             */
/*   Updated: 2020/02/12 14:16:00 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

int			**make_imap(t_map_info *info)
{
	int		idx;
	int		**imap;

	idx = 0;
	imap = (int **)malloc(sizeof(int *) * info->max_row + 1);
	while (idx < info->max_row)
	{
		imap[idx] = (int *)malloc(sizeof(int *) * (info->max_col + 1));
		idx++;
	}
	return (imap);
}

int			mark_one(int **imap, t_map_info *info)
{
	int		idx;
	int		sub_idx;

	idx = 0;
	while (idx < info->max_row)
	{
		sub_idx = 0;
		while (sub_idx < info->max_col)
		{
			if (imap[idx][sub_idx] == 1)
			{
				info->val = 1;
				info->row = idx;
				info->col = sub_idx;
				return (0);
			}
			sub_idx++;
		}
		idx++;
	}
	return (1);
}

int			**char_to_int_map(char *cmap, t_map_info *info, int i, int j)
{
	int		index2;
	int		**imap;

	imap = make_imap(info);
	while (i < info->max_row)
	{
		index2 = 0;
		while (index2 < info->max_col)
		{
			if (cmap[j] == info->word[0])
				imap[i][index2] = 1;
			else if (cmap[j] == info->word[1])
				imap[i][index2] = 0;
			else if (cmap[j] == '\n')
				index2--;
			else
				info->max_col = 0;
			index2++;
			j++;
		}
		i++;
	}
	if (mark_one(imap, info))
		info->max_col = 0;
	return (imap);
}
