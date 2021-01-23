/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <jfreitas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:25:36 by user42            #+#    #+#             */
/*   Updated: 2021/01/23 22:56:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libasm.h"

int main(int ac, char **av)
{
	if (ac == 3 && ft_strcmp(av[1], "strlen") == 0)
	{
		printf("\n\033[1;32mft_strlen\033[0m(\"%s\") = %zu\n\n", av[2], ft_strlen(av[2]));
		printf("   \033[1;32mstrlen\033[0m(\"%s\") = %zu\n\n", av[2], strlen(av[2]));
	}
/* ************************************************************************** */
	else if (ac == 3 && ft_strcmp(av[1], "strcpy") == 0)
	{
		char	dest1[10000];
		char	dest2[10000];
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
/* ************************************************************************** */
	else if (ac == 3 && ft_strcmp(av[1], "strdup") == 0)
	{
		char	*dup;
		char	*ft_dup;

		ft_dup = ft_strdup(av[2]);
		dup = strdup(av[2]);
		printf("\n\033[1;32mft_strdup\033[0m(\"%s\") = %s\n\n", av[2], ft_dup);
		printf("   \033[1;32mstrdup\033[0m(\"%s\") = %s\n\n", av[2], dup);
		free(ft_dup);
		free(dup);
	}
/* ************************************************************************** */
	else if (ac == 3 && ft_strcmp(av[1], "write") == 0)
	{
		int		ft_fd;
		int		fd;
		size_t	av2_len;
		ssize_t	ft_ret;
		ssize_t	ret;
		char	buf[10000];

		av2_len = ft_strlen(av[2]);
		printf("\n------------------- fd = open() ------------------");
		//open() will return a fd >= 3 and write will write to a file
		ft_fd = open("ft_write_example.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		ft_ret = ft_write(ft_fd, av[2], av2_len);
		if (&__errno_location)
			printf("\033[2;37m\nerrno: %d|%s\033[0m", errno, strerror(errno));
		printf(" -> \033[1;32mft_write\033[0m(%d, \"%s\", %zu) = %zu (number of bytes written)\n", ft_fd, av[2], av2_len, ft_ret);
		printf("\033[2;37mopen ft_write_example.txt to see that \"%s\" was written there\n\n\033[0m", av[2]);
		close(ft_fd);

		fd = open("write_example.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		ret = write(fd, av[2], av2_len);
		if (&__errno_location)
			printf("\033[2;37merrno: %d|%s\033[0m", errno, strerror(errno));
		printf(" ->    \033[1;32mwrite\033[0m(%d, \"%s\", %zu) = %zu (number of bytes written)\n", fd, av[2], av2_len, ret);

		printf("\033[2;37mopen write_example.txt to see that \"%s\" was written there\n\033[0m", av[2]);
		close(fd);

		printf("\n---------------------- fd = 1 --------------------");
		//fd1 = stdout and write will write on the standard output (on terminal)
		printf("\ninput a string to be written to the stdout fd: ");
		scanf("%[^\n]", buf);
		av2_len = ft_strlen(buf);
		ft_ret = ft_write(1, buf, av2_len);
		if (&__errno_location)
			printf("\033[2;37m\nerrno: %d|%s\033[0m", errno, strerror(errno));
		printf(" -> \033[1;32mft_write\033[0m(%d, \"%s\", %zu) = %zu (number of bytes written)\n\n", 1, buf, av2_len, ft_ret);

		ret = write(1, buf, av2_len);
		if (&__errno_location)
			printf("\033[2;37m\nerrno: %d|%s\033[0m", errno, strerror(errno));
		printf(" ->    \033[1;32mwrite\033[0m(%d, \"%s\", %zu) = %zu (number of bytes written)\n", 1, buf, av2_len, ret);

	}
/* ************************************************************************** */
	else if (ac == 3 && ft_strcmp(av[1], "read") == 0)
	{
		int		ft_fd;
		int		fd;
		int		atoi_av2;
		ssize_t	ft_ret;
		ssize_t	ret;
		char	ft_buf[10000];
		char	buf[10000];

		atoi_av2 = atoi(av[2]);
		printf("\n------------------- fd = open() ------------------");
		ft_fd = open("ft_write_example.txt", O_RDONLY);
		ft_ret = ft_read(ft_fd, ft_buf, atoi_av2);
		ft_buf[ft_ret] = '\0';
		if (&__errno_location)
			printf("\n\033[2;37merrno: %d|%s\033[0m", errno, strerror(errno));
		printf("\n\033[1;32mft_read\033[0m(%d, \"%s\", %s) = %zu (number of bytes written) AND buf = \"%s\"\n\n", ft_fd, ft_buf, av[2], ft_ret, ft_buf);
		close(ft_fd);

		fd = open("write_example.txt", O_RDONLY);
		ret = read(fd, buf, atoi_av2);
		buf[ret] = '\0';
		if (&__errno_location)
			printf("\033[2;37merrno: %d|%s\033[0m", errno, strerror(errno));
		printf("\n   \033[1;32mread\033[0m(%d, \"%s\", %s) = %zu (number of bytes written) AND buf = \"%s\"\n\n", fd, buf, av[2], ret, buf);
		close(fd);
	}
/* ************************************************************************** */
	else
	{
		printf("\n\033[37mUsage: ./libasm \033[32m[Function] \033[37m[Function arg1] [Function arg2 if needed] ...\n\n\033[0m");
		// ft_strlen(const char *s);
		printf("       ./libasm \033[32m strlen \033[37m   [string]\n");
		// ft_strcpy(char *dest, const char *src);
		printf("       ./libasm \033[32m strcpy \033[37m   [src_string]\n");
		// ft_strcmp(const char *s1, const char *s2);
		printf("       ./libasm \033[32m strcmp \033[37m   [string1]       [string2]\n");
		// ft_strdup(const char *s);
		printf("       ./libasm \033[32m strdup \033[37m   [string]\n");
		// ft_write(int fd, const void *buf, size_t count);
		printf("       ./libasm \033[32m write \033[37m    [buffer]\n");
		// ft_read(int fd, void *buf, size_t count);
		printf("       ./libasm \033[32m read \033[37m     [length]\n\n");
	}
	return 0;
}
