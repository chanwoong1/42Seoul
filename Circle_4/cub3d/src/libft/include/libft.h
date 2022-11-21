/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:45:16 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/21 00:12:59 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdbool.h>

/* ==========================================================================*
 * |                                                                         |
 * |        * push_swap additional function                                  |
 * |-------------------------------------------------------------------------|
 * |                                                                         |
 * |  NOTE(1)   no description                                               |
 * |                                                                         |
 * ==========================================================================*/

/* --------------------------------------------
 * @ Strong interger format checking.
 * - (1) check is given string contains only number ("1234a" = false).
 * - (2) check if integer overflow/underflow happens. (2747483699 = false).
 * - If given str passes these cases, then function returns true (test passed)
 * */
extern bool		ft_isinteger(char *str);

/* ==========================================================================*
 * |                                                                         |
 * |        * pipe_x additional function                                     |
 * |-------------------------------------------------------------------------|
 * |                                                                         |
 * |  NOTE(1)   no description                                               |
 * |                                                                         |
 * ==========================================================================*/

/* --------------------------------------------
 * @ Allocate and return joined strings passed as argument.
 * - Str_num is a total number of strings to join.
 * - Returns NULL on error.
 * - ex. ft_strjoin_all(3, str1, str2, str3) */
extern char		*ft_strjoin_all(size_t str_num, ...);

/* ==========================================================================*
 * |                                                                         |
 * |  * Implemantion of C++ STL std::vector.                                 |
 * |  * Data type is void**, so it is suitable of storing pointers.          |
 * |-------------------------------------------------------------------------|
 * |                                                                         |
 * |  NOTE(1) reset() : free every containing data.                          |
 * |                                                                         |
 * |  NOTE(2) pop_back() : it will free it's last containing data.           |
 * |                                                                         |
 * |  NOTE(3) delete_vector(), it will free everything                       | 
 * |          including the pointer passed to argument.                      |
 * |                                                                         |
 * ==========================================================================*/

typedef struct s_darray	t_vector;

/* NOTE : Use vector instead of darray */
/* ============================ */
/* Vector Usage */
/* Wrapper function for std::Vector */
/* ============================ 
 * @Default Constructor.
 * [ Ex. t_vector *vec = new_vector(20) ];
 * --> Returns NULL on error! */
extern t_vector	*new_vector(size_t	init_capacity);

/* ============================
 * @Default Destructor.
 * * Free everything, including pointer passed as argument. 
 * --> Use this function to delete vector! */
extern void		delete_vector(t_vector **address_of_vec);

/* ---------------------------
 * @Type define for D-array/Vector.
 * . 
 * - size     : number of pointers filled in **data.
 * - capacity : total size of it's allocated memory.
 * - **data   : pointer to array of data(= void *) set. */

typedef struct s_darray {
	size_t		size;
	size_t		capacity;
	void		**data;
	void		(*push_back)(t_vector *vec, void *new_elem);
	void		(*pop_back)(t_vector *vec);
	void		(*reset)(t_vector *vec);
	int			(*is_empty)(t_vector *vec);
	void		*(*shrink_to_fit)(t_vector *vec);
	void		*(*reserve)(t_vector *vec, size_t new_capacity);
	void		*(*get_last)(t_vector *vec);
	void		(*iterate)(t_vector *vec, void (*f)(void *));
	t_vector	*(*map_malloc)(t_vector *vec, void *(*f)(void *));
}	t_darray;

/* ============================ 
 * @Default Constructor.
 * [ Ex. t_darray *arr = new_darray(20) ];
 * --> Returns NULL on error! */
extern t_darray	*new_darray_malloc(size_t init_capacity);
/* ============================
 * @Default Destructor.
 * * Frees everything, including pointer passed as argument. 
 * --> Use this function to delete D-Array! */
extern void		delete_darray(t_darray **arr_ptr);
/* ----------------------------
 * * NOTE : Capacity of d-array doesn't change!
 * * Frees every elements of it's data, set array size to 0. 
 * - 
 * * if you want to set capacity to 0, call darray_shrink_to_fit(). */
extern void		darray_reset(t_darray *arr);
/* Returns last data pointer */
extern void		*darray_get_last(t_darray *arr);
/* ----------------------------
 * * Return true(1) if darray is empty, else return false(0) */
