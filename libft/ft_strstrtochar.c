/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrtochar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 19:08:44 by abezanni          #+#    #+#             */
/*   Updated: 2018/05/06 19:28:58 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strstrtochar(char *str, char *to_find, char c)
{
	int i;

	i = 0;
	while (to_find[i] == str[i] && to_find[i])
		i++;
	return (!to_find[i] && str[i] == c ? i : 0);
}
