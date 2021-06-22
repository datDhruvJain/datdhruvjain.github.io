# A Great Vim Cheat Sheet

[Check This amazing resource from freecodecamp too!](https://www.freecodecamp.org/news/learn-linux-vim-basic-features-19134461ab85/)

Note: If you’re decent at Vim and want your mind blown, check out [Advanced Vim](advanced.html).

I’ve compiled a list of *essential* Vim commands that I use every day. I have then given a few instructions on how to make Vim as great as it should be, because it’s painful without configuration.

## Cursor movement (Inside command/normal mode)

<img src="images/hjkl.png" alt="The four directions in Vim, keys h, j, k, and l."/>

* `w` - jump by start of words (punctuation considered words)
* `W` - jump by words (spaces separate words)
* `e` - jump to end of words (punctuation considered words)
* `E` - jump to end of words (no punctuation)
* `b` - jump backward by words (punctuation considered words)
* `B` - jump backward by words (no punctuation)
* `0` - (zero) start of line
* `^` - first non-blank character of line (same as 0w)
* `$` - end of line
* Advanced (in order of what I find most useful)
    * `Ctrl+d` - move down half a page
    * `Ctrl+u` - move up half a page
    * `}` - go forward by paragraph (the next blank line)
    * `{` - go backward by paragraph (the next blank line)
    * `gg` - go to the top of the page
    * `G` - go the bottom of the page
    * `: [num] [enter]` - Go to that line in the document
    * Searching
        * `f [char]` - Move to the next char on the current line after the cursor
        * `F [char]` - Move to the next char on the current line before the cursor
        * `t [char]` - Move to before the next char on the current line after the cursor
        * `T [char]` - Move to before the next char on the current line before the cursor
        * All these commands can be followed by `;` (semicolon) to go to the next searched item, and `,` (comma) to go the previous searched item

## Insert/Appending/Editing Text
* Results in Insert mode
    * `i` - start insert mode at cursor
    * `I` - insert at the beginning of the line
    * `a` - append after the cursor
    * `A` - append at the end of the line
    * `o` - open (append) blank line below current line (no need to press return)
    * `O` - open blank line above current line
    * `cc` - change (replace) an entire line
    * `c  [movement command]` - change (replace) from the cursor to the move-to point.
    * ex. `ce` changes from the cursor to the end of the cursor word
* `Esc` or `Ctrl+[` - exit insert mode
* `r  [char]` - replace a single character with the specified char (does not use Insert mode)
* `d` - delete
    * `d` - [movement command] deletes from the cursor to the move-to point.
    * ex. `de` deletes from the cursor to the end of the current word
* `dd` - delete the current line
* Advanced
    * `J` - join line below to the current one

## Marking text (visual mode)
* `v` - starts visual mode
    * From here you can move around as in normal mode (`h`, `j`, `k`, `l` etc.) and can then do a command (such as `y`, `d`, or `c`)
* `V` - starts linewise visual mode
* `Ctrl+v` - start visual block mode
* `Esc` or `Ctrl+[` - exit visual mode
* Advanced
    * `O` - move to other corner of block
    * `o` - move to other end of marked area

## Visual commands
Type any of these while some text is selected to apply the action

* `y` - yank (copy) marked text
* `d` - delete marked text
* `c` - delete the marked text and go into insert mode (like c does above)

## Cut and Paste
* `yy` - yank (copy) a line
* `p` - put (paste) the clipboard after cursor
* `P` - put (paste) before cursor
* `dd` - delete (cut) a line
* `x` - delete (cut) current character
* `X` - delete previous character (like backspace)

## Exiting
* `:w` - write (save) the file, but don't exit
* `:wq` - write (save) and quit
* `:q` - quit (fails if anything has changed)
* `:q!` - quit and throw away changes

## Search/Replace
* `/pattern` - search for pattern
* `?pattern` - search backward for pattern
* `n` - repeat search in same direction
* `N` - repeat search in opposite direction
* `:%s/old/new/g` - replace all old with new throughout file ([gn](http://vimcasts.org/episodes/operating-on-search-matches-using-gn/) is better though)
* `:%s/old/new/gc` - replace all old with new throughout file with confirmations

## Working with multiple files
* `:e filename` - Edit a file
* `:tabe` - Make a new tab
* `gt` - Go to the next tab
* `gT` - Go to the previous tab
* Advanced
    * `:vsp` - vertically split windows
    * `ctrl+ws` - Split windows horizontally
    * `ctrl+wv` - Split windows vertically
    * `ctrl+ww` - switch between windows
    * `ctrl+wq` - Quit a window

## Marks
Marks allow you to jump to designated points in your code.

* `m{a-z}` - Set mark {a-z} at cursor position 
* A capital mark {A-Z} sets a global mark and will work between files
* `‘{a-z}` - move the cursor to the start of the line where the mark was set
* `‘’` - go back to the previous jump location

## General
* `u` - undo
* `Ctrl+r` - redo
* `.` - repeat last command

# Making Vim actually useful
Vim is quite unpleasant out of the box. For example, typing `:w` for every file save is awkward and copying and pasting to the system clipboard does not work. However, a few changes will get you much closer to the editor of your dreams.

## .vimrc
* [My .vimrc file](https://github.com/theicfire/dotfiles/blob/master/vim/.vimrc) has some pretty great ideas I haven't seen elsewhere.
* This is a minimal vimrc that focuses on three priorities:
    * adding options that are strictly better (like more information showing in autocomplete)
    * more convenient keystrokes (like  `[space]w` for write, instead of `:w [enter]`)
    * a similar workflow to normal text editors (like enabling the mouse)

### Installation
* Copy this to your home directory and restart Vim. Read through it to see what you can now do (like  `[space]w` to save a file)
    * Mac users - making a hidden normal file is suprisingly tricky. Here’s one way:
        * in the command line, go to the home directory
        * type `nano .vimrc`
        * paste in the contents of the .vimrc file
        * `ctrl+x`, `y`, `[enter]` to save
* You should now be able to press  `[space]w` in normal mode to save a file.
* `[space]p` should paste from the system clipboard (outside of Vim).
    * If you can’t paste, it’s probably because Vim was not built with the system clipboard option. To check, run `vim --version` and see if `+clipboard` exists. If it says `-clipboard`, you will not be able to copy from outside of Vim.
    * For Mac users, homebrew install Vim with the clipboard option. Install homebrew and then run `brew install vim`.
        * then move the old Vim binary: `$ mv /usr/bin/vim /usr/bin/vimold`
        * restart your terminal and you should see `vim --version` now with `+clipboard`

## Plugins
* The easiest way to make Vim more powerful is to use Vintageous in Sublime Text (version 3). This gives you Vim mode inside Sublime. I suggest this (or a similar setup with the Atom editor) if you aren't a Vim master. Check out [Advanced Vim](advanced.html) if you are.
* Vintageous is great, but I suggest you change a few settings to make it better.
    * Clone [this repository](https://github.com/theicfire/Vintageous) to `~/.config/sublime-text-3/Packages/Vintageous`, or similar. Then check out the "custom" branch.
        * Alternatively, you can get a more updated Vintageous version by cloning [the official](https://github.com/guillermooo/Vintageous) repository and then copying over [this patch](https://github.com/theicfire/Vintageous/commit/19ff6311b01e3ae259b7eb8e3944687b42ba06ff).
    * Change the user settings (`User/Preferences.sublime-settings`) to include:
        * `"caret_style": "solid"`
        * This will make the cursor not blink, like in Vim.
        * Sublime Text might freeze when you do this. It’s a bug; just restart Sublime Text after changing the file.
    * `ctrl+r` in Vim means "redo". But there is a handy Ctrl + R shortcut in Sublime Text that gives an "outline" of a file. I remapped it to alt+r by putting this in the User keymap
        * `{ "keys": ["alt+r"], "command": "show_overlay", "args": {"overlay": "goto", "text": "@"} },`
    * [Add the ability to toggle Vintageous on and off](https://github.com/guillermooo/Vintageous/wiki/Toggling-Vintageous)
    * Mac users: you will not have the ability to hold down a navigation key (like holding j to go down). To fix this, run the commands specified here: [https://gist.github.com/kconragan/2510186](https://gist.github.com/kconragan/2510186)
 
* Now you should be able to restart sublime and have a great Vim environment! Sweet Dude.

## Switch Caps Lock and Escape
* I highly recommend you switch the mapping of your caps lock and escape keys. You'll love it, promise! Switching the two keys is platform dependent; Google should get you the answer.

## Other
I don’t personally use these yet, but I’ve heard other people do!

* `:wqa` - Write and quit all open tabs (thanks Brian Zick)

---

# Advanced Vim Cheat Sheet
The best possible resource on vim is the book [Practical Vim](http://www.amazon.com/Practical-Vim-Thought-Pragmatic-Programmers/dp/1934356980). I’ve outlined some of my personal favorites, and will also put in some plugins that might just change your world.

## General

* Text Objects
	* Say you have `def (arg1, arg2, arg3)`, where your cursor is somewhere in the middle of the parenthesis.
    * `di(` deletes everything between the parenthesis. That says "change everything inside the nearest parenthesis". Without text objects, you would need to do `T(dt)`.
	* Learn more [here](http://blog.carbonfive.com/2011/10/17/vim-text-objects-the-definitive-guide/)
* automatic marks
    * [http://vim.wikia.com/wiki/Using\_marks](http://vim.wikia.com/wiki/Using_marks) under "special marks"
* `%` - jumps between matching `()` or `{}`
* [jump list](http://vim.wikia.com/wiki/Jumping_to_previously_visited_locations)
	* `ctrl+o` - go backwards in the jump list
	* `ctrl+i` - go forwards in the jump list
* [change list](http://vim.wikia.com/wiki/Jumping_to_previously_visited_locations)
	* `g;` - go backwards in the change list
    * `g,` - go forwards in the change list
* `Ctrl+r + 0` in insert mode inserts the last yanked text (or in command mode)
* `gv` - reselect (select last selected block of text, from visual mode)
* `ctrl+e / ctrl+y` - Scroll down/up one line

## Plugins
The most helpful part of plugins is that they make vim a better fully featured IDE. Concepts like global search and finding a file to open are solved with plugins. They also can bring out some missing features of vim, like automatic commenting.

### Essential Plugins
* *vim-pathogen*: Either this or Vundle are good ways to manage your plugins.
* *vim-sensible*: tiny set of reasonable defaults that every vim user should have. This allows you to keep your .vimrc a bit smaller.
* *ag.vim*: Fantastically fast global searches.
* *ctrlp.vim*: Open up any file or buffer.
* *nerdcommenter*: Allows you to comment some block of code

### Awesome Plugins
* indentLine: Shows you visibly your tabs or spaces, like sublime
* neocomplete.vim (or you complete me): Autocomplete
* nerdtree: File browser
* vim-surround: Quicker way to add or delete some characters *around* something
* tagbar: Similar to the "outline" feature of many IDE's

## Regex and Searching
* Searching in vim is very unintuitive. There are 4 modes of searching, ranging from "very magic" to "very no magic". They determine what needs to be escaped with a `\` in your search term. If you just want "regex on" or "regex off" then always search in Very Magic or Very No Magic mode.
* Check out the details by running `:h \\v`.

### Perl style regexes (Very Magic Mode)

Start a search with `\v`. Everything else can act like a normal regex search, except you have to escape `/` and `\`. If you are searching backwards, you’ll also have to escape `?`.

* E.g. search for a url starting with `www` and ending with `.com`: `\vwww\..*\.com`

#### Differences from Perl Regex
The `<` and `>` characters are special for start and end of word. Escape them to search for them literally.

### Literal Search (Very No Magic Mode)
Start a search with `\V`. Now you *only have to escape* `/` and `\`. It would be nice if you didn't have to escape *anything*, but alas vim is not like this.

### Advanced: Match a subsection of your search
Let's say you have this file

```
www.yahoo.com
blah some other stuff
www.google.com
www.ebay.org
```
And you want to change it to

```
www.chase.com
blah some other stuff
www.chase.com
www.chase.org
```
What you're doing is saying *find all domain names and change the inner part to `chase`*. You can do this by specifying the part of the search to *match*.
Put `\zs` before where you want to match and `\ze` after where you want to match.
	
So in this case: `\v` `www\.` **\zs** `.*` **\ze** `\.com`

* An extension to this is looking for the start of a word without matching it. For example looking for the variable `i`. We could then use this search: `\v\W\zsi\ze\W`. Note: Use `\W` matches everything except `[a-zA-Z0-9_]`
	* There’s a shortcut called word boundaries, with `<` and `>`:
		* `\v<i>` ([More info](http://vim.wikia.com/wiki/Search_patterns))
        * You can get this same behavior by pressing `*` in normal mode, while having your cursor over the word you want to search.

### Faster Search and Replace
* Vim 7.4 has an [amazing "gn" command](http://vimcasts.org/episodes/operating-on-search-matches-using-gn/) that allows you to search and replace faster. `gn` means "select the next search term".
