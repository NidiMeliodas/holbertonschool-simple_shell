
# Readme - Simple SHELL

A straightforward shell program coded in C that enables users to input commands and executes them. This shell is intended to serve as a fundamental interactive command-line interface.

---

## REQUIREMENTS :
- Allowed editors: vi, vim, emacs
- Compilation on Ubuntu 20.4 LTS
- All files should end with a new line
- All files should follow the Betty style
- No memory leaks
- No more than 5 functions per file
- The header file should be include guarded
- Use system calls only when needed

---
## Compilation Command :
To compile the project, your code will be compiled this way :
```gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell```

### List of allowed functions and system calls+

All functions from string.h.
- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- getpid (man 2 getpid)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- printf (man 3 printf)
- fprintf (man 3 fprintf)
- vfprintf (man 3 vfprintf)
- sprintf (man 3 sprintf)
- putchar (man 3 putchar)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

---
## Commands
The shell supports executing various commands available on the system. Enter a command and press Enter to execute it.
Exit
To exit the shell, use the Ctrl + D keyboard shortcut or enter the exit command.
Debugging
The program includes debugging information that can be enabled or disabled by modifying the print_debug function calls in the code.

---
## Testing

```bash
valgrind --leak-check=full ./shell
echo "/bin/ls" | valgrind --leak-check=full ./shell
echo "                                                       " | valgrind --leak-check=full --show-leak-kinds=all ./shell
echo "/bin/ls -l -a" | valgrind --leak-check=full ./shell
```
* Interactive mode
``` 
root@id:/holbertonschool-simple_shell# ./hsh   
$ /bin/ls
$ hsh main.c shell.c
$ exit
root@id:/holbertonschool-simple_shell#
```
* Non-interactive mode
```
root@id:/holbertonschool-simple_shell# echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
root@id:/holbertonschool-simple_shell#
root@id:/holbertonschool-simple_shell# cat test_ls_2
/bin/ls
/bin/ls
root@id:/holbertonschool-simple_shell#
root@id:/holbertonschool-simple_shell# cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
root@id:/holbertonschool-simple_shell#
```
This README file, along with the entirety of this project, was made by : 
- **[Nidigashan Kanagendran] (https://github.com/NidiMeliodas)**
