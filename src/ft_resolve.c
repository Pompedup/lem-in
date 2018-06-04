/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adibou <adibou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:17:36 by ccoupez           #+#    #+#             */
/*   Updated: 2018/06/04 23:09:59 by adibou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*t_bool	ft_init_indice(t_data *data, t_path ***ways)
{
	int i;

	while (ways[i])
		i++;
	data->nb_ways = i;
	if (!(data->way = malloc(sizeof(int) * i)))
		return (FALSE);
	i = 0;
	while (ways[i])
	{

	}
}*/

/*
**	Appel des fonctions pour trouver tous les chemins
**	puis les chemins les plus optimises
*/

int		ft_resolve(t_data *data)
{
	t_path	*ways;
	t_path	***best_ways;
	//t_path	*tmp;
	int		i;

	i = 0;
	ways = NULL;
	ft_search_ways(data, &ways);
	//tmp = ways;
	//while (ways)
	//{
	//	i = 0;
	//	while (i < ways->len)
	//		i++;
	//	ways = ways->next;
	//}
	//ways = tmp;
	best_ways = ft_search_best_ways(ways, data);
	send_ant(best_ways, data);
	return (0);
}
