/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_for_testing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 15:15:51 by abezanni          #+#    #+#             */
/*   Updated: 2018/06/04 13:17:30 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_values(t_path ***back)
{
	int j;
	int i;
	int d = 0;

	printf("--------------------------------\n");
	while (back[d])
	{

		printf("Indice : %d\n\n", d);
		j = 0;
		while (back[d][j])
		{
			i = 0;
			while (i < back[d][j]->len)
			{
				printf("%d %s", back[d][j]->way[i], i < back[d][j]->len - 1 ? "-" : "");
				i++;
			}
			printf("\nways->len %d\n\n\n\n", back[d][j]->len);
			j++;
		}
		d++;

	}
}
