/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:47:34 by alevra            #+#    #+#             */
/*   Updated: 2023/02/10 02:15:21 by alevra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	freepath(char **paths);

char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path_w_slash;
	char	*path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path_w_slash = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path_w_slash, cmd);
		free(path_w_slash);
		if (access(path, F_OK) == 0)
			return (freepath(paths), free(paths), path);
		free(path);
		i++;
	}
	return (freepath(paths), free(paths), NULL);
}

static void	freepath(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
		free(paths[i++]);
}
