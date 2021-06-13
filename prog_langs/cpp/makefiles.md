# Makefiles

makefiles are build instructions

Example:
```makefile
# Makefile automated build system for the DSA_Lab
# target: dependencies
# 	command
# target expects *exact target*
# eg linkedlist/linkedlist does not work for linkedlist/linkedlist.out

cc=gcc

all: Week_02 linkedlist/linkedlist.out

# Week_02
Week_02: Week_02/Cpp-StackQa.out Week_02/C-StackQa.out
	
Week_02/Cpp-StackQa.out: Week_02/StackQa.cpp
	g++ Week_02/StackQa.cpp -std=c++11 -o Week_02/Cpp-StackQa.out

Week_02/C-StackQa.out: Week_02/StackQa.c 
	cc Week_02/StackQa.c -std=c11 -o Week_02/C-StackQa.out

linkedlist/linkedlist.out: linkedlist/linkedlist.c
	cc linkedlist/linkedlist.c -o linkedlist/linkedlist.out
```

Here, all is the default make target.

all depends on Week_02, so next we see week_02,

Week_02 depends on C-StackQa and Cpp-stackQa, so next wee see wbre they are.

Week_02/C-stackQa and Week_02/Cpp-stackQa have coomands, which arw executed

btw the Week_02/filename specifies the folder of operation

youncan also create variables in make files

```makefile
cc=gcc

add: lol.c
	cc lol.c
```

Also checkout [makefiles in windows](https://cognitivewaves.wordpress.com/makefiles-windows/)
