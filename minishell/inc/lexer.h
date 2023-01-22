/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 08:55:35 by scornhol          #+#    #+#             */
/*   Updated: 2022/07/02 08:55:36 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "global.h"
# include "token.h"

# define WHITESPACES		" \t\n"
# define QUOT_MARKS			"\'\""

# define ERR_SYNTAX			"syntax error"
# define ERR_SYNTAX_EXIT	2

# define ERR_UNO_BRACKET	"unopened brackets"
# define ERR_UNC_BRACKET	"unclosed brackets"
# define ERR_EMPTY_BRACKET	"empty brackets"
# define ERR_REDIR			"invalid redirection"
# define ERR_QUOTE			"unclosed quotation mark"
# define ERR_LIST			"incomplete command list"
# define ERR_MISS_OP		"missing operator"
# define ERR_PIPE			"incomplete pipe"

// src/lexer/lexer.c
t_list	*lexer(char *input);

// src/lexer/lexer_syntax.c
int		lexer_syntax_check(t_list *l_token);

// src/lexer/lexer_token_other.c
int		lexer_token_bin_op(char *str, int *i, t_list **l_token);
int		lexer_token_redir(char *str, int *i, t_list **l_token);
int		lexer_token_pipe(char *str, int *i, t_list **l_token);
int		lexer_token_bracket(char *str, int *i, t_list **l_token);

// src/lexer/lexer_token_text.c
int		lexer_token_text(char *str, int *i, t_list **l_token);
int		lexer_token_quote(char *str, int *i, t_list **l_token);

#endif
