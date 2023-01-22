/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 08:55:43 by scornhol          #+#    #+#             */
/*   Updated: 2022/07/02 08:55:44 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_H
# define PRINTER_H

# include <stdio.h>
# include "global.h"
# include "cmd.h"

// src/printer/printer_cmd.c
void	printer_cmd(t_list *l_cmd);
void	printer_structure(t_list *l_cmd);

// src/printer/printer_scmd.c
void	printer_scmd(t_c_scmd *scmd);
void	printer_other(int type);
void	printer_scmd_pipeline(t_list *l_scmd_pipeline, bool newline);

// src/printer/printer_token.c
void	printer_token(t_list *l_token);

#endif
