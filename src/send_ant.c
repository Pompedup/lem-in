/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:39:42 by ccoupez           #+#    #+#             */
/*   Updated: 2018/06/04 16:22:39 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool   send_ant(t_path ***back, t_data *graph, int nb_ways)
{
	int		i;
	int		j;
    int		ant;
	int		ant_send;
	int		arrived;
	t_walk	**walks;


	if (!(walks = malloc(sizeof(t_walk *) * graph->nb_ant)))
		return (FALSE);
	ants_walking = 0;
	arrived = 0;
	i = 1;
	printf("send ant\n");
	while (arrived != graph->nb_ant)
	{
		i = 0;
		if (i < ants_walking)
		{
			while (i < ants_walking)
			{
				printf("L%d-%d  ", walks[i]->ant, back[walks[i]->i_w[0]][walks[i]->i_w[1]]->way[walks[i]->i_w[2]);
				
				if (i < back[walks[i]->i_w[0]][walks[i]->i_w[1]]->len)
					walks[i]->i_w[2]++;
				else
				{
					//la fourmie est arrivee a la fin
					ants_walking--;
				}
				i++;
			}
			//faire avancer les fourmis en cours
			
		}
		//ici il faudra choisir par quelle chemin la fourmie commence
		walk[i]->ant = i + 1;
		walks[i]->i_w[0] = 0;
		walks[i]->i_w[1] = 0;
		walks[i]->i_w[2] = 0;
		ants_walking++;
		//faire avancer de nouvelles fourmies
	}	
}
typedef struct		s_walk
{
	int				ant;
	int				i_w[3];
}					t_walk;
