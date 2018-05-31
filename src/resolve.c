/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:17:36 by ccoupez           #+#    #+#             */
/*   Updated: 2018/05/31 16:14:00 by abezanni         ###   ########.fr       */
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
	if (room == graph->rooms[graph->wayout[0]])
		ft_lst_path_pushback(path, ft_lst_path_new(visited, graph->nb_rooms));
	i = 0;
	while (i < room->nb_link)
	{
		if (not_on_the_way(visited, room->links[i], graph->nb_rooms))
			deep_course(graph, path, graph->rooms[room->links[i]], visited);
		i++;
	}
	unmark(visited,room->num_room);
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
	deep_course(data, &ways, data->rooms[data->entrance[0]], tab);

	while (ways)
	{
		i = 0;
		while (i < ways->len)
			printf("%d - ", ways->way[i++]);
		printf("\n");
		ways = ways->next;
	}
	return (0);

}
