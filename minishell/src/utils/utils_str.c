/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 08:58:32 by scornhol          #+#    #+#             */
/*   Updated: 2022/07/02 08:58:35 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/global.h"

char	*str_append_str(char *str, char *append)
{
	char	*tmp;

	tmp = str;
	str = ft_strjoin(str, append);
	free(tmp);
	return (str);
}

char	*str_append_chr(char *str, char append)
{
	char	*new_str;
	int		i;

	if (!str)
		return (NULL);
	new_str = malloc(ft_strlen(str) + 2);
	if (new_str)
	{
		i = 0;
		while (str[i])
		{
			new_str[i] = str[i];
			i++;
		}
		new_str[i] = append;
		new_str[i + 1] = '\0';
	}
	free(str);
	return (new_str);
}

char	str_last_chr(char *str)
{
	if (str[0] != '\0')
		return (str[ft_strlen(str) - 1]);
	else
		return ('\0');
}
