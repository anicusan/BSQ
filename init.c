/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anicusan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 18:50:45 by anicusan          #+#    #+#             */
/*   Updated: 2016/07/27 23:12:57 by anicusan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaggerissimo.h"

void	info(int fd, char *infoc, int *nrlinii)
{
	char	*line1;
	int		i;

	if (fd < 0)
		printerror(&nrlinii[3]);
	i = 0;
	line1 = (char*)malloc(sizeof(char) * 1000);
	if (nrlinii[3] != 42)
		read(fd, line1, 1);
	while (line1[i] != '\n' && nrlinii[3] != 42)
	{
		i++;
		read(fd, line1 + i, 1);
	}
	if (nrlinii[3] != 42)
	{
		infoc[2] = line1[--i];
		infoc[1] = line1[--i];
		infoc[0] = line1[--i];
	}
	if ((infoc[2] == infoc[1] || infoc[2] == infoc[0] ||
			infoc[1] == infoc[0]) && nrlinii[3] != 42)
		printerror(&nrlinii[3]);
	nrlinii[0] = ft_atoi(line1, (i - 1), nrlinii);
	free(line1);
}

void	saloc(int **s, int *nrlc)
{
	if (nrlc[2] == 0)
		s[nrlc[2]] = (int*)malloc(sizeof(int) * 1003);
	else
		s[nrlc[2]] = (int*)malloc(sizeof(int) * nrlc[1] + 2);
}

void	wrline(int **s, int *nrlc, int *fd, char *infoc)
{
	int		i;
	char	c;

	i = 0;
	saloc(s, nrlc);
	if (read(*fd, &c, 1) == 0)
		nrlc[3] = 42;
	while (c != '\n' && nrlc[3] != 42)
	{
		if (c == infoc[0])
			s[nrlc[2]][i] = -1;
		else if (c == infoc[1])
			s[nrlc[2]][i] = 0;
		else
			nrlc[3] = 42;
		if (nrlc[3] != 42)
			if (read(*fd, &c, 1) == 0)
				nrlc[3] = 42;
		i++;
	}
	s[nrlc[2]][i] = 0;
	if (nrlc[2] == 0 && i != 0 && nrlc[3] != 42)
		nrlc[1] = i;
	else if (nrlc[3] == 42 || nrlc[1] != i || i == 0)
		printerror(&nrlc[3]);
}

void	wrlast(int **s, int *nrlc, int *fd)
{
	int		i;
	char	c;

	i = 0;
	s[nrlc[2]] = (int*)malloc(sizeof(int) * 2000);
	while (i <= nrlc[1])
	{
		s[nrlc[0]][i] = 0;
		i++;
	}
	if (*fd != 1 && read(*fd, &c, 1) != 0)
		printerror(&nrlc[3]);
}

void	init(int fd)
{
	char	infoc[3];
	int		**s;
	int		nrlc[4];

	nrlc[3] = 0;
	info(fd, infoc, nrlc);
	s = (int**)malloc(sizeof(int*) * nrlc[0] + 3);
	nrlc[2] = 0;
	if (nrlc[0] == 0 && nrlc[3] != 42)
		printerror(&(nrlc[3]));
	while (nrlc[2] < nrlc[0] && nrlc[3] != 42)
	{
		wrline(s, nrlc, &fd, infoc);
		nrlc[2]++;
	}
	if (nrlc[3] != 42)
		wrlast(s, nrlc, &fd);
	if (nrlc[3] != 42)
		squares(nrlc, infoc, s);
	nrlc[1] = 0;
	while ((nrlc[1] < nrlc[2] && nrlc[3] == 42) ||
			(nrlc[1] <= nrlc[2] && nrlc[3] != 42))
		free(s[nrlc[1]++]);
	free(s);
}
