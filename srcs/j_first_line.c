/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_first_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:03:24 by junkang           #+#    #+#             */
/*   Updated: 2020/02/11 16:53:13 by junkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

int		ft_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		char_check(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
			return (1);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_atoi(char *b_str, int len)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < len - 3)
	{
		res = res * 10 + (b_str[i] - '0');
		i++;
	}
	return (res);
}

int		first_line(char *str, t_map_info *info)
{
	int		i;
	int		len;
	char	*b_str;

	b_str = str;
	len = ft_len(str);
	if (len < 4)
		return (1);
	else if (*str < '1' || *str > '9')
		return (1);
	str++;
	i = 1;
	while (i++ < len - 3)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	if (char_check(str))
		return (1);
	info->max_row = ft_atoi(b_str, len);
	info->word[0] = *str++;
	info->word[1] = *str++;
	info->word[2] = *str;
	return (0);
}
