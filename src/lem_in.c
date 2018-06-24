/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:13:14 by abezanni          #+#    #+#             */
/*   Updated: 2018/06/24 15:19:39 by ccoupez          ###   ########.fr       */
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
	data->option = 0;
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
	t_data	data;
	t_lst	*lst;

	ft_init_struct(&data);
	lst = NULL;
	if (ac > 1)
		ft_check_option(&data, ac, av);
	if (!ft_parse(&data, &lst))
		return (ft_invalide_file());
	if (!ft_resolve(&data, lst))
		return (ft_invalide_file());
	return (0);
}