extern int		darray_is_empty(t_darray *arr);
/* ----------------------------
 * - Requests that the darray capacity be at least enough 
 * to contain n elements. 
 * - If n is smaller than (or equal to) it's current capacity, 
 * the function call does not cause a reallocation 
 * and the darray capacity is not affected.
 * - This function has no effect on the darray size and cannot 
 * alter its elements. 
 * --> Returns NULL on error! */
extern void		*darray_reserve(t_darray *arr, size_t new_capacity);
/* ----------------------------
 * - Add data(void *) to the end. */
extern void		darray_push_back(t_darray *arr, void *new);
/* ----------------------------
 * * Remove and free it's last data(void *). */
extern void		darray_pop_back(t_darray *arr);
/* ----------------------------
 * - Requests the container to reduce its capacity to fit its size. 
 * - This may cause a reallocation, but has no effect on the 
 * darray size and cannot alter its elements. 
 * --> Returns NULL on error!! */
extern void		*darray_shrink_to_fit(t_darray *arr);
/* ----------------------------
 * - Iterates the D-Array and applies the function ’f’ 
 * to the content of each element. */
extern void		darray_iterate(t_darray *arr, void (*f)(void *));
/* ----------------------------
 * - NOTE : new D-Array is auto-shrinked to 
 * original array's size (not capacity).
 * .
 * - Iterates D-Array and applies the function ’f’ to the 
 * content of each element.
 * - Allocates a new D-Array resulting of the successive 
 * applications of the function ’f’. 
 * --> Returns NULL on error!! */
extern t_darray	*darray_map_malloc(t_darray *arr, void *(*f)(void *));

/* ==========================================================================*
 * |                                                                         |
 * |        * ft_printf function + additional function                       |
 * |-------------------------------------------------------------------------|
 * |                                                                         |
 * |  NOTE(1)   used __attribute__ Compiler format checking                  |
 * |                                                                         |
 * ==========================================================================*/

/* ----------------------------
 * * @PRINTF_MANDATORY
 * - Doesn't support float and additional format specifier. */
extern int		ft_printf(const char *fmt, ...)__attribute__(\
		(format (printf, 1, 2)));

/* ----------------------------
 * * Converts the initial portion of the string pointed by str to int
representation.*/
extern int		ft_atoi_base(char *str, char *base);

/* ==========================================================================*
 * |                                                                         |
 * |        * get_next_line + additional functions                           |
 * |-------------------------------------------------------------------------|
 * |                                                                         |
 * |  NOTE(1)   no description                                               |
 * |                                                                         |
 * ==========================================================================*/

/* ----------------------------
 * * @GNL_MANDATORY
 * - Returns a line read from a single file descriptor. 
 * - returns NULL if there is nothing else to read, or an error occurred. */
extern char		*get_next_line(int fd);

/* ----------------------------
 * * @GNL_BONUS
 * - Returns a line read from multiplefile descriptors. 
 * - returns NULL if there is nothing else to read, or an error occurred.
 *   (+supports multiple filedesciptor) */
extern char		*get_next_line_multi(int fd);

/* ----------------------------
 * * Print max n characters of string. */
extern void		ft_nputstr_fd(const char *string, int fd, size_t n);

/* ----------------------------
 * * Convert number to input base, returns allocated result*/
extern char		*ft_convert_nbr_base_malloc(int nb, char *base);

/* ----------------------------
 * * Get unsigned number length. */
extern size_t	ft_nbrlen_uint(unsigned int u_int);

/* ----------------------------
 * * Print only unsigned integer */
extern void		ft_putnbr_uint_fd(unsigned int n, int fd);

/* ----------------------------
 * * Get number length. for example, (-1) returns 2 */
extern size_t	ft_nbrlen(int num);

/* ----------------------------
 * * Checks for white-space characters. */
extern bool		ft_isspace(char c);

/* ==========================================================================*
 * |                                                                         |
 * |        * Original LIBFT project                                         |
 * |-------------------------------------------------------------------------|
 * |                                                                         |
 * |  NOTE(1)   no description                                               |
 * |                                                                         |
 * ==========================================================================*/

