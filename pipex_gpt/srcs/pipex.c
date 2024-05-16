/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:03:30 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/05/07 13:37:21 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	***cmd;
	int		fd[2];
	int		pid;
	char	**path_list;
	char	*path;
	int		path_index;
	int		fd_file;
	int		fd_output;
	// printf("envp[0]: %s\n", envp[0]);
	cmd = check_argv(argc, argv);
	if (!cmd)
		return (1);
	if (pipe(fd) == -1)
	{
		ft_putendl_fd(strerror(errno), 2);
		return (1);
	}

	// ファイルを読み取り専用で開く
	fd_file = open(argv[1], O_RDONLY);
	if (fd_file == -1) {
		perror("open");
		return 1;
	}
	
	pid = fork();
	if (pid == -1)
	{
		ft_putendl_fd(strerror(errno), 2);
		return (1);
	}
	if (pid == 0)
	{

		// ファイルディスクリプタを標準入力に置き換える
		if (dup2(fd_file, 0) == -1) {
			perror("dup2");
			close(fd_file); // ファイルディスクリプタを閉じる
			return 1;
		}
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		while (ft_strncmp(*envp, "PATH=", 5))
			envp++;
		// ft_putendl_fd(*envp, 2);
		path_list = ft_split(*envp + 5, ':');
		path_index = 0;
		while (path_list[path_index])
		{
			path = ft_strjoin(path_list[path_index], "/");
			path = ft_strjoin(path, cmd[0][0]);
			if (access(path, F_OK) == 0)
				break ;
			free(path);
			path_index++;
		}
		if (!path_list[path_index])
		{
			ft_putendl_fd("Error: command not found", 2);
			return (1);
		}
		execve(path, cmd[0], envp);
		ft_putendl_fd(strerror(errno), 2);
		return (1);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);

		// ファイルを書き込み専用で開く（存在しない場合は新規作成）
		fd_output = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd_output == -1) {
			perror("open");
			return 1;
		}

		// ファイルディスクリプタを標準出力に置き換える
		if (dup2(fd_output, 1) == -1) {
			perror("dup2");
			close(fd_output); // ファイルディスクリプタを閉じる
			return 1;
		}
		
		while (ft_strncmp(*envp, "PATH=", 5))
			envp++;
		// ft_putendl_fd(*envp, 2);
		path_list = ft_split(*envp + 5, ':');
		path_index = 0;
		while (path_list[path_index])
		{
			path = ft_strjoin(path_list[path_index], "/");
			path = ft_strjoin(path, cmd[1][0]);
			if (access(path, F_OK) == 0)
				break ;
			free(path);
			path_index++;
		}
		if (!path_list[path_index])
		{
			ft_putendl_fd("Error: command not found", 2);
			return (1);
		}
		execve(path, cmd[1], envp);
		ft_putendl_fd(strerror(errno), 2);
		return (1);
	}

	return (0);
}