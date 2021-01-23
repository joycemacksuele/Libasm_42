#include "../libasm.h"

//add to libasm.h
#ifndef BG_LIGHT

#define BLACK           "\033[1;30m"
#define RED             "\033[1;31m"
#define GREEN           "\033[1;32m"
#define YELLOW          "\033[1;33m"
#define BLUE            "\033[1;34m"
#define PURPLE          "\033[1;35m"
#define CYAN            "\033[1;36m"
#define GREY            "\033[1;37m"
#define NC              "\033[0m"

#else

#define BLACK           "\033[0;30m"
#define RED             "\033[0;31m"
#define GREEN           "\033[0;32m"
#define YELLOW          "\033[0;33m"
#define BLUE            "\033[0;34m"
#define PURPLE          "\033[0;35m"
#define CYAN            "\033[0;36m"
#define GREY            "\033[0;37m"
#define NC              "\033[0m"

#endif

static	int	len_test(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
		++i;
	return (i);
}

static	int	len_dst(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
		++i;
	return (i);
}

int	main(void)
{
	int	i;
	int	end; 
	int	ft_ret;
	int	ret;
	int	nb_test;
	int	error;

	nb_test = 4;

	size_t	len[nb_test];
	char	*test[nb_test];

	test[0] = "salut\n";
	len[0] = 7;
	test[1] = "bonjour";
	len[1] = 4;
	test[2] = "0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	len[2] = 1060;
	test[nb_test - 1] = NULL;

	i = 0;
	end = len_test(test);

	printf("%sft_write%s\n", GREEN, NC);
	printf("%s********%s\n", GREEN, NC);

	while (i < end)
	{
		error = 0;
		ft_ret = 0;
		ret = 0;

		printf("%stest %d%s\n", PURPLE, i, NC);
		printf("------\n");
		
		printf("*** %sft_write%s ***\n", BLACK, NC);
		
		printf("%s", GREY);
		ft_ret = ft_write(1, test[i], len[i]);
		error = errno;
		printf("%s", NC);
		printf("|--> %s%d%s\n", GREY, ft_ret, NC);
		
	//	printf("ERRNO = %s%d%s\n", GREY, error, NC);
		
		printf("*** %swrite%s ***\n", BLACK, NC);
		printf("%s", GREY);
		ret = write(1, test[i], len[i]);
		error = errno;
		printf("%s", NC);
		
		printf("|--> %s%d%s\n", GREY, ret, NC);
		
	//	printf("ERRNO = %s%d%s\n", GREY, error, NC);
		++i;
	}
	error = 0;
	ft_ret = 0;
	ret = 0;

	printf("%stest error%s\n", PURPLE, NC);
	printf("----------\n");

	printf("*** %sft_write%s ***\n", BLACK, NC);
	printf("%s", GREY);
	ft_ret = ft_write(10, "salut", 6);
	error = errno;
	printf("%s", NC);
	printf("|--> %s%d%s\n", GREY, ft_ret, NC);
	printf("ERRNO = %s%d%s\n", GREY, error, NC);

	printf("*** %swrite%s ***\n", BLACK, NC);
	printf("%s", GREY);
	ret = write(10, "salut", 6);
	error = errno;
	printf("%s", NC);
	printf("|--> %s%d%s\n", GREY, ret, NC);
	printf("ERRNO = %s%d%s\n", GREY, error, NC);

	printf("\n\n --------------------------------------------------------\n\n");

	int	ffft_ret;
	int	ffret;

	ffft_ret = 0;
	ffret = 0;

	nb_test = 5;


	test[0] = "salut\n";
	test[1] = "bonjour";
	test[2] = "0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	test[3] = "";
	test[nb_test - 1] = NULL;

	i = 0;
	end = len_test(test);

	printf("%sft_strlen%s\n", GREEN, NC);
	printf("%s*********%s\n", GREEN, NC);

	while (i < end)
	{
		ffft_ret = 0;
		ffret = 0;

		printf("%stest %d%s\n", PURPLE, i, NC);
		printf("------\n");
		
		printf("*** %sft_strlen%s ***\n", BLACK, NC);
		
		printf("%s", GREY);
		ffft_ret = ft_strlen(test[i]);
		printf("%s", NC);
		printf("|--> %s%d%s\n", GREY, ffft_ret, NC);
		
		
		printf("*** %sstrlen%s ***\n", BLACK, NC);
		printf("%s", GREY);
		ffret = strlen(test[i]);
		printf("%s", NC);
		
		printf("|--> %s%d%s\n", GREY, ffret, NC);
		
		++i;
	}

	printf("\n\n --------------------------------------------------------\n\n");

	char	*tt_ret;
	char	*tet;
	tet = NULL;
	tt_ret = NULL;

	printf("%sft_strdup%s\n", GREEN, NC);
	printf("%s*********%s\n", GREEN, NC);

// test short string

	printf("%stest short string%s\n", PURPLE, NC);
	printf("-----------\n");
// ft__strdup
	tet = NULL;
	printf("%s*** ft_strdup ***%s\n", BLACK, NC);
	tet = ft_strdup("salut");
	printf("%s%s%s", GREY, tet, NC);
	printf("|--> %s%p%s\n", GREY, tet, NC);
	free(tet);

// strdup
	tet = strdup("salut");
	printf("%s*** strdup ***%s\n", BLACK, NC);
	printf("%s%s%s", GREY, tet, NC);
	printf("|--> %s%p%s\n", GREY, tet, NC);
	free(tet);

// test long string

	printf("%stest long string%s\n", PURPLE, NC);
	printf("-----------\n");

// ft__strdup
	tet = NULL;
	printf("%s*** ft_strdup ***%s\n", BLACK, NC);
	tet = ft_strdup("0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789aaaaaaaaaaaaa");
	printf("%s%s%s", GREY, tet, NC);
	printf("|--> %s%p%s\n", GREY, tet, NC);
	free(tet);

// strdup
	tet = strdup("0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789aaaaaaaaaaaaa");
	printf("%s*** strdup ***%s\n", BLACK, NC);
	printf("%s%s%s", GREY, tet, NC);
	printf("|--> %s%p%s\n", GREY, tet, NC);
	free(tet);

// test empty string

	printf("%stest empty string%s\n", PURPLE, NC);
	printf("-----------------\n");
// ft__strdup
	tet = NULL;
	printf("%s*** ft_strdup ***%s\n", BLACK, NC);
	tet = ft_strdup("");
	printf("%s%s%s", GREY, tet, NC);
	printf("|--> %s%p%s\n", GREY, tet, NC);
	free(tet);

// strdup
	tet = strdup("");
	printf("%s*** strdup ***%s\n", BLACK, NC);
	printf("%s%s%s", GREY, tet, NC);
	printf("|--> %s%p%s\n", GREY, tet, NC);
	free(tet);


	printf("\n\n --------------------------------------------------------\n\n");


	char	*t_ret;
	char	*et;


	nb_test = 4;

	char		*dst[nb_test];
	char	*src[nb_test];

	dst[0] = ft_strdup("salut");
	src[0] = "yo";
	dst[1] = ft_strdup("yo");
	src[1] = "bonjour";
	dst[2] = calloc(1, 1030);
	src[2] = "0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789";
	dst[nb_test - 1] = NULL;
	src[nb_test - 1] = NULL;

	i = 0;
	end = len_dst(dst);

	printf("%sft_strcpy%s\n", GREEN, NC);
	printf("%s*********%s\n", GREEN, NC);

	while (i < end)
	{
		t_ret = NULL;
		et = NULL;

		printf("%stest %d%s\n", PURPLE, i, NC);
		printf("------\n");

		printf("*** %sft_strcpy%s ***\n", BLACK, NC);

		printf("%s", GREY);
		t_ret = ft_strcpy(dst[i], src[i]);
		printf("%s", NC);
		printf("|--> %s%s%s\n", GREY, t_ret, NC);


		printf("*** %sstrcpy%s ***\n", BLACK, NC);
		printf("%s", GREY);
		et = strcpy(dst[i], src[i]);
		printf("%s", NC);

		printf("|--> %s%s%s\n", GREY, et, NC);
		free(dst[i]);

		++i;
	}

	printf("\n\n --------------------------------------------------------\n\n");

	int	fft_ret;
	int	fret;

	nb_test = 6;

	char	*s1[nb_test];
	char	*s2[nb_test];

	s1[0] = ft_strdup("");
	s2[0] = "yo";
	s1[1] = ft_strdup("yo");
	s2[1] = "yolo";
	s1[2] = ft_strdup("yofo");
	s2[2] = "yo";
	s1[3] = ft_strdup("yoao");
	s2[3] = "yo";
	s1[4] = ft_strdup("");
	s2[4] = "";
	s1[nb_test - 1] = NULL;
	s2[nb_test - 1] = NULL;

	i = 0;
	end = len_dst(s1);

	printf("%sft_strcmp%s\n", GREEN, NC);
	printf("%s*********%s\n", GREEN, NC);

	while (i < end)
	{
		fft_ret = 0;
		fret = 0;

		printf("%stest %d%s\n", PURPLE, i, NC);
		printf("------\n");
		printf("*** %sft_strcmp%s ***\n", BLACK, NC);

		printf("%s", GREY);
		fft_ret = ft_strcmp(s1[i], s2[i]);
		printf("%s", NC);
		printf("|--> %s%d%s\n", GREY, fft_ret, NC);

		printf("*** %sstrcmp%s ***\n", BLACK, NC);
		printf("%s", GREY);
		fret = strcmp(s1[i], s2[i]);
		printf("%s", NC);

		printf("|--> %s%d%s\n", GREY, fret, NC);
		free(s1[i]);
		++i;
	}


	printf("\n\n --------------------------------------------------------\n\n");

	int	buffer_size = 400;
	char	*buffer[buffer_size];
	int	fd;
	ssize_t	rret;

	rret = 0;

	fd = 0;
	printf("\n%sft_read%s\n", GREEN, NC);
	printf("%s*******%s\n", GREEN, NC);

// test
	printf("%stest%s\n", PURPLE, NC);
	printf("----\n");

// ft__read
	printf("%s*** ft__read ***%s\n", BLACK, NC);
	printf("%s", GREY);

	fd = open("test.txt", O_RDONLY);
	rret = ft_read(fd, buffer, buffer_size);
	write(1, buffer, rret);
	printf("%s", NC);
	printf("|--> %s%zu%s\n", GREY, rret, NC);
	close(fd);

// read
	printf("%s*** read ***%s\n", BLACK, NC);
	printf("%s", GREY);

	fd = open("test.txt", O_RDONLY);
	rret = read(fd, buffer, buffer_size);
	write(1, buffer, rret);
	close(fd);
	printf("%s", NC);
	printf("|--> %s%zu%s\n", GREY, rret, NC);

// test errno
	printf("%stest errno%s\n", PURPLE, NC);
	printf("----------\n");

	error = 0;

// ft__read

	printf("%s*** ft__read ***%s\n", BLACK, NC);
	printf("%s", GREY);

	rret = ft_read(10, buffer, buffer_size);
	error = errno;
	write(1, buffer, rret);
	printf("%s", NC);
	printf("|--> %s%zu%s\n", GREY, rret, NC);
	printf("ERRNO = %s%d%s\n", GREY, error, NC);
	error = 0;
// read
	printf("%s*** read ***%s\n", BLACK, NC);
	printf("%s", GREY);

	rret = read(10, buffer, buffer_size);
	error = errno;
	write(1, buffer, rret);
	printf("%s", NC);
	printf("|--> %s%zu%s\n", GREY, rret, NC);
	printf("ERRNO = %s%d%s\n\n", GREY, error, NC);

	return (0);
}
