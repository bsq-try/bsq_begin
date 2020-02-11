/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   y_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:04:50 by youlee            #+#    #+#             */
/*   Updated: 2020/02/11 17:14:16 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	free_cmap(char **cmap, t_map_info info)
{
	int index;

	index = 0;
	while (index < info.max_row)
		free(cmap[index++]);
	free(cmap);
}

int	**char_to_int_map(char **cmap, t_map_info *info)
{
	int idx;
	int idx2;
	int **imap;

	imap = (int **)malloc(sizeof(int *) * (info -> max_row));
	idx = 0;
	while (idx < info -> max_row)
	{
		idx2 = 0;
		imap[idx] = (int *)malloc(sizeof(int *) * (info -> max_col));
		while (idx2 < info -> max_col)
		{
			if (cmap[idx][idx2] == info -> word[0])
				imap[idx][idx2] = 1;
			else if(cmap[idx][idx2] == info -> word[1])
				imap[idx][idx2] = 0;
			idx2++;
		}
		idx++;
	}
	free_cmap(cmap, info);
	return (imap);
}
