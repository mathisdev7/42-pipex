/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:26:38 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/11 20:26:38 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(int exit_nbr)
{
	if (exit_nbr == 1)
		ft_putstr_fd("Error, the command must follow this syntax:\n./pipex infile cmd1 cmd2 outfile\n", 2);
	exit(0);
}
