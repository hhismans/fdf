/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getinfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 11:58:03 by hhismans          #+#    #+#             */
/*   Updated: 2014/11/27 00:58:44 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include "fdf.h"

static int		*filltab(char **tab_char)
{
	int size;
	int i;
	int *tab_int;

	size = 0;
	while (tab_char[size])
		size++;
	tab_int = (int *)ft_memalloc(sizeof(int) * (size + 1));
	tab_int[0] = size;
	i = 1;
	while (i < size + 1)
	{
		tab_int[i] = ft_atoi(tab_char[i - 1]);
		i++;
	}
	return (tab_int);
}

int		**getinfo(char *file)
{
	char *line;
	char **tab_char;
	int nbr_line;
	int i;
	int ret;
	int fd;
	int **tab_int;
	t_list *lst_line;
	t_list *tmp;

	nbr_line = 0;
	fd = open(file, O_RDONLY);
	if ((ret = get_next_line(fd, &line)))
	{
		lst_line = ft_lstnew(line, sizeof(char) * (ft_strlen(line) + 1));
		nbr_line++;
	}
	tmp = lst_line;
	while ((ret = get_next_line(fd, &line)))
	{
		tmp->next = ft_lstnew(line, sizeof(char) * (ft_strlen(line) + 1));
		tmp = tmp->next;
		nbr_line++;
	}
	close(fd);
	i = 0;
	tab_int = (int **)ft_taballoc(sizeof(int) * (nbr_line));
	tmp = lst_line;
	while (tmp)
	{
		tab_char = ft_strsplit((char *)tmp->content, ' ');
		tab_int[i] = filltab(tab_char);
		i++;
		tmp = tmp->next;
	}
	return(tab_int);
}

int		**convert_cavaliere(int **tab_int)
{
	int **tab_cav;
	int size;
	int i;
	int j;
	//t_point
	size = 0;
	while (tab_int[size])
		size++;
	i = 0;
	j = 0;
	tab_cav = (int **)ft_taballoc(sizeof(int) * (size + 1));
	while (tab_int[j])
	{
			ft_putendl("while EXTERNE");
		tab_cav[j] = (int *)ft_memalloc(tab_int[j][0] + 1);
		tab_cav[j][0] = tab_int[j][0];
		i = 1;
		while (i <= tab_int[j][0])
		{
			//ft_putendl("while interne");
			tab_cav[j][i] = (i - 1) + (35 * tab_int[j][i]);
			i++;
		}
		j++;
	}
	return (tab_cav);
}

int		main(int argc, char **argv)
{
	int **tab;
	int **tab_cav;
	int i;
	int j;

	j = 0;
	i = 0;
	tab = getinfo(argv[1]);
	while (tab[j])
	{
		i = 0;
		while (i <= tab[j][0])
		{
			ft_putnbr(tab[j][i]);
			ft_putstr("\t");
			i++;
		}
		ft_putendl("");
		j++;
	}
	i = 0;
	j = 0;
	ft_putendl("CONVERTI");
	tab_cav = convert_cavaliere(tab);
	ft_putendl("CONVERTI");
	while (tab_cav[j])
	{
		i = 0;
		while (i <= tab_cav[j][0])
		{
			ft_putnbr(tab_cav[j][i]);
			ft_putstr("\t");
			i++;
		}
		ft_putendl("");
		j++;
	}
	return (argc);
}
