/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 14:58:47 by ccoupez           #+#    #+#             */
/*   Updated: 2018/06/24 17:38:55 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool	cmd_valide(t_data *data, t_lst *lst, int i)
{
	if (data->option & 1)
		ft_putendl(lst->str);
	if ((lst->type == -1 || lst->type == -2)
		&& lst->next && lst->next->type < 0)
	{
		data->nb_rooms = i;
		ft_putendl(lst->next->str);
		return (FALSE);
	}
	return (TRUE);
}
