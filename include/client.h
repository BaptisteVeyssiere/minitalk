#ifndef CLIENT_H_
# define CLIENT_H_

#define _POSIX_SOURCE
#define _DEFAULT_SOURCE
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int	client(char*, char*);
int	my_strlen(char*);
void	byte_send(char, int);

#endif /* !CLIENT_H_ */
