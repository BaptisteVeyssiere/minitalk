#include "server.h"

int	server()
{
  return (0);
}

int	main(int ac, char **av, char **env)
{
  if (env == NULL)
    return (-1);
  if (server() == -1)
    return (-1);
  return (0);
}
