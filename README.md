# minishell

### 42 minishell subject : 나만의 작은 쉘 만들기

21.05.25 ~ 

[@mocha-kim](https://github.com/mocha-kim) [@AYoungSn](https://github.com/AYoungSn)

2021.07.05 서브젝트 업데이트
> ## Mandatory part 
> 
> - Not interpret unclosed quotes or unspecified special characters like \ or;.
> - Not use more than one global variable, think about it and be ready to explain why you do it.
> - Show a prompt when waiting for a new command.
> - Have a working History.
> - Search and launch the right executable (based on the PATH variable or by using relative or absolute path)
> - It must implement the builtins:
>   - echo with option -n
>   - cd with only a relative or absolute path
>   - pwd with no options
>   - export with no options
>   - unset with no options
>   - env with no options or arguments
>   - exit with no options
> - ’ inhibit all interpretation of a sequence of characters.
> - " inhibit all interpretation of a sequence of characters except for $.
> - Redirections:
>   - < should redirect input.
>   - \> should redirect output.
>   - “<<” read input from the current source until a line containing only the delimiter is seen. it doesn’t need to update history!
>   - “>>” should redirect output with append mode.
> - Pipes | The output of each command in the pipeline is connected via a pipe to the input of the next command.
> - Environment variables ($ followed by characters) should expand to their values.
> - $? should expands to the exit status of the most recently executed foreground pipeline.
> - ctrl-C ctrl-D ctrl-\ should work like in bash.
> - When interactive:
>   - ctrl-C print a new prompt on a newline.
>   - ctrl-D exit the shell.
>   - ctrl-\ do nothing.
> Anything not asked is not required.
> For every point, if you have any doubt take bash as a reference.


이전 서브젝트
> ## Mandatory part 
>
> - Not use more than one global variable, think about it and be ready to explain why you do it.
> - Show a prompt when waiting for a new command
> - Search and launch the right executable (based on the PATH variable or by using relative or absolute path) like in bash
> - It must implement the builtins like in bash:
>   - echo with option ’-n’
>   - cd with only a relative or absolute path
>   - pwd without any options
>   - export without any options
>   - unset without any options
>   - env without any options and any arguments
>   - exit without any options
> - ; in the command should separate commands like in bash
> - ’ and " should work like in bash except for multiline commands
> - Redirections < > “>>” should work like in bash except for file descriptor aggregation
> - Pipes | should work like in bash except for multiline commands
> - Environment variables ($ followed by characters) should work like in bash
> - $? should work like in bash
> - ctrl-C, ctrl-D and ctrl-\ should have the same result as in bash
> - Use up and down arrows to navigate through the command using termcap (mandatory) history which we will then be able to edit (at least like we can for classic lines) if we feel like it (the line, not the history).
