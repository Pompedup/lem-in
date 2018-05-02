/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:06:51 by abezanni          #+#    #+#             */
/*   Updated: 2018/05/02 16:41:08 by abezanni         ###   ########.fr       */
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
	t_bool		entrance;
	t_bool		wayout;
	t_lst		*next;
};

typedef struct	s_room
{
	char		*name;
	int			num_room;
	int			nbr_link;
	int			*links;
	int			pos[2];
	t_bool		entrance;
	t_bool		exit;
}				t_room;

typedef struct	s_data
{
	int 		nbr_rooms;
	int			nbr_ant;
	int			nb_entrance;
	int			nb_wayout;
	int			*entrance;
	int			*wayout;
	t_room		**rooms;
}				t_data;

/*
**	ft_lst.c
*/

t_bool	ft_destroy(t_lst *lst);
void	ft_free_item(t_lst **lst);
t_lst	*ft_lst_new(char *str, int passage);
void	ft_lst_pushback(t_lst **begin, t_lst *to_add);

/*
**	ft_parse.c
*/

t_bool	ft_check_rooms(t_data *data, t_lst **lst);
t_bool	ft_check_int(int *value, char *str);
t_bool	ft_parse(char *name, t_data *data);

#endif
