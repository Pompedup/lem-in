/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adibou <adibou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:13:14 by abezanni          #+#    #+#             */
/*   Updated: 2018/04/30 12:42:03 by adibou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/*
**  Affiche une erreur
*/

int		ft_invalide_file(void)
{
	ft_putendl("ERROR");
	return (0);
}

/*
**  Ai-je besoin de le préciser ?
*/

int		main(int ac, char **av)
{
	t_data data;

	if (ac != 2)
	{
		ft_putendl("usage: lem-in source_file");
		exit(0);
	}
	if (!ft_parse(av[1], &data))
		return (ft_invalide_file());
	return (0);
}
