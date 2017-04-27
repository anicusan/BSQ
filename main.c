/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anicusan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 18:43:16 by anicusan          #+#    #+#             */
/*   Updated: 2016/07/27 22:50:22 by anicusan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaggerissimo.h"
#include <stdio.h>

void	printerror(int *potato)
{
	ft_putstrerr("map error\n");
	*potato = 42;
}

int		pathfd(char *s)
{
	return (open(s, O_RDONLY));
}

int		main(int argc, char **argv)
{
	int i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			init(pathfd(argv[i]));
			i++;
		}
	}
	else
		init(0);
	return (0);
}
