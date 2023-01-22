/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 08:54:35 by scornhol          #+#    #+#             */
/*   Updated: 2022/07/02 09:26:40 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtin.h"
#include "../../inc/env.h"

static char	*get_dir(int argc, char **argv)
{
	char	*dir;

	dir = NULL;
	if (argc == 1)
	{
		dir = env_get_value("HOME");
		if (!dir)
			print_error(SHELL_NAME, "cd", NULL, "HOME not set");
	}
	else if (argv[1] && ft_strncmp(argv[1], "-", 2) == 0)
	{
		dir = env_get_value("OLDPWD");
		if (!dir)
			print_error(SHELL_NAME, "cd", NULL, "OLDPWD not set");
	}
	else
		dir = argv[1];
	return (dir);
}

static int	update_pwd(void)
{
	char	buf[PATH_MAX];

	if (env_get_value("PWD"))
	{
		if (env_set_env("OLDPWD", env_get_value("PWD")) == ERROR)
			return (ERROR);
	}
	else
		env_unset_var("OLDPWD");
	if (getcwd(buf, sizeof(buf)) == NULL)
	{
		print_error_errno(SHELL_NAME, "cd", NULL);
		return (ERROR);
	}
	if (env_set_env("PWD", buf) == ERROR)
		return (ERROR);
	return (0);
}

int	builtin_cd(int argc, char **argv)
{
	char	*dir;

	dir = get_dir(argc, argv);
	if (!dir)
		return (EXIT_FAILURE);
	if (chdir(dir) == -1)
	{
		print_error_errno(SHELL_NAME, "cd", dir);
		return (EXIT_FAILURE);
	}
	if (argv[1] && ft_strncmp(argv[1], "-", 2) == 0)
		ft_putendl_fd(dir, STDOUT_FILENO);
	if (update_pwd() == ERROR)
		return (EXIT_FAILURE);
	return (0);
}
