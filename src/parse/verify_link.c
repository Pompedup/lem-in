/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:21:05 by abezanni          #+#    #+#             */
/*   Updated: 2018/06/24 15:10:56 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Teste les noms des liens pour verifier s'ils sont tous repertories
*/

t_bool	ft_verif_links_names(t_room **rooms, int nbr_rooms, char *link)
{
	int i;
	int j;
	int	dash;

	i = 0;
	while (i < nbr_rooms && !(dash =
		ft_strstrtochar(link, rooms[i]->name, '-')))
		i++;
	if (!dash)
		return (FALSE);
	rooms[i]->nb_link++;
	j = 0;
	while (j < nbr_rooms && ft_strcmp(rooms[j]->name, link + dash + 1))
		j++;
	if (j != nbr_rooms)
		rooms[j]->nb_link++;
	return (j == nbr_rooms || i == j ? FALSE : TRUE);
}

/*
**	Verifier si la liste est correcte
*/

t_bool	ft_corrects_links(t_data *data, t_lst *lst)
{
	while (lst)
	{
		if (data->option & 1)
			ft_putendl(lst->str);
		if (*(lst->str) != '#'
			&& !(ft_verif_links_names(data->rooms, data->nb_rooms, lst->str)))
			return (FALSE);
		lst = lst->next;
	}
	return (TRUE);
}
