/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:17:36 by ccoupez           #+#    #+#             */
/*   Updated: 2018/06/06 14:11:54 by abezanni         ###   ########.fr       */
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
	return (0);
}
