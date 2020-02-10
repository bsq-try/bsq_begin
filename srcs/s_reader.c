/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_reader.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:22:54 by sseo              #+#    #+#             */
/*   Updated: 2020/02/10 19:32:31 by junkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

void		check_map_info(char *file_name, t_map_info )
{
	int					fd;
	char				condition[4];
	char				a;
	static t_map_info	out;

	out.row = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (out);
	
	read(fd, condition, 4);


int		*ont_d_array_make(char *file_name)
{
	static t_map_info	row_col;
	int					fd;
	char				a;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		

int		**two_d_array_make(char *one_d_array, int idx, int idx_r, int idx_c)
{
	int				**out;

	out = (int **)malloc(sizeof(int *) * row_col.row);
	while (idx_r < row_col.row)
	{
		out[idx_r] = (int *)malloc(sizeof(int) * row_col.col);
		idx_c = 0;
		while (idx_c < row_col.col)
		{
			out[idx_r][idx_c] = one_d_array[idx];
			idx_c++;
			idx++;
		}
		idx++;
		idx_r++;
	}
	free(one_d_array);
	return (out);
}

int		**reader_control(char *file_name)
{
	int				*one_d_array;
	int				**out;

	one_d_array = one_d_array_make(file_name);
	if (row_col.row == 0)
		/*error*/
	else
	{
		out = two_d_array_make(one_d_array, 0);
		return (out);
	}
}
