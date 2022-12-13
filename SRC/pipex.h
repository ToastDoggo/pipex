/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehernan <rehernan@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:13:35 by rehernan          #+#    #+#             */
/*   Updated: 2022/06/21 19:27:26 by rehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../ft_printf/ft_printf.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

void	ft_exiterr(int err);
void	pipex(int *fds, char **argv, char ***mypaths);

#endif