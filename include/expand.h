/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 03:26:41 by aelomari          #+#    #+#             */
/*   Updated: 2024/10/17 23:12:30 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(EXPAND_H)
# define EXPAND_H
# include "Minishell.h"

int		count_dollar(char *line);
int		lendchar(char **arr);
char	**get_variable(char *line, char **variable);
char	*handle_special(char **variable, int i);
char	**get_value(char **variable, char **value);
char	*get_new_line(char *line, char **variable, char **value);
char	*remove_dollar(char *line);
int		lendchar(char **arr);
char	*my_getenv(const char *name);
char	**get_value(char **variable, char **value);

#endif // EXPAND_H
