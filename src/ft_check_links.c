/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_links.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 18:15:15 by abezanni          #+#    #+#             */
/*   Updated: 2018/05/06 19:41:10 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Je sais pu pour le moment
*/

t_bool	ft_parse_link(char *str, t_room **rooms, int nbr_rooms)
{
	int i;
	//int k;
	int	first_len;

	i = 0;
	while (i < nbr_rooms && (ft_strstr(str, rooms[i]->name)) != str)
		i++;
	first_len = ft_strlen(rooms[i]->name);
	//while (j < nbr_rooms && )
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
	rooms[i]->nbr_link++;
	j = 0;
	while (j < nbr_rooms && ft_strcmp(rooms[j]->name, link + dash + 1))
		j++;
	rooms[j]->nbr_link++;
	return (j == nbr_rooms || i == j ? FALSE : TRUE);
}

/*
**	Verifier si la liste est correcte
*/

t_bool	ft_corrects_links(t_data *data, t_lst *lst)
{
	while (lst)
	{
		if (!(ft_verif_links_names(data->rooms, data->nbr_rooms, lst->str)))
			return (FALSE);
		lst = lst->next;
	}
	return (TRUE);
}

/*
**	Cherche les liens entre les salles
*/

t_bool	ft_check_links(t_data *data, t_lst *lst)
{
	int i;

	i = 0;
	if (!ft_corrects_links(data, lst))
		return (FALSE);
	/*while (i < data->nbr_rooms)
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
	}*/
	return (TRUE);
}
