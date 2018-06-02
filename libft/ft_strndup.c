/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:18:20 by abezanni          #+#    #+#             */
/*   Updated: 2018/05/04 10:38:13 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Fais une copie des n premiers charactere de la chaine str
*/

char	*ft_strndup(const char *str, size_t len)
{
	char	*back;

	if (!(back = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strncpy(back, str, len);
	back[len] = 0;
	return (back);
}
