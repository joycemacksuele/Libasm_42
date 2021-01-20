/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <jfreitas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:25:36 by user42            #+#    #+#             */
/*   Updated: 2021/01/20 22:39:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libasm.h"

int main(int ac, char **av)
{
//	if (ft_strcmp(av[1], "strlen") == 0)
	if (ac == 3 && strcmp(av[1], "strlen") == 0)
	{
		printf("ft_strlen(\"%s\") = %zu\n", av[2], ft_strlen(av[2]));
		printf("   strlen(\"%s\") = %zu\n", av[2], strlen(av[2]));
	}
//	if (ft_strcmp(av[1], "strcpy") == 0)
	else if (ac == 3 && strcmp(av[1], "strcpy") == 0)
	{
		char	dest1[10];
		char	dest2[10];
		char	*argv2;

		argv2 = av[2];
		printf("ft_strcpy(dest1[100], \"%s\") = %s\n", av[2], ft_strcpy(dest1,av[2]));
		printf("   strcpy(dest2[100], \"%s\") = %s\n", argv2,    strcpy(dest2,argv2));
	}
//	if (ft_strcmp(av[1], "strcmp") == 0)
	else if (ac == 4 && strcmp(av[1], "strcmp") == 0)
	{
		char	*argv2;
		char	*argv3;

		argv2 = av[2];
		argv3 = av[3];
		printf("ft_strcmp(\"%s\", \"%s\") = %d\n", av[2], av[3], ft_strcmp(av[2],av[3]));
		printf("   strcmp(\"%s\", \"%s\") = %d\n", av[2], av[3], strcmp(argv2,argv3));
	}
//	if (ft_strcmp(av[1], "strdup") == 0)
/*	else if (ac == 3 && strcmp(av[1], "strdup") == 0)
	{
		char	*s;
		char	*r;

		//printf("ft_strdup(av[1]) = %s\n", (r = ft_strdup(av[2])));
		printf("   strdup(av[1]) = %s\n", (s = strdup(av[2])));
		free(s);
		free(r);
	}
//	if (ft_strcmp(av[1], "write") == 0)
	else if (ac == 3 && strcmp(av[1], "write") == 0)
	{
		int res;

		//res = ft_write(1, av[2], *av[3]);
		printf("\nreturn = |%d| ft_write(1, %s, %s) = |^|\n", res, av[2], av[3]);

		res = write(1, av[2], *av[3]);
		printf("\nreturn = |%d|    write(1, %s, %s) = |^|\n", res, av[2], av[3]);
	}
//	if (ft_strcmp(av[1], "read") == 0)
	else if (ac == 3 && strcmp(av[1], "read") == 0)
	{
		char ft_buff[11];
		char buff[11];
		int fd;
		int d;

		fd = open(av[2], O_RDONLY);
		//d = ft_read(fd, ft_buff, 10);
		ft_buff[d] = '\0';
		printf("fd = %d | (%d) = ft_read(fd, buff, 10)\n|%s|\n",fd , d, ft_buff);

		fd = open(av[2], O_RDONLY);
		d = read(fd, buff, 10);
		buff[d] = '\0';
		printf("fd = %d | (%d) =    read(fd, buff, 10)\n|%s|\n",fd , d, buff);
	}*/
	else
	{
		printf("\n\033[37mUsage: ./libasm \033[32m[Function] \033[37m[Function arg1] [Function arg2 if needed] ...\n\n\033[0m");
	//	printf("\033[1;37m");
		// ft_strlen(const char *s);
		printf("       ./libasm \033[32m strlen \033[37m   [string]\n");
		// ft_strcpy(char *dest, const char *src);
//		printf("       ./libasm \033[32m strcpy \033[37m   [dest_string]   [src_string]\n");
		printf("       ./libasm \033[32m strcpy \033[37m   [src_string]\n");
		// ft_strcmp(const char *s1, const char *s2);
		printf("       ./libasm \033[32m strcmp \033[37m   [string1]       [string2]\n");
		// ft_strdup(const char *s);
		printf("       ./libasm \033[32m strdup \033[37m   [string]\n");
		// ft_write(int fd, const void *buf, size_t count);
		printf("       ./libasm \033[32m write \033[37m    [buffer]        [length]\n");
		// ft_read(int fd, void *buf, size_t count);
		printf("       ./libasm \033[32m read \033[37m     [buffer]        [length]\n\n");
	}
	return 0;
}
