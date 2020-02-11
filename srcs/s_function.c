/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_function.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:23:19 by sseo              #+#    #+#             */
/*   Updated: 2020/02/11 19:53:02 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

unsigned int	get_len_to_sep(char *str, char sep, unsigned int start)
{
	unsigned int	idx;

	idx = 0;
	while (str[start + idx] != 0 && str[start + idx] != sep)
		idx++;
	return (idx);
}

char		*partial(char *str, unsigned int start, unsigned int end)
{
	char			*out;
	unsigned int	idx;
	unsigned int	len;

	idx = 0;
	len = end - start;
	if (end == 0)
	{
		out = (char *)malloc(sizeof(char));
		out[0] = 0;
		return (out);
	}
	out = (char *)malloc(sizeof(char) * (len + 1));
	while (idx < len)
	{
		out[idx] = str[start + idx];
		idx++;
	}
	out[idx] = 0;
	return (out);
}
