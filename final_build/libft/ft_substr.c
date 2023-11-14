/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:04:25 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/09/19 14:02:33 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	a;

	if (!s)
		return (0);
	dest = malloc (len * sizeof (char) + 1);
	if (!dest)
		return (0);
	a = 0;
	if (ft_strlen(s) >= start)
	{
		while (s[start] && a != len)
		{
			dest[a] = s[start];
			a++;
			start++;
		}
	}
	dest[a] = '\0';
	return (dest);
}

/*int	main(void)
{
	char source[] = "bora";

	printf("%s", ft_substr(source, 5, 2));
	return (0);
}*/
