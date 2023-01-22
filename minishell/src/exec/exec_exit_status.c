/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exit_status.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 08:56:07 by scornhol          #+#    #+#             */
/*   Updated: 2022/07/02 08:56:09 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/exec.h"

static int	*exit_status_pointer(void)
{
	static int	last_exit_status = 0;

	return (&last_exit_status);
}

int	exec_exit_status_get(void)
{
	return (*exit_status_pointer());
}

void	exec_exit_status_set(int status)
{
	if (status == ERROR)
		status = EXIT_FAILURE;
	*exit_status_pointer() = status;
}
