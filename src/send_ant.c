/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:39:42 by ccoupez           #+#    #+#             */
/*   Updated: 2018/06/05 17:08:46 by ccoupez          ###   ########.fr       */
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

int		ft_test(int i, int *max, int prev)
{
	int nb_pass;
	int by_turn;

	by_turn = i + 1;
	nb_pass = prev + by_turn;
	while (max[i] < max[i + 1])
	{
		nb_pass += by_turn;
		max[i]++;
	}
	return (nb_pass);
}
/*
 1 /  2 /  3 /  4 /  5 /  6 /  7 /  8 /  9 / 10 / 11 / 12 / 13 / 14 / 15

 2 /  2 /  2 /  1 /  1 /  1 /  1

		        1 /  2 /  3 /  4 /  5 /  6 /  7 /  8 /  9 / 10 / 11 / 12 -  6     7
                                         2 /  4 /  6 /  8 / 10 / 12 /    -  11   12
								                   3 /  6 /  9 / 12      -  15   16
										                4 /  8 / 12   
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
		//printf("-----------return_when\n");
		tab[i] = ft_test(i, max, i == 0 ? 1 : tab[i - 1] - i);
		ft_putnbrendl(tab[i]);
		i++;
	}
	return (tab);
}

int		*ft_create_opti_tab(t_path ***ways)
{
	int i;

	i = 0;
	while (ways[i]) // on va la ou il y a le plus de chemin
		i++;
	//printf("i creat opti tab %d\n", i);
	return (ft_return_when(ways, i));
}

int		ft_check_opti_way(int nb_ant, t_path ***ways)
{
	static int	*tab = NULL;
	int			i;

	i = 0;
	if (!tab)
		tab = ft_create_opti_tab(ways);
	//printf("1ds check opti way tab[i] %d\n", tab[i]);
	//printf("1ds check opti way nb_ant %d\n", nb_ant);
	while (ways[i + 1] && nb_ant >= tab[i])
	{
		//printf("ds check opti way tab[i] %d\n", tab[i]);
		//printf("ds check opti way nb_ant %d\n", nb_ant);
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
	int j = 1;
	while (num_ant < graph->nb_ant)
	{
		opti_ways = ft_check_opti_way(graph->nb_ant - num_ant, back);
		printf("opti_ways %d\n", opti_ways);
		i = 0;
		while (i <= opti_ways)
			ft_add_ant(&walks, ++num_ant, back[opti_ways][i++]);
		printf("%d\n", j++);
		ft_make_forward(graph, &walks);
	}
	while (walks)
	{
		printf("%d\n", j++);
		ft_make_forward(graph, &walks);
	}
	return (TRUE);
}