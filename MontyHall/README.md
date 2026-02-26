# COMP710: Studio Session 01 – Exercise:

## EXERCISE NAME: Game – Monty Hall

Add a C++ Project named “Monty Hall” to your “SS01” Visual Studio Solution. The Monty Hall Game is a famous entertainment game show. Design and implement a C++ program which allows a human player to play multiple rounds of the game. At the start of the game, print a welcome banner for the game as follows:

```
The Monty Hall Game Show!

-------------------------
```

In the game, a player is presented with three doors. Print the three doors in the following style:

```
Door1        Door2        Door3
+---+        +---+        +---+
|   |        |   |        |   |
| 1 |        | 2 |        | 3 |
|   |        |   |        |   |
+---+        +---+        +---+
```

Behind one of the doors is a valuable prize ($). Behind the other two doors is a bogus prize (x).

At the start of the game, the player is allowed to choose one of the three doors. Print a prompt as follows, allowing the user to respond:

```
Which door does the player choose (1/2/3)? 3
```

After the player chooses a door, the game show host (the computer’s AI) will open up one of the other two doors – they will always open a losing door, not a winning one. Print the host opened door as follows:

```
The game host chooses door number 1...
Door1        Door2        Door3
+---+        +---+        +---+
|   |        |   |        |   |
| x |        | 2 |        | 3 |
|   |        |   |        |   |
+---+        +---+        +---+
```

Next the game show host must allow the player the option to switch their choice from their initial choice, to the remaining unopened door. Prompt the user as follows:

```
Does the player want to switch from door 3 to door 2 (y/n)? n
```

The game must then react to whether or not the player chooses to switch doors, in this case they do not switch:

```
Player chooses to stay with door 3...
```

If the player chose to swap, the game must output in the following style:

```
Player swaps to door 2...
```

Finally the game must reveal what is behind each door, in the following style:

```
Door1        Door2        Door3
+---+        +---+        +---+
|   |        |   |        |   |
| x |        | $ |        | x |
|   |        |   |        |   |
+---+        +---+        +---+
```

The game must then state whether the player wins, or loses – in this case the player loses:

```
Oh no! The player loses!
```

If the player had won, the game would output in the following style:

```
Congratulations! The player wins!
```

Once the game has finished, the player must be prompted as to whether or not they want to play another round. The game must be replayable until the user chooses to stop playing:

```
Play again (y/n)? n
```

Ensure the program output is exactly as described, and that the whitespace of your source code is well formatted. Utilise good naming practices when declaring variables.

Test your program with a variety of input to ensure the implementation is robust. Full screen captures of the completed game are supplied on the following pages.

---

## Example Game Flow 1

```
The Monty Hall Game Show!
-------------------------
Which door does the player choose (1/2/3)? 3

The game host chooses door number 1...
Does the player want to switch from door 3 to door 2 (y/n)? n
Player chooses to stay with door 3...
It's time to reveal the prizes!
Oh on! The player loses!

Play again (y/n)? n
```

---

## Example Game Flow 2 (Winning Case)

```
The Monty Hall Game Show!
-------------------------
Which door does the player choose (1/2/3)? 1

The game host chooses door number 3...
Does the player want to switch from door 1 to door 2 (y/n)? y

Player swaps to door 2...
It's time to reveal the prizes!
Congratulations! The player wins!

Play again (y/n)? n
```

---

Implement this game using C++. Create modular program source code using functions. Do not use global variables!

Follow good programming standards for code layout whitespace, naming and commenting. Ensure your C++ source code can successfully compile. Test your program with a variety of input and ensure the resulting program output is as described above. Once complete, commit your program’s source code to your individual GitHub repository.

---
