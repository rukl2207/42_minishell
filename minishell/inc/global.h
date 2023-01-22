/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:01:38 by scornhol          #+#    #+#             */
/*   Updated: 2022/07/02 08:53:55 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# include <errno.h>
# include <limits.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>

# include "../libft/libft.h"

# define ERROR 		-1
# define PROMPT 	"$> "
# define SHELL_NAME	"minishell"
# define DEBUG_ENV	"DEBUG"

extern char	**g_env;

// src/utils/utils_error.c
int		print_error(char *s1, char *s2, char *s3, char *message);
int		print_error_errno(char *s1, char *s2, char *s3);

// src/utils/utils_gnl.c
char	*minishell_get_next_line(int fd);

// src/utils/utils_lst.c
int		lst_node_remove(t_list **lst, t_list *node, void (*del)(void *));
t_list	*lst_node_prev(t_list *lst, t_list *node);
int		lst_relink(t_list **lst, t_list *node, t_list *start, t_list *end);

// src/utils/utils_split.c
int		split_count(char **split);
int		split_append_str(char ***split, char *new_str);
int		split_remove_str(char ***split, char *remove_str);
int		split_replace_str(char ***split, char *old_str, char *new_str);
void	split_sort(char **split);

// src/utils/utils_str.c
char	*str_append_str(char *str, char *append);
char	*str_append_chr(char *str, char append);
char	str_last_chr(char *str);

#endif
