/*
** server.c for minitalk in /home/ghost/rendu/Programmation_Shell/PSU_2015_minitalk/src
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Sun Feb  7 22:36:59 2016 Baptiste Veyssiere
** Last update Thu Feb 18 20:41:01 2016 Baptiste Veyssiere
*/

#include "server.h"

int	pid;

int	my_strlen(char *s)
{
  int	i;

  i = -1;
  while (s[++i] != 0);
  return (i);
}

int	exitfunc(char *func, int mode)
{
  write(1, "The function ", 13);
  write(1, func, my_strlen(func));
  write(1, " failed\nEnd of the program\n", 27);
  if (mode == -1)
    exit(-1);
  else
    return (-1);
  return (0);
}

void		get_pid(int sig)
{
  static char	bit_nb = 0;

  if (sig == SIGUSR1)
    pid = ((1 << bit_nb) | pid);
  ++bit_nb;
  if (bit_nb == 32)
    {
      bit_nb = 0;
      if (signal(SIGUSR1, server) == SIG_ERR ||
	  signal(SIGUSR2, server) == SIG_ERR)
	exitfunc("signal", -1);
    }
  else if (signal(SIGUSR1, get_pid) == SIG_ERR ||
	   signal(SIGUSR2, get_pid) == SIG_ERR)
    exitfunc("signal", -1);
}

void		server(int sig)
{
  static char	bit_counter = 0;
  static char	ascii = 0;

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

  if (signal(SIGUSR1, get_pid) == SIG_ERR ||
      signal(SIGUSR2, get_pid) == SIG_ERR)
    return (exitfunc("signal", 0));
  server_pid = getpid();
  my_put_posnbr(server_pid);
  while (1)
    pause();
  return (0);
}
