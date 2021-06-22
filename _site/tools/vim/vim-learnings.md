
# Key Bindings
## Some Basic Movements

`w`: jump to next word


`b`: jump to previous word


`x`: deletes a character


`a`: insert after cursor
`A`: insert at the end of the line.


`o`: insert on the next line, `O` insert on the previous line


`I`: insert at the begining of the line.

`19G` : Jumps to line number 19


`diw` and `daw`: deletes the word if you are in the middle of a word. diw stands for *delete inner word*, daw stands for *delete a word*


`cw`: deletes entire word, and `ce` deletes word and enters insert mode.


`D` deletes the rest of the line, `S` deletes the entire line and enters insert mode.

## Indentation

`==`: indents the current line


`gg = G`: auto-indent file

## Completion

(do not work in normal mode, work in insert mode, Don't know about other modes)

`ctrl x ctrl o`: trigger omnifunc


`ctrl x ctrl n` or `ctrl n`: triggers *next* word completion


`ctrl x ctrl p` or `ctrl p`: triggers *previous* word completion


`ctrl x ctrl l`: triggers whole line completion

## Visual Block mode

To add something to to alot of line together, you can use the visual block mode.

Enter visual block mode using `ctrl-v` and mark all the lines, then type `I`, Capital "I" and insert text, then press `esc` and then... magic! 

# other misc stuff
## StatusLine

Toggle Statusline with the following:

- set laststatus=0 : don't show statusline
- set laststatus=1 : show statusline only if we have more than one windows.
- set laststatus=2 : always show statusline

you can set the statusline color with `:hi Statusline ctermbg=[0-256] ctermfg=[0-256] guitermbg=[#someThingsHex] guitermfg=[#someThingsHex]`

## Folding

`mb%zf'a` assigns fold

#### Bracket matching happens with % in normal mode

## Netrw (File Explorer)

You can open the default file explorer with `:Explore` or use `:Lexplore` or `:Lex` to open a toggalable Netrw window on the left.

You can specify the size with `:19Lexplore` or `:[size]Lex`

## Creating a command shortcut

Say you don't want to use a leader key, you can create a command, and then call it like the normal `:Lol` way.


Remeber though, you cannot create a new command if your first character is small. So here in Lol, first L **NEEDs** to be capital.


Eg, `:command Lol 19Lexplore`


Now you can call `19Lexplore` from just `:lol`

## Mouse support

you can enable nice mouse fatures using `set mouse=nicr` or `set mouse=`a`. (Though what each one does is beyond me)

## Per project config

You can define each project to have a different config using .exrc or .nvimrc/.vimrc at the base of the directory

**you need to specify it in the main vimrc** using `set secure exrc`