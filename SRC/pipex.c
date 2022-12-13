/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehernan <rehernan@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 11:23:59 by rehernan          #+#    #+#             */
/*   Updated: 2022/06/21 19:53:12 by rehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child_process(int fd[2], int fd1, char **cmd1, char ***mypaths)
{
	int		i;
	char	*cmd;

	dup2 (fd1, STDIN_FILENO);
	dup2 (fd[1], STDOUT_FILENO);
	close (fd[0]);
	close (fd1);
	i = -1;
	execve(cmd1[0], cmd1, mypaths[1]);
	while (mypaths[0][++i])
	{
		cmd = ft_strjoin(mypaths[0][i], cmd1[0]);
		execve(cmd, cmd1, mypaths[1]);
		free (cmd);
	}
	exit (EXIT_FAILURE);
}

int	parent_process(int fd[2], int fd2, char **cmd2, char ***mypaths)
{
	int		status;
	int		i;
	char	*cmd;

	dup2(fd2, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	waitpid(-1, &status, 0);
	close(fd[1]);
	close(fd2);
	i = -1;
	execve(cmd2[0], cmd2, mypaths[1]);
	while (mypaths[0][++i])
	{
		cmd = ft_strjoin(mypaths[0][i], cmd2[0]);
		execve(cmd, cmd2, mypaths[1]);
		free (cmd);
	}
	exit(EXIT_FAILURE);
}

char	**parsing(char *argv)
{
	char	**mycmdargs;

	mycmdargs = ft_split(argv, ' ');
	return (mycmdargs);
}

void	pipex(int *fds, char **argv, char ***mypaths)
{
	int		fd[2];
	pid_t	id;
	char	**cmd;

	if (pipe(fd) == -1)
		ft_exiterr(1);
	id = fork ();
	if (id < 0)
		ft_exiterr(4);
	if (!id)
	{
		cmd = parsing(argv[2]);
		child_process(fd, fds[0], cmd, mypaths);
	}
	else
	{
		cmd = parsing(argv[3]);
		parent_process(fd, fds[1], cmd, mypaths);
	}
}
