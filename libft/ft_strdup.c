/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:16:51 by abezanni          #+#    #+#             */
/*   Updated: 2018/05/04 10:47:36 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*back;

	if (!(back = (char*)malloc(ft_strlen(src) + 1)))
		return (NULL);
	ft_strcpy(back, src);
	return (back);
}
