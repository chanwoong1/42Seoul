

/// atoi

/*
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	const char *str1 = "            +9584---12324asdca";
	const char *str2 = "  -12345aa123455";

	printf("----string----\n");
	printf("%s%s\n%s%s\n\n", "str1 : ", str1, "str2 : ", str2);
	printf("----atoi----\n");
	printf("%s%d\n", "atoi(str1) : ", atoi(str1));
	printf("%s%d\n\n", "atoi(str2) : ", atoi(str2));
	printf("----ft_atoi----\n");
	printf("%s%d\n", "ft_atoi(str1) : ", ft_atoi(str1));
	printf("%s%d\n", "ft_atoi(str2) : ", ft_atoi(str2));
}
*/

//// bzero

/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	int i;
	printf("==설정 전 ==\n");
	for(i=0; i<10; i++)
		printf("%s%d%s", "[", arr[i], "]");//쓰레기 값 출력
	printf("\n");
	//bzero(arr, 1);
	ft_bzero(arr, 4);//arr의 메모리를 0으로 설정
	printf("==설정 후 ==\n");
	for(i=0; i<10; i++)
		printf("%s%d%s", "[", arr[i], "]");
	printf("\n");
	return 0;
}
*/

//// calloc
/*
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	int arr_1[5];	// 배열 선언
	int *arr_2;		// 포인터 변수 선언
	int *arr_3;
	int i;

	for(i = 0; i < 5; i++)
		arr_1[i] = i+1;
	arr_2 = (int*)calloc(5, sizeof(int));

	printf("-----calloc-----\n");
	for(i = 0; i < 5; i++)
	{
		arr_2[i] = arr_1[i];
		printf("%d ", arr_2[i]);
	}
	free(arr_2);
	printf("\n");
	printf("\n-----ft_calloc-----\n");
	arr_3 = (int *)ft_calloc(5, sizeof(int));

	for(i = 0; i < 5; i++)
	{
		arr_3[i] = arr_1[i];
		printf("%d ", arr_3[i]);
	}
	free(arr_3);
	return 0;
}
*/

//// itoa

/*
#include <stdio.h>
int main(void)
{
	// int	n1 = 2147483647;
	// int n2 = -2147483648;
	// int n3 = 'z';

	printf("--------------------\n");
	// printf("%s%s\n", "n1 : ", ft_itoa(n1));
	// printf("%s%s\n", "n2 : ", ft_itoa(n2));
	// printf("%s%s\n", "n3 : ", ft_itoa(n3));

	printf("%s%s\n", "n1 : ", ft_itoa(-623));
 	printf("%s%s\n", "n1 : ", ft_itoa(156));
 	printf("%s%s\n", "n1 : ", ft_itoa(10));
	return 0;
}
*/

//// memchr

/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char *str = "abcdeabcde";

	printf("--str--\n%s", str);
	printf("\n\n--memchr(5)--\n%s%s", \
		"string : ", memchr(str, 'c', 5));
	printf("\n\n--memchr(2)--\n%s", memchr(str, 'k', 2));
	printf("\n\n--ft_memchr(5)--\n%s%s", \
		"string : ", ft_memchr(str, 'c', 5));
	printf("\n\n--ft_memchr(2)--\n%s", ft_memchr(str, 'k', 2));
	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
    printf("%s", (char *)ft_memchr(tab, -1, 7));
}
*/

//// memcmp

/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char *s1 = "abcdeabcde";
	char *s2 = "abcdefghij";

	printf("--string--\n%s%s", "s1 : ", s1);
	printf("\n%s%s", "s2 : ", s2);
	printf("\n\n--memcmp(5)--\n%s%d", \
		"compare : ", memcmp(s1, s2, 0));
	printf("\n\n--memcmp(5)--\n%s%d", \
		"compare : ", memcmp(s1, s2, 5));
	printf("\n\n--memcmp(8)--\n%s%d", \
		"compare : ", memcmp(s1, s2, 8));
	printf("\n\n--ft_memcmp(8)--\n%s%d", \
		"compare : ", ft_memcmp(s1, s2, 0));
	printf("\n\n--ft_memcmp(5)--\n%s%d", \
		"compare : ", ft_memcmp(s1, s2, 5));
	printf("\n\n--ft_memcmp(8)--\n%s%d", \
		"compare : ", ft_memcmp(s1, s2, 8));
}
*/