/* ----------------------------
 * * Check if c is an alphabetic character.
 * it is equivalent to (isupper(c) || islower(c)).*/
extern int		ft_isalpha(int c);

/* ----------------------------
 * * Check if c is a digit (0 through 9). */
extern int		ft_isdigit(int c);

/* ----------------------------
 * * Check if c is an alphanumeric character. 
 * it is equivalent to (isalpha(c) || isdigit(c)). */
extern int		ft_isalnum(int c);

/* ----------------------------
 * * Check whether c is a 7-bit unsigned char value 
 * that fits into the ASCII character set. */
extern int		ft_isascii(int c);

/* ----------------------------
 * * Check whether c is a printable character including space. */
extern int		ft_isprint(int c);

/* ----------------------------
 * * Return the length of str. */
extern size_t	ft_strlen(const char *str);

/* ----------------------------
 * * Set n bytes of mem to 0. */
extern void		ft_bzero(void *mem, size_t n);

/* ----------------------------
 * * Copy up to dstsize - 1 characters from the NUL-terminated 
 * string src to dest, NUL-terminating the result. */
extern size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);

/* ----------------------------
 * * Append the NUL-terminated string src to the end of dest.
 * It will append at most size - strlen(dest) - 1 bytes, 
 * NUL-terminating the result. */
extern size_t	ft_strlcat(char *dest, const char *src, size_t n);

/* ----------------------------
 * * Convert lowercase letter c to uppercase. */
extern int		ft_toupper(int c);

/* ----------------------------
 * * Convert uppercase letter c to lowercase. */
extern int		ft_tolower(int c);

/* ----------------------------
 * * Returns a pointer to the first occurrence of 
 * the character c in the string str. */
extern char		*ft_strchr(const char *str, int c);

/* ---------------------------- 
 * * Returns a pointer to the last occurrence of 
 * the character c in the string str. */
extern char		*ft_strrchr(const char *str, int c);

/* ----------------------------
 * * Compare n characters of str1 and str2. */
extern int		ft_strncmp(const char *str1, const char *str2, size_t n);

/* ----------------------------
 * * Copy src with len size of characters to dst.
 * After copy, dst is not include newline. */
extern int		ft_strlcpy_without_newline(char *dst, char *src, int len);

/* ----------------------------
 * * Fill the first len bytes of the memory area 
 * pointed to by b with the constant byte c. */
extern void		*ft_memset(void *b, int c, size_t len);

/* ----------------------------
 * * Copy n bytes from memory area src to memory area dest.
 * The memory areas must not overlap.
 * Use ft_memmove if the memory areas do overlap. */
extern void		*ft_memcpy(void *dest, const void *src, size_t n);

/* ----------------------------
 * * Copy len bytes from memory area src to memory area dest.
 * The memory areas may overlap: copying takes place as 
 * though the bytes in src are first copied into a temporary array 
 * that does not overlap src or dest, and the bytes are then copied 
 * from the temporary array to dest. */
extern void		*ft_memmove(void *dest, const void *src, size_t len);

/* ----------------------------
 * * Scan the initial n bytes of the memory area pointed to 
 * by mem for the first instance of c.
 * Both c and the bytes of the memory area pointed to 
 * by mem are interpreted as unsigned char. 
 * *
 * * RETURN VALUES.
 * The memchr() function returns a pointer to the byte located, 
 * or NULL if no such byte exists within n bytes.
 * */
extern void		*ft_memchr(const void *mem, int c, size_t nbytes);

/* ----------------------------
 * * Compares the first nbytes (each interpreted as unsigned char) 
 * of the memory areas mem1 and mem2. */
extern int		ft_memcmp(const void *mem1, const void *mem2, size_t nbytes);

/* ----------------------------
 * * Locates the first occurrence of the null-terminated string needle
 * in the string haystack, where not more than len characters are searched. */
extern char		*ft_strnstr(const char *haystack, \
		const char *needle, size_t len);

/* ----------------------------
 * * Convert the initial portion of the string pointed to by str to int. 
 * ft_atoi() does not detect errors, such as overflow. */
extern int		ft_atoi(const char *str);

/* ----------------------------
 * * Allocates memory for an array of count elements of size bytes each.
 * Returns a pointer to the allocated memory, which is set to zero. */
