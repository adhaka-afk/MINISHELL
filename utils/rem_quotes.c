/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rem_quotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:21:26 by eweiberl          #+#    #+#             */
/*   Updated: 2023/12/04 09:50:57 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*copy_quotes(char *str, char *output, int *i_str, int *i_output);
static char	*replace_quotes(char *str, char **split);
static int	skip_whitespaces(char *str, int i);

int	rem_quotes(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		split[i] = replace_quotes(split[i], split);
		if (split[i] == NULL)
			return (ft_fprintf(2, "malloc fail in rem_quotes\n"), 1);
		i++;
	}
	return (0);
}

static char	*replace_quotes(char *str, char **split)
{
	int		i_str;
	int		i_output;
	char	*output;

	if (ft_strchr(str, '"') == NULL && ft_strchr(str, '\'') == NULL)
		return (str);
	output = ft_calloc(ft_strlen(str), sizeof(char));
	if (output == NULL)
		return (free_strings((void **)split), NULL);
	i_str = 0;
	i_output = 0;
	while (str[i_str] != '\0')
	{
		i_str = skip_whitespaces(str, i_str);
		while (str[i_str] && !ft_isblank(str[i_str]) && !ft_isquote(str[i_str]))
			output[i_output++] = str[i_str++];
		if (str[i_str] && ft_isblank(str[i_str]) == 1)
			output[i_output++] = str[i_str++];
		if (str[i_str] != '\0' && ft_isquote(str[i_str]) != 0)
			output = copy_quotes(str, output, &i_str, &i_output);
	}
	free(str);
	return (output);
}

/// @brief Copies the quoted sections of the str and if needed a space
/// @param str the str to copy from
/// @param output the destination
/// @param i_str the start position in the str
/// @param i_output start position in the destination
/// @return a pointer to the str
static char	*copy_quotes(char *str, char *output, int *i_str, int *i_output)
{
	char	type;

	type = str[*i_str];
	(*i_str)++;
	while (str[*i_str] != type)
	{
		output[*i_output] = str[*i_str];
		(*i_str)++;
		(*i_output)++;
	}
	(*i_str)++;
	if (str[*i_str] == ' ' || str[*i_str] == '\t')
	{
		output[*i_output] = str[*i_str];
		(*i_str)++;
		(*i_output)++;
	}
	*i_str = skip_whitespaces(str, *i_str);
	return (output);
}

/// @brief Skips the whitespaces
/// @param str the string to skip in
/// @param i the position in string
/// @throw isnt NULL protected
/// @return the first non whitespace position after i
static int	skip_whitespaces(char *str, int i)
{
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
		i++;
	return (i);
}
