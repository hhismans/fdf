/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getinfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 11:58:03 by hhismans          #+#    #+#             */
/*   Updated: 2014/11/24 23:17:48 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static int		*filltab(char *tab_char)
{
	int size;
	int i;
	int *tab_int;

	size = 0;
	while (tab_char[size])
		size++;
	ft_memalloc(sizeof(int) * (size + 1));
	tab_int[0] = size;
	i = 1;
	while (i < size + 1)
	{
		tab_int[i] = ft_itoa(tab[i - 1]);
		i++;
	}
}

int		**getinfo(char *file)
{
	char *line;
	char **tab;
	int nbr_line;
	int i;
	int ret;
	int fd;
	int **tab_int;

	nbr_line++;
	fd = open(file, ORDONLY);
	while ((ret = get_next_line(fd, &line)))
		nbr_line++;
	close(fd);
	fd = open(file, ORDONLY);
	i = 0;
	tab_int = taballoc(sizeof(int) * (nbr_line));
	while ((ret = get_next_line(fd ,&line)))
	{
		ft_strsplit(line);
		tab_int[i] = filltab(tab_char);
	}

}
