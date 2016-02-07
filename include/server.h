/*
** server.h for minitalk in /home/ghost/rendu/Programmation_Shell/PSU_2015_minitalk/include
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Sun Feb  7 22:37:36 2016 Baptiste Veyssiere
** Last update Sun Feb  7 22:37:38 2016 Baptiste Veyssiere
*/

#ifndef SERVER_H_
# define SERVER_H_

#include <signal.h>
#include <unistd.h>

#define UNUSED __attribute__ ((unused))

int	server();
void	my_put_posnbr(int);
void	bit_addition(char, unsigned char*);
void	bit_on(int);
void	bit_off(int);

#endif /* !SERVER_H_ */
