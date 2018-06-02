/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 15:15:24 by abezanni          #+#    #+#             */
/*   Updated: 2018/05/02 12:00:51 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split_charset(char *str, char *charset)
{
	char	**back;
	int		size_words;
	int		i;

	if (!(str && charset) || !(back = malloc(sizeof(char*) * ((ft_nbr_words_charset(str, charset) + 1)))))
		return (NULL);
	i = 0;
	while (*str)
	{
		size_words = 0;
		while (ft_strchr(charset, *str))
			str++;
		while (*str && !ft_strchr(charset, *str))
		{
			str++;
			size_words++;
		}
		if (size_words)
			back[i++] = ft_strndup(str - size_words, size_words);
	}
	back[i] = NULL;
	return (back);
}
