# Linux-Learning

Exercises from the chapters in the book called Advanced programming in the linux enviornment.

Also various different exercise on system administration.
- Package management for DEB and RPM.
- Setting up a remote server.
- Random implenetation of common system utilities like PSTree and df (disk file system usage)

To download the source code to run the examples please go here: http://www.apuebook.com/code3e.html

After uncompressing the source code, go in the directory and run make:

$ cd SCADDRESS
$ make

To compile an example program, tun this GCC command:

$ gcc -o myprog mprog.c -I SCADDRESS/include/ -L SCADDRESS/lib/ -lapue

- I tells GCC which directory to look for the include file.
- L tells it the location of the library directory.
