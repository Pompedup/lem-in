/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:17:36 by ccoupez           #+#    #+#             */
/*   Updated: 2018/05/31 17:05:42 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	mark(int *way, int num)
{
	int i;

	i = 0;
	while (way[i] != -1)
		i++;
	way[i] = num;
}

void	unmark(int *way, int num)
{
	int i;

	i = 0;
	while (way[i] != num)
		i++;
	way[i] = -1;
}

int		not_on_the_way(int *way, int actual, int max)
{
	int i;

	i = 0;
	while (way[i] != -1 && i < max)
	{
		if (way[i] == actual)
			return(0);
		i++;
	}
	return (1);
}

void	deep_course(t_data *graph, t_path **path, t_room *room, int *visited)
{
	int i;

	mark(visited, room->num_room);
	i = 0;
	while (i < graph->nb_wayout)
		if (room == graph->rooms[graph->wayout[i++]])
		{
			ft_lst_path_pushback(path, ft_lst_path_new(visited, graph->nb_rooms));
			unmark(visited,room->num_room);
			return ;
		}
	i = 0;
	while (i < room->nb_link)
	{
		if (not_on_the_way(visited, room->links[i], graph->nb_rooms))
			deep_course(graph, path, graph->rooms[room->links[i]], visited);
		i++;
	}
	unmark(visited,room->num_room);
}

void	sort_ways(t_path *ways)
{
	t_path	*actual;
	t_path	*tmp;

	actual = ways;
	while (actual)
	{
		tmp = actual->next;
		while (tmp)
		{
			if (actual->len > tmp->len)
			{
				change_place(actual, tmp);
				tmp = actual->next;
			}
			else
				tmp = tmp->next;
		}
		actual = actual->next;
	}
}

int     resolve(t_data *data)
{
	t_path 	*ways;
	int		tab[data->nb_rooms];
	int		i;

	i = 0;
	while (i < data->nb_rooms)
		tab[i++] = -1;
	ways = NULL;
	i = 0;
	while (i < data->nb_entrance)
		deep_course(data, &ways, data->rooms[data->entrance[i++]], tab);
	sort_ways(ways);
	while (ways)
	{
		i = 0;
		while (i < ways->len)
		{
			printf("%d %s ", ways->way[i], i < ways->len - 1 ? "-" : "");
			i++;
		}
		printf("\nways->len %d\n", ways->len);
		printf("\n");
		ways = ways->next;
	}
	return (0);

}
