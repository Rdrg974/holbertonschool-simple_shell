Simple Shell
============

## Table of contents

* [Description of the project](#description-of-the-project)
* [Main files](#main-files)
* [Other files contains functions](#other-files-contains-functions)
* [Compilation](#compilation)
* [Examples](#examples)
* [Requirements](#requirements)
* [Man Simple Shell](#man-simple-shell)
* [Authors](#authors)

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

```
.TH SIMPLE_SHELL 1 "December 2023" "Version 1.0"

.SH NAME
simple_shell \- a simple UNIX command line interpreter

.SH SYNOPSIS
.B simple_shell

.SH DESCRIPTION
.PP
.B simple_shell
is a simple UNIX command line interpreter that allows users to execute commands,
handle paths, and work with environment variables.

.SH COMMANDS
.PP
.B simple_shell
supports the following built-in commands:

.TP
.B exit
Exit the shell.

.SH ENVIRONMENT VARIABLES
.PP
.B simple_shell
uses the following environment variable:

.TP
.B PATH
The directories to search for executable files.

.SH USAGE
.PP
Run
.B simple_shell
from the command line, and it will provide a prompt for entering commands.
It supports basic command execution and environment variable handling.

.SH EXAMPLES
.PP
.B Interactive Mode:
.RS
.B $ ./shell
.B $ ls
.B $ pwd
.B $ exit
.RE

.B Non-Interactive Mode:
.RS
.B $ echo "ls" | ./shell
.B $ echo "Hello, world!" | ./shell
.B $ echo "/bin/ls -al" | ./shell
.RE

.SH ERRORS
.PP
.B simple_shell
may display the following error messages:

.TP
.BR ./shell: <command_number>: <command>: not found
The specified command could not be found in the directories listed in the PATH environment variable.

.TP
.BR ./shell: <command>: cannot access '<file>': No such file or directory
The executable file for the specified command could not be found.

.SH SEE ALSO
.PP
.BR execve (2),
.BR fork (2),
.BR wait (2),
.BR environ (7),
.BR perror (3).

.SH AUTHOR
.PP
Abdou Rodrigue HASSANY MOHAMED
Mathys QUAGGIO
```

## Authors:

This file lists all contributors to the repository:

[Abdou Rodrigue HASSANY MOHAMED](https://github.com/Rdrg974)
[Mathys QUAGGIO](https://github.com/Horalta)
