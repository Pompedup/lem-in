/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adibou <adibou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:06:51 by abezanni          #+#    #+#             */
/*   Updated: 2018/04/29 14:46:25 by adibou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define TRUE 1
# define FALSE 0

# include <fcntl.h>
# include "../../libft/libft.h"
# include <stdio.h>

typedef char	t_bool;

typedef	struct	s_lst t_lst;

struct 			s_lst
{
	char		*str;
	t_lst		*next;
};

typedef struct	s_room
{
	char		*name;
	int			num_room;
	int			nbr_link;
	int			*links;
	int			pos[2];
}				t_room;

typedef struct	s_data
{
	int 		last;
	int			nbr_ant;
	t_room		*rooms;
}				t_data;

/*
**	ft_lst.c
*/

t_lst	*ft_lst_new(char *str);
void	ft_lst_pushback(t_lst **begin, t_lst *to_add);

/*
**	ft_parce.c
*/

t_bool	ft_check_rooms(t_data *data, t_lst **lst, t_lst *begin, t_lst *end);
t_bool	ft_check_int(int *value, char *str);

#endif
