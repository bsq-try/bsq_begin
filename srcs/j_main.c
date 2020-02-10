/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:44:25 by junkang           #+#    #+#             */
/*   Updated: 2020/02/10 20:59:11 by junkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

int main(void)
{
	t_map_int_info	info;
	int				i;
	int				**map;

	i = 1;
	while (i < argc)
	{
		map = reader_control(argv[i], &info);
		dynamic(map, &info);
		print_map(map, info);
		j_free(map, info);
		i++;
	}
	return (0);
}
