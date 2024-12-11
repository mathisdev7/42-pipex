/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:24:42 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/11 20:24:42 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_putstr_fd(char *s, int fd);
void	ft_exit(int exit_nbr);
char	**ft_split(char *str, char c);
int 	dup2(int oldfd, int newfd);

#endif
