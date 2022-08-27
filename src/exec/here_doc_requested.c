/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_requested.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:56:46 by kbrousse          #+#    #+#             */
/*   Updated: 2022/08/27 17:31:29 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	here_doc_requested(t_pipex *pipex, char **argv)
{
	char	*user_input;
	int		length_limiter;
	int		pipefd[2];
	char	buf;
	
	if (pipe(pipefd) == -1)
		clear_program(pipex, "In HDR.c, malloc failed");
	length_limiter = ft_strlen(argv[2]);
	while (1)
	{
		ft_printf("heredoc> ");
		user_input = get_next_line(STD_IN);
		if (ft_strncmp(user_input, argv[2], length_limiter) == 0
		&& user_input[length_limiter + 1] == '\0')
		{
			free(user_input);
			close(pipefd[1]);
			break ;
		}
		ft_putstr_fd(user_input, pipefd[1]);
		free(user_input);
		user_input = NULL;
	}
	while (read(pipefd[0], &buf, 1) > 0)
		write(1, &buf, 1);
	close(pipefd[0]);
}
