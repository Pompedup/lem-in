/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:17:36 by ccoupez           #+#    #+#             */
/*   Updated: 2018/06/06 17:29:42 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Appel des fonctions pour trouver tous les chemins
**	puis les chemins les plus optimises
*/

int		ft_resolve(t_data *data)
{
	t_path	*ways;
	t_path	***best_ways;
	int		i;

	i = 0;
	ways = NULL;
	ft_search_ways(data, &ways);
	best_ways = ft_search_best_ways(ways, data);
	send_ant(best_ways, data);
	ft_free_t_path(best_ways, ways);
	ft_free_t_data(data);
	return (0);
}
