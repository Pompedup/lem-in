/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:13:14 by abezanni          #+#    #+#             */
/*   Updated: 2018/06/06 14:20:11 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_init_struct(t_data *data)
{
	data->nb_rooms = 0;
	data->nb_start = 0;
	data->nb_end = 0;
	data->start = NULL;
	data->end = NULL;
	data->rooms = NULL;
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
	ft_init_struct(&data);
	if (!ft_parse(&data))
		return (ft_invalide_file());
	ft_resolve(&data);
	return (0);
}
