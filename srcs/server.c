/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malrifai <malrifai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:34:12 by alrfa3i           #+#    #+#             */
/*   Updated: 2024/12/10 21:41:21 by malrifai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	sig_handler(int sig)
{
	static int	bit = 0;
	static int	i = 0;
	static char	buffer[1024];
	static int	index = 0;
	if (sig == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (i == '\0')
		{
			buffer[index] = '\0';
			ft_printf("%s\n", buffer);
			index = 0;
		}
		else
			buffer[index++] = i;
		bit = 0;
		i = 0;
	}
}
int	main(void)
{
    struct sigaction sa;
	pid_t	pid;

    sa.sa_handler = sig_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
    {
        ft_printf("Error: Failed to set SIGUSR1 handler\n");
        exit(EXIT_FAILURE);
    }
    if (sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        ft_printf("Error: Failed to set SIGUSR2 handler\n");
        exit(EXIT_FAILURE);
    }
	while (1)
		pause();
	return (0);
}
