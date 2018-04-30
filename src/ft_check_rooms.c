/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adibou <adibou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 12:33:23 by adibou            #+#    #+#             */
/*   Updated: 2018/04/30 12:42:48 by adibou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/*
**  Remplis une salle avec les données disponibles
*/

t_bool	ft_init_room(char *str, int i_r, t_room *room, t_lst **to_null)
{
	int		i;
	char	*first;
	char	*second;
	char	*third;

	if (to_null)
		*to_null = NULL;
	second = NULL;
	third = NULL;
	first = NULL;
	i = 0;
	while (str[i])
	{
		if ((i == 0 || !first) && !ft_isspace(str[i]))
			first = str + i;
		else if (ft_isspace(str[i]) && !ft_isspace(str[i + 11]))
		{
			if (!second)
				second = str + i + 1;
			else if (!third)
				third = str + i + 1;
		}
		if (ft_isspace(str[i]))
			str[i] = 0;
		i++;
	}
	if (*first == 'L')
		return (FALSE);
	if (!(ft_check_int(&(room[i_r].pos[0]), second) &&
        ft_check_int(&(room[i_r].pos[1]), third)))
		return (FALSE);
	room[i_r].name = ft_strdup(first);
	room[i_r].num_room = i_r;
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

t_bool	ft_check_rooms(t_data *data, t_lst **lst, t_lst *begin, t_lst *end)
{
	int		nbr_rooms;
	int		i;

	ft_free_item(lst);
	if ((nbr_rooms = ft_count_rooms(*lst)) < 2)
		return (FALSE);
	if (!(data->rooms = malloc(sizeof(t_room) * nbr_rooms)))
		return (FALSE);
	i = 0;
	data->last = nbr_rooms - 1;
	while (i < nbr_rooms)
	{
		if (*lst == begin)
			ft_init_room((*lst)->str, 0, data->rooms, &begin);
		else if (*lst == end)
			ft_init_room((*lst)->str, data->last, data->rooms, &end);
		else
			ft_init_room((*lst)->str, begin ? i + 1 : i, data->rooms, NULL);
		ft_free_item(lst);
		i++;
	}
	return (TRUE);
}