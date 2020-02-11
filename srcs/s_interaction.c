/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_interaction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:55:26 by sseo              #+#    #+#             */
/*   Updated: 2020/02/11 20:03:25 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				init_interaction(t_map_info *info)
{
	int			idx;
	char		init_info[1024];

	idx = 0;
	read(0, init_info, 1024);
	if(first_line(init_info, info))
		write(1, "Map Error\n", 10);
	else
	{
		while (idx
