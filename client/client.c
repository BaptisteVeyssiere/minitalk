/*
** client.c for minitalk in /home/ghost/rendu/Programmation_Shell/PSU_2015_minitalk/src
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Sun Feb  7 22:35:55 2016 Baptiste Veyssiere
** Last update Wed Feb 10 03:39:54 2016 Baptiste Veyssiere
*/

#include "client.h"

void	handler(int sig)
{
  if (sig == SIGUSR1)
    signal(SIGUSR1, handler);
}

void	client(int server_pid, char *str)
{
  int	i;
  char	bit_pos;
  char	bit;

  i = -1;
  while (++i < my_strlen(str))
    {
      bit_pos = 8;
      while (--bit_pos > -1)
	{
	  bit = ((1 << bit_pos) & str[i]) >> bit_pos;
	  if (bit == 1)
	    kill(server_pid, SIGUSR1);
	  else
	    kill(server_pid, SIGUSR2);
	  pause();
	}
    }
}

void	send_pid(int pid, int server_pid)
{
  char	bit_pos;
  char	bit;

  bit_pos = -1;
  while (++bit_pos < 32)
    {
      bit = ((1 << bit_pos) & pid) >> bit_pos;
      if (bit == 1)
	kill(server_pid, SIGUSR1);
      else
	kill(server_pid, SIGUSR2);
      usleep(1500);
    }
}

int	main(int ac, char **av, char **env)
{
  int	server_pid;

  if (ac != 3 || env == NULL)
    return (-1);
  signal(SIGUSR1, handler);
  server_pid = my_getnbr(av[1]);
  send_pid(getpid(), server_pid);
  client(server_pid, av[2]);
  return (0);
}
