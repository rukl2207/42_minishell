/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 08:55:40 by scornhol          #+#    #+#             */
/*   Updated: 2022/07/02 08:55:41 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "global.h"
# include "cmd.h"
# include "token.h"

// src/parser/parser.c
t_list	*parser(t_list *l_token);

// src/parser/parser_group.c
int		parser_cmd_group_merge(t_list **l_cmd);

// src/parser/parser_heredoc.c
int		parser_heredoc(t_list *l_token);

// src/parser/parser_pipeline.c
int		parser_cmd_pipeline_merge(t_list **l_cmd);

// src/parser/parser_scmd.c
t_list	*parser_scmd_tokens(t_list *l_token);

#endif
