#include "client.h"

int	client(char *str, char *pid)
{
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