//// memcpy

/*
#include<string.h>
#include<stdio.h>
int main(void)
{
	int src[] = {1,2,3,4, 5, 6};
	int dst[3];

	printf("\n--------------------\n");
	printf("%s\n", "src : ");
	for (int i = 0; i < 6; ++i)
		printf("%d", src[i]);
	printf("\n%s", "dst : ");
	for (int i = 0; i < 3; ++i)
		printf("%d", dst[i]);
	memcpy(dst, src, sizeof(int) * 3);
	printf("\n%s", "memcpy(dst) : ");
	for (int i = 0; i < 6; ++i)
		printf("%d", dst[i]);
	int dst1[3];
	printf("\n--------------------\n");
	printf("%s\n", "src : ");
	for (int i = 0; i < 6; ++i)
		printf("%d", src[i]);
	printf("\n%s", "dst : ");
	for (int i = 0; i < 3; ++i)
		printf("%d", dst1[i]);
	ft_memcpy(dst1, src, sizeof(int) * 3);
	printf("\n%s", "ft_memcpy(dst) : ");
	for (int i = 0; i < 6; ++i)
		printf("%d", dst1[i]);

	printf("\n\n\n%s\n", ft_memcpy(((void *)0), ((void *)0), 3));
	return 0;
}
*/

//// memmove

/*
#include <string.h>
#include <stdio.h>
int main() 
{
	char Like[10] = "ILikeYou";
	char Hate[10] = "IHateYou";
	char str[] = "12345678";

	printf("memmove before : %s\n", Like);
	ft_memmove(Like + 1, Hate + 1, 4);
	printf("memmove after : %s\n", Like);

	printf("memmove before : %s\n", str);
	ft_memmove(str+3, str +1, 3);
	printf("memmove after : %s\n", str);
    
	return 0;
}
*/

//// memset
/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	int i;
	printf("==설정 전 ==\n");
	for(i=0; i<10; i++)
		printf("%s%d%s", "[", arr[i], "]");//쓰레기 값 출력
	printf("\n");
	//memset(arr, 2, 4);
	ft_memset(arr, 2, 4);//arr의 메모리를 0으로 설정
	printf("==설정 후 ==\n");
	for(i=0; i<10; i++)
		printf("%s%d%s", "[", arr[i], "]");
	printf("\n");
	return 0;
}
*/

//// putchar

/*
#include <stdio.h>
int main(void)
{
	ft_putchar_fd('a', 1);
	return (0);
}
*/

//// putnbr

/*
#include <stdio.h>
int main(void)
{
	int n1 = 2147483647;
	int n2 = -2147483648;
	int n3 = 0;

	ft_putnbr_fd(-5, 2);
	printf("\n");
	ft_putnbr_fd(n1, 2);
	printf("\n");
	ft_putnbr_fd(n2, 2);
	printf("\n");
	ft_putnbr_fd(n3, 2);
	return (0);
}
*/

//// putstr

/*
#include <stdio.h>
int main(void)
{
	char *s = "abcdefg";

	ft_putstr_fd(s, 1);
	return (0);
}
*/

//// split

/*
#include <stdio.h>
int main(void)
{
	char *s = "Hello, Wor!!ld! 12!@#$3 4#689*879 &8a^scnkp# oqnk@al! wiihuv";
	char c = ' ';
	char **result;

	printf("\n--------------------\n");
	printf("%s%s\n", "s : ", s);
	printf("%s%c\n", "c : ", c);
	result = ft_split(s, c);
	int i = 0;
	int j = 0;
	while (result[i])
		i++;
	printf("%s%d\n", "str's size : ", i);
	printf("%s\n", "split");
	while (j < i)
	{
		printf("%s%s%s ", "[", result[j], "]");
		j++;
	}
	return 0;
}
*/

