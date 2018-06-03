/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:13:14 by abezanni          #+#    #+#             */
/*   Updated: 2018/06/03 18:23:28 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_structe(t_data *data)
{
	int		i;
	t_room	*room;

	i = 0;
	if (data)
	{
		if (data->rooms)
		{
			while (i < data->nb_rooms)
			{
				room = data->rooms[i];
				ft_putendl(room->name);
				ft_putnbrendl(room->num_room);
				ft_putnbrendl(room->pos[0]);
				ft_putnbrendl(room->pos[1]);
				i++;
			}
		}
	}
}

/*
**  Affiche une erreur
*/

int		ft_invalide_file(void)
{
	ft_putendl_fd("ERROR", 2);
	return (0);
}

/*
**  Ai-je besoin de le préciser ?
*/

int		main(int ac, char **av)
{
	t_data data;

	if (ac > 1)
	{
		(void)av;
		data.option = 1;
	}
	if (!ft_parse(&data))
		return (ft_invalide_file());
	//ft_print_struct(&data);
	ft_resolve(&data);
	return (0);
}
