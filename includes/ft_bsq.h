/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:32:21 by sseo              #+#    #+#             */
/*   Updated: 2020/02/12 15:42:41 by junkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_map_info
{
	int			max_row;
	int			max_col;
	int			row;
	int			col;
	int			val;
	char		word[3];		/*빈문자 장애물 마킹*/
}				t_map_info;

/*	j_first_line.c	*/
int				ft_len(char *str);
int				char_check(char *str);
int				ft_atoi(char *b_str, int len);
int				first_line(char *str, t_map_info *info);
/*	j_free.c	*/
void			j_free(int **map, int max_row);
/*	jc_make.c	*/
void			ft_putchar(char a);
int				box_check(int i, int j, t_map_info info);
void			print_map(int **map, t_map_info info);
/*	s_function.c	*/
unsigned int	get_len_to_sep(char *str, char sep, unsigned int start);
char			*partial(char *str, unsigned int start, unsigned int end);
/*	s_reader.c	*/
unsigned int	get_total_len(char *file_name);
char			*make_one_d_array(char *file_name, unsigned int len);
int				check_board(char *board, t_map_info *info);
char			*one_d_array_f(char *file_name, t_map_info *info);
/*	y_convert.c	*/
int				mark_one(int **imap, t_map_info *info);
int				**make_imap(t_map_info *info);
int				**char_to_int_map(char *cmap, t_map_info *info, int i, int j);
/*	y_sol.c	*/
void			checkmax(int row, int col, int val, t_map_info *info);
int				minn(int a, int b);
void			dynamic(int **map, t_map_info *info);
/*	j_main.c	*/
char			*newline_to_null(char *str);
int				is_argv(char *file_name);

#endif
