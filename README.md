# MINIS_HELL


## Description:

MiniShell is a collaborative project executed by a team of two. This simple UNIX shell implementation written in C provides a command-line interface for users to interact with the operating system. The shell supports various features such as command execution, history management, environment variable expansion, redirections, pipes, and built-in commands.
## Project Structure

The MiniShell project is organized into several directories, each serving a specific purpose. Below is an overview of the project structure:

. builtins/: Contains source files for implementing built-in shell commands.

. environment/: Contains source files related to managing the shell environment variables.

. execution/: Contains files for executing commands and managing process execution.

. expander/: Includes files for expanding variables and special characters in command strings.

. final_execution/: Holds files for the final execution of commands after parsing and expansion.

. lexer/: Contains the lexer source files responsible for tokenizing input commands.

. libft/: Directory for the Libft library, which provides various utility functions.

. libmock/: Directory for any mocked or simulated libraries used in testing.

. parser/: Contains files related to parsing input commands into executable form.

. setup/: Contains files for initializing and setting up the shell environment.

. sig_hndlr/: Contains source files for handling signals within the shell.

. utils/: Contains utility functions used throughout the project.

. Makefile: Makefile for compiling and managing the project.

. main.c: Main entry point of the MiniShell application.

This organized structure helps maintain clarity and separation of concerns within the project, making it easier to manage and maintain as the codebase grows.


## Features

. Interactive Prompt: The shell displays a prompt when waiting for a new command, allowing users to input commands interactively.

. Command History: The shell maintains a working command history, allowing users to access and re-execute previous commands using keyboard shortcuts.

. Executable Search: The shell searches and launches the right executable based on the PATH variable or using a relative or absolute path specified by the user.

. Quoting: The shell handles single quotes ('') and double quotes ("") to prevent interpretation of metacharacters, with different rules for each type of quote.

. Redirections: The shell supports input redirection (<), output redirection (>), append mode output redirection (>>), and here documents (<<).

. Pipes: The shell supports pipes (|) to connect the output of one command to the input of another command in a pipeline.

. Environment Variables: The shell expands environment variables (e.g., $PATH) to their corresponding values.

. Exit Status: The shell expands $? to the exit status of the most recently executed foreground pipeline.

. Signal Handling: The shell handles signals such as SIGINT (Ctrl-C), SIGQUIT (Ctrl-), and EOF (Ctrl-D) as per bash conventions.

. Built-in Commands: The shell implements various built-in commands, including echo, cd, pwd, export, unset, env, and exit.


## Compilation

To compile the project, simply run 'make':

```bash
make
```
## Usage 
. Run the compiled program to start the MiniShell:

```bash
./minishell
```

## Collaboration:

This two-person project was done with [itseugen](https://github.com/itseugen).

. I was responsible for the parsing, argument checking, error management, and signal handling.

. Eugen took care of the environment variables, built-in functions, execution, redirection, and piping.
## 🚀 Next Project

[CPP00](https://github.com/adhaka-afk/CPP00)

## ⏳ Previous Project

[Philosophers](https://github.com/adhaka-afk/Philosophers)


