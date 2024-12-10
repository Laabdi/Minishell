/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 03:42:51 by aelomari          #+#    #+#             */
/*   Updated: 2024/11/15 08:00:34 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define MAX_HEREDOCS 16
# define MALLOC_FAILED \
	"\033[0;35mminishell\033[0m\033[0;32m \033[0m: \
malloc failed"
# define FALSE false
# define TRUE true
# define CMD_NOT_FOUND "Command '' not found\n"
// # define PROMPT "\033[0;35mMINIHELL∆\033[0m\033[0;32m➜ \033[0m"
# define HEREDOCMAXDELIM \
	"\033[0;35mminishell\033[0m\033[0;32m \033[0m: \
maximum here-document count exceeded"
# define PROMPT "\033[0;35mminishell\033[0m∆\033[0;32m➜❖ \033[0m"
# define SYNTPIPE \
	"\033[0;35mminishell\033[0m\033[0;32m \033[0m: \
syntax error near unexpected token `|'"
# define SNTPIPE2 \
	"\033[0;35mminishell\033[0m\033[0;32m \033[0m: \
syntax error near unexpected token `||'"
# define REDERROR \
	"\033[0;35mminishell\033[0m\033[0;32m \033[0m: \
syntax error near unexpected token `newline'"
# define REDERRO2 \
	"\033[0;35mminishell\033[0m\033[0;32m \033[0m: \
syntax error near unexpected token `>>'"

# define CMDNOTFOUND " : command not found\n"
# define CMDNOTFOUND2 " : No such file or directory\n"
# define MINISHELL "\033[0;35mminishell\033[0m\033[0;32m \033[0m: "
# define HEREDOC_PREFIX "/tmp/heredoc_"
#endif