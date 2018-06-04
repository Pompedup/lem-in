/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_best_ways.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adibou <adibou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 18:54:06 by abezanni          #+#    #+#             */
/*   Updated: 2018/06/05 01:34:51 by adibou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Compte le nombre maximum de chemins disponibles
**	Peut etre a opti
*/

int		ft_count_max_ways(t_data *data)
{
	int nb_link_start;
	int nb_link_end;
	int i;

	i = 0;
	nb_link_start = 0;
	nb_link_end = 0;
	while (i < data->nb_start)
	{
		nb_link_start += data->rooms[data->start[i]]->nb_link;
		i++;
	}
	i = 0;
	while (i < data->nb_end)
	{
		nb_link_end += data->rooms[data->end[i]]->nb_link;
		i++;
	}
	return (nb_link_start > nb_link_end ? nb_link_end : nb_link_start);
}

/*
**	Compare deux chemins
*/

t_bool	ft_cmp_ways(t_path **ways, t_path *tocmp, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (!(ft_int_tab_cmp(ways[i]->way + 1,
		tocmp->way + 1, ways[i]->len - 2, tocmp->len - 2)))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/*
**	Appelle recurcivement avec les chemins suivent pour voir s'il arrive
**	a trouver un nombre nb_ways de chemins qui ne se croisent pas avec une
**	longueur maximum de len_max salles
*/

t_bool	ft_search_only_ways(t_path **tab_w, t_path *ways, int len_max, int nb_ways)
{
	t_path	*send;
	int		i;

	i = 0;
	while (tab_w[i])
		i++;
	while (ways && ways->len <= len_max)
	{
		if (i == 0 || ft_cmp_ways(tab_w, ways, i))
		{
			tab_w[i] = ways;
			if (i == nb_ways - 1)
				return (TRUE);
			send = ways->next;
			while (send && send->len <= len_max)
			{
				if (ft_search_only_ways(tab_w, send, len_max, nb_ways))
					return (TRUE);
				send = send->next;
			}
			tab_w[i] = NULL;
		}
		ways = ways->next;
	}
	return (FALSE);
}

/*
**	Alloue pour un certain nombre des chemins a utiliser puis appelle
**	la recurcive qui cherches les chemins puis retourne le tableau
**	s'il a trouve les valeurs necessaires ou NULL
*/

t_path	**ft_check_optis_ways(t_path *ways, int nb_max_ways)
{
	int		i;
	int		len_max;
	t_path	**back;
	t_path	*tmp;

	if (!(back = malloc(sizeof(t_path*) * nb_max_ways + 1)))
		return (NULL);
	i = 0;
	while (i <= nb_max_ways)
		back[i++] = NULL;
	len_max = ways->len;
	tmp = ways;
	while (!(ft_search_only_ways(back, ways, len_max, nb_max_ways)))
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

/*
**	Alloue le tableau pour avoir les divers chemins en fonction du nombre
**	de d'entree ou de sorties disponibles
*/

t_path	***ft_search_best_ways(t_path *ways, t_data *data)
{
	int		nb_max_ways;
	t_path	***back;

	nb_max_ways = ft_count_max_ways(data);
	if (!(back = malloc(sizeof(t_path **) * nb_max_ways + 1)))
		return (NULL);
	//printf("[%d]\n", nb_max_ways);
	back[nb_max_ways] = NULL;
	while (nb_max_ways--)
		back[nb_max_ways] = ft_check_optis_ways(ways, nb_max_ways + 1);
	//print_values(back);
	return (back);
}
