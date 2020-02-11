/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_reader.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:22:54 by sseo              #+#    #+#             */
/*   Updated: 2020/02/11 21:54:39 by junkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

unsigned int		get_total_len(char *file_name)
{
	int				fd;
	unsigned int	cnt;
	unsigned int	lf_cnt;
	char			a;

	cnt = 0;
	lf_cnt = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (0);
	while (read(fd, &a, 1))
	{
		cnt++;
		if (a == '\n')
			lf_cnt++;
	}
	close(fd);
	if (lf_cnt < 2)
		return (0);
	return (cnt);
}

char				*make_one_d_array(char *file_name, unsigned int len)
{
	int				fd;
	unsigned int	idx;
	char			*out;
	char			a;
	unsigned int	col_cnt;

	idx = 0;
	out = (char *)malloc(sizeof(char) * (len + 1));
	if (len == 0)
	{
		out[0] = 0;
		return (out);
	}
	fd = open(file_name, O_RDONLY);
	while (idx < len)
	{
		read(fd, &a, 1);
		out[idx] = a;
		idx++;
	}
	close(fd);
	out[idx] = 0;
	return (out);
}

int					check_board(char *board, t_map_info *info)
{
	int				idx;
	int				row_cnt;

	idx = 0;
	row_cnt = 0;
	while (board[idx] != 0)
	{
		if (idx % info->col == 0 && idx != 0)
		{
			if (board[idx] != '\n')
				return (1);
			else
				row_cnt++;
		}
		idx++;
	}
	if (info->row != row_cnt)
		return (2);
	return (0);
}

char				*one_d_array_f(char *file_name, t_map_info *info)
{
	char			*temp;
	char			*map_head;
	char			*map_left;
	unsigned int	devided_point;
	unsigned int	len;

	len = get_total_len(file_name);
	temp = make_one_d_array(file_name, len);
	devided_point = get_len_to_sep(temp, '\n', 0);
	map_head = partial(temp, 0, devided_point);
	map_left = partial(temp, devided_point + 1, len);
	info->max_col = (int)get_len_to_sep(map_left, '\n', 0);
	free(temp);
	if (first_line(map_head, info) || check_board(map_left, info))
	{
		free(map_head);
		map_left[0] = 0;
		return (map_left);
	}
	free(map_head);
	return (map_left);
}
