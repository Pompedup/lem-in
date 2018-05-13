/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 13:38:16 by abezanni          #+#    #+#             */
/*   Updated: 2018/05/10 13:55:28 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	int fd;
	int ret;
	char buf[10];

	fd = open("txt", O_RDONLY);
	ret = read(fd, buf, 5);
	if (ret == -1)
		/*perror("");*/strerror(errno);
	return (0);
}
