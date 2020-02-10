/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:32:21 by sseo              #+#    #+#             */
/*   Updated: 2020/02/10 17:43:41 by sseo             ###   ########.fr       */
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
	char			e; /*빈문자*/
	char			o; /*장애물*/
	char			x; /*마킹*/
}					t_map_info;

#endif
