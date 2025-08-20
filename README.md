<h1>Custom shell interpreter</h1>

<p id="description">Build a BASH-like command line interpreter in C</p>

<h2>Project Screenshots:</h2>

<img src="https://github.com/tcampbel22/42_hive_minishell/blob/master/lib/ezgif-336910bade8b2.gif?raw=true" alt="project-screenshot" width="600" height="400/">

<h2>Features</h2>

*   Pipes (|)
*   Single & Double Quote Handling
*   Signal Handling
*   Redirections (< > << >>)
*   Builtins
    * exit
    * cd
    * echo
    * export
    * unset
    * env
    * pwd

<h2>🛠️ Installation Steps:</h2>

<p>1. Download</p>

```
git clone "https://github.com/tcampbel22/custom_shell_interpreter"
```

<p>2. Compile</p>

```
cd custom_shell_interpeter
make
```

<p>3. Run</p>

```
./minishell
```

<h2>About</h2>

Minishell is about creating a mini command line interpreter in C. This is one of the bigger projects of the 42 curriculum and presented many challenges. 

This was built by @xrierac(Xavi) and myself, we split the proect into 2 larger parts 
- Input parsing
- Execution

I handled the parsing and Xavi the exection.

The parsing involved taking the input, sansitising it, checking for errors before storing it in tokens to be sent to the execution. 
The data structure we used was a 2d array of nested structs, each struct was made of 2 parts the 2D char pointer and an ENUM specifying the type of command (CMD, R_INPUT, R_OUTPUT).
The parser basic workflow would be -
				
   - User input
   - Syntax error checks
   - Enviromental variable checks
   - Handle Heredoc</ul>
   - Split input by pipes
   - Split each individual command into strings
   - Send each command to execution

Once the execution recieves the formatted command it will create child processes based on the amount of pipes in the command, the command will then be executed using the execve function and return the output to the specified file descriptor and correct exit code.

Addtionally a global signal handler handles ctrl+c, ctrl+d and ctrl+\.

<h2>Visualisation of our token structure:</h2>

<img src="https://github.com/tcampbel22/42_hive_minishell/blob/master/lib/Screenshot%20from%202025-02-06%2017-44-35.png?raw=true" alt="project-screenshot" width="600" height="400/">
 
If you want test our minishell follow the installation guide above or try the live demo <a href="https://tcampbel22.github.io/shell">here</a> and try running some commands!

  
<h2>💻 Built with</h2>

*   Bash
*   C
