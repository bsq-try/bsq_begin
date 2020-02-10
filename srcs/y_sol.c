/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   y_sol.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:34:44 by youlee            #+#    #+#             */
/*   Updated: 2020/02/10 19:19:51 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"
#include <stdio.h>
void	checkmax(int row, int col, int val, t_map_info *info)
{
	if (val > info -> val)
	{
		info -> row = row;
		info -> col = col;
		info -> val = val;
	}
	printf("info.val : %d\n",info -> val);
}

int		minn(int a,int b)
{
	if (a > b)
		return b;
	else
		return a;
}

void	dynamic(int (*map)[10], t_map_info *info)
{
	int idx;
	int idx2;

	idx = 1;
	idx2 = 1;
	while (idx < info -> max_row)
	{
		while (idx2 < info -> max_col)
		{
			if (map[idx][idx2] != 0)
			{
				map[idx][idx2] = minn(map[idx-1][idx2], map[idx][idx2-1]);
				map[idx][idx2] = minn(map[idx][idx2] , map[idx-1][idx2-1]);
				map[idx][idx2]++;
			}
			checkmax(idx, idx2, map[idx][idx2], info);
			idx2++;
		}
		idx2 = 0;
		idx++;
	}
}
int main(void)
{
	int ar[10][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1}	
	};
	t_map_info st;
	st.max_row = 10;
	st.max_col = 10;
	dynamic(ar, &st);
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			printf("%d ",ar[i][j]);
		}
		printf("\n");
	}
	printf("st val : %d\n st row : %d\n st col : %d\n",st.val,st.row,st.col);
}
