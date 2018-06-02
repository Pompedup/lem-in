/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 23:50:52 by abezanni          #+#    #+#             */
/*   Updated: 2018/05/04 10:36:58 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Copie len caracteres de la chaine str depuis la position start
*/

char	*ft_strsub(const char *str, unsigned int start, size_t len)
{
	char	*back;

	if (!str)
		return (NULL);
	if (!(back = (char *)malloc(len + 1)))
		return (NULL);
	ft_strncpy(back, str + start, len);
	back[len] = 0;
	return (back);
}
