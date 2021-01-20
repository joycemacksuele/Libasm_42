/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <jfreitas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:25:36 by user42            #+#    #+#             */
/*   Updated: 2021/01/19 23:49:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libasm.h"

int main(int argc, char **argv)
{
	if (argc >= 3)
	{
//		if (ft_strcmp(argv[1], "strlen") == 0)
		if (strcmp(argv[1], "strlen") == 0)
		{
			printf("ft_strlen(\"%s\") = %zu\n", argv[2], ft_strlen(argv[2]));
			printf("   strlen(\"%s\") = %zu\n", argv[2], strlen(argv[2]));
		}
//		if (ft_strcmp(argv[1], "strcpy") == 0)
		if (strcmp(argv[1], "strcpy") == 0)
		{
			char s[100];
			printf("ft_strcpy(s , d) = |%s|\n", ft_strcpy(s,argv[2]));
			printf("   strcpy(s , d) = |%s|\n",    strcpy(s,argv[2]));
		}
//		if (ft_strcmp(argv[1], "strcmp") == 0)
/*		if (strcmp(argv[1], "strcmp") == 0)
		{
			//printf("ft_strcmp(argv[1], 'NO') = |%d|\n", ft_strcmp(argv[2],argv[3]));
			printf("   strcmp(argv[1], 'NO') = |%d|\n", strcmp(argv[2],argv[3]));
		}
//		if (ft_strcmp(argv[1], "strdup") == 0)
		if (strcmp(argv[1], "strdup") == 0)
		{
			char *s, *r;
			//printf("ft_strdup(argv[1]) = |%s|\n", (r = ft_strdup(argv[2])));
			printf("   strdup(argv[1]) = |%s|\n", (s = strdup(argv[2])));
			free(s);
			free(r);
		}
//		if (ft_strcmp(argv[1], "write") == 0)
		if (strcmp(argv[1], "write") == 0)
		{
			int res;

			//res = ft_write(1, argv[2], *argv[3]);
			printf("\nreturn = |%d| ft_write(1, %s, %s) = |^|\n", res, argv[2], argv[3]);

			res = write(1, argv[2], *argv[3]);
			printf("\nreturn = |%d|    write(1, %s, %s) = |^|\n", res, argv[2], argv[3]);
		}
//		if (ft_strcmp(argv[1], "read") == 0)
		if (strcmp(argv[1], "read") == 0)
		{
			char ft_buff[11];
			char buff[11];
			int fd;
			int d;

			fd = open(argv[2], O_RDONLY);
			//d = ft_read(fd, ft_buff, 10);
			ft_buff[d] = '\0';
			printf("fd = %d | (%d) = ft_read(fd, buff, 10)\n|%s|\n",fd , d, ft_buff);

			fd = open(argv[2], O_RDONLY);
			d = read(fd, buff, 10);
			buff[d] = '\0';
			printf("fd = %d | (%d) =    read(fd, buff, 10)\n|%s|\n",fd , d, buff);
		}*/
	}
	else
	{
		printf("\n\033[37mUsage: ./libasm \033[32m[Function] \033[37m[Function arg1] [Function arg2 if needed] ...\n\n\033[0m");
	//	printf("\033[1;37m");
		// ft_strlen(const char *s);
		printf("       ./libasm \033[32m strlen \033[37m   [string]\n");
		// ft_strcpy(char *dest, const char *src);
		printf("       ./libasm \033[32m strcpy \033[37m   [dest_string]   [src_string]\n");
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
