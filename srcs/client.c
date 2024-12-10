/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malrifai <malrifai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:28:10 by alrfa3i           #+#    #+#             */
/*   Updated: 2024/12/10 20:50:29 by malrifai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minitalk.h"

void error_handling(char *message, int sig)
{   
    if(sig == SIGUSR1)
        ft_printf("Error: Failed to send SIGUSR1\n");
    else
        ft_printf("Error: Failed to send SIGUSR2\n");
    free(message);
}

void	send_bits(pid_t pid, char c, char *msg)
{
	int	bit;
	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)) != 0)
        {
			if (kill(pid, SIGUSR1) == -1)
                return error_handling(msg, SIGUSR1);
        }
		else
			if (kill(pid, SIGUSR2) == -1)
                return error_handling(msg, SIGUSR2);
		usleep(300);
		bit++;
	}
}
int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*msg;
    int     i;
    
	if (argc != 3)
	{
		ft_printf("Error: ./client <PID> <MESSAGE>\n");
		return (1);
	}
    i = 0;
    pid = ft_atoi(argv[1]);
	msg = argv[2];
	while (msg[i] != '\0')
	{
		send_bits(pid, msg[i], msg);
		i++;
	}
	send_bits(pid, '\0', msg);
	return (0);
}
