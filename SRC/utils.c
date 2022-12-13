/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehernan <rehernan@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:48:47 by rehernan          #+#    #+#             */
/*   Updated: 2022/11/16 09:41:20 by rehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exiterr(int err)
{
	if (err == 1)
		ft_putstr_fd("Pipe error.\n", 2);
	else if (err == 2)
		ft_putstr_fd("Not enough arguments.\n", 2);
	else if (err == 3)
		ft_putstr_fd("Invalid arguments.\n", 2);
	else if (err == 4)
		ft_putstr_fd("Fork error.\n", 2);
	else if (err == 5)
		ft_putstr_fd("File descriptor error (dup2).\n", 2);
	else if (err == 6)
		ft_putstr_fd("File descriptor error (open).\n", 2);
	else if (err == 7)
		ft_putstr_fd("The command doesn't exist.\n", 2);
	exit (1);
}
