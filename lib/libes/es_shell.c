/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   es_shell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 06:47:04 by amenadue          #+#    #+#             */
/*   Updated: 2022/02/11 00:43:38 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exam.h"

shell	es_shellnew(void)
{
	shell sh;

	sh.prompt = strdup("/e[93mexamshell/e[0m> ");
}

void	es_print_usage()
{
	printf("\nThe following commands are available to you:\n");
	printf("  \e[92mstatus\e[0m: Displays the status of your session, including information about\n");
	printf("    your current assignment, and the exam history.\n");
	printf("  \e[92mgrademe\e[0m: Asks the server to grade your current assignment. If you have\n");
	printf("    done it right, you will gain the points of the current assignment, go up a level,\n");
	printf("    and try the next one. If you fail, however, you will have another assignment of\n");
	printf("    the same level to do, and it will potentially bring you less points on your grade ...\n");
	printf("    So be sure of yourself before you launch this command!\n");
	printf("  \e[92mfinish\e[0m: Tells the server you are finished with your exam.\n\n");
	printf("You can log out at any time. If this program tells you that you earned points,\n");
	printf("then they will be counted whatever happens.");
}

void	es_helpEOF(void)
{
	printf("(Called when you issue a Ctrl-D) Alias for exit\n");
}

int		es_doEOF(str line)
{
	return (es_doexit(line));
}

void	es_helpexit(void)
{
	printf("Exists the program\n");
}

int		es_doexit(str line)
{
	line;
	return (1);
}

void	es_helpstatus(void);
int		es_dostatus(str line);

void	es_helpfinish(void);
int		es_dofinish(str line);

void	es_helpgrademe(void);
int		es_dogrademe(str line);