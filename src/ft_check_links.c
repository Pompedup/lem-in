/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_links.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 18:15:15 by abezanni          #+#    #+#             */
/*   Updated: 2018/05/02 18:26:54 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/*
**
*/

t_bool	ft_parse_link(char *str, t_room **rooms, int nbr_rooms)
{
	int i;
	int k;
	int	first_len;

	i = 0;
	while (i < nbr_rooms && (ft_strstr(str, rooms[i]->name)) != str)
		i++;
	first_len = ft_strlen(rooms[i]->name);
	while (j < nbr_rooms && )
	return (TRUE);
}

/*
**	Retourne le nombre de liens
*/

int		ft_nb_links(char *str, t_lst *lst)
{
	int		back;
	char	*link;

	back = 0;
	while (lst)
	{
		if ((link = ft_strstr(lst->str, str)))
			back++;
		lst = lst->next;
	}
	return (back);
}

/*
**	Cherche les liens entre les salles
*/

t_bool	ft_check_links(t_data *data, t_lst *lst)
{
	int i;

	i = 0;
	while (i < data->nbr_rooms)
	{
		data->rooms[i]->nbr_link = ft_nb_links(data->rooms[i]->name, lst);
		if (!(data->rooms[i]->links =
			malloc(sizeof(int) * data->rooms[i]->nbr_link)))
			return (FALSE);
		i++;
	}
	while (lst)
	{
		if (!(ft_parse_link(lst->str, data->rooms, data->nbr_rooms)))
			return (FALSE);
		ft_free_item(&lst);
	}
	return (TRUE);
}
