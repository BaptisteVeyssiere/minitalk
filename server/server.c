/*
** server.c for minitalk in /home/ghost/rendu/Programmation_Shell/PSU_2015_minitalk/src
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Sun Feb  7 22:36:59 2016 Baptiste Veyssiere
** Last update Wed Feb 10 15:22:11 2016 Baptiste Veyssiere
*/

#include "server.h"

int	pid;

void		get_pid(int sig)
{
  static char	bit_nb = 0;

  if (sig == SIGUSR1)
    pid = ((1 << bit_nb) | pid);
  ++bit_nb;
  if (bit_nb == 32)
    {
      bit_nb = 0;
      signal(SIGUSR1, server);
      signal(SIGUSR2, server);
    }
  else
    {
      signal(SIGUSR1, get_pid);
      signal(SIGUSR2, get_pid);
    }
}

void		server(int sig)
{
  static char	bit_counter = 0;
  static char	ascii = 0;

  signal(SIGUSR1, server);
  signal(SIGUSR2, server);
  if (sig == SIGUSR1)
    ascii = ((1 << (7 - bit_counter)) | ascii);
  ++bit_counter;
  if (bit_counter == 8)
    {
      bit_counter = 0;
      write(1, &ascii, 1);
      ascii = 0;
    }
  if (kill(pid, SIGUSR1) == -1)
    {
      bit_counter = 0;
      ascii = 0;
      pid = 0;
      get_pid(sig);
    }
}

int	main()
{
  int	server_pid;

  signal(SIGUSR1, get_pid);
  signal(SIGUSR2, get_pid);
  server_pid = getpid();
  my_put_posnbr(server_pid);
  while (1)
    pause();
  return (0);
}
