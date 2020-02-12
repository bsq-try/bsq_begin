/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:44:25 by junkang           #+#    #+#             */
/*   Updated: 2020/02/12 15:39:34 by junkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

int		is_argv(char *file_name)
{
	char			*map_char;
	int				**map_int;
	t_map_info		info;

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

char	*newline_to_null(char *str)
{
	char	*res;

	res = str;
	while (*str != '\n')
		str++;
	*str = '\0';
	return (res);
}

int		main(int argc, char *argv[])
{
	int		i;
	char	file_name[10000];

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			is_argv(argv[i]);
			i++;
		}
	}
	else
	{
		while (1)
		{
			read(0, file_name, sizeof(file_name));
			is_argv(newline_to_null(file_name));
		}
	}
	return (0);
}
