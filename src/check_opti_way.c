/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opti_way.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:39:34 by abezanni          #+#    #+#             */
/*   Updated: 2018/06/06 18:09:42 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Calcul le nombre de fourmis qui peuvent etre envoyee
**	par les salles plus petites
*/

int		ft_calcul(int i, int *max, int prev)
{
	int nb_pass;
	int by_turn;

	by_turn = i + 1;
	nb_pass = prev + by_turn;
	while (max[i] < max[i + 1])
	{
		nb_pass += by_turn;
		max[i]++;
	}
	return (nb_pass);
}

/*
**	Retourne le tableau avec les valeurs de changement de salles
*/

void	ft_return_when(t_path ***way, int nb_way, int *tab)
{
	int max[nb_way];
	int i;
	int j;

	i = 0;
	while (i < nb_way)
		max[i++] = 0;
	i = 0;
	while (way[i])
	{
		j = 0;
		while (way[i][j])
		{
			if (way[i][j]->len > max[i])
				max[i] = way[i][j]->len;
			j++;
		}
		i++;
	}
	i = 0;
	while (way[i + 1])
	{
		tab[i] = ft_calcul(i, max, i == 0 ? 1 : tab[i - 1] - i);
		i++;
	}
}

int		*ft_create_opti_tab(t_path ***ways)
{
	int nb_way;
	int	*tab;

	nb_way = 0;
	while (ways[nb_way])
		nb_way++;
	if (!(tab = malloc(sizeof(int) * (nb_way - 1))))
		return (NULL);
	ft_return_when(ways, nb_way, tab);
	return (tab);
}

int		ft_check_opti_way(int nb_ant, t_path ***ways)
{
	static int	*tab = NULL;
	int			i;

	i = 0;
	if (!tab)
		tab = ft_create_opti_tab(ways);
	while (ways[i + 1] && nb_ant >= tab[i])
		i++;
	if (nb_ant == i + 1)
		free(tab);
	return (i);
}
