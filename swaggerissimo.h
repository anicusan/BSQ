/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaggerissimo.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anicusan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 18:47:55 by anicusan          #+#    #+#             */
/*   Updated: 2016/07/27 22:14:07 by anicusan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAGGERISSIMO_H
# define SWAGGERISSIMO_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

void	init(int fd);
void	squares(int *nrlc, char *infoc, int **s);
void	printerror(int *potato);
int		ft_atoi(char *str, int fin, int *nrlc);
void	ft_putstrerr(char *str);
void	ft_putchar(char c);

#endif
