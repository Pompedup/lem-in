/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 10:12:17 by abezanni          #+#    #+#             */
/*   Updated: 2018/05/04 10:27:32 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main(void)
{
	char **back;
	int i = 0;

	back = ft_strsplit("arthur suce des bites", 'e');
	while (back[i])
		ft_putendl(back[i++]);
	return (0);
}
