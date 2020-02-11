/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   y_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:04:50 by youlee            #+#    #+#             */
/*   Updated: 2020/02/11 20:30:59 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//char *map 을 int ** map 으로 바꾸어주는 작업.

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
			if (cmap[index][index2] == info->word[0])
				imap[index3] = 1;
			else if (cmap[index][index2] == info->word[1])
				imap[index3] = 0;
			index2++;
			index3++;
		}
		index++;
	}
	free(cmap);
	return (imap);
}
