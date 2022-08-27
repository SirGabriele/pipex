/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_cmd_access.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 02:13:44 by kbrousse          #+#    #+#             */
/*   Updated: 2022/08/23 06:50:31 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

static void	verify_access(t_pipex *pipex, t_pipex_cmd *copy)
{
	int			i;
	char		*path_line;
	char		*path_line_temp;

	i = -1;
	while (++i < 10)
	{
		path_line_temp = ft_strjoin(pipex->tab_env_paths[i], "/");
		path_line = ft_strjoin(path_line_temp, copy->tab_cmd[0]);
		free(path_line_temp);
		path_line_temp = NULL;
		if (access(path_line, F_OK) == -1 && i == 9)
		{
			free(path_line);
			path_line = NULL;
			clear_program(pipex, "Access failed");
		}
		else if (access(path_line, F_OK) == 0)
			break ;
		free(path_line);
		path_line = NULL;
	}
	copy->correct_path = ft_strdup(path_line);
	free(path_line);
	path_line = NULL;
}

static void	fill_tab_cmd(t_pipex *pipex, int argc, char **argv)
{
	t_pipex_cmd	*copy;
	int			i;

	copy = pipex->first_cmd;
	i = 1;
	while (copy != NULL && ++i < argc - 1)
	{
		copy->tab_cmd = ft_split(argv[i], ' ');
		copy = copy->next;
	}
}

static int	path_line_length(char *copy)
{
	int		i;
	char	*temp;
	int		count;

	count = 0;
	i = 0;
	temp = copy;
	while (temp[i] != '\n' && temp[i] != '\0')
	{
		i++;
		count++;
	}
	return (count);
}

static char	*extract_path_lines(t_pipex *pipex, char **env)
{
	char	*copy_env;
	char	*path_line;
	int		i;

	copy_env = *env;
	while (ft_strncmp("PATH=/n", copy_env, 7) != 0)
		copy_env++;
	if (copy_env == NULL)
		clear_program(pipex, "Path line not found");
	copy_env = copy_env + 5;
	path_line = (char *)malloc(sizeof(char) * path_line_length(copy_env) + 1);
	i = 0;
	while (copy_env[i] != '\n' && copy_env[i] != '\0')
	{
		path_line[i] = copy_env[i];
		i++;
	}
	path_line[i] = '\0';
	pipex->tab_env_paths = ft_split(path_line, ':');
	free(path_line);
	path_line = NULL;
	return (path_line);
}

void	verify_cmd_access(t_pipex *pipex, int argc, char **argv, char **env)
{
	int			i;
	t_pipex_cmd	*copy;

	i = 1;
	copy = pipex->first_cmd;
	extract_path_lines(pipex, env);
	fill_tab_cmd(pipex, argc, argv);
	while (++i < argc - 1)
	{
		if (access(copy->tab_cmd[0], F_OK) == 0)
			copy->correct_path = ft_strdup(copy->tab_cmd[0]);
		else
			verify_access(pipex, copy);
		copy = copy->next;
	}
}
