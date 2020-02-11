/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   y_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:04:50 by youlee            #+#    #+#             */
/*   Updated: 2020/02/11 21:47:22 by junkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//char *map 을 int ** map 으로 바꾸어주는 작업.

#include "../includes/ft_bsq.h"
#include <stdio.h>
int	**char_to_int_map(char *cmap, t_map_info *info)
{
	int index;
	int index2;
	int index3;
	int **imap;

	index3 = 0;
	imap = (int **)malloc(sizeof(int *) * (info->max_row));
	index = 0;
	while (index < info->max_row)
	{
		index2 = 0;
		imap[index] = (int *)malloc(sizeof(int *) * (info->max_col));
		while (index2 < info->max_col)
		{
			if (cmap[index3] == info->word[0])
				imap[index][index2] = 1;
			else if (cmap[index3] == info->word[1])
				imap[index][index2] = 0;
			index2++;
			index3++;
		}
		index++;
	}
	for(int i=0;i<index;i++)
	{
		for(int j=0;j<index2;j++)
			printf("%d ",imap[i][j]);
		printf("\n");
	}
	free(cmap);
	return (imap);
}
