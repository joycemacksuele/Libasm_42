/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <jfreitas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:25:36 by user42            #+#    #+#             */
/*   Updated: 2021/01/21 23:48:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libasm.h"

int main(int ac, char **av)
{
//	if (ac == 3 && strcmp(av[1], "strlen") == 0)
	if (ac == 3 && ft_strcmp(av[1], "strlen") == 0)
	{
		printf("\n\033[1;32mft_strlen\033[0m(\"%s\") = %zu\n\n", av[2], ft_strlen(av[2]));
		printf("   \033[1;32mstrlen\033[0m(\"%s\") = %zu\n\n", av[2], strlen(av[2]));
	}
//	else if (ac == 3 && strcmp(av[1], "strcpy") == 0)
	else if (ac == 3 && ft_strcmp(av[1], "strcpy") == 0)
	{
		char	dest1[10];
		char	dest2[10];
		char	*argv2;

		argv2 = av[2];
		printf("\n\033[1;32mft_strcpy\033[0m(dest1[100], \"%s\") = %s\n\n", av[2], ft_strcpy(dest1,av[2]));
		printf("   \033[1;32mstrcpy\033[0m(dest2[100], \"%s\") = %s\n\n", argv2,    strcpy(dest2,argv2));
	}
//	else if (ac == 4 && strcmp(av[1], "strcmp") == 0)
	else if (ac == 4 && ft_strcmp(av[1], "strcmp") == 0)
	{
		char	*argv2;
		char	*argv3;

		argv2 = av[2];
		argv3 = av[3];
		printf("\n\033[1;32mft_strcmp\033[0m(\"%s\", \"%s\") = %d\n\n", av[2], av[3], ft_strcmp(av[2],av[3]));
		printf("   \033[1;32mstrcmp\033[0m(\"%s\", \"%s\") = %d\n\n", av[2], av[3], strcmp(argv2,argv3));
	}
//	else if (ac == 3 && strcmp(av[1], "strdup") == 0)
	else if (ac == 3 && ft_strcmp(av[1], "strdup") == 0)
	{
		char	*dup;
		char	*ft_dup;
//		char	*test;

//		test = "";
		ft_dup = ft_strdup(av[2]);
		dup = strdup(av[2]);
//		dup = ft_strdup("");
		printf("\n\033[1;32mft_strdup\033[0m(\"%s\") = %s\n\n", av[2], ft_dup);
		printf("   \033[1;32mstrdup\033[0m(\"%s\") = %s\n\n", av[2], dup);
		free(ft_dup);
		free(dup);
	}
//	else if (ac == 4 && strcmp(av[1], "write") == 0)
	else if (ac == 3 && ft_strcmp(av[1], "write") == 0)
	{
		int		ft_fd;
		int		fd;
		size_t	av2_len;
		ssize_t	ft_ret;
		ssize_t	ret;

		ft_fd = open("ft_write_example.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		av2_len = ft_strlen(av[2]);
		ft_ret = ft_write(ft_fd, av[2], av2_len);
		printf("\nerrno: %d\n", errno);
		printf("\n\033[1;32mft_write\033[0m(%d, \"%s\", %zu) = %zu (number of bytes written)\n", ft_fd, av[2], av2_len, ft_ret);
		printf("\033[2;37mopen ft_write_example.txt to see that \"%s\" was written there\n\n\033[0m", av[2]);
		close(ft_fd);

		fd = open("write_example.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		ret = write(fd, av[2], av2_len);
		printf("   \033[1;32mwrite\033[0m(%d, \"%s\", %zu) = %zu (number of bytes written)\n", fd, av[2], av2_len, ret);
		printf("\033[2;37mopen write_example.txt to see that \"%s\" was written there\n\n\033[0m", av[2]);
		close(fd);
	}
//	else if (ac == 4 && strcmp(av[1], "read") == 0)
/*	else if (ac == 4 && ft_strcmp(av[1], "read") == 0)
	{
		char	ft_buff[11];
		char	buff[11];
		int		fd;
		ssize_t	d;

		fd = open(av[2], O_RDONLY);
		//d = ft_read(fd, ft_buff, 10);
		ft_buff[d] = '\0';
		printf("\nfd = %d | (%d) = \033[1;32mft_read\033[0m(fd, buff, 10)\n|%s|\n\n",fd , d, ft_buff);

		fd = open(av[2], O_RDONLY);
		d = read(fd, buff, 10);
		buff[d] = '\0';
		printf("fd = %d | (%d) =    \033[1;32mread\033[0m(fd, buff, 10)\n|%s|\n\n",fd , d, buff);
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
		printf("       ./libasm \033[32m write \033[37m    [buffer]\n");
		// ft_read(int fd, void *buf, size_t count);
		printf("       ./libasm \033[32m read \033[37m     [buffer]        [length]\n\n");
	}
	return 0;
	//CHECK OTHER MAINS
}
