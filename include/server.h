/*
** server.h for minitalk in /home/ghost/rendu/Programmation_Shell/PSU_2015_minitalk/include
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Sun Feb  7 22:37:36 2016 Baptiste Veyssiere
** Last update Wed Feb 10 02:48:05 2016 Baptiste Veyssiere
*/

#ifndef SERVER_H_
# define SERVER_H_

#define _POSIX_SOURCE
#define _DEFAULT_SOURCE
#include <signal.h>
#include <unistd.h>

void	server(int);
void	my_put_posnbr(int);
void	get_pid(int);

#endif /* !SERVER_H_ */
