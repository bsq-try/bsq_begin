/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:44:25 by junkang           #+#    #+#             */
/*   Updated: 2020/02/12 14:20:36 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

int		is_argv(char *file_name, t_map_info info)
{
	char			*map_char;
	int				**map_int;

	map_char = one_d_array_f(file_name, &info);
	if (map_char[0] == 0)
	{
		write(1, "map error\n", 10);
		free(map_char);
		return (1);
	}
	map_int = char_to_int_map(map_char, &info, 0, 0);
	free(map_char);
	if (info.max_col == 0)
	{
		j_free(map_int, info.max_row);
		write(1, "map error\n", 10);
		return (2);
	}
	dynamic(map_int, &info);
	print_map(map_int, info);
	j_free(map_int, info.max_row);
	return (0);
}

int		main(int argc, char *argv[])
{
	int				i;
	t_map_info		info;

	i = 1;
	while (i < argc)
	{
		is_argv(argv[i], info);
		i++;
	}
	return (0);
}
