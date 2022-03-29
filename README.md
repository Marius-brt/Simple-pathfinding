# Simple C pathfinding

Simple pathfinding using backtracking. Not always the shortest path but a good compromise between speed calculation and short path. 

## Example of path

x -> start position<br>
o -> goal<br>
\# -> obstacle<br>
. -> empty

```
x . . # . . . .
# . . . . . . .
. . . # . . . .
. . . # . # . .
. . . . . o . .
```

You can add rows, columns and change the position of the differents characters.

## Result of the example

\* -> path

```
x * * # . . . .
# . * . . . . .
. . * # . . . .
. . * # . # . .
. . * * * o . .
```

Compile and execute the script with the command.
```bash
gcc *.c && ./a.out
```

> [!] Doesn't work on windows (cause I use unistd lib). Please execute with WSL or in VM if you are on windows. 