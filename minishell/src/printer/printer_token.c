/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 08:57:41 by scornhol          #+#    #+#             */
/*   Updated: 2022/07/02 08:57:45 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/printer.h"
#include "../../inc/token.h"

void	printer_token(t_list *l_token)
{
	printf("\e[37;7mTOKEN:\t\t\e[m");
	if (l_token != NULL)
	{
		while (l_token->next != NULL)
		{
			if (token_content(l_token)->flags & TOK_CONNECTED)
				printf("%s \033[0;35m+ \033[m", token_content(l_token)->str);
			else
				printf("%s \033[0;32m: \033[m", token_content(l_token)->str);
			l_token = l_token->next;
		}
		printf("%s\n", token_content(l_token)->str);
	}
}
