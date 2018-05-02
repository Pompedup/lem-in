/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 12:33:23 by adibou            #+#    #+#             */
/*   Updated: 2018/05/02 17:22:05 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/*
**  Remplis une salle avec les données disponibles
*/

t_bool	ft_init_room(char *str, int i_r, t_room **room)
{
	char	**words;

	words = ft_split_charset(str, " \t");
	if (*words[0] == 'L')
		return (FALSE);
	if (!(room[i_r] = malloc(sizeof(t_room))))
		return (FALSE);
	if (!(ft_check_int(&(room[i_r]->pos[0]), words[1]) &&
		ft_check_int(&(room[i_r]->pos[1]), words[2])))
		return (FALSE);
	room[i_r]->name = words[0];
	room[i_r]->num_room = i_r;
	free(words[1]);
	free(words[2]);
	free(words);
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
**	Cree les tableaux d'entree ou de sortie
*/

int		*ft_table_entrance_wayout(t_lst *lst, int nb, int entrance)
{
	int *back;
	int i;
	int j;

	if (!(back = malloc(sizeof(int) * nb)))
		return (NULL);
	i = 0;
	j = 0;
	while (i < nb)
	{
		while ((entrance ? lst->entrance : lst->wayout) == 0)
		{
			j++;
			lst = lst->next;
		}
		back[i] = j;
		lst = lst->next;
		i++;
	}
	return (back);
}

/*
**  Créé la liste des salles
*/

t_bool	ft_check_rooms(t_data *data, t_lst **lst)
{
	int		i;

	ft_free_item(lst);
	if (!(data->entrance =
		ft_table_entrance_wayout(*lst, data->nb_entrance, 1)))
		return (FALSE);
	if (!(data->wayout = ft_table_entrance_wayout(*lst, data->nb_wayout, 0)))
		return (FALSE);
	if ((data->nbr_rooms = ft_count_rooms(*lst)) < 2)
		return (FALSE);
	if (!(data->rooms = malloc(sizeof(t_room*) * data->nbr_rooms)))
		return (FALSE);
	i = 0;
	while (i < data->nbr_rooms)
	{
		ft_init_room((*lst)->str, i, data->rooms);
		ft_free_item(lst);
		i++;
	}
	return (TRUE);
}
