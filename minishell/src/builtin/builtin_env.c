/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 08:54:42 by scornhol          #+#    #+#             */
/*   Updated: 2022/07/02 09:26:48 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtin.h"

int	builtin_env( \
	int argc __attribute__((unused)), \
	char **argv __attribute__((unused)))
{
	int	i;

	if (!g_env)
	{
		print_error(SHELL_NAME, "env", NULL, "environ not set");
		return (EXIT_FAILURE);
	}
	i = 0;
	while (g_env[i])
	{
		ft_putendl_fd(g_env[i], STDOUT_FILENO);
		i++;
	}
	return (0);
}
