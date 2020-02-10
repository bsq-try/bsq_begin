/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joockim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:00:23 by joockim           #+#    #+#             */
/*   Updated: 2020/02/10 18:50:16 by joockim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

int		box_check(int i, int j, t_map_info info)
{
	int		i_min;
	int		i_max;
	int		j_min;
	int		j_max;

	i_min = info.row - info.val + 1;
	i_max = info.row;
	j_min = info.col - info.val + 1;
	j_max = info.col;
	if (i >= i_min && i <= i_max && j >= j_min && j <= j_max)
		return (1);
	return (0);
}

void	print_map(int **map, t_map_info info)
{
	int i;
	int j;

	i = 0;
	while (i <= max_col)
	{
		j = 0;
		while (j <= max_row)
		{
			if (map[i][j] == 0)
				ft_putchar(info.word[1]);
			else if (box_check(i, j, info))
				ft_putchar(info.word[2]);
			else
				ft_putchar(info.word[0]);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
	write(1, "\n", 1);
}