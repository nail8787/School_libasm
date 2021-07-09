#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

size_t		ft_strlen(const char *s);
int			ft_strcmp(const char *s1, const char *s2);
char 		*ft_strcpy(char *dst, const char *src);
ssize_t		ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t		ft_read(int fildes, void *buf, size_t nbyte);
char 		*ft_strdup(const char *s1);

int		main(void)
{
	char	strlenbuf[] = "qwertyuiykmivqmhrquvhnrqlmcjriqojncv iqh muqhvmruq qsfsfhsjadadadad";
	char	strcmpbuf1[] = "abc";
	char	strcpydst[200] = {0};
	int		fd;
	char	buf[100];
	char	buf2[100];
	char	buf3[100];
	char	buf4[100];
	char	*bufcpy;
	ssize_t	bytes_read;

	fd = open("text.txt", O_RDWR);
	/* Проверка ft_strlen */

	printf("\n@ Check for strlen @\n");

	printf("	strlen: %zu\n", strlen(""));
	printf("	ft_strlen: %zu\n", ft_strlen(""));

	printf("\n	strlen: %zu\n", strlen(strlenbuf));
	printf("	ft_strlen: %zu\n", ft_strlen(strlenbuf));
	/* Проверка ft_strcpy */

	printf("@ Check for strcpy @\n");

	printf("	strcpy: %s\n", bufcpy = strcpy(strcpydst, "hello"));
	printf("	ft_strcpy: %s\n", bufcpy = ft_strcpy(strcpydst, "hello"));

	printf("	strcpy: %s\n", bufcpy = strcpy(strcpydst, ""));
	printf("	ft_strcpy: %s\n", bufcpy = ft_strcpy(strcpydst, ""));
	/* Проверка ft_strcmp */

	printf("\n@ Check for strcmp @\n");

	printf("	strcmp: %d\n", strcmp("", ""));
	printf("	ft_strcmp: %d\n", ft_strcmp("", ""));

	printf("\n	strcmp: %d\n", strcmp("", strcmpbuf1));
	printf("	ft_strcmp: %d\n", ft_strcmp("", strcmpbuf1));

	printf("\n	strcmp: %d\n", strcmp(strcmpbuf1, ""));
	printf("	ft_strcmp: %d\n", ft_strcmp(strcmpbuf1, ""));

	printf("\n	strcmp: %d\n", strcmp("abc", "abc"));
	printf("	ft_strcmp: %d\n", ft_strcmp("abc", "abc"));
	/* Проверка ft_write */

	printf("\n@ Check for ft_write @\n");

	printf("	write: %zd\n", write(1, "Hello", 5));
	printf("	ft_write: %zd\n", ft_write(1, "Hello", 5));

	printf("\n	write: %zd\n", write(fd, "Pet", 3));
	printf("	ft_write: %zd\n", ft_write(fd, "Pet", 3));

	printf("\n	write: %zd\n", write(-1, "abc", 3));
	perror("	Error");
	errno = 0;
	printf("	ft_write: %zd\n", ft_write(-1, "abc", 3));
	perror("	Error");
	errno = 0;
	/* Проверка ft_read */

	printf("\n@ Check for ft_read @\n");	

	printf("	read: %zd\n", bytes_read = read(0, buf3, 5));
	buf3[bytes_read] = '\0';
	printf("	buf: %s\n", buf3);
	fd = open("text.txt", O_RDWR);
	printf("	ft_read: %zd\n", bytes_read = ft_read(0, buf4, 5));
	buf4[bytes_read] = '\0';
	printf("	buf: %s\n", buf4);
	
	fd = open("text.txt", O_RDWR);
	printf("	read: %zd\n", bytes_read = read(fd, buf, 5));
	buf[bytes_read] = '\0';
	printf("	buf: %s\n", buf);
	fd = open("text.txt", O_RDWR);
	printf("	ft_read: %zd\n", bytes_read = ft_read(fd, buf2, 5));
	buf2[bytes_read] = '\0';
	printf("	buf: %s\n", buf2);

	printf("\n	read: %zd\n", read(-1, buf, 3));
	perror("	Error");
	errno = 0;
	printf("	ft_read: %zd\n", ft_read(-1, buf2, 3));
	perror("	Error");
	errno = 0;
	/* Проверка ft_strdup */
	printf("\n@ Check for ft_strdup @\n");

	printf("	strdup: %s\n", strdup(""));
	printf("	ft_strdup: %s\n", ft_strdup(""));

	printf("	strdup: %s\n", strdup(strlenbuf));
	printf("	ft_strdup: %s\n", ft_strdup(strlenbuf));
	return(0);
}
