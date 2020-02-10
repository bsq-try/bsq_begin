/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:32:21 by sseo              #+#    #+#             */
/*   Updated: 2020/02/10 18:47:08 by junkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct		s_map_info
{
	int				max_row;
	int				max_col;
	int				row;
	int				col;
	int				val;
	char			word[3]; /*빈문자 장애물 마킹*/
}					t_map_info;

#endif
