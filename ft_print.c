/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 20:55:30 by cvictor           #+#    #+#             */
/*   Updated: 2016/07/27 23:04:07 by anicusan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaggerissimo.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putcharerr(char c)
{
	write(2, &c, 1);
}

void	ft_putstrerr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putcharerr(str[i]);
		i++;
	}
}

int		ft_atoi(char *str, int fin, int *nrlc)
{
	int x;
	int i;

	x = 0;
	i = 0;
	if (str[i] >= '0' && str[i] <= '9')
	{
		while (str[i] == '0')
			i++;
		while (str[i] >= '0' && str[i] <= '9' && i <= fin)
		{
			x = x * 10 + (str[i] - '0');
			i++;
		}
		if (i <= fin)
			if (nrlc[3] != 42)
				printerror(&nrlc[3]);
	}
	else if (nrlc[3] != 42)
		printerror(&nrlc[3]);
	return (x);
}
