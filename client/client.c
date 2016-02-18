/*
** client.c for minitalk in /home/ghost/rendu/Programmation_Shell/PSU_2015_minitalk/src
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Sun Feb  7 22:35:55 2016 Baptiste Veyssiere
** Last update Thu Feb 18 20:23:17 2016 Baptiste Veyssiere
*/

char	*str;

#include "client.h"

void	client(int sig)
{
  static int	server_pid = 0;
  static int	i = -1;
  static char	bit_pos = 7;
  static int	length = 0;
  char		bit = 0;

  if (length == 0)
    length = my_strlen(str);
  if (server_pid == 0)
    server_pid = sig;
  if (i == length)
    exit(0);
  if (bit_pos == 7)
    ++i;
  bit = ((str[i]) >> bit_pos);
  --bit_pos;
  if (bit_pos == -1)
    bit_pos = 7;
  if ((bit & 1) == 1)
    {
      if (kill(server_pid, SIGUSR1) == -1)
	exit(-1);
    }
  else if (kill(server_pid, SIGUSR2) == -1)
    exit(-1);
}

void	send_pid(int pid, int server_pid)
{
  char	bit_pos;
  char	bit;

  bit_pos = -1;
  while (++bit_pos < 32)
    {
      bit = pid >> bit_pos;
      if ((bit & 1) == 1)
	{
	  if (kill(server_pid, SIGUSR1) == -1)
	    exit(-1);
	}
      else if (kill(server_pid, SIGUSR2) == -1)
	exit(-1);
      usleep(1500);
    }
}

int	main(int ac, char **av, char **env)
{
  int	server_pid;

  if (ac != 3 || env == NULL)
    return (-1);
  if (signal(SIGUSR1, client) == SIG_ERR)
    return (-1);
  server_pid = my_getnbr(av[1]);
  if (server_pid < 1)
    return (0);
  send_pid(getpid(), server_pid);
  str = av[2];
  client(server_pid);
  while (1)
    pause();
  return (0);
}
