/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:32:21 by sseo              #+#    #+#             */
/*   Updated: 2020/02/12 19:52:24 by joockim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_map_info
{
	int			max_row;
	int			max_col;
	int			row;
	int			col;
	int			val;
	char		word[3];
}				t_map_info;

int				ft_len(char *str);
int				char_check(char *str);
int				ft_atoi(char *b_str, int len);
int				first_line(char *str, t_map_info *info);
void			j_free(int **map, int max_row);
void			ft_putchar(char a);
int				box_check(int i, int j, t_map_info info);
void			print_map(int **map, t_map_info info);
unsigned int	get_len_to_sep(char *str, char sep, unsigned int start);
char			*partial(char *str, unsigned int start, unsigned int end);
unsigned int	get_total_len(char *file_name);
char			*make_one_d_array(char *file_name, unsigned int len);
int				check_board(char *board, t_map_info *info);
char			*one_d_array_f(char *file_name, t_map_info *info);
int				mark_one(int **imap, t_map_info *info);
int				**make_imap(t_map_info *info);
int				**char_to_int_map(char *cmap, t_map_info *info, int i, int j);
void			checkmax(int row, int col, int val, t_map_info *info);
int				minn(int a, int b);
void			dynamic(int **map, t_map_info *info);
char			*newline_to_null(char *str);
int				is_argv(char *file_name);

#endif