//// strchr
/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char str[10] = { "abcdeabcde" };

	printf("--str--\n%s", str);
	printf("\n--strchr('f')--\n%s%c\n%s%s", \
		"located character : ", *strchr(str, 'c'), \
		"string : ", strchr(str, 'c'));
	printf("\n--strchr('k')--\n%s", strchr(str, 'k'));
	printf("\n--ft_strchr('f')--\n%s%c\n%s%s", \
		"located character : ", *ft_strchr(str, 'c'), \
		"string : ", ft_strchr(str, 'c'));
	printf("\n--ft_strchr('k')--\n%s", ft_strchr(str, 'k'));
}
*/

//// strdup

/*
#include<string.h>
#include<stdio.h>
int main(void)
{
	char src[] = "Hello, World!";

	printf("\n--------------------\n");
	printf("%s%s\n", "src : ", src);
	printf("%s%s\n", "strdup(src) : ", strdup(src));
	printf("%s%s\n", "ft_strdup(src) : ", ft_strdup(src));
	return 0;
}
*/

//// strjoin

/*
#include <stdio.h>
int main(void)
{
	char *s1 = "Hello, World!";
	char *s2 = " I'm chanwjeo.";

	printf("\n--------------------\n");
	printf("%s%s\n", "s1 : ", s1);
	printf("%s%s\n", "s2 : ", s2);
	printf("%s%s\n", "ft_strjoin(s1, s2) : ", ft_strjoin(s1, s2));
	return 0;
}
*/

//// strlcat
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char src[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	char dst[5] = {1, 2, 3};
	int i;

	printf("---src---\n");
	for (i = 0; i < 10; i++)
		printf("%s%d%s", "[", src[i], "]");
	printf("\n---strlcat---");
	printf("\n%lu\n", strlcat(dst, src, 5));
	for (i = 0; i < 10; i++)
		printf("%s%d%s", "[", dst[i], "]");
	char dst1[5] = {1, 2, 3};
	printf("\n---ft_strlcat---");
	printf("\n%lu\n", ft_strlcat(dst1, src, 5));
	for (i = 0; i < 10; i++)
		printf("%s%d%s", "[", dst[i], "]");
	return (0);
}
*/

//// strlcpy
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
    char src[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    char dst[10];
    int i;

    printf("---src---\n");
    for (i = 0; i < 10; i++)
        printf("%s%d%s", "[", src[i], "]");
    strlcpy(dst, src, 6);
    printf("\n---strlcpy---\n");
    for (i = 0; i < 10; i++)
        printf("%s%d%s", "[", dst[i], "]");
    char dst1[10];
    ft_strlcpy(dst1, src, 6);
    printf("\n---ft_strlcpy---\n");
    for (i = 0; i < 10; i++)
        printf("%s%d%s", "[", dst[i], "]");
}
*/

//// strmapi
/*
#include <stdio.h>
char mapi(unsigned int i, char c)
{
	return (c + i);
}
int main(void)
{
	char *s = "aaaaaaaaaaaaaaaaaaaaaaaaaa";

	printf("-----------------------------\n");
	printf("%s%s\n", "s : ", s);
	printf("%s%s", "ft_strmapi(s) : ", ft_strmapi(s, &mapi));
	return (0);
}
*/

//// strncmp
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char s1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	char s2[10] = {1, 2, 3, 4, 5, 6, 7, 9, 8, 0};
	int i;

	printf("---s1---\n");
	for (i = 0; i < 10; i++)
		printf("%s%d%s", "[", s1[i], "]");
	printf("\n---s2---\n");
	for (i = 0; i < 10; i++)
		printf("%s%d%s", "[", s2[i], "]");
	printf("\n---strncmp---");
	printf("\n%d\n", strncmp(s1, s2, 10));
	printf("\n---ft_strncmp---");
	printf("\n%d\n", ft_strncmp(s1, s2, 10));
}
*/

