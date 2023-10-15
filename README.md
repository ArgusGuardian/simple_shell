# Simple Shell

The Simple Shell is a basic command-line shell implemented in C. It provides users with a minimalistic command-line interface for running shell commands. This project was created as part of a learning exercise and serves as a simplified, educational example of how a shell can be implemented.

## Table of Contents

- [Authors](#authors)
- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Commands](#commands)
- [Error Handling](#error-handling)

## Authors

- [Alaa Eddine Elhannaoui](mailto:Alaaelhannaoui@proton.me)
- [Zakaria Elrharbi](mailto:Zakariaelrharbi62@gmail.com)

## Introduction

A shell is a fundamental component of any operating system. It allows users to interact with the system by providing a text-based interface for running commands and managing processes. The Simple Shell project aims to provide a basic understanding of how a shell works and how it can be implemented.

## Features

- **Command Execution**: The shell can execute various shell commands and external programs.

- **Change Directory (cd)**: Users can change their current working directory using the `cd` command.

- **Exit**: The shell handles the `exit` command to terminate the shell.

- **Error Handling**: The shell provides basic error handling for invalid commands and situations.

## Getting Started

To get started with the Simple Shell, follow these steps:

1. Clone the repository to your local machine:

   ```shell
   git clone https://github.com/your-username/simple-shell.git
   ```

2. Compile the code:

   ```shell
   gcc -o hsh *.c
   ```

3. Run the shell:

   ```shell
   ./hsh
   ```

## Usage

The Simple Shell supports basic shell commands and external programs. Here are some examples of how to use the shell:

- Running a command:

   ```shell
   '$ ls'
   ```

- Changing directories (cd):

   ```shell
   '$ cd /path/to/directory'
   ```

- Exiting the shell:

   ```shell
   '$ exit'
   ```

Please note that this is a minimal shell and does not support all the features of a full-featured shell like Bash.

## Commands

The Simple Shell supports a variety of shell commands, including but not limited to:

- `ls`: List files and directories in the current directory.
- `cd`: Change the current working directory.
- `pwd`: Print the current working directory.
- `echo`: Print arguments to the standard output.
- `cat`: Concatenate and display the content of files.
- `exit`: Exit the shell.
- ...

## Error Handling

The shell includes basic error handling. It can detect and handle various error conditions, such as:

- Invalid commands.
- Issues with executing external programs.
- Errors related to changing directories.
