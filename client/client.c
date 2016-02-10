/*
** client.c for minitalk in /home/ghost/rendu/Programmation_Shell/PSU_2015_minitalk/src
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Sun Feb  7 22:35:55 2016 Baptiste Veyssiere
** Last update Wed Feb 10 15:53:17 2016 Baptiste Veyssiere
*/

char	*str;

#include "client.h"

void	client(int sig)
{
  static int	server_pid = 0;
  static int	i = -1;
  static char	bit_pos = 7;
  char		bit = 0;

  signal(SIGUSR1, client);
  if (server_pid == 0)
    server_pid = sig;
  if (i == my_strlen(str))
    exit(0);
  if (bit_pos == 7)
    ++i;
  bit = ((1 << bit_pos) & str[i]) >> bit_pos;
  --bit_pos;
  if (bit_pos == -1)
    bit_pos = 7;
  if (bit == 1)
    kill(server_pid, SIGUSR1);
  else
    kill(server_pid, SIGUSR2);
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
  signal(SIGUSR1, client);
  server_pid = my_getnbr(av[1]);
  send_pid(getpid(), server_pid);
  str = av[2];
  client(server_pid);
  while (1)
    pause();
  return (0);
}
