/*
** my_getnbr.c for my_getnbr.c in /home/VEYSSI_B/rendu/test
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Wed Dec  2 22:43:56 2015 Baptiste veyssiere
** Last update Thu Dec  3 00:41:17 2015 Baptiste veyssiere
*/

int	my_getnbr(char *str)
{
  int	i;
  int	j;
  int	limit;
  int	nbr;

  i = 0;
  nbr = 0;
  limit = 0;
  if (str[0] == '-')
    limit = 1;
  while (str[i] != 0)
    i++;
  i--;
  j = 1;
  while (i >= limit)
    {
      nbr += j * (str[i--] - 48);
      j *= 10;
    }
  if (str[0] == '-')
    nbr *= -1;
  return (nbr);
}
