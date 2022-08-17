/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_1_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:12:56 by kbrousse          #+#    #+#             */
/*   Updated: 2022/08/17 15:25:33 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_1_process(int *pipefd, char **argvec, char **env)
{
	dup2(pipefd[1], 1);
	close(pipefd[0]);
	close(pipefd[1]);
	execve(argvec[0], argvec, env);
	exit(0);
}
