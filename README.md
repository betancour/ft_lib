# libft — 42 School

Custom C library reimplementing a subset of libc, plus useful helpers and a
linked-list API (bonus). Written to match the **42 Norme** and the **libft**
subject.

## Layout

```
ft_lib/
├── Makefile
├── README.md
├── include/
│   └── libft.h
└── src/
    └── ft_*.c
```

## Build

```bash
make          # mandatory part → libft.a
make bonus    # mandatory + list functions
make clean    # remove object files
make fclean   # remove objects and libft.a
make re       # fclean + all
```

## Usage

```c
#include "libft.h"

int	main(void)
{
	ft_putendl_fd("Hello, libft!", 1);
	return (0);
}
```

Compile against the archive:

```bash
cc -Wall -Wextra -Werror -Iinclude your_main.c -L. -lft -o your_program
```

## Norme

All `.c` / `.h` files carry a 42 header and pass `norminette`.

> Update the author login in the 42 headers if yours is not `betanco`.

## License

See `doc/LICENSE`.
