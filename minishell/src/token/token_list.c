/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 08:58:06 by scornhol          #+#    #+#             */
/*   Updated: 2022/07/02 08:58:09 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/token.h"

static int	l_token_count_strings(t_list *l_token)
{
	int	i;

	i = 0;
	while (l_token)
	{
		if (!(token_content(l_token)->flags & TOK_CONNECTED))
			i++;
		l_token = l_token->next;
	}
	return (i);
}

static int	l_token_append_connected(t_list **l_token, char **split_str)
{
	char	*tmp;

	while (token_content(*l_token)->flags & TOK_CONNECTED)
	{
		tmp = *split_str;
		*split_str = ft_strjoin(*split_str, \
				token_content((*l_token)->next)->str);
		free(tmp);
		if (*split_str == NULL)
			return (ERROR);
		*l_token = (*l_token)->next;
	}
	return (0);
}

char	**l_token_to_split(t_list *l_token)
{
	t_list	*iter;
	char	**split;
	int		i;

	if (!l_token)
		return (NULL);
	split = malloc((l_token_count_strings(l_token) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	iter = l_token;
	while (iter)
	{
		split[i] = ft_strdup(token_content(iter)->str);
		if (!split[i] || l_token_append_connected(&iter, &split[i]) == ERROR)
		{
			ft_free_split(&split);
			return (NULL);
		}
		iter = iter->next;
		i++;
	}
	split[i] = NULL;
	return (split);
}
