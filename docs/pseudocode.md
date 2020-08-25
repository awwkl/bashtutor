<main.c>    // start_program, program loop, exit_program
<start.c>   // welcome message, show chapters, prompt_jump
<exit.c>    // exit message
<explain.c> // explain, next, previous, jump, print_progress
<input.c>   // get, parse, [intercept], execute
<misc.c>    // print_help, exit

<<main.c>>
main()
    start_program()
    while (get_parse_execute());
    exit_program();

<<start.c>>
start_program()
    print welcome message
    print_chapters()
    prompt_jump() to specified chapter, else defaults to chapter 1
    print first info text

<<input.c>>
get_parse_execute()
    return (get_input() &&
            parse_input() &&
            exec_input())

get_input()
    print prompt "bashtutor> "
    read user input into static global char `input[4096]`

parse_input()
    strtok into static char *command[64]

exec_input()
    intercept to check for bashtutor commands
    intercept to check for bash built-ins like "cd"
    system(command) // performs fork(), execl(), waitpid() 

<<exit.c>>
    print exit message
    exit program

<<explain.c>
    `progress` counter variable to track progress
    advance progress based on user actions (or on receiving "next")
    jump to different points by changing progress variable 

explain()
    print explanation based on progress

jump()
    "jump 3" will jump to chapter 3
    "jump 209" will jump to 10th text in chapter 2
    set progress = xxx
    explain

next()
    progress++
    explain

previous()
    progress--
    explain

print_chapters()

<!-- 
print_progress() should just print the progress number e.g. 209
 -->

<<misc.c>>
print_help()
    print help information
