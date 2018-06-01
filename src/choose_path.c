/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 10:20:10 by ccoupez           #+#    #+#             */
/*   Updated: 2018/06/01 19:18:45 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
/*
int		compare_ways(t_path *actual, t_path *tmp)
{
	int		i;
	int		j;

	i = 0;
	while (i < actual->len)
	{
		j = 0;
		while (j < tmp->len)
		{
			if (actual->way[i] == tmp->way[j])
			{
				printf("not compatible!!!");
				return (0);
			}
			j++;
		}
		tmp =
		i++;
	}
	return (1);
}

void	choose_ways(int nb_ant, int max_start, t_path *ways)
{
	t_path	*actual;
	t_path	*tmp;
	int		nb;

	actual = ways;
	tmp = ways->next;
	nb = 0;
	while (actual && nb < max_start)
	{
		while (tmp && nb < max_start)
		{
			nb += compare_ways(actual, tmp);
			tmp = tmp->next;
		}
		actual = actual->next;
	}
}

int		nb_ways(t_data *graph)
{
	int i;
	int	nb;

	i = 0;
	nb = 0;
	while (i < graph->nb_entrance)
		nb += graph->rooms[graph->entrance[i++]]->nb_link;
	return (nb);
}
*/
