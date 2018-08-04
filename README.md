# ft_printf
### [42 school Silicon Valley][42]

## TOC

* [What is it about?](#what-is-it-about)
* [Usage](#usage)
* [Examples](#examples)
* [Authors](#authors)
* [License](#license)

## What is it about?
The goal of this project is to mimic the printf function (included in <stdio.h>).
Other information about the project:

 * there is no required buffer, as is present in the system printf
 * the following conversions are supported: sSpdDioOuUxXcC
 * the %% is supported
 * the following flags are supported: #0-+[SPACE]
 * the following lengths flags are supported: hh, h, l, ll, j, z
 * precision is supported
 * basic functionality for * is supported 

##### Creator: Pedago Team. [Task description][pdf]

## Usage
Download and compile repo:
```sh
    git clone https://github.com/IvanKozlov95/ft_printf
    cd ft_printf
    make
```
Not `libftprintf.a` library is created.

## Examples
There is a main file created for tests. Run command `make test` inside repo folder.
```sh
    make test
    ./a.out
    > Hello world!
```
Fell free to edit main function in `test/main.c` to add more.

## Authors
This project was developed by Ivan Kozlov [@ivankozlov95][me]

## License
This project is licensed under the [GNU General Public License 3][license].

[42]: http://42.us.org "42 USA"
[pdf]: https://github.com/IvanKozlov95/fillit/blob/master/resources/ft_printf.en.pdf "pdf"
[license]: https://github.com/IvanKozlov95/fillit/blob/master/LICENSE "license"
[me]: https://github.com/IvanKozlov95 "ivankozlov95"
