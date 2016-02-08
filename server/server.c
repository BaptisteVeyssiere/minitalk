/*
** server.c for minitalk in /home/ghost/rendu/Programmation_Shell/PSU_2015_minitalk/src
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Sun Feb  7 22:36:59 2016 Baptiste Veyssiere
** Last update Mon Feb  8 15:02:49 2016 Baptiste Veyssiere
*/

#include "server.h"

void	bit_addition(char bit_index, unsigned char *ascii)
{
  int	i;
  int	nbr;

  i = 0;
  nbr = 1;
  while (++i < bit_index)
    nbr *= 2;
  *ascii += nbr;
}

void		server(int sig)
{
  static char		bit_counter = 0;
  static unsigned char	ascii = 0;

  signal(SIGUSR1, server);
  signal(SIGUSR2, server);
  if (sig == SIGUSR1)
    bit_addition((8 - bit_counter), &ascii);
  ++bit_counter;
  if (bit_counter == 8)
    {
      bit_counter = 0;
      write(1, &ascii, 1);
      ascii = 0;
    }
}

int	main(UNUSED int ac, UNUSED char **av, char **env)
{
  int	pid;

  if (env == NULL)
    return (-1);
  signal(SIGUSR1, server);
  signal(SIGUSR2, server);
  pid = getpid();
  my_put_posnbr(pid);
  while (1)
    pause();
  return (0);
}
