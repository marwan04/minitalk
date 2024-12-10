/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malrifai <malrifai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:34:17 by alrfa3i           #+#    #+#             */
/*   Updated: 2024/12/10 21:03:06 by malrifai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
#define BUFFER_SIZE 1024

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include <limits.h>

void sig_handler(int sig);

#endif
