# ftlib - 42 School libc Implementation

ftlib is a custom C library implementation inspired by the libc standard library. It has been developed as part of my studies at 42 School, following the guidelines and requirements set by the school.

## Table of Contents

- [About](#about)
- [Features](#features)
- [Usage](#usage)
- [Build](#build)
- [Contributing](#contributing)
- [License](#license)

## About

The ftlib library is designed to provide a collection of common C functions, similar to those found in the standard C library (libc). It's intended to be used for educational purposes and as part of various programming assignments at 42 School.

## Features

- Custom implementations of standard C library functions.
- Follows the Norme guidelines and requirements of 42 School.
- Designed to be used in 42 School projects and assignments.

## Usage

To use ftlib in your 42 School projects, you can include the `libft.h` header and link your project with the `libft.a` library.

Here's an example of how to use ftlib in your C project:

```c
#include "libft.h"

int main() {
    char *str = "Hello, ftlib!";
    ft_putstr(str);
    return 0;
}
