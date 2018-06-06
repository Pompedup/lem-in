/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_double_rooms.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:43:38 by abezanni          #+#    #+#             */
/*   Updated: 2018/06/06 14:43:51 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Teste les noms et les positions
*/

t_bool	ft_check_name_and_pos(t_room *room, t_room **rooms, int nbr_rooms)
{
	int i;

	i = 0;
	while (i < nbr_rooms)
	{
		if (!ft_strcmp(room->name, rooms[i]->name))
			return (FALSE);
		if (room->pos[0] == rooms[i]->pos[0]
			&& room->pos[1] == rooms[i]->pos[1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/*
**	Verifie qu'il n'y a aucune salle avec le meme nom ou les memes positions
*/

t_bool	ft_verif_no_double(t_room **rooms, int nbr_rooms)
{
	int i;

	i = 0;
	while (i < nbr_rooms - 1)
	{
		if (!ft_check_name_and_pos(rooms[i], rooms + i + 1, nbr_rooms - i - 1))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
