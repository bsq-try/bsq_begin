/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:44:25 by junkang           #+#    #+#             */
/*   Updated: 2020/02/11 21:54:36 by junkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

int		main(int argc, char *argv[])
{
	t_map_info		info;
	int				i;
	int				**map;
	char			*map2;
	i = 1;
	while (i < argc)
	{
		map2 = one_d_array_f(argv[i], &info);
		map = char_to_int_map(map2, &info);
		dynamic(map, &info);
		print_map(map, info);
		j_free(map, info);
		i++;
	}
	return (0);
}
