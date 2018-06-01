/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_ways.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 18:47:38 by abezanni          #+#    #+#             */
/*   Updated: 2018/06/01 19:57:25 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
				ft_change_place(actual, tmp);
				tmp = actual->next;
			}
			else
				tmp = tmp->next;
		}
		actual = actual->next;
	}
}

void	mark(int *way, int num, int mark)
{
	int i;

	i = 0;
	while (mark ? way[i] != -1 : way[i] != num)
		i++;
	way[i] = mark ? num : -1;
}

int		not_on_the_way(int *way, int actual, int max)
{
	int i;

	i = 0;
	while (way[i] != -1 && i < max)
	{
		if (way[i] == actual)
			return (0);
		i++;
	}
	return (1);
}

void	deep_course(t_data *graph, t_path **path, t_room *room, int *visited)
{
	int i;

	mark(visited, room->num_room, 1);
	i = 0;
	while (i < graph->nb_wayout)
		if (room == graph->rooms[graph->wayout[i++]])
		{
			ft_lst_path_pushback(path,
			ft_lst_path_new(visited, graph->nb_rooms));
			mark(visited, room->num_room, 0);
			return ;
		}
	i = 0;
	while (i < room->nb_link)
	{
		if (not_on_the_way(visited, room->links[i], graph->nb_rooms))
			deep_course(graph, path, graph->rooms[room->links[i]], visited);
		i++;
	}
	mark(visited, room->num_room, 0);
}

void	ft_search_ways(t_data *data, t_path **ways)
{
	int i;
	int	tab[data->nb_rooms];

	i = 0;
	while (i < data->nb_rooms)
		tab[i++] = -1;
	i = 0;
	while (i < data->nb_entrance)
		deep_course(data, ways, data->rooms[data->entrance[i++]], tab);
	sort_ways(*ways);
}
