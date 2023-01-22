/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 08:52:55 by scornhol          #+#    #+#             */
/*   Updated: 2022/07/02 08:52:57 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "global.h"
# include "redir.h"

# define EXEC_NOEXEC	126
# define EXEC_NOTFOUND	127

// src/exec/exec.c
int		exec_recursive(t_list *l_cmd, bool subshell, t_list *l_free);
void	exec_free_all(char **argv, t_list *l_free);

// src/exec/exec_exit_status.c
int		exec_exit_status_get(void);
void	exec_exit_status_set(int status);

// src/exec/exec_group.c
int		exec_group(t_list *l_cmd, t_list *l_free);

// src/exec/exec_pipeline_pipes.c
void	exec_pipeline_pipes_close(int pipes[2][2], int i, bool last);
void	exec_pipeline_pipes_set(int fd[2], int pipes[2][2], int i, bool last);
void	exec_pipeline_pipes_init(int pipes[2][2]);

// src/exec/exec_pipeline.c
int		exec_pipeline(t_list *pipeline, t_list *l_free);

// src/exec/exec_scmd_path.c
int		exec_scmd_search_path(char **argv);

// src/exec/exec_scmd.c
int		exec_scmd(t_list *scmd, bool subshell, t_list *l_free);
int		exec_scmd_preperation(t_list *scmd, char ***argv);
int		exec_scmd_exec(char **argv);
void	exec_scmd_free_exit(int status, char **argv, t_list *l_free);

// src/exec/exec_wait.c
int		exec_wait_pid(int last_pid, char *name);
int		exec_wait_for_all(int last_pid);

#endif
