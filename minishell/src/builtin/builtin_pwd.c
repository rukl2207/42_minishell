/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 08:54:52 by scornhol          #+#    #+#             */
/*   Updated: 2022/07/02 09:26:56 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtin.h"

int	builtin_pwd( \
	int argc __attribute__((unused)), \
	char **argv __attribute__((unused)))
{
	char	buf[PATH_MAX];

	if (getcwd(buf, sizeof(buf)))
	{
		ft_putendl_fd(buf, STDOUT_FILENO);
		return (EXIT_SUCCESS);
	}
	print_error_errno(SHELL_NAME, "pwd", NULL);
	return (EXIT_FAILURE);
}
