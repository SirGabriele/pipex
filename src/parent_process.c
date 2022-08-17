/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:22:38 by kbrousse          #+#    #+#             */
/*   Updated: 2022/08/17 14:37:55 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(pid_t pid1, int *pipefd)
{
	char	buf;

	close(pipefd[1]);
	while (read(pipefd[0], &buf, sizeof(char)) > 0)
		write(1, &buf, 1);
	close(pipefd[0]);
	waitpid(pid1, NULL, 0);
}
