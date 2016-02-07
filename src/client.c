/*
** client.c for minitalk in /home/ghost/rendu/Programmation_Shell/PSU_2015_minitalk/src
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Sun Feb  7 22:35:55 2016 Baptiste Veyssiere
** Last update Sun Feb  7 22:36:14 2016 Baptiste Veyssiere
*/

#include "client.h"

void	byte_send(char pid, int ascii)
{
  int	i;
  int	nbr;
  int	bit_tab[8];

  i = -1;
  nbr = 128;
  while (++i < 8)
    {
      bit_tab[i] = nbr;
      nbr /= 2;
    }
  i = -1;
  while (++i < 8)
    {
      if (bit_tab[i] <= ascii)
	{
	  ascii -= bit_tab[i];
	  kill(pid, SIGUSR1);
	}
      else
	kill(pid, SIGUSR2);
      usleep(1);
    }
}

int	client(char *str, char *pid)
{
  int	server_pid;
  int	i;

  server_pid = my_getnbr(pid);
  i = -1;
  while (++i < my_strlen(str))
    byte_send(str[i], server_pid);
  return (0);
}

int	main(int ac, char **av, char **env)
{
  if (ac != 3 || env == NULL)
    return (-1);
  if (client(av[1], av[2]) == -1)
    return (-1);
  return (0);
}
