# 0x16. C - Simple Shell

## Task
* Write a simple UNIX command interpreter.

## Description
What we should learn from this project:

* How does a shell work
* What is a pid and a ppid
* How to manipulate the environment of the current process
* What is the difference between a function and a system call
* How to create processes
* What are the three prototypes of main
* How does the shell use the PATH to find the programs
* How to execute another program with the execve system call
* How to suspend the execution of a process until one of its children terminates
* What is EOF / “end-of-file”?

## General
* All files will be compiled on Ubuntu 14.04 LTS
* Our shell will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic

---

### [0.0 README](./README.md)
* README is present

### [0.1 man](./man_1_simple_shell)
* A man for your shell.


### [0.2 AUTHORS](./AUTHORS)

* AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository.

### [1. Betty would be proud](https://github.com/holbertonschool/Betty/wiki/Betty-style-usage)
* Code is compliant to Betty style format

### [2. Test suite]()
* Contribute to a test suite for your shell.

### [3. Simple shell 0.1](./main.c)
A UNIX command line interpreter.
* The Shell should:
* Display a prompt and wait for the user to type a command. A command line always ends with a new line.
* The prompt is displayed again each time a command has been executed.
* The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
* The command lines are made only of one word. No arguments will be passed to programs.
* If an executable cannot be found, print an error message and display the prompt again.
* Handle errors.
* Handles the “end of file” condition (Ctrl+D)

It does not:
* use the PATH
* implement built-ins
* handle special characters : ", ', `, \, *, &, #
* be able to move the cursor
* handle commands with arguments

```
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ ./shelly
$ /bin/ls
atoi.c		    getenv.c		_memcpy.c	 _strlen.c
AUTHORS		    getenviron.c	printenv.c	 _strncmp.c
builtin.h	    get_global.c	README.md	 _strncpy.c
_cd.c		    _getline.c		_realloc.c	 _strndup.c
environment.h	    get_nargs.c		shelly		 _strtok.c
exit_.c		    getpath.c		stdlibwrapper.h  _strtoll.c
free_linkedlist.c   global.h		_strcat.c	 strtow.c
frees.c		    inputhelper.h	_strcmp.c	 which.c
get_builtin_func.c  linkedlist.h	_strcpy.c
get_builtin_ld.c    main.c		_strdup.c
get_builtin_sd.c    man_1_simple_shell	stringwrapper.h
```

### [4. Simple shell 0.1.1](./_getline.c)
Simple shell 0.1
* Our own getline function
* Use a buffer to read many chars at once and call the least possible the read system call
* We do not use getline

It does not:
* move the cursor



### [5. Simple shell 0.2](./main.c)
Simple shell 0.1
* Handle command lines with arguments

```
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ ./shelly
$ ls -la
total 240
drwxrwxr-x  3 vagrant vagrant  4096 Aug 18 06:57 .
drwxr-xr-x 23 vagrant vagrant  4096 Aug 18 06:07 ..
-rw-rw-r--  1 vagrant vagrant   768 Aug 17 20:45 atoi.c
-rw-rw-r--  1 vagrant vagrant   135 Aug 18 02:53 AUTHORS
-rw-rw-r--  1 vagrant vagrant   660 Aug 17 22:18 builtin.h
-rw-rw-r--  1 vagrant vagrant   621 Aug 17 22:18 _cd.c
-rw-rw-r--  1 vagrant vagrant   345 Aug 17 22:18 environment.h
-rw-rw-r--  1 vagrant vagrant   411 Aug 17 22:18 exit_.c
-rw-rw-r--  1 vagrant vagrant   196 Aug 17 22:18 free_linkedlist.c
-rw-rw-r--  1 vagrant vagrant   161 Aug 17 22:18 frees.c
-rw-rw-r--  1 vagrant vagrant   519 Aug 17 20:45 get_builtin_func.c
-rw-rw-r--  1 vagrant vagrant   525 Aug 17 09:01 get_builtin_ld.c
-rw-rw-r--  1 vagrant vagrant   604 Aug 17 22:04 get_builtin_sd.c
-rw-rw-r--  1 vagrant vagrant   390 Aug 17 22:18 getenv.c
-rw-rw-r--  1 vagrant vagrant  1140 Aug 17 22:18 getenviron.c
-rw-rw-r--  1 vagrant vagrant   143 Aug 17 22:18 get_global.c
-rw-rw-r--  1 vagrant vagrant   746 Aug 17 22:18 _getline.c
-rw-rw-r--  1 vagrant vagrant   378 Aug 17 22:18 get_nargs.c
-rw-rw-r--  1 vagrant vagrant   568 Aug 17 19:18 getpath.c
drwxrwxr-x  8 vagrant vagrant  4096 Aug 18 02:55 .git
-rw-rw-r--  1 vagrant vagrant    15 Aug 17 01:01 .gitignore
-rw-rw-r--  1 vagrant vagrant   167 Aug 17 22:18 global.h
-rw-rw-r--  1 vagrant vagrant   146 Aug 17 19:18 inputhelper.h
-rw-rw-r--  1 vagrant vagrant   411 Aug 17 22:18 linkedlist.h
-rw-rw-r--  1 vagrant vagrant  2002 Aug 17 22:39 main.c
-rwxrw-r--  1 vagrant vagrant  1618 Aug 18 02:52 man_1_simple_shell
-rw-rw-r--  1 vagrant vagrant   337 Aug 17 19:18 _memcpy.c
-rw-rw-r--  1 vagrant vagrant   339 Aug 17 22:39 printenv.c
-rw-rw-r--  1 vagrant vagrant  2162 Aug 18 06:07 README.md
-rw-r--r--  1 vagrant vagrant 20480 Aug 18 07:10 .README.md.swp
-rw-rw-r--  1 vagrant vagrant   581 Aug 17 22:18 _realloc.c
-rwxrwxr-x  1 vagrant vagrant 42459 Aug 18 06:57 shelly
-rw-rw-r--  1 vagrant vagrant   245 Aug 17 19:18 stdlibwrapper.h
-rw-rw-r--  1 vagrant vagrant   421 Aug 17 19:18 _strcat.c
-rw-rw-r--  1 vagrant vagrant   319 Aug 17 19:18 _strcmp.c
-rw-rw-r--  1 vagrant vagrant   403 Aug 17 19:18 _strcpy.c
-rw-rw-r--  1 vagrant vagrant   592 Aug 17 19:35 _strdup.c
-rw-rw-r--  1 vagrant vagrant   611 Aug 17 22:39 stringwrapper.h
-rw-rw-r--  1 vagrant vagrant   236 Aug 17 19:18 _strlen.c
-rw-rw-r--  1 vagrant vagrant   303 Aug 17 22:18 _strncmp.c
-rw-rw-r--  1 vagrant vagrant   441 Aug 17 21:06 _strncpy.c
-rw-rw-r--  1 vagrant vagrant   634 Aug 17 19:35 _strndup.c
-rw-rw-r--  1 vagrant vagrant   105 Aug 17 22:18 _strtok.c
-rw-rw-r--  1 vagrant vagrant  1056 Aug 17 19:18 _strtoll.c
-rw-rw-r--  1 vagrant vagrant   506 Aug 17 22:18 strtow.c
-rw-rw-r--  1 vagrant vagrant   807 Aug 17 22:18 which.c
```

### [6. Simple shell 0.2.1](./_strtok)
Simple shell 0.2
* Our own strtok

### [7. Simple shell 0.3](./getpath.c)
Simple shell 0.2
* Handle the PATH



### [8. Simple shell 0.4](./exit_.c)
Simple shell 0.3
* Implement the exit built-in, that exits the shell
* Usage: exit
* No arguments to the built-in exit

```
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ ./shelly
$ exit
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$
```

### [9. Simple shell 0.4.1](./exit_.c)
Simple shell 0.4
* handle arguments for the built-in exit
* Usage: exit status, where status is an integer used to exit the shell

```
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ ./shelly
$ exit 98
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ echo $?
98
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$
```

### [10. Simple shell 0.4.2]()
Simple shell 0.4
* Handle Ctrl+C: your shell should not quit when the user inputs ^C

### [11. Simple shell 1.0](./printenv.c)
Simple shell 0.4
* Implement the env built-in, that prints the current environment

```
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ ./shelly
$ env
XDG_SESSION_ID=2
TERM=xterm-256color
SHELL=/bin/bash
SSH_CLIENT=10.0.2.2 49536 22
OLDPWD=/home/vagrant
SSH_TTY=/dev/pts/0
USER=vagrant
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arj=01;31:*.taz=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.zip=01;31:*.z=01;31:*.Z=01;31:*.dz=01;31:*.gz=01;31:*.lz=01;31:*.xz=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.jpg=01;35:*.jpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.axv=01;35:*.anx=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.axa=00;36:*.oga=00;36:*.spx=00;36:*.xspf=00;36:
MAIL=/var/mail/vagrant
PATH=/home/vagrant/bin
PWD=/home/vagrant/simple_shell
LANG=en_US.UTF-8
SHLVL=1
HOME=/home/vagrant
LC_TERMINAL_VERSION=3.3.1
LOGNAME=vagrant
SSH_CONNECTION=10.0.2.2 49536 10.0.2.15 22
LC_CTYPE=en_US.UTF-8
LESSOPEN=| /usr/bin/lesspipe %s
XDG_RUNTIME_DIR=/run/user/1000
LC_TERMINAL=iTerm2
LESSCLOSE=/usr/bin/lesspipe %s %s
_=./shelly
```

### [12. setenv, unsetenv]()
Simple shell 1.0
* Implement the setenv and unsetenv builtin commands
setenv
* Initialize a new environment variable, or modify an existing one
* Command syntax: setenv VARIABLE VALUE
* Should print something on stderr on failure
unsetenv
* Remove an environment variable
* Command syntax: unsetenv VARIABLE
* Should print something on stderr on failure

### [13. cd](./_cd.c)
Simple shell 1.0
Implement the builtin command cd:
* Changes the current directory of the process.
* Command syntax: cd [DIRECTORY]
* If no argument is given to cd the command must be interpreted like cd $HOME
* You have to handle the command cd -
* You have to update the environment variable PWD when you change directory


### [19. help]()
Simple shell 1.0
* Implement the help built-in
* Usage: help [BUILTIN]

---
## Author
* **Ben Cook** - [benjamesian](https://github.com/benjamesian)
* **Ryuichi Miyazaki** - [rmiyazaki6499](https://github.com/rmiyazaki6499)
