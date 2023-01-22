/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 08:52:51 by scornhol          #+#    #+#             */
/*   Updated: 2022/07/02 08:52:53 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "global.h"

// src/env/env.c
int		env_init(void);
char	*env_get_value(char *name);
char	*env_find_var(char *name);
bool	env_var_is_value(char *var_name, char *value);
bool	env_is_var_char(char c);

// src/env/env_modify.c
int		env_unset_var(char *name);
int		env_put_var(char *str);
int		env_set_env(char *name, char *value);

#endif
