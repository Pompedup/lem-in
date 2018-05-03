/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adibou <adibou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 12:33:23 by adibou            #+#    #+#             */
/*   Updated: 2018/04/30 15:24:32 by adibou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/*
**  Remplis une salle avec les données disponibles
*/

t_bool	ft_init_room(char *str, int i_r, t_room **room, t_lst **to_null)
{
	char	**data_room;

	if (to_null)
		*to_null = NULL;
	if (!(*room = malloc(sizeof(t_room))))
		return (FALSE);
    data_room = ft_split_charset(str, " \t");
	if (*(data_room[0]) == 'L')
		return (FALSE);
	if (!(ft_check_int(&((*room)->pos[0]), data_room[1]) &&
        ft_check_int(&((*room)->pos[1]), data_room[2])))
		return (FALSE);
	(*room)->name = ft_strdup(data_room[0]);
	(*room)->num_room = i_r;
    ft_free_char_tab(data_room);
	return (TRUE);
}

/*
**  Compte le nombre de salles
*/

int		ft_count_rooms(t_lst *lst)
{
	int		nbr_rooms;

	nbr_rooms = 0;
	while (ft_nbr_words_charset(lst->str, " \t") == 3)
	{
		nbr_rooms++;
		lst = lst->next;
	}
	return (nbr_rooms);
}

/*
**  Créé la liste des salles
*/

t_bool	ft_check_rooms(t_data *data, t_lst **lst, t_lst **begin, t_lst **end)
{
	int		nbr_rooms;
	int		i;
	int		to_send;

	ft_free_item(lst);
	if ((nbr_rooms = ft_count_rooms(*lst)) < 2)
		return (FALSE);
	if (!(data->rooms = malloc(sizeof(t_room*) * (nbr_rooms + 1))))
		return (FALSE);
	i = 0;
	data->last = nbr_rooms - 1;
	while (i < nbr_rooms)
	{
		to_send = *begin ? i + 1 : i;
		to_send = *end ? to_send : to_send - 1;
		if (*lst == *begin)
			ft_init_room((*lst)->str, 0, &(data->rooms[0]), begin);
		else if (*lst == *end)
			ft_init_room((*lst)->str, data->last, &(data->rooms[data->last]), end);
		else
			ft_init_room((*lst)->str, to_send, &(data->rooms[to_send]), NULL);
		ft_free_item(lst);
		i++;
	}
	data->rooms[i] = NULL;
	return (TRUE);
}