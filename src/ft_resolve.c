/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:17:36 by ccoupez           #+#    #+#             */
/*   Updated: 2018/06/01 15:28:46 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
			return(0);
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
			ft_lst_path_pushback(path, ft_lst_path_new(visited, graph->nb_rooms));
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

/*
**	Peut etre a opti
*/

int		ft_count_max_ways(t_data *data)
{
	int nb_link_entrance;
	int nb_link_wayout;
	int i;

	i = 0;
	nb_link_entrance = 0;
	nb_link_wayout = 0;
	while (i < data->nb_entrance)
	{
		nb_link_entrance += data->rooms[data->entrance[i]]->nb_link;
		i++;
	}
	i = 0;
	while (i < data->nb_wayout)
	{
		nb_link_wayout += data->rooms[data->wayout[i]]->nb_link;
		i++;
	}
	return (nb_link_entrance > nb_link_wayout ? nb_link_wayout : nb_link_entrance);
}

t_bool	ft_check_if_present(t_path **ways, t_path *tocmp, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (!(ft_int_tab_cmp(ways[i]->way + 1, tocmp->way + 1, ways[i]->len - 2, tocmp->len - 2)))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	ft_search_ways(t_path **opti_ways, t_path *all_ways, int len_max, int nb_ways)
{
	t_path	*send;
	int		i;

	i = 0;
	while (opti_ways[i])
		i++;
	while (all_ways && all_ways->len <= len_max)
	{
		if (i == 0 || ft_check_if_present(opti_ways, all_ways, i))
		{
			opti_ways[i] = all_ways;
			if (i == nb_ways - 1)
				return (TRUE);
			send = all_ways->next;
			while (send && send->len <= len_max)
			{
				if (ft_search_ways(opti_ways, send, len_max, nb_ways))
					return (TRUE);
				send = send->next;
			}
			opti_ways[i] = NULL;
		}
		all_ways = all_ways->next;
	}
	return (FALSE);
}

t_path	**ft_check_optis_ways(t_path *ways, int nb_max_ways)
{
	int		i;
	int		len_max;
	t_path	**back;
	t_path	*tmp;

	if (!(back = malloc(sizeof(t_path*) * nb_max_ways + 1)))
		return (NULL);
	i = 0;
	while (i < nb_max_ways)
		back[i++] = NULL;
	len_max = ways->len;
	tmp = ways;
	while (!(ft_search_ways(back, ways, len_max, nb_max_ways)))
	{
		while (tmp && tmp->len == len_max)
			tmp = tmp->next;
		if (!tmp)
		{
			free(back);
			return (NULL);
		}
		len_max = tmp->len;
	}
	return (back);
}

t_bool	search_best_ways(t_path *ways, t_data *data)
{
	int		nb_max_ways;
	t_path	***back;

	nb_max_ways = ft_count_max_ways(data);
	if (!(back = malloc(sizeof(t_path **) * nb_max_ways + 1)))
		return (FALSE);
	back[nb_max_ways] = NULL;
	ft_putnbrendl(nb_max_ways);
	while (nb_max_ways--)
	{
		back[nb_max_ways] = ft_check_optis_ways(ways, nb_max_ways + 1);
	}
	print_values(back);
	return (TRUE);
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



	t_path *tmp = ways;
	while (ways)
	{
		i = 0;
		while (i < ways->len)
		{
			printf("%d %s ", ways->way[i], i < ways->len - 1 ? "-" : "");
			i++;
		}
		printf("\nways->len %d + %p\n", ways->len, ways);
		printf("\n");
		ways = ways->next;
	}
	ways = tmp;
	search_best_ways(ways, data);
	return (0);
}
