/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:16:43 by aelomari          #+#    #+#             */
/*   Updated: 2024/11/07 01:20:20 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/Minishell.h"

// void	check_redirect(t_var *var)
// {
// 	char	**tochek;
// 	int		i;

// 	i = 0;
// 	tochek = ft_split(var->line, ' ');
// 	if (!tochek)
// 		return ;
// 	while (tochek[i])
// 	{
// 		if (tochek[i][0] == '>' || tochek[i][0] == '<')
// 		{
// 			if ((tochek[i][1] == '>' && tochek[i][2] != '\0'
// 					&& tochek[i][2] != '>') || (tochek[i][1] != '>'
// 					&& tochek[i][1] != '\0'))
// 			{
// 				if (tochek[i][1] == '<' && (tochek[i][2] == '\0' && !tochek[i
// 						+ 1]))
// 					return ((void)free_all(tochek),
// 						thisisasynerror(ERROR_REDIR),
// 						(void)(var->synerrflag = TRUE));
// 			}
// 			else if (tochek[i][1] == '>' && tochek[i][2] == '>')
// 			{
// 				return ((void)free_all(tochek), thisisasynerror(ERROR_REDI2),
// 					(void)(var->synerrflag = TRUE));
// 			}
// 			else if ((tochek[i][1] == '>' && (tochek[i + 1] == NULL || tochek[i
// 						+ 1][0] == '>' || tochek[i + 1][0] == '<'))
// 				|| (tochek[i][1] == '\0' && (tochek[i + 1] == NULL || tochek[i
// 						+ 1][0] == '>' || tochek[i + 1][0] == '<'))
// 				|| (tochek[i][1] == '<' && tochek[i + 1] == NULL))
// 				return ((void)free_all(tochek), thisisasynerror(ERROR_REDIR),
// 					(void)(var->synerrflag = TRUE));
// 		}
// 		i++;
// 	}
// 	free_all(tochek);
// }

static int	check_double_redirect(char *token)
{
	(t_unused) token;
	if ((token[1] == '>' && token[2] == '>') || (token[1] == '<'
			&& token[2] == '<'))
	{
		thisisasynerror(ERROR_REDIR);
		return (1);
	}
	return (0);
}

static int	check_single_redirect(char **tochek, int i)
{
	if ((tochek[i][1] == '>' && tochek[i][2] != '\0' && tochek[i][2] != '>')
		|| (tochek[i][1] != '>' && tochek[i][1] != '\0'))
	{
		if (tochek[i][1] == '<' && (tochek[i][2] == '\0' && !tochek[i + 1]))
		{
			thisisasynerror(ERROR_REDI2);
			return (1);
		}
	}
	else if ((tochek[i][1] == '>' && (tochek[i + 1] == NULL || tochek[i
				+ 1][0] == '>' || tochek[i + 1][0] == '<'))
		|| (tochek[i][1] == '\0' && (tochek[i + 1] == NULL || tochek[i
				+ 1][0] == '>' || tochek[i + 1][0] == '<'))
		|| (tochek[i][1] == '<' && tochek[i + 1] == NULL))
	{
		thisisasynerror(ERROR_REDI2);
		return (1);
	}
	return (0);
}

static int	check_redirect_syntax(char **tochek, int i)
{
	if (check_double_redirect(tochek[i]))
		return (1);
	if (check_single_redirect(tochek, i))
		return (1);
	return (0);
}

void	check_redirect(t_var *var)
{
	char	**tochek;
	int		i;

	tochek = ft_split(var->line, ' ');
	if (!tochek)
		return ;
	i = 0;
	while (tochek[i])
	{
		if (tochek[i][0] == '>' || tochek[i][0] == '<')
		{
			if (check_redirect_syntax(tochek, i))
			{
				free_all(tochek);
				var->synerrflag = TRUE;
				return ;
			}
		}
		i++;
	}
	free_all(tochek);
}
