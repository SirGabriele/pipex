/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:16:42 by kbrousse          #+#    #+#             */
/*   Updated: 2022/08/17 15:20:51 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int	pipefd[2];
	pid_t	pid1;
	char *argvec[] = {"/usr/bin/cat", "test.c", NULL};

	(void)argv;
	if (argc != 5)
		return (ft_printf("Usage is <<< ./pipex file1 cmd1 cmd2 file2 >>>\n"));
	check_args_first_half(argv);
	if (pipe(pipefd) == -1)
		clear_program("Pipe failed");
	pid1 = fork();
	if (pid1 == -1)
		clear_program("Fork 1 failed");
	if (pid1 == 0)
		child_1_process(pipefd, argvec, env);
	parent_process(pid1, pipefd);
	return (0);
}