//// strnstr
/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	const char *largestring = "Foo Bar Baz";
	const char *smallstring = "Bar";
	char *ptr;
	
	printf("----string----\n");
	printf("%s%s\n%s%s\n\n", "largestring : ", largestring, \
		"smallstring : ", smallstring);
	printf("----strnstr----\n");
	ptr = strnstr(largestring, smallstring, 8);
	printf("%s%s\n", "strnstr(large, small, 8) : ", ptr);
	ptr = strnstr(largestring, smallstring, 2);
	printf("%s%s\n\n", "strnstr(large, small, 2) : ", ptr);
	printf("----ft_strnstr----\n");
	ptr = strnstr(largestring, smallstring, 8);
	printf("%s%s\n", "ft_strnstr(large, small, 8) : ", ptr);
	ptr = strnstr(largestring, smallstring, 2);
	printf("%s%s\n", "ft_strnstr(large, small, 2) : ", ptr);

	printf("----------------------------------------\n");
	char haystack[30] = "aaabcabcd";
	printf("\n\n%s", strnstr(haystack, "cd", 8));
	printf("\n\n%s", ft_strnstr(haystack, "cd", 8));
}
*/

//// strrchr
/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char str[10] = "abcdeabcde";

	printf("--str--\n%s", str);
	printf("\n--strrchr('f')--\n%s%c\n%s%s", \
		"located character : ", *strrchr(str, 'c'), \
		"string : ", strrchr(str, 'c'));
	printf("\n--strrchr('k')--\n%s", strrchr(str, 'k'));
	printf("\n--ft_strrchr('f')--\n%s%c\n%s%s", \
		"located character : ", *ft_strrchr(str, 'c'), \
		"string : ", ft_strrchr(str, 'c'));
	printf("\n--ft_strrchr('k')--\n%s", ft_strrchr(str, 'k'));
}
*/

//// substr
/*
#include <stdio.h>
int main(void)
{
	char *s = "Hello, World!";

	printf("\n--------------------\n");
	printf("%s%s\n", "s : ", s);
	printf("%s%s\n", "ft_substr(s, 2, 7) : ", ft_substr(s, 2, 7));
	printf("%s%s\n", "ft_substr(s, 7, 7) : ", ft_substr(s, 7, 7));
	printf("%s%s\n", "ft_substr(s, 14, 7) : ", ft_substr(s, 14, 7));

	printf("-----------------------\n\n");
	char *str = "01234";
 	size_t size = 10;
 	printf("%s\n", ft_substr(str, 10, size));
	return 0;
}
*/

//// tolower
/*
#include <ctype.h>
#include <stdio.h>
int	main(void)
{
	int	arr[10] = {'a', 'z', '1', '2', '3', '4', 'A', 'B', 'C', ' '};
	printf("--tolower--\n");
	for (int i = 0; i < 10; i++)
		printf("%s%c%s", "[", tolower(arr[i]), "]");
	printf("\n--ft_tolower--\n");
	for (int i = 0; i < 10; i++)
		printf("%s%c%s", "[", ft_tolower(arr[i]), "]");
	return (0);
}
*/

//// toupper
/*
#include <ctype.h>
#include <stdio.h>
int	main(void)
{
	int	arr[10] = {'a', 'z', '1', '2', '3', '4', 'A', 'B', 'C', ' '};
	printf("--toupper--\n");
	for (int i = 0; i < 10; i++)
		printf("%s%c%s", "[", toupper(arr[i]), "]");
	printf("\n--ft_toupper--\n");
	for (int i = 0; i < 10; i++)
		printf("%s%c%s", "[", ft_toupper(arr[i]), "]");
	return (0);
}
*/