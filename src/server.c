/*
** server.c for minitalk in /home/ghost/rendu/Programmation_Shell/PSU_2015_minitalk/src
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Sun Feb  7 22:36:59 2016 Baptiste Veyssiere
** Last update Sun Feb  7 22:37:09 2016 Baptiste Veyssiere
*/

#include "server.h"

int	signal_detect;

void	bit_on(UNUSED int sig)
{
  signal(SIGUSR1, bit_on);
  ++signal_detect;
}

void	bit_off(UNUSED int sig)
{
  signal(SIGUSR2, bit_off);
  signal_detect += 2;
}

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

int		server()
{
  int		loop_check;
  int		server_pid;
  char		bit_counter;
  unsigned char	ascii;

  server_pid = getpid();
  my_put_posnbr(server_pid);
  loop_check = 1;
  bit_counter = 0;
  while (loop_check)
    {
      if (signal_detect)
	{
	  if (signal_detect == 1)
	    bit_addition((8 - bit_counter), &ascii);
	  signal_detect = 0;
	  ++bit_counter;
	}
      if (bit_counter == 8)
	{
	  bit_counter = 0;
	  write(1, &ascii, 1);
	  ascii = 0;
	}
    }
  return (0);
}

int	main(UNUSED int ac, UNUSED char **av, char **env)
{
  if (env == NULL)
    return (-1);
  signal(SIGUSR1, bit_on);
  signal(SIGUSR2, bit_off);
  if (server() == -1)
    return (-1);
  return (0);
}
