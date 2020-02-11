/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:32:21 by sseo              #+#    #+#             */
/*   Updated: 2020/02/11 18:49:58 by sseo             ###   ########.fr       */
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

char				*partial(char *str, unsigned int start, unsigned int end);

int					ft_len(char *str);
int					char_check(char *str);
int					ft_atoi(char *b_str, int len);
int					first_line(char *str, t_map_info *info);


#endif
