/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 20:23:45 by abezanni          #+#    #+#             */
/*   Updated: 2018/06/02 18:12:09 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_write_links(int nb, t_data *data, t_room *room)
{
	int i;

	i = 0;
	while (i < room->nb_link)
	{
		if (nb < room->links[i])
		{
			ft_putstr(room->name);
			ft_putstr("-");
			ft_putendl(data->rooms[room->links[i]]->name);
		}
		i++;
	}
}

t_bool	ft_is_not_into(int nb, t_data *data)
{
	int i;

	i = 0;
	while (i < data->nb_entrance)
		if (nb == data->entrance[i++])
			return (FALSE);
	i = 0;
	while (i < data->nb_wayout)
		if (nb == data->wayout[i++])
			return (FALSE);
	return (TRUE);
}

void	ft_print_indications_room(t_room *room)
{
	ft_putstr(room->name);
	ft_putstr(" ");
	ft_putnbr(room->pos[0]);
	ft_putstr(" ");
	ft_putnbrendl(room->pos[1]);
}

void	ft_print_struct(t_data *data)
{
	int		i;

	if (data)
	{
		i = 0;
		ft_putnbrendl(data->nb_ant);
		ft_putendl("##start");
		while (i < data->nb_entrance)
			ft_print_indications_room(data->rooms[data->entrance[i++]]);
		ft_putendl("##end");
		i = 0;
		while (i < data->nb_wayout)
			ft_print_indications_room(data->rooms[data->wayout[i++]]);
		i = 0;
		while (i < data->nb_rooms)
		{
			if (ft_is_not_into(i, data))
				ft_print_indications_room(data->rooms[i]);
			i++;
		}
		i = 0;
		while (i < data->nb_rooms)
		{
			ft_write_links(i, data, data->rooms[i]);
			i++;
		}
	}
}
