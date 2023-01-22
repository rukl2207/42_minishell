/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 08:53:01 by scornhol          #+#    #+#             */
/*   Updated: 2022/07/02 08:53:12 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "global.h"
# include "cmd.h"

# define WILDCARD	-1
# define VAR_SPACE	-1

// src/expand/expand.c
int		expand_var(t_c_scmd *c_scmd);
int		expand_wildcard(t_c_scmd *c_scmd);

// src/expand/expand_var_split.c
int		expand_var_splitting(t_list **l_token);

// src/expand/expand_var.c
int		expand_var_token_list(t_list *l_token);

// src/expand/expand_wildcard_utils.c
bool	expand_token_is_wildcard(t_list *token);
char	*expand_pattern_get(t_list *token);
char	*expand_wildcard_append_str(char *wildcard, t_list *token);
char	**expand_files_current_dir(void);
void	expand_wildcard_replace_connected(t_list **l_token, \
			t_list *old, t_list *new);

// src/expand/expand_wildcard.c
int		expand_wildcard_list(t_list	**l_token, char **files);

#endif