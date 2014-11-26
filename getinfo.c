/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getinfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 11:58:03 by hhismans          #+#    #+#             */
/*   Updated: 2014/11/26 23:41:55 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

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
		ft_putstr("contenu de line:");
		ft_putendl(line);
		lst_line = ft_lstnew(line, sizeof(char) * (ft_strlen(line) + 1));
		ft_putstr("contenu de lst_line->content:");
		ft_putendl(lst_line->content);
		nbr_line++;
	}
	tmp = lst_line;
	while ((ret = get_next_line(fd, &line)))
	{
		ft_putstr("contenu de line ; ");
		ft_putendl(line);
		tmp->next = ft_lstnew(line, sizeof(char) * (ft_strlen(line) + 1));
		tmp = tmp->next;
		ft_putstr("contenu de tmp->content ; ");
		ft_putendl(tmp->content);
		nbr_line++;
	}
	close(fd);
	i = 0;
	tab_int = (int **)ft_taballoc(sizeof(int) * (nbr_line));
	tmp = lst_line;
	ft_putstr("contenu de tmp->content  @; ");
	ft_putendl(tmp->next->content);
	while (tmp)
	{
		ft_putstr("tmp content debut : ");
		ft_putendl(tmp->content);
		tab_char = ft_strsplit((char *)tmp->content, ' ');
		ft_putendl("ANALYSE TABCHAR");
			int t = 0;
			while (tab_char[t])
			{
			ft_putstr("elem :");
			ft_putendl(tab_char[t]);
		t++;
		}
		tab_int[i] = filltab(tab_char);
		i++;
		tmp = tmp->next;
		//ft_putendl(tmp->content);
	}
	//ft_lstdel(&lst_line);
	return(tab_int);
}

int		main(int argc, char **argv)
{
	int **tab;
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
			ft_putstr(" ");
			i++;
		}
		ft_putendl("");
		j++;
	}
	return (argc);
}
