/*
** my_put_posnbr.c for minitalk in /home/ghost/rendu/Programmation_Shell/PSU_2015_minitalk/src
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Sun Feb  7 22:36:31 2016 Baptiste Veyssiere
** Last update Sun Feb  7 22:36:33 2016 Baptiste Veyssiere
*/

#include "server.h"

void	my_put_posnbr(int nb)
{
  int	pow;
  char	digit;

  pow = 1;
  while ((nb / pow) >= 10)
    pow *= 10;
  while (pow > 1)
    {
      digit = 48 + (nb / pow);
      write(1, &digit, 1);
      nb -= (nb / pow) * pow;
      pow /= 10;
    }
  digit = 48 + nb;
  write(1, &digit, 1);
  write(1, "\n", 1);
}
