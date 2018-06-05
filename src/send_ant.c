/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adibou <adibou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:39:42 by ccoupez           #+#    #+#             */
/*   Updated: 2018/06/05 12:26:49 by adibou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_remove_walk(t_walk **p_walks, t_walk *walks)
{
	t_walk *tmp;

	if (*p_walks == walks)
		*p_walks = walks->next;
	else
	{
		tmp = *p_walks;
		while (tmp->next != walks)
			tmp = tmp->next;
		tmp->next = walks->next;
	}
	free(walks);
}

void	ft_make_forward(t_data *data, t_walk **p_walks)
{
	t_walk *walks;
	t_walk *tmp;

	walks = *p_walks;
	while (walks)
	{
		printf("L%d-%s ", walks->ant, data->rooms[walks->myway->way[walks->i++]]->name);
		if (walks->i == walks->myway->len)
		{
			tmp = walks;
			walks = walks->next;
			ft_remove_walk(p_walks, tmp);
		}
		else
			walks = walks->next;
	}
	printf("\n");
}

t_bool	ft_add_ant(t_walk **walk, int nb, t_path *way)
{
	t_walk *to_add;
	t_walk *tmp;

	if (!(to_add = malloc(sizeof(t_walk))))
		return (FALSE);
	to_add->ant = nb;
	to_add->myway = way;
	to_add->i = 1;
	to_add->next = NULL;
	if (!(*walk))
		*walk = to_add;
	else
	{
		tmp = *walk;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = to_add;
	}
	return (TRUE);
}

int		ft_test(int i, int *max)
{
	int tab[2][3];

	tab[0][0] = i + 1;
	tab[0][1] = max[i];
	tab[0][2] = i + 1;
	tab[1][0] = i+ 2;
	tab[1][1] = max[i + 1];
	tab[1][2] = i + 2;
	while (tab[0][1] < tab[1][1])
	{
		tab[0][0] += tab[0][2];
		tab[0][1]++;
	}
	//	ft_putnbrendl(tab[0][0]);
	/*while (tab[1][0] < tab[0][0])
	{
		ft_putendl("");
		ft_putnbrendl(tab[0][1]);
		tab[0][0] += tab[0][2];
		ft_putnbrendl(tab[0][0]);
		tab[1][0] += tab[1][2];
		ft_putnbrendl(tab[1][0]);
		tab[0][1]++;
		ft_putnbrendl(tab[0][1]);
		tab[1][1]++;
		ft_putnbrendl(tab[1][1]);
	}*/
	return (tab[0][0]);
}
/*
4 / 5 / 6 / 7 / 8 / 9 / 10 / 11 / 12 / 13 / 14 / 15

1 / 2 / 3 / 4 / 5 / 6 /  7 /  8 /  9 / 10 / 11 / 12
                    2 /  4 /  6 /  8 / 10 /12 /
*/

int		*ft_return_when(t_path ***way, int nb_way)
{
	int max[nb_way];
	int	*tab;
	int i;
	int j;

	i = 0;
	while (i < nb_way)
		max[i++] = 0;
	i = 0;
	if (!(tab = malloc(sizeof(int) * nb_way - 1)))
		return (NULL);
	while (way[i])
	{
		j = 0;
		while (way[i][j])
		{
			if (way[i][j]->len > max[i])
				max[i] = way[i][j]->len;
			j++;
		}
		i++;
	}
	i = 0;
	while (way[i + 1])
	{
		tab[i] = ft_test(i , max);
		ft_putnbrendl(tab[i]);
		i++;
	}
	return (tab);
}

int		*ft_create_opti_tab(t_path ***ways)
{
	int i;

	i = 0;
	while (ways[i])
		i++;
	return (ft_return_when(ways, i));
}

int		ft_check_opti_way(int nb_ant, t_path ***ways)
{
	static int	*tab = NULL;
	int			i;

	i = 0;
	if (!tab)
		tab = ft_create_opti_tab(ways);
	while (ways[i + 1] && nb_ant >= tab[i])
	{
		i++;
	}	
	return (i);
}

t_bool   send_ant(t_path ***back, t_data *graph)
{
	int		opti_ways;
	int		i;
	int		num_ant;
	t_walk	*walks;

	walks = NULL;
	num_ant = 0;
	while (num_ant < graph->nb_ant)
	{
		opti_ways = ft_check_opti_way(graph->nb_ant - num_ant, back);
		i = 0;
		while (i <= opti_ways)
			ft_add_ant(&walks, ++num_ant, back[opti_ways][i++]);
		ft_make_forward(graph, &walks);
	}
	while (walks)
		ft_make_forward(graph, &walks);
	return (TRUE);
}