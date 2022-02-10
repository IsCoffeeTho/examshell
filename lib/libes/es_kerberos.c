/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   es_kerberos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 06:23:16 by amenadue          #+#    #+#             */
/*   Updated: 2022/02/11 00:45:13 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exam.h"

str		get_principal(void)
{
	krb5_error_code	errcode;
	krb5_context	context;
	krb5_ccache		ccache;
	krb5_principal	principal;
	register str	*name;
	
	krbVError = krb5_init_context(&context);
	if (krbVError) return NULL;
	krbVError = krb5_cc_default(context, &ccache);
	if (krbVError) return NULL;
	krbVError = krb5_cc_get_principal(context, ccache, &principal);
	if (krbVError) return NULL;
	krbVError = krb5_unparse_name(context, principal, name);
	if (krbVError) return NULL;
	return (strdup(*name));
}

void	check_principal(void)
{ 
	str pn;

	pn = get_principal();
	if (pn == NULL) {
		printf("You do not have a valid Kerberos ticket. Please run \"kinit <your_login>\" and run \"examshell\" again.\n");
		fatal();
	} else if (!startswith(pn, "exam@")) {
		printf("Your Kerberos ticket is for \"%s\". You must have a Kerberos ticket with your own login to use this system. Please run \"kinit <your_login>\" and run \"examshell\" again.\n", pn);
		fatal();
	}
}