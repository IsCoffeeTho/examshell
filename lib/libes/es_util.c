/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   es_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 06:27:14 by amenadue          #+#    #+#             */
/*   Updated: 2022/02/10 21:51:37 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exam.h"

int		startswith(const str h, const str n)
{
	int	hl;
	int	nl;
	int	i;

	hl = strlen(h);
	nl = strlen(n);
	if (hl >= nl)
	{
		i = 0;
		while (i < nl)
		{
			if (h[i] != n[i])
			{
				return (0);
			}
			i++;
		}
		return (1);
	}
	return (0);
}

int		query_yes_no(str question, int def)
{
	str prompt;
	str	choice = malloc(4 * sizeof(char));

	if (def == 0)
	{
		prompt = strdup("[y/N]");	
	}
	else if (def == 1)
	{
		prompt = strdup("[Y/n]");	
	}
	else
	{
		prompt = strdup("[y/n]");
	}

	printf("%s %s ", question, prompt);

	while (1)
	{
		scanf(" %[^\n]", choice);
		if (!strcmp(choice, "y") || !strcmp(choice, "ye") || !strcmp(choice, "yes"))
		{
			return (1);
		}
		else if (!strcmp(choice, "n") || !strcmp(choice, "no"))
		{
			return (0);
		}
		else
		{
			if (def == 0 || def == 1)
			{
				return (def);
			}
			printf("Please respond with 'yes' or 'no' ");
		}
	}
}