/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 02:54:20 by amenadue          #+#    #+#             */
/*   Updated: 2022/02/11 00:47:03 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXAM_H
# define EXAM_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <krb5/krb5.h>

typedef char* str;

# include "file/files.h"

# define __version__ "1.1.2"

typedef struct s_assingment
{
	str	name;
} assignment;


typedef struct s_shell {
	str	prompt;
	assignment current_assignment;
} shell;

int	REAL_MODE;
int	CLEAN_BASEDIR;

str	HOST_BASE;

str	EXAM_BASEDIR;
str	SUBJECTS_DIR;
str	TRACES_DIR;
str	GIT_DIR;
str	DOCS_DIR;

int	krbVError;

void	fatal(void);

int	startswith(const str h, const str n);
int	query_yes_no(str question, int def);

str		get_principal(void);
void	check_principal(void);

/* examshell class */
shell	es_shellnew();

void	es_print_usage();

void	es_helpEOF(void);
int		es_doEOF(str line);

void	es_helpexit(void);
int		es_doexit(str line);

void	es_helpstatus(void);
int		es_dostatus(str line);

void	es_helpfinish(void);
int		es_dofinish(str line);

void	es_helpgrademe(void);
int		es_dogrademe(str line);
/* examshell class end*/

#endif