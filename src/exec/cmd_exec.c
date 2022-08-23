/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 07:23:01 by kbrousse          #+#    #+#             */
/*   Updated: 2022/08/23 10:08:44 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	child_n(t_pipex *pipex, int argc, char **argv, char **env)
{
	(void)pipex;
	(void)argc;
	(void)argv;
	(void)env;
}

static void	child_last(t_pipex *pipex, int argc, char **argv, char **env)
{
	close(pipex->pipefd[1]);
	dup2(pipex->pipefd[0], STD_IN);
	close(pipex->pipefd[0]);
	pipex->outfile = open(argv[argc - 1], O_WRONLY);
	dup2(pipex->outfile, STD_OUT);
	close(pipex->outfile);
	waitpid(pipex->tab_pid[0], NULL, WUNTRACED);
	if (execve(pipex->first_cmd->next->tab_cmd[0], pipex->first_cmd->next->tab_cmd, env) == -1)
		ft_printf("Oskur, %s\n", pipex->first_cmd->next->tab_cmd[0]);
}

static void	child_one(t_pipex *pipex, char **argv, char **env)
{
	close(pipex->pipefd[0]);
	pipex->infile = open(argv[1], O_RDONLY);
	dup2(pipex->infile, STD_IN);
	close(pipex->infile);
	dup2(pipex->pipefd[1], STD_OUT);
	close(pipex->pipefd[1]);
	if (execve(pipex->first_cmd->tab_cmd[0], pipex->first_cmd->tab_cmd, env) == -1)
		ft_printf("Aled\n");
}

void	cmd_exec(t_pipex *pipex, int argc, char **argv, char **env)
{
	int		i;

	i = -1;
	if (pipe(pipex->pipefd) == -1)
		clear_program(pipex, "Pipe failed");
	while (++i < argc - 3)
	{
		pipex->tab_pid[i] = fork();
		if (pipex->tab_pid[i] == -1)
			clear_program(pipex, "Fork in while failed");
		if (i == 0 && pipex->tab_pid[i] == 0)
			child_one(pipex, argv, env);
		else if (i == argc - 4 && pipex->tab_pid[i] == 0)
			child_last(pipex, argc, argv, env);
		else if (pipex->tab_pid[i] == 0)
			child_n(pipex, argc, argv, env);
	}
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	i = -1;
	while (++i < argc - 3)
		waitpid(pipex->tab_pid[i], NULL, WUNTRACED);
}
