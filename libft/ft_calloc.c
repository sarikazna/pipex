/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:58:35 by srudman           #+#    #+#             */
/*   Updated: 2023/04/28 20:34:45 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(1);
		if (ptr == NULL)
			return (NULL);
		ft_memset(ptr, 0, 1);
		return (ptr);
	}
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}

/*
#include <stdio.h>
int main(void)
{
    size_t nmemb = 5; // number of elements
    size_t size = 4; // size of each element
    int *arr = (int*) ft_calloc(nmemb, size);

    if (arr == NULL) 
    {
        printf("Memory allocation failed!\n");
        return (1);
    }
    size_t i = 0;
    while (i++ < nmemb)
        arr[i] = i * 3;

    printf("Array elements: ");
    i = 0;
    while (i++ < nmemb)
        printf("%d ", arr[i]);
    printf("\n");
    // free allocated memory
    free(arr);

    return (0);
}
*/