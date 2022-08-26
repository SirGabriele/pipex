/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_commands_requested.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:19:41 by kbrousse          #+#    #+#             */
/*   Updated: 2022/08/24 18:14:00 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	child_last(t_pipex *pipex, char **argv, char **env)
{
	t_pipex_cmd	*copy;

	close(pipex->pipefd[1]);
	dup2(pipex->pipefd[0], STD_IN);
	close(pipex->pipefd[0]);
	pipex->outfile = open(argv[4], O_WRONLY | O_TRUNC);
	dup2(pipex->outfile, STD_OUT);
	close(pipex->outfile);
	copy = pipex->first_cmd->next;
	if (execve(copy->correct_path, copy->tab_cmd, env) == -1)
		clear_program(pipex, "Execve child_last failed");
}

static void	child_one(t_pipex *pipex, char **argv, char **env)
{
	close(pipex->pipefd[0]);
	pipex->infile = open(argv[1], O_RDONLY);
	dup2(pipex->infile, STD_IN);
	close(pipex->infile);
	dup2(pipex->pipefd[1], STD_OUT);
	close(pipex->pipefd[1]);
	if (execve(pipex->first_cmd->correct_path, pipex->first_cmd->tab_cmd, env) == -1)
		clear_program(pipex, "Execve child_one failed");
}

void	two_commands_requested(t_pipex *pipex, char **argv, char **env)
{
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(pipex->pipefd) == -1)
		clear_program(pipex, "Pipe failed");
	pid1 = fork();
	if (pid1 == -1)
		clear_program(pipex, "Fork 1 failed");
	else if (pid1 == 0)
		child_one(pipex, argv, env);
	pid2 = fork();
	if (pid2 == -1)
		clear_program(pipex, "Fork 2 failed");
	else if (pid2 == 0)
		child_last(pipex, argv, env);
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	waitpid(pid1, NULL, WUNTRACED);
	waitpid(pid2, NULL, WUNTRACED);
}
