/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_funcs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:18:04 by eweiberl          #+#    #+#             */
/*   Updated: 2023/12/04 09:52:26 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mock_functions.h"

/// @brief Fails malloc on the FAILTIMEth call
/// @param size
/// @throw malloc could still fail
/// @return NULL on the FAILTIMEth try
void	*t_malloc(size_t size)
{
	static int	i = 1;

	if (i == FAIL_TIME)
		return (NULL);
	return (malloc(size));
}

/// @brief Fails ft_calloc on the FAILTIMEth call
/// @param nmemb
/// @param size
/// @throw malloc could still fail
/// @return NULL on the FAILTIMEth call otherwise ft_calloc
void	*t_ft_calloc(size_t nmemb, size_t size)
{
	static int	i = 1;

	if (i == FAIL_TIME)
		return (NULL);
	return (ft_calloc(nmemb, size));
}

/// @brief Fails pipe on the FAILTIMEth call
/// @param pipefd
/// @throw pipe could still fail
/// @return -1 on the FAILTIMEth call otherwise pipe
// int	t_pipe(int pipefd[2])
// {
// 	static int	i = 1;

// 	if (i == FAIL_TIME)
// 		return (-1);
// 	return (pipe(pipefd));
// }

/// @brief Fails a call to open on the FAILTIMEth call
/// @param pathname
/// @param flags
/// @param mode
/// @return -1 on the FAILTIMEth call otherwise open
int	t_open(const char *pathname, int flags, mode_t mode)
{
	static int	i = 0;

	if (i == FAIL_TIME)
		return (-1);
	return (open(pathname, flags, mode));
}
