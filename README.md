# Pipex

**Pipex Project - 42 School**

Pipex is a program that mimics the behavior of input/output redirection (`<`, `>`) and piping (`|`) as used in a shell. Below are the main features:

---

## About

The **Pipex** project allows you to implement input/output redirection and piping in C, emulating the behavior of the shell for chaining commands with pipes and redirecting the standard input/output.

This project helps you understand how to handle processes, file descriptors, pipes, and redirection in C. The goal is to gain experience working with these low-level concepts while recreating the shell-like behavior.

---

### Mandatory Part

The program takes an input file, two commands, and an output file as arguments. It executes the commands in a way that mimics the following shell behavior:  
```bash
< infile cmd1 | cmd2 > outfile
```

---

### Mandatory Part

The bonus part of the program extends the functionality to support multiple commands, and the ability to append or overwrite files using >> for appending and > for overwriting. Additionally, it supports here_doc, allowing user input until a specified delimiter is typed. The behavior mimics the following shell command:
```bash
./pipex_bonus here_doc <limiter> cmd1 | cmd2 | cmd3 ... > outfile
```
or for appending:
```bash
./pipex here_doc <limiter> cmd1 | cmd2 | cmd3 ... >> outfile
```

---

## Instructions

To compile the project, run the `Makefile` in the terminal:

```bash
make

    

To clean up object files, run:

make clean



To remove all generated files, run:

make fclean



To compile the bonus:

make bonus



To recompile the project and the test executable, run:

make re
```
