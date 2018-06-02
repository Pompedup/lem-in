/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_tab_cmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:14:33 by abezanni          #+#    #+#             */
/*   Updated: 2018/06/01 15:13:38 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

int	ft_int_tab_cmp(int *tab1, int *tab2, int size1, int size2)
{
	int i;
	int j;

	i = 0;
	while (i < size1)
	{
		j = 0;
		while (j < size2)
		{
			if (tab1[i] == tab2[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
