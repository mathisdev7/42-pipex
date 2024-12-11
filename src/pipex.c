/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:19:24 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/11 20:19:24 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <sys/wait.h>

void child_read(int end[2], char *cmd, char *file)
{
    char    **cmd_args;
    int     infile;

    infile = open(file, O_RDONLY);
    if (infile == -1)
        exit(EXIT_FAILURE);
    cmd_args = ft_split(cmd, ' ');
    if (!cmd_args)
        exit(EXIT_FAILURE);
    if (dup2(infile, STDIN_FILENO) == -1)
        exit(EXIT_FAILURE);
    if (dup2(end[1], STDOUT_FILENO) == -1)
        exit(EXIT_FAILURE);
    close(infile);
    close(end[0]);
    close(end[1]);
    execvp(cmd_args[0], cmd_args);
    exit(EXIT_FAILURE);
}

void close_fd(int outfile, int *end)
{
	close(outfile);
    close(end[0]);
    close(end[1]);
}

void parent_write(int end[2], char *cmd, char *file)
{
    char    **cmd_args;
    int     outfile;
    int     status;
    pid_t   pid;

    outfile = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (outfile == -1)
        exit(EXIT_FAILURE);
    pid = fork();
    if (pid == -1)
        exit(EXIT_FAILURE);
    if (pid == 0)
	{
        cmd_args = ft_split(cmd, ' ');
        if (!cmd_args)
            exit(EXIT_FAILURE);
        if (dup2(end[0], STDIN_FILENO) == -1 || dup2(outfile, STDOUT_FILENO) == -1)
            exit(EXIT_FAILURE);
        close_fd(outfile, end);
        execvp(cmd_args[0], cmd_args);
        exit(EXIT_FAILURE);
    }
    close_fd(outfile, end);
    waitpid(pid, &status, 0);
}

int main(int argc, char **argv, char **envp)
{
	(void)envp;
    int     p_fd[2];
    pid_t   pid;

    if (argc != 5)
        ft_exit(1);
    if (pipe(p_fd) == -1)
        exit(EXIT_FAILURE);
    pid = fork();
    if (pid == -1)
        exit(EXIT_FAILURE);
    if (pid == 0)
        child_read(p_fd, argv[2], argv[1]);
    else
        parent_write(p_fd, argv[3], argv[4]);
    return (0);
}
