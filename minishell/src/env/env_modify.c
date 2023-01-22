/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_modify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 08:55:18 by scornhol          #+#    #+#             */
/*   Updated: 2022/07/02 08:55:20 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/env.h"

int	env_unset_var(char *name)
{
	char	*env_var;

	env_var = env_find_var(name);
	if (!env_var)
		return (ERROR);
	split_remove_str(&g_env, env_var);
	return (0);
}

int	env_put_var(char *str)
{
	char	*old_var;
	char	*new_var;
	int		status;

	if (!str || !ft_strchr(str, '='))
		return (ERROR);
	new_var = ft_strdup(str);
	if (!new_var)
		return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));
	old_var = env_find_var(str);
	status = split_replace_str(&g_env, old_var, new_var);
	if (status == ERROR)
	{
		status = split_append_str(&g_env, new_var);
		if (status == ERROR)
			return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));
	}
	return (0);
}

int	env_set_env(char *name, char *value)
{
	char	*var_str;
	char	*tmp;
	int		status;

	if (!name || !value)
		return (ERROR);
	tmp = ft_strjoin(name, "=");
	if (!tmp)
		return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));
	var_str = ft_strjoin(tmp, value);
	free(tmp);
	if (!var_str)
		return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));
	status = env_put_var(var_str);
	free(var_str);
	return (status);
}
