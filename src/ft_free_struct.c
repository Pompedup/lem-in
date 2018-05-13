/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 18:44:33 by abezanni          #+#    #+#             */
/*   Updated: 2018/05/13 19:23:08 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_free_tab(char **tab, int i)
{
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	ft_free_rooms(t_room **rooms, int nb_rooms)
{
	int i;

	i = 0;
	while (i < nb_rooms)
	{
		if (rooms[i]->links)
			free(rooms[i]->links);
		free(rooms[i]->name);
		free(rooms[i]);
		i++;
	}
	free(rooms);
}

void	ft_free_t_data(t_data *data)
{
	if (data->rooms)
		ft_free_rooms(data->rooms, data->nb_rooms);
	if (data->entrance)
		free(data->entrance);
	if (data->wayout)
		free(data->wayout);
}
