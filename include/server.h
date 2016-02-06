#ifndef SERVER_H_
# define SERVER_H_

#include <signal.h>
#include <unistd.h>

#define UNUSED __attribute__ ((unused))

int	server();
void	bit_on(int);
void	bit_off(int);

#endif /* !SERVER_H_ */