extern void		*ft_calloc(size_t nmemb, size_t bytes);

/* ----------------------------
 * * Return a pointer to a new string which is a duplicate of the string str1.
 * */
extern char		*ft_strdup(const char *str1);

/* ----------------------------
 * * Return a pointer to a new string which is a duplicate of the string str1.
 * The new string is not include newline.*/
extern char		*ft_strdup_without_newline(char *s);

/* ----------------------------
 * * Allocates and returns a substring from the string ’str’.
 * The substring begins at index ’start’ and is of maximum size ’len’.*/
extern char		*ft_substr(char const *str, unsigned int start, size_t len);

/* ----------------------------
 * * Allocates and returns a new string, which is the result 
 * of the concatenation of ’str1’ and ’str2’ */
extern char		*ft_strjoin(char const *str1, char const *str2);

/* ----------------------------
 * * Allocates and returns a new string, which is the result 
 * of the concatenation of ’str1’ and ’str2’.
 * The new string is not include newline. */
extern char		*ft_strjoin_without_newline(char *s1, char *s2);

/* ----------------------------
 * * Allocates and returns a copy of ’str1’ with the characters 
 * specified in ’set’ removed from the beginning and the end of the string. */
extern char		*ft_strtrim(char const *str1, char const *set);

/* ----------------------------
 * * Allocates and returns an array of strings obtained by splitting 
 * ’s’ using the character ’c’ as a delimiter. */
extern char		**ft_split(char const *str, char c);

/* ----------------------------
 * * Allocates and returns a string representing the integer 
 * received as an argument. */
extern char		*ft_itoa(int num);

/* ----------------------------
 * * Allocates and returns a string resulting from successive 
 * applications of ’func’ to each character of the string ’s’.*/
extern char		*ft_strmapi(char const *string, \
		char (*func)(unsigned int, char));

/* ----------------------------
 * * Applies the function 'func' to each character of the string 
 * passed as argument, and passing its index to 'f' as first argument. */
extern void		ft_striteri(char *string, void (*func)(unsigned int, char*));

/* ----------------------------
 * * Outputs the character ’c’ to the given file descriptor. */
extern void		ft_putchar_fd(char character, int fd);

/* ----------------------------
 * * Outputs the string ’s’ to the given file descriptor. */
extern void		ft_putstr_fd(char *str, int fd);

/* ----------------------------
 * * Outputs the string ’s’ to the given file descriptor, 
 * followed by a newline. */
extern void		ft_putendl_fd(char *str, int fd);

/* ----------------------------
 * * Outputs the integer ’n’ to the given file descriptor. */
extern void		ft_putnbr_fd(int num, int fd);

/* ----------------------------
 * * Bonus Part (Linked List) */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* Allocates and returns a pointer to the new element of t_list.
 * (1) t_list variable ’content’ is initialized with the value 
 * of the parameter ’content’.
 * (2) t_list variable 'next' is initialized to NULL. */
extern t_list	*ft_lstnew(void *content);

/* Adds the element ’new’ at the beginning of the list. */
extern void		ft_lstadd_front(t_list **lst, t_list *new);

/* Counts the number of elements in a list. */
extern int		ft_lstsize(t_list *lst);

/* Returns the last element of the list. */
extern t_list	*ft_lstlast(t_list *lst);

/* Adds the element ’new’ at the end of the list. */
extern void		ft_lstadd_back(t_list **lst, t_list *new);

/* Delete one element pointed by 'lst' using the function 'del',
 * then free the element. */
extern void		ft_lstdelone(t_list *lst, void (*del)(void *));

/* Delete content (using 'del') and free every element of the list,
 * then set the pointer to the list to NULL. */
extern void		ft_lstclear(t_list **lst, void (*del)(void *));

/* Iterates the list and applies the function ’f’ 
 * to the content of each element. */
extern void		ft_lstiter(t_list *lst, void (*f)(void *));

/* Iterates the list and applies the function ’f’
 * to the content of each element.
 * Allocates a new list resulting of the successive applications 
 * of the function ’f’. The ’del’ function is used to delete 
 * the content of an element if needed. */
extern t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), \
		void (*del)(void *));

#endif	/* LIBFT_H */
