/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:17:36 by ccoupez           #+#    #+#             */
/*   Updated: 2018/06/06 19:24:49 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Appel des fonctions pour trouver tous les chemins
**	puis les chemins les plus optimises
*/

t_bool	ft_resolve(t_data *data, t_lst *lst)
{
	t_path	*ways;
	t_path	***best_ways;
	int		i;

	i = 0;
	ways = NULL;
	ft_search_ways(data, &ways);
	if (!ways)
		return (ft_destroy(data, lst));
	else
		ft_print_free_lst(lst, !(data->option & 1));
	best_ways = ft_search_best_ways(ways, data);
	send_ant(best_ways, data);
	ft_free_t_path(best_ways, ways);
	ft_free_t_data(data);
	return (TRUE);
}
