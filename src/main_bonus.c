/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:29:47 by kbrousse          #+#    #+#             */
/*   Updated: 2022/08/24 16:32:13 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	*pipex;

	if (argc < 5)
		return (ft_printf("Usage is <<< ./pipex infile cmd_1 cmd_2"\
		" ... cmd_n outfile >>>\n"));
	pipex = ft_calloc(1, sizeof(t_pipex));
	if (pipex == NULL)
		return (-1);
	init_pipex(pipex, argc);
	check_args(pipex, argc, argv, env);
	if (argc >= 5)
		prepare_bonus(pipex, argc, argv, env);	
	clear_program(pipex, NULL);
	return (0);
}
