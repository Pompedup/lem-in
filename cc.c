/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adibou <adibou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 00:32:05 by adibou            #+#    #+#             */
/*   Updated: 2018/06/05 00:44:56 by adibou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main()
{
	int tab[2][3];

	tab[0][0] = nb_coup_mini_way-;4
	tab[0][1] = nb_coup_actuel;6
	tab[0][2] = nb_ant/way-;1
	tab[1][0] = nb_coup_mini_way+;4
	tab[1][1] = nb_coup_actuel;6
	tab[1][2] = nb_fourmi/way+;2

	while (tab[0][1] < tab[1][1])
	{
		tab[0][0] += tab[0][2];
		tab[0][1]++;
	}
	while (tab[1][0] < tab[0][0])
	{
		tab[0][0] += tab[0][2];
		tab[1][0] += tab[1][2];
		tab[0][1]++;
		tab[1][1]++;
	}
}