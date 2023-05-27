# 0x16. C - Simple Shell

Simple Shell is a basic command-line shell program implemented in C. It provides a simple interactive interface for users to execute commands and perform basic shell operations.

## Features

- Command execution: Executes user-specified commands using the `execvp` function.
- Input parsing: Parses user input into individual commands and arguments.
- Prompt display: Displays a prompt to the user for interactive mode.
- Environment variables: Supports built-in commands to manipulate environment variables.
- Variable replacement: Replaces special variables like `$?` and `$$` with their respective values.
- Error handling: Handles errors during command execution and input reading.

## Usage

1. Compilation: Compile the source code using a C compiler.
   ```
   gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
   ```
2. Execution: Run the compiled binary.
   ```
   $ ./hsh
   ```

3. Shell Commands:
- Command Execution: Enter commands at the prompt to execute them.
  ```
  $ ls -l
  $ pwd
  $ echo Hello, world!
  ```

- Command Separation: Separate multiple commands using a semicolon (`;`).
  ```
  $ command1 ; command2 ; command3
  ```

- Logical Operators: Use the shell logical operators `&&` and `||` to control command execution based on the previous command's success or failure.
  ```
  $ command1 && command2    # Execute command2 only if command1 succeeds
  $ command1 || command2    # Execute command2 only if command1 fails
  ```

- Environment Variables:
  - Display Environment Variables: Use the `env` command to display all environment variables.
    ```
    $ env
    ```

  - Set Environment Variable: Use the `setenv` command to set a new environment variable.
    ```
    $ setenv VAR_NAME VAR_VALUE
    ```

  - Unset Environment Variable: Use the `unsetenv` command to remove an environment variable.
    ```
    $ unsetenv VAR_NAME
    ```

- Variable Replacement: Use special variables like `$?` and `$$` for variable replacement.
  - `$?`: Represents the exit status of the previous command.
    ```
    $ command1
    $ echo $?
    ```

  - `$$`: Represents the current process ID.
    ```
    $ echo $$
    ```

4. Exit: To exit the shell, use the `exit` command or press `Ctrl + D`.
