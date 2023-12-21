Simple Shell
============

## Description of the project:

This is a simple Unix shell implementation written in C. The shell provides a command-line interface for users to execute commands, similar to the standard Unix shell. It supports basic command execution, including commands with arguments and searching for executable files in the system's PATH.

## Main files:

- simple\_shell.h: Header file containing function prototypes and necessary include statements.
- simple\_shell.c: Main source code file implementing the basic functionality of the shell, including the main function, command execution, argument parsing, and environment variable retrieval.

## Other files contains functions:

- argument.c :
    - Description: Parses a command line and returns an array of arguments.
    - Parameters: 
        - buffer - The command line string.
    - Returns: An array of strings representing the command and its arguments.

- path.c :
    - Description: Handles the PATH environment variable and returns the full path of an executable.
    - Parameters: 
        - buffer - The command line string.
    - Returns: The full path of the executable or NULL if not found.

- exec.c : 
    - free\_args:
        - Description: Frees the memory allocated for an array of strings.
        - Parameters: 
            - args - The array of strings to be freed.

    - execute\_command:
        - Description: Executes a command in a child process using fork and execve.
        - Parameters:
            - array_argument - The array of arguments representing the command.
            - nbr_command - The number of the command typed.

- _getenv.c :
    - Description: Searches for the value of an environment variable
    - Parameters:
        - name - The name of the environment variable.
    - Returns: The value associated with the environment variable or NULL if not found.

## Compilation:

All files were created and compiled on Ubuntu 20.04 using GCC 9.4.0 with the command:
```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o shell
```
Run the compiled program to start the shell: ./shell

## Examples:

```
/root/holbertonschool-simple_shell# ./shell
$ ls
file1.txt  file2.txt  folder
$ lx
./shell: 1: lx: not found
$ echo Hello, World!
Hello, World!
$ /bin/echo "Goodbye, World!"
Goodbye, World!
$ ls non\_existent\_directory
ls: cannot access 'non\_existent\_directory': No such file or directory
$ exit
/root/holbertonschool-simple\_shell#
```

## Requirements:

- Allowed editors : vi, vim, emacs -> we use vi here
- To have the Betty style
- A README.md (logic I'm writing in it :hand:)
- No more than 5 functions per file
- To push the header file simple\_shell.h who contains the prototypes of all our functions

## Man Simple Shell:



## Authors:

This file lists all contributors to the repository:

[Abdou Rodrigue HASSANY MOHAMED](abdou-rodrigue.hassany-mohamed@holbertonstudents.com)
[Mathys QUAGGIO](mathys.quaggio@holbertonstudents.com)
