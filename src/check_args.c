/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:12:51 by kbrousse          #+#    #+#             */
/*   Updated: 2022/08/17 20:03:23 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args_first_half(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		clear_program("Open failed");
	if (close(fd) == -1)
		clear_program("Close failed");
						ft_printf("Open et read succedeed\n"); // A SUPPRIMER



//PSEDO CODE POUR VERIF ACCESS CMD1
	while (ft_strncmp("PATH", *env, 4) != 0)
		*env++;
	if (*env == NULL)
		clear_program
	temp = *env + 5; 5 = !PATH=!
	str = split(*env, ":")
	while (str[i] != NULL)
	{
		str2 = join(str[i], argv[2]);
		access(str2);
	}


	if (access("/bin/ls", F_OK) == -1)
		clear_program("access failed");
}
