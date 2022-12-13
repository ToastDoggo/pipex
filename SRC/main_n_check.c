/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_n_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehernan <rehernan@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:17:39 by rehernan          #+#    #+#             */
/*   Updated: 2022/06/21 19:46:06 by rehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	input_checker(char **argv)
{
	int	yesno;
	int	i;

	i = -1;
	yesno = 0;
	while (argv[++i])
	{
		i++;
	}
	return (yesno);
}

char	**parsing_envp(char **envp)
{
	char	*path_from_envp;
	char	**mypaths;
	int		i;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
	}
	path_from_envp = &envp[i][5];
	mypaths = ft_split(path_from_envp, ':');
	i = -1;
	while (mypaths[++i])
		mypaths[i] = ft_strjoin(mypaths[i], "/");
	return (mypaths);
}

int	main(int argc, char *argv[], char **envp)
{
	int		fd[2];
	char	**paths[2];

	if (argc != 5)
		ft_exiterr(2);
	if (input_checker(argv) == 1)
		ft_exiterr(3);
	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] < 0)
		ft_exiterr(6);
	fd[1] = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd[1] < 0)
		ft_exiterr(6);
	paths[0] = parsing_envp(envp);
	paths[1] = envp;
	pipex(fd, argv, paths);
	return (0);
}
