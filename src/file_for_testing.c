/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_for_testing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 15:15:51 by abezanni          #+#    #+#             */
/*   Updated: 2018/06/01 15:21:15 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_values(t_path ***back)
{
	int j;
	int i;
	int d = 0;

	while (back[d])
	{

		printf("Indice : %d\n\n\n", d);
		j = 0;
		while (back[d][j])
		{
			i = 0;
			while (i < back[d][j]->len)
			{
				printf("%d %s", back[d][j]->way[i], i < back[d][j]->len - 1 ? "-" : "");
				i++;
			}
			printf("\nways->len %d\n", back[d][j]->len);
			printf("\n");
			j++;
		}
		d++;

	}
}
