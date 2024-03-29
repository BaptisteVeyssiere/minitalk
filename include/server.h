/*
** server.h for minitalk in /home/ghost/rendu/Programmation_Shell/PSU_2015_minitalk/include
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Sun Feb  7 22:37:36 2016 Baptiste Veyssiere
** Last update Thu Feb 18 20:36:16 2016 Baptiste Veyssiere
*/

#ifndef SERVER_H_
# define SERVER_H_

#define _POSIX_SOURCE
#define _DEFAULT_SOURCE
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void	server(int);
void	my_put_posnbr(int);
void	get_pid(int);
int	my_strlen(char*);
int	exitfunc(char*, int);

#endif /* !SERVER_H_ */
