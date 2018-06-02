/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 00:10:52 by abezanni          #+#    #+#             */
/*   Updated: 2018/05/04 10:48:00 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Enleve les espaces au debut et a la fin de la chaine str
*/

char	*ft_strtrim(const char *str)
{
	char	*back;
	size_t	end;
	size_t	bgn;

	bgn = 0;
	back = NULL;
	if (!str)
		return (NULL);
	while (str[bgn] == ' ' || str[bgn] == '\n' || str[bgn] == '\t')
		bgn++;
	end = ft_strlen(str);
	while ((str[end] == ' ' || str[end] == '\n' ||
	str[end] == '\t' || str[end] == '\0') && end)
		end--;
	if (str[bgn] == '\0')
		return (ft_strdup(""));
	else if (bgn <= end)
	{
		if (!(back = (char*)malloc(end - bgn + 2)))
			return (NULL);
		ft_strncpy(back, str + bgn, end - bgn + 1);
	}
	return (back);
}
