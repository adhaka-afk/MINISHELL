/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:06:38 by eweiberl          #+#    #+#             */
/*   Updated: 2023/12/04 09:50:38 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/// @brief Tests if the character is a ' or "
/// @param c the character to test
/// @return 1 if it is, otherwise 0
int	ft_isquote(char c)
{
	if (c == '\'' || c == '"')
		return (1);
	return (0);
}

/// @brief Tests if the character is a whitespace
/// @param c the character to test
/// @return 1 if it is, otherwise 0
int	ft_isblank(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}
