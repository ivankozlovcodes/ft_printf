# ft_printf
### [42 school Silicon Valley][42]

## TOC

* [What is it about?](#what-is-it-about)
* [Usage](#usage)
* [Examples](#examples)
* [Authors](#authors)
* [License](#license)

## What is it about?
A bin-packing algorithm to fit Tetris pieces into a box, using recursive backtracking. Bitwise implementations.
##### Creator: Pedago Team. [Task description][pdf]

The purpose is to make the smallest possible "square" (which can contain holes) with a given list of tetriminos(tetris pieces), but the disposition must be as such that it returns the first possible solution when placing them recursively from the top left.

## Usage
Download and compile repo:
```sh
    git clone https://github.com/IvanKozlov95/fillit
    cd fillit
    make
```
Executable `fillit` will be created. Usage:
```sh
    ./fillit [file]
```

## Examples
There are some example files in `sample` folder for you to try it out.
```sh
    ./fillit samples/test_8

    .AABB..
    AACCB..
    .CC.BDD
    .EE.DD.
    EEFFGG.
    .FFGGHH
    ....HH.
```

## Authors
This project was developed jointly by Ivan Kozlov [@ivankozlov95](me) and Marc G Tan [@mgia](marc)

## License
This project is licensed under the [GNU General Public License 3][license].

[42]: http://42.us.org "42 USA"
[pdf]: https://github.com/IvanKozlov95/fillit/blob/master/resources/fillit.en.pdf "pdf"
[license]: https://github.com/IvanKozlov95/fillit/blob/master/LICENSE "license"
[me]: https://github.com/IvanKozlov95 "ivankozlov95"
[marc]: https://github.com/mgia "crazy rich asian"
