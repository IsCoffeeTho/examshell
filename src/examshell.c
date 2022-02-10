/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   examshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 02:40:00 by amenadue          #+#    #+#             */
/*   Updated: 2022/02/11 00:45:50 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* In reference of the examshell-cli.py:
 *
 * WHY, oh WHY would you read this script? It's way too ugly!
 * Just go back to your exam...
 * Seriously, just do it.
 *
 * zaz
 * 2015
*/

#include "../lib/exam.h"

int main(int c, str *v)
{
	shell	sh;
	str		tmp;
	FILE	*f = fl_read("/etc/exam_master_host");
	
	HOST_BASE = strdup("https://");
	tmp = (str) malloc(1024 * sizeof(char));
	if (f != NULL) {
		fscanf(f, "%[^\n]", tmp);
		HOST_BASE = strcat(HOST_BASE, tmp);
	} else {
		HOST_BASE = strcat(HOST_BASE, "exam-master.42.fr");
	}

	getlogin_r(tmp, 1024);
	if (!strcmp(tmp, "exam")) {
		REAL_MODE = 1;
		EXAM_BASEDIR = strdup("~/");
		CLEAN_BASEDIR = 0;
	} else {
		REAL_MODE = 0;
		EXAM_BASEDIR = strdup("~/exam-basedir");
		CLEAN_BASEDIR = 1;
	}

	if (c > 1) {
		printf("Running with local server\n");
		HOST_BASE = strdup("https://localhost:8000");
		EXAM_BASEDIR = strdup("~/exam-basedir");
		CLEAN_BASEDIR = 1;
		REAL_MODE = (!strcmp(v[1], "-real"));
	}

	printf("examshell v\e[92m%s\e[0m\n\n", __version__);
	check_principal();

	sh = es_shellnew();
	
	return 0;
}