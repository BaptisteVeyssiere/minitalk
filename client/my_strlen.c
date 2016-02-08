/*
** my_strlen.c for minitalk in /home/ghost/rendu/Programmation_Shell/PSU_2015_minitalk/src
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Sun Feb  7 22:36:47 2016 Baptiste Veyssiere
** Last update Sun Feb  7 22:36:49 2016 Baptiste Veyssiere
*/

int	my_strlen(char *s)
{
  int	i;

  i = -1;
  while (s[++i] != 0);
  return (i);
}
