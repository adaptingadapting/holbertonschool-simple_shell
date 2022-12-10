# Holberton Simple Shell (hsh)

The Holberton's Simple Shell is the program corresponding to the last project of the first trimester of the foundations branch, and it's a command line interpreter that tries to emulate the functions of BASH.

---
<summario>
<h3>Description</h3>
The shell corresponds to the second group project and, as said, is a command line interpreter that can take said commands from the terminal or other files (also called interactive and uninteractive modes) and send them to the operative system to be executed. It emulates some of the functions of the Bourne Again SHell.
</summario>

---
<h3>Requirements</h3>
For normal utility, it is needed a functioning linux operative system.

---
<h3>Installation</h3>



 1. Clone the repository as follows.
		   ``
		   git clone https://github.com/adaptingadapting/holbertonschool-simple_shell.git
 ``
 2. Compile the code inside the repository once you have it, this way.


    ``
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
``

   ---
   <h3>Files</h3>




 1. main.h
 2. shell.c
 3. tokenize.c
 4. pathCat.c
 5. execute.c
 6. getEnv.c
 7. sigHandler.c
 8. xuteFunc.c
 9. secondaryFunctions.c


<h4>Main.h</h4>
This file is the header file, containing all the prototypes and libraries necesary for the program to work.

<h4>Shell.c</h4>
This is the main file of the program, containing the main function. It executes the rest of the code, and contains the interactive mode.

<h4>Tokenize.c</h4>
This file contains a function of the same name, whose function is that of dividing in tokens the received input (by the terminal or by another file) so it can be executed and properly used.

<h4>pathCat</h4>
This file contains a function named
`programStat` that takes the first token of the input (it being normally the given command) and checks in the path of executables in the operative system if it is usable. When it founds it, returns the complete path with the added command for its execution.

<h4>Execute.c</h4>
This file contains one function named `executePathProgram` that takes the input already tokenized and the path already given by the function above, and forks itself to execute it without breaking the program upon use.

<h4>getEnv.c</h4>
This file contains the function `_getenv`, that does the exact same as its C Library counterpart, but as it isn't allowed in the project, we use our own.

<h4>sigHandler.c</h4>

<h4>xuteFunc.c</h4>
This file contains a function called xcuteFunc, that shortcuts the execution progress by checking the path of the program and seeing if it is compatible.

<h4>secondaryFunctions.c</h4>
Similar to the case of getEnv.c, this file contains some functions that are used throughout the project. This functions are _strcmp, _strcat, _strcpy, and _strlen, and they do the same as their counterparts in their respective C libraries.

---
<h3>Testing</h3>

Here you can see some examples of how to test this program. As follows.

<h4>Interactive Mode</h4>

> $ ./hsh
$ /bin/ls
hsh main.c shell.c
$
$ exit
$

<h4>Uninteractive Mode</h4>

> $ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$





