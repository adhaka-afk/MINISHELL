/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_functions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:27:32 by eweiberl          #+#    #+#             */
/*   Updated: 2023/12/04 09:52:19 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOCK_FUNCTIONS_H
# define MOCK_FUNCTIONS_H

# ifndef FAIL_TIME
#  define FAIL_TIME 10
# endif

# include "../libft/libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

void	*t_malloc(size_t size);
void	*t_ft_calloc(size_t nmemb, size_t size);
int		t_pipe(int pipefd[2]);
int		t_open(const char *pathname, int flags, mode_t mode);

#endif
