<h1>Custom shell interpreter</h1>

<p id="description">Build a BASH-like command line interpreter in C</p>

<h2>Project Screenshots:</h2>

<img src="https://github.com/tcampbel22/42_hive_minishell/blob/master/lib/ezgif-336910bade8b2.gif?raw=true" alt="project-screenshot" width="600" height="400/">

<h2>Features</h2>

*   Pipes
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
git clone "this repository"
```

<p>2. Compile</p>

```
make
```

<p>3. Run</p>

```
./minishell
```

<h2>About</h2>

Minishell is about creating a mini shell in C. This is one of the bigger projects of the 42 curriculum and presented many challenges. 

This was built with myself and @xrierac(Xavi) Xavi handled the execution part while I did the parsing. 

To parse the information from the command line I needed to tokenise the information validate it and then store it for execution. 

Our method for storing was a pointer to a 2D array of structs. Each struct contained a token type (CMD HEREDOC etc) and a 2D char pointer containing the information to be executed. 

The token type alerted the execution which function was to be executed.

<h2>Visualisation of our token structure:</h2>

<img src="https://github.com/tcampbel22/42_hive_minishell/blob/master/lib/Screenshot%20from%202025-02-06%2017-44-35.png?raw=true" alt="project-screenshot" width="600" height="400/">


Additional parts of the parsing required checks for each type redirection single and double quotes environmental variables and finally running the Heredoc. 

If you want test our minishell follow the installation guide above and try running some commands!

  
<h2>💻 Built with</h2>

*   Bash
*   C Language
