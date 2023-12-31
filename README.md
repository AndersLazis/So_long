# So_long

<p align="center">
  <img src="https://github.com/AndersLazis/AndersLazis/blob/main/assets/covers/cover-so_long.png" alt="So_long 42 project badge"/>
</p>

The fifth project at 42 programming school. It's the first graphical project in the Core. The so_long consists of a top-down game, which we code from scratch using the MiniLibx graphical library. It involves a series of validations from the map that is passed as argument, checks to prevent memory leaks, the game engineering, managing windows, events, sprites and maps.


## Status

Validated 24 May 2023. Grade: 100%.
<p align="center">
  <img src="https://github.com/AndersLazis/So_long/blob/master/images/Screen%20Shot%202023-12-31%20at%205.07.35%20PM.png" alt="So_long 42 project screenshot"/>
</p>

## Usage

You should have MinilibX library preinstalled!
Clone the repository https://github.com/AndersLazis/So_long.git
```
git clone https://github.com/AndersLazis/So_long.git
```

To compile:

```shell
cd So_long & make
```

To run the program:

```shell
./so_long
```


## Supported Features

<h3 id="controls" align="left"> Controls </h3>   
    
| KEY |	OBJECT   |
| --------- | ---------- |
| W or ⬆️        |    Move up   |
| A	or ⬅️        |    Move left |
| S	or ⬇️     |    Move down   |
| D or ➡️       |   Move para right|      
| Q or Esc      |   Close the game     | 
    
    
Use WASD or arrow keys to move.	
	
After getting all the magic potions, the exit opens and you can escape downstairs.
	
You can close the game by Clicking on the red cross on the window’s frame, or pressing Q or Esc.
	
<h2 align="left" id="how-did-I-test-it"> How do I test it? </h2>  

To test the game itself it's recommendable to run it with some different maps and try things like:

Running into a wall and see if you're blocked or if the movements counter increase while you're stucked.

Go to the exit without collecting all the magic potions.

Go through the same path at least one time.

Try to move with the arrow keys and with WASD.

Check if the window closes when clicking the red cross on window's frame, same with Esc or Q.

Try to minimize the window and open it again.

Run the project with Valgrind to see if there's any memory leak.

To test some map validations as 
No map, missing argv, multiple argv, invalid extension, map with an empty line, invalid map parameter
missing W parameter, missing C parameter, missing E parameter, missing P parameter, extra P parameter

---
### Useful Resources for the Minishell Project

