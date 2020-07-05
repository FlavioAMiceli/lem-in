# libft

my own library of self-written useful `C` functions

## compiling
At the root of the repository, run `make`. You can add the path to the repository to your library search path or link the compiled library *libft.a* directly to your executable. Let me know if you run into any problems.

## included functions

| return | name | params | description |
| --- | --- | --- | --- |
| *int* | `ft_printf` | *const char* \*`format`, ... | *rewritten system-function* |
| *int* | `ft_dprintf` | *const int* `fd`, *const char* \*`format`, ... | *rewritten system-function* |
| | | | |
| *int* | `get_next_line` | *const int* `fd`, *char* \*\*`line` | reads from `fd` and saves one line (excl. '\n' character) in `line` |
| | | | |
| *long long int* | `ft_atoi` | *const char* \*`s` | *rewritten system-function* |
| *char\** | `ft_itoa` | *long long int* `n` | converts `n` to corresponding string |
| *char\** | `ft_itoa_base_unsgnd` | *unsigned long long int* `n`, *int* `base`, *int* `is_cap`, *unsigned int* `len` | same as `itoa` but then with different `base`, `is_cap` = 1 for capital letters when `base` > 10 |
| | | | |
| *long long int* | `ft_absolute` | *long long int* `nbr` | returns the absolute value of `nbr` with base 10 |
| *unsigned int* | `ft_absolute_doublelen` | *long double* `ld`, *unsigned int* `prcs` | returns the length of the absolute of `ld` with `prcs` (precision) in bytes |
| *unsigned int* | `ft_absolute_nbrlen` | *long long int* `nbr`, *int* `base` | returns the length of the absolute of `nbr` with `base` |
| *int* | `ft_power` | *int* `base`, *unsigned int* `exp` | returns `base` ^ `exp` |
| *double* | `ft_double_power` | *double* `base`, *int* `exp` | returns `base` ^ `exp` |
| *long double* | `ft_ldouble_power` | *long double* `base`, *int* `exp` | returns `base` ^ `exp` |
| | | | |
| *void* | `ft_bzero` | *void* \*`s`, *size_t* `n` | *rewritten system-function* |
| | | | |
| *void* | `ft_swap_ptr` | *void* \*\*`ptr1`, *void* \*\*`ptr2` | swaps `ptr1` and `ptr2` |
| | | | |
| *void* | `ft_lstadd` | *t_list* \*\*`alst`, *t_list* \*`item` | adds an `item` to linked list with head `alst` |
| *void* | `ft_lstdel` | *t_list* \*\*`alst`, *void (\*`del`)(void\*,size_t)* | uses `del` to delete linked list with head `alst` |
| *void* | `ft_lstdelone` | *t_list* \*\*`alst`, *void (\*`del`)(void\*,size_t)* | uses `del` to delete linked list item `alst` |
| *void* | `ft_lstiter` | *t_list* \*`lst`, *void (\*`f`)(t_list \*elem)* | iterates over `lst` and applies `f` to each node |
| *t_list\** | `ft_lstmap` | *t_list* \*`lst`, *t_list \*(\*`f`)(t_list \*elem)* | iterates over `lst`, applies `f` to each node and returns a "fresh" list with the new nodes |
| *t_list\** | `ft_lstnew` | *void const* \*`content`, *size_t* `content_size` | allocates and returns a "fresh" node for `content` |
| *void* | `ft_lstadd_back` | *t_list* \*\*`alst`, *t_list* \*`item` | adds an `item` to the end of `alst` |
| *void* | `ft_lstfold` | *t_list* \*\*`alst`, *t_list* \*`start`, *t_list* \*`end` | folds the list `alst` at `start` and `end` and deletes all nodes in between |
| *void* | `ft_lstadd_behind` | *t_list* \*\*`alst`, *t_list* \*`node`, *t_list* \*`new_nd` | adds `new_node` behind `node` to `alst` |
| *void* | `ft_lstadd_before` | *t_list* \*\*`alst`, *t_list* \*`node`, *t_list* \*`new_nd` | adds `new_node` before `node` to `alst` |
| *size_t* | `ft_lstcount` | *t_list* \*`lst` | counts nodes of `lst` |
| *t_list\** | `ft_lstrev` | *t_list* \*\*`alst` | reverses order of linked list `(*alst)` |
| *void* | `ft_delete` | *void* \*`ptr`, *size_t* `size` | sets `size` bytes at `ptr` to 0 and frees `ptr` |
| | | | |
| *void\** | `ft_memalloc` | *size_t* `size` | allocates and returns "fresh" pointer to memory of size `size` |
| *void\** | `ft_memccpy` | *void* \*`dst`, *const void* \*`src`, *int* `c`, *size_t* `n` | *rewritten system-function* |
| *void\** | `ft_memchr` | *const void* \*`s`, *int* `c`, *size_t* `n` | *rewritten system-function* |
| *int* | `ft_memcmp` | *const void* \*`s1`, *const void* \*`s2`, *size_t* `n` | *rewritten system-function* |
| *void\** | `ft_memcpy` | *void* \*`dst`, *const void* \*`src`, *size_t* `n` | *rewritten system-function* |
| *void* | `ft_memdel` | *void* \*\*`ap` | frees memory at `*ap` and sets pointer to NULL |
| *void\** | `ft_memmove` | *void* \*`dst`, *const void* \*`src`, *size_t* `len` | *rewritten system-function* |
| *void\** | `ft_memset` | *void* \*`b`, *int* `c`, *size_t* `len` | *rewritten system-function* |
| *void\** | `ft_memdup` | *void* \*`ptr`, *size_t* `size` | allocates and returns "fresh" memory of `size` and copies `size` bytes from `ptr` into it |
| | | | |
| *char\** | `ft_strcat` | *char* \*`s1`, *const char* \*`s2` | *rewritten system-function* |
| *char\** | `ft_strchr` | *const char* \*`s`, *int* `c` | *rewritten system-function* |
| *void* | `ft_strclr` | *char* \*`s` | sets all characters of `s` to '\0' |
| *int* | `ft_strcmp` | *const char* \*`s1`, *const char* \*`s2` | *rewritten system-function* |
| *char\** | `ft_strcpy` | *char* \*`dst`, *const char* \*`src` | *rewritten system-function* |
| *void* | `ft_strdel` | *char* \*\*`as` | deletes string at `*as` and sets the pointer to NULL |
| *void* | `ft_strarrdel` | *char* \*\*\*`arr` | deletes an array of strings and sets all characters and pointers to '\0' / NULL |
| *char\** | `ft_strdup` | *const char* \*`s` | *rewritten system-function* |
| *int* | `ft_strequ` | *const char* \*`s1`, *const char* \*`s2` | returns 1 if `s1` == `s2` and returns 0 if `s1` != `s2` |
| *void* | `ft_striter` | *char* \*`s`, *void(\*`f`)(char\*)* | iterates over `s` and applies `f` to each character |
| *void* | `ft_striteri` | *char* \*`s`, *void(\*`f`)(unsigned int, char\*)* | applies `f` to each character of `s` and passing its index as first argument |
| *char\** | `ft_strjoin` | *const char* \*`s1`, *const char* \*`s2` | returns a "fresh" string with `s1` and `s2` concatenated |
| *size_t* | `ft_strlcat` | *char* \*`s1`, *const char* \*`s2`, *size_t* `size` | *rewritten system-function* |
| *size_t* | `ft_strlen` | *const char* \*`s` | *rewritten system-function* |
| *char\** | `ft_strmap` | *const char* \*`s`, *char(\*`f`)(char)* | applies `f` to each character of `s` and returns "fresh" string with the resulting characters |
| *char\** | `ft_strmapi` | *const char* \*`s`, *char (\*`f`)(unsigned int, char)* | applies `f` to character with given index of `s` and returns "fresh" string with the resulting characters |
| *char\** | `ft_strncat` | *char* \*`s1`, *const char* \*`s2`, *size_t* `n` | *rewritten system-function* |
| *int* | `ft_strncmp` | *const char* \*`s1`, *const char* \*`s2`, *size_t* `n` | *rewritten system-function* |
| *char\** | `ft_strncpy` | *char* \*`dst`, *const char* \*`src`, *size_t* `len` | *rewritten system-function* |
| *int* | `ft_strnequ` | *const char* \*`s1`, *const char* \*`s2`, *size_t* `n` | like `ft_strequ` but only compares the first `n` bytes |
| *char\** | `ft_strnew` | *size_t* `size` | creates new string of `size` and initializes all characters to '\0' |
| *char\** | `ft_strnstr` | *const char* \*`hay`, *const char* \*`needle`, *size_t* `n` | *rewritten system-function* |
| *char\** | `ft_strrchr` | *const char* \*`s`, *int* `c` | *rewritten system-function* |
| *char\** | \*`ft_strsplit` | *const char* \*`s`, *char* `c` | splits `s` at all occurrences of `c` and returns the resulting array of strings |
| *char\** | `ft_strstr` | *const char* \*`hay`, *const char* \*`needle` | *rewritten system-function* |
| *char\** | `ft_strsub` | *const char* \*`s`, *unsigned int* `start`, *size_t* `len` | creates a new string with the first `len` bytes of `s` substituted by the first `len` bytes of `start` |
| *char\** | `ft_strtrim` | *const char* \*`s` | trims white-spaces of the beginning and end of `s` and returns its result in a "fresh" string |
| *char\** | `ft_strrev` | *char* \*`s` | reverses the characters of `s` |
| | | | |
| *void* | `ft_putchar` | *char* `c` | *rewritten system-function* |
| *void* | `ft_putchar_fd` | *char* `c`, *int* `fd` | writes `c` in `fd` |
| *void* | `ft_putnbr` | *int* `n` | writes string representing `n` in stdout |
| *void* | `ft_putnbr_fd` | *int* `n`, *int* `fd` | writes string representing `n` in `fd` |
| *void* | `ft_putendl` | *const char* \*`s` | writes `s` with added newline in stdout |
| *void* | `ft_putendl_fd` | *const char* \*`s`, *int* `fd` | writes `s` with added newline in `fd` |
| *void* | `ft_putstr` | *const char* \*`s` | writes `s` in stdout |
| *void* | `ft_putstr_fd` | *const char* \*`s`, *int* `fd` | writes `s` in `fd` |
| *ssize_t* | `ft_putnstr_fd` | *const char* \*`str`, *size_t* `len`, *int* `fd` | writes first `len` bytes of `str` in `fd` |
| | | | |
| *int* | `ft_isint` | *char* \* `str` | checks if `str` represents an integer |
| *int* | `ft_isalnum` | *int* `c` | *rewritten system-function* |
| *int* | `ft_isalpha` | *int* `c` | *rewritten system-function* |
| *int* | `ft_isascii` | *int* `c` | *rewritten system-function* |
| *int* | `ft_isdigit` | *int* `c` | *rewritten system-function* |
| *int* | `ft_isprint` | *int* `c` | *rewritten system-function* |
| *int* | `ft_islower` | *int* `c` | *rewritten system-function* |
| *int* | `ft_isupper` | *int* `c` | *rewritten system-function* |
| | | | |
| *int* | `ft_tolower` | *int* `c` | *rewritten system-function* |
| *int* | `ft_toupper` | *int* `c` | *rewritten system-function* |

## contributors
 | https://github.com/ItsWendell (`ft_printf` and `ft_dprintf`)
