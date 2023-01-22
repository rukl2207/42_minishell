/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 08:55:49 by scornhol          #+#    #+#             */
/*   Updated: 2022/07/02 08:55:50 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "global.h"

// src/signals/signals.c
void	signal_ctlc(int sig);
void	signal_ctlc_heredoc(int sig);
int		termios_change(bool echo_ctl_chr);

#endif
