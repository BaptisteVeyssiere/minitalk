/*
** server.h for minitalk in /home/ghost/rendu/Programmation_Shell/PSU_2015_minitalk/include
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Sun Feb  7 22:37:36 2016 Baptiste Veyssiere
** Last update Mon Feb  8 14:53:07 2016 Baptiste Veyssiere
*/

#ifndef SERVER_H_
# define SERVER_H_

#include <signal.h>
#include <unistd.h>

#define UNUSED __attribute__ ((unused))

void	server(int);
void	my_put_posnbr(int);
void	bit_addition(char, unsigned char*);

#endif /* !SERVER_H_ */
