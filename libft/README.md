_This project has been created as part of the 42 curriculum by zleullie._

# libft
My very first library, with general purpose functions for writing C programs.

## Description
Libft is a set of general purpose functions that help with memory handling, string manipulation, creating and editing linked lists, and much more. They were created based on code that I wrote during the Piscine, with some extras. I have organized some functions in the same file as others, because their funcitonality was similar.

## Instructions

To compile this library, run:
```sh
$ make
```

To compile cleanly (removing leftover binaries):
```sh
$ make re
```

To clean the intermediary objects:
```sh
$ make clean
```

To clean all binaries:
```sh
$ make fclean
```

### Resources
To develop these functions, I have read source code from Glibc, Musl, FreeBSD's libc, and Apple's Darwin kernel's libc. I have written the functions myself, only analyzing the way they work to assist in the understanding of the logic required.

AI was used to develop a testing application, but not to develop any functions in this project.

AI was also used to assist in the writing of the list of functions and their description, in the section below.

### List of functions

#### Character Checks
- `int ft_isalnum(int c);` - Checks for an alphanumeric character.
- `int ft_isalpha(int c);` - Checks for an alphabetic character.
- `int ft_isdigit(int c);` - Checks for a digit (0 through 9).
- `int ft_isprint(int c);` - Checks for any printable character.
- `int ft_isascii(int c);` - Checks whether `c` is a 7-bit unsigned char value that fits into the ASCII character set.
- `int ft_toupper(int c);` - Converts a lower-case letter to the corresponding upper-case letter.
- `int ft_tolower(int c);` - Converts an upper-case letter to the corresponding lower-case letter.

#### String Manipulation
- `size_t ft_strlen(const char *s);` - Calculates the length of the string `s`.
- `char *ft_strchr(const char *s, int c);` - Returns a pointer to the first occurrence of the character `c` in the string `s`.
- `char *ft_strrchr(const char *s, int c);` - Returns a pointer to the last occurrence of the character `c` in the string `s`.
- `size_t ft_strlcpy(char *dst, const char *src, size_t size);` - Copies up to `size - 1` characters from the string `src` to `dst`, NUL-terminating the result.
- `size_t ft_strlcat(char *dst, const char *src, size_t size);` - Appends the NUL-terminated string `src` to the end of `dst`.
- `int ft_strncmp(const char *s1, const char *s2, size_t n);` - Compares at most the first `n` bytes of `s1` and `s2`.
- `char *ft_strnstr(const char *big, const char *little, size_t len);` - Locates the first occurrence of the null-terminated string `little` in the string `big`, where not more than `len` characters are searched.
- `char *ft_strdup(const char *s);` - Returns a pointer to a new string which is a duplicate of the string `s`.
- `char *ft_substr(char const *s, unsigned int start, size_t len);` - Allocates and returns a substring from the string `s`.
- `char *ft_strjoin(char const *s1, char const *s2);` - Allocates and returns a new string, the concatenation of `s1` and `s2`.
- `char *ft_strtrim(char const *s1, char const *set);` - Allocates and returns a copy of `s1` with the characters specified in `set` removed from the beginning and the end.
- `char **ft_split(char const *s, char c);` - Allocates and returns an array of strings obtained by splitting `s` using the character `c` as a delimiter.
- `char *ft_strmapi(char const *s, char (*f)(unsigned int, char));` - Applies the function `f` to each character of the string `s` to create a new string.
- `void ft_striteri(char *s, void (*f)(unsigned int, char*));` - Applies the function `f` on each character of the string `s`, passing its index as first argument.

#### Memory Manipulation
- `void *ft_memset(void *s, int c, size_t n);` - Fills memory with a constant byte.
- `void ft_bzero(void *s, size_t n);` - Erases the data in the `n` bytes of the memory starting at the location pointed to by `s`, by writing zeros to that area.
- `void *ft_memmove(void *dest, const void *src, size_t n);` - Copies `n` bytes from memory area `src` to memory area `dest` (memory areas may overlap).
- `void *ft_memcpy(void *dest, const void *src, size_t n);` - Copies `n` bytes from memory area `src` to memory area `dest` (memory areas must not overlap).
- `void *ft_memchr(const void *s, int c, size_t n);` - Scans the initial `n` bytes of the memory area pointed to by `s` for the first instance of `c`.
- `int ft_memcmp(const void *s1, const void *s2, size_t n);` - Compares the first `n` bytes of the memory areas `s1` and `s2`.
- `void *ft_calloc(size_t nmemb, size_t size);` - Allocates and zeroes out memory for an array of `nmemb` elements of `size` bytes each and returns a pointer to the allocated memory.

#### Numbers & Output
- `int ft_atoi(const char *nptr);` - Converts the initial portion of the string pointed to by `nptr` to `int`.
- `char *ft_itoa(int n);` - Allocates and returns a string representing the integer received as an argument.
- `void ft_putchar_fd(char c, int fd);` - Outputs the character `c` to the given file descriptor.
- `void ft_putstr_fd(char *s, int fd);` - Outputs the string `s` to the given file descriptor.
- `void ft_putendl_fd(char *s, int fd);` - Outputs the string `s` to the given file descriptor followed by a newline.
- `void ft_putnbr_fd(int n, int fd);` - Outputs the integer `n` to the given file descriptor.

#### Linked Lists
- `typedef struct s_list t_list;` - The structure representing a node in the linked list, containing a `void *content` and a pointer to the next node.
- `t_list *ft_lstnew(void *content);` - Allocates and returns a new node.
- `void ft_lstadd_front(t_list **lst, t_list *new);` - Adds the node `new` at the beginning of the list.
- `int ft_lstsize(t_list *lst);` - Counts the number of nodes in a list.
- `t_list *ft_lstlast(t_list *lst);` - Returns the last node of the list.
- `void ft_lstadd_back(t_list **lst, t_list *new);` - Adds the node `new` at the end of the list.
- `void ft_lstdelone(t_list *lst, void (*del)(void*));` - Frees the memory of the node's content using the `del` function and frees the node.
- `void ft_lstclear(t_list **lst, void (*del)(void*));` - Deletes and frees the given node and every successor of that node, using the function `del` and `free`.
- `void ft_lstiter(t_list *lst, void (*f)(void *));` - Iterates the list `lst` and applies the function `f` on the content of each node.
- `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));` - Iterates the list `lst` and applies the function `f` on the content of each node, creating a new list.

