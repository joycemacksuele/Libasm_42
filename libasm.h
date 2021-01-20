/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <jfreitas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:59:17 by user42            #+#    #+#             */
/*   Updated: 2021/01/19 21:02:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <string.h> /*for strlen, strcpy, strcmp, strdup*/
# include <unistd.h> /* for write and read*/

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>


/*int		ft_strlen(char const *str);*/
size_t	ft_strlen(const char *s);

/*char	*ft_strcpy(char *dst, char const *src);*/
char	*ft_strcpy(char *dest, const char *src);

/*int		ft_strcmp(char const *s1, char const *s2);*/
int		ft_strcmp(const char *s1, const char *s2);

/*char	*ft_strdup(char const *s1);*/
char	*ft_strdup(const char *s);

/*ssize_t	ft_write(int fd, void const *buf, size_t nbyte);*/
ssize_t	ft_write(int fd, const void *buf, size_t count);

/*ssize_t	ft_read(int fd, void *buf, size_t nbyte);*/
ssize_t	ft_read(int fd, void *buf, size_t count);


#endif
