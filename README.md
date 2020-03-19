# Tactical RPG demo

![alt text](https://i.imgur.com/iqKZzW5.png)

## CIS 29 Group 2 (Winter 2020)
* Michael Ruiz (Group lead)
* Lai Chi (Lychee) C. 
* Michael E.
* Casey N.

## About
A simple turn based tactical rpg game. The point of the game is to eliminate the opposing team's units to claim victory.

## Controls
#### Keyboard:
`WSAD - move cursor`
`Enter - select`
`Backspace - back`
`- mute volume`
`+ raise volume`

#### Controller:
`DPad - move cursor`
`A - select`
`B - back`

## Getting started
#### Mac OS & Linux
##### Requirements:
* SFML
>official download: https://www.sfml-dev.org/tutorials/2.5/
><br>Mac OS: `brew install sfml`</br>
><br>Ubuntu: `apt-get install sfml-dev`</br>
><br>Arch Linux: `pacman -S sfml`</br>
* GCC & GNU Make
>Mac OS: `brew install gcc`
><br>Ubuntu: `apt-get install build-essential`</br>
><br>Arch Linux: `pacman -S base-devel`</br>

##### How to run:
`make && make run`
or
`make clean && make run`
#### Windows
Due to the annoying nature of developing on windows, it is not officially supported. 
However, it should run fine if you are able to get `gcc make` on some sort of windows bash shell or compile the source files yourself.
##### Requirements:
 * SFML https://www.sfml-dev.org/tutorials/2.5/
 * GCC & GNU make (probably using cygwin)
## Gameplay


## Style Guidelines
* 1) Class attribute and methods are lowercase and words separated by underscore, to differentiate SFML camelcase methods.
* 2) File paths are const strings in their respective class headers.
* 3) Brackets are inline with the function definition.
* 4) Variables declared at beginning of each function and initialized to some default value.
* 5) Class accessor/mutator functions are inline header functions if they are only one line.
* 6) Use define guards in header files as #CIS29GROUP2GAME_(CLASSNAME)_H
* 7) Include headers in the following order: C++ library headers, SFML headers, project headers, const definitions.
* 8) Do not use 'using-directives', with few exceptions the game's classes should be in it's own namespace.
* 9) Each call on new should have a comment listing which function(s) triggers it's deletion. Furthermore, each deletion should assign that pointer to nullptr.
* 10) Class data members should be private or protected, unless they are constant.

 ## Credit
 * SFML
 https://www.sfml-dev.org/index.php
 
