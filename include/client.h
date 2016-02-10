/*
** client.h for minitalk in /home/ghost/rendu/Programmation_Shell/PSU_2015_minitalk/include
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Sun Feb  7 22:37:24 2016 Baptiste Veyssiere
** Last update Wed Feb 10 03:30:01 2016 Baptiste Veyssiere
*/

#ifndef CLIENT_H_
# define CLIENT_H_

#define _POSIX_SOURCE
#define _DEFAULT_SOURCE
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void	handler(int);
void	client(int, char*);
int	my_strlen(char*);
void	send_pid(int, int);
int	my_getnbr(char*);

#endif /* !CLIENT_H_ */
