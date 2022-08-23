/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 02:34:11 by kbrousse          #+#    #+#             */
/*   Updated: 2022/08/23 02:35:03 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	path_line_length(char *copy)
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
