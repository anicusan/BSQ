/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squares.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anicusan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 19:50:48 by anicusan          #+#    #+#             */
/*   Updated: 2016/07/26 23:59:58 by anicusan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaggerissimo.h"

void	min(int **s, int i, int j, int *max)
{
	if (s[i + 1][j] <= s[i + 1][j + 1] && s[i + 1][j] <= s[i][j + 1])
		s[i][j] = s[i + 1][j] + 1;
	else if (s[i + 1][j + 1] <= s[i + 1][j] && s[i + 1][j + 1] <= s[i][j + 1])
		s[i][j] = s[i + 1][j + 1] + 1;
	else if (s[i][j + 1] <= s[i + 1][j + 1] && s[i][j + 1] <= s[i + 1][j])
		s[i][j] = s[i][j + 1] + 1;
	if (s[i][j] >= max[0])
	{
		max[0] = s[i][j];
		max[1] = i;
		max[2] = j;
	}
}

void	display(int **s, int *max, char *infoc, int *nrlc)
{
	int i;
	int j;

	i = 0;
	while (i < nrlc[0])
	{
		j = 0;
		while (j < nrlc[1])
		{
			if (i >= max[1] && i < max[1] + max[0] &&
					j >= max[2] && j < max[2] + max[0])
				ft_putchar(infoc[2]);
			else if (s[i][j])
				ft_putchar(infoc[0]);
			else
				ft_putchar(infoc[1]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	squares(int *nrlc, char *infoc, int **s)
{
	int i;
	int j;
	int max[3];

	i = nrlc[0] - 1;
	max[0] = 0;
	while (i >= 0)
	{
		j = nrlc[1] - 1;
		while (j >= 0)
		{
			if (s[i][j] == -1)
				min(s, i, j, max);
			j--;
		}
		i--;
	}
	display(s, max, infoc, nrlc);
}
