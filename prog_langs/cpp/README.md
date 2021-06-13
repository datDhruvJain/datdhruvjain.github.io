# Learning C++

## The very basics

`std::cout<<"lol"` -> cout stands for console statement and like the unix format, `<<` stands for write to or append to.

`std` stands for std and is a namespace. namespace is just like a block and allows you to create multiple things under the same header name. We can create two functions with the same name under two different libraries and use the one that we want using namespaces. eg here we use function name cout of std/standard namespace.

you can eliminate the `std::cout` by using the keywords `using namespace std`. you can also use "using declaration" wherein you specify the exact function that you want to use instead of the entire thing.

Here cout is an object(!!!). cout comes under the class ostream.

you can add to what is to be added to cout by adding more `<< statements`, eg: `std::cout << "You have" << slices << of pizza. << std::endl`. Here endl stands for endline (which if you don't put, you will get a %. idk why)

#### taking input

to take in input, you need `std::cin >> varname`. cin is a object of istream.

## Vectors

Vectors are akin to lists or arraylists. They are dynamic in nature and can increase memory use when adding new elements

to use vectors you need to pass a flag during compilation, `g++ -std=c++11 file.cpp`

to declare a vector:

```cpp
std::vector<int> items = {1,2};
items.push_back(100);    // add element 100 to the list
items[2]    // returns the third element
items.size()    // returns the size of vector
```

vectors are pass by value rather than pass by value

## STL Arrays (standard template lib arrays)

**<anything> is a template**

to create a stl array,

```cpp
std::array<type,size> lol;
std::array<int, 4> lol;    
```

- they are statically sized
- they are passed by value
- they remember their own size

## arrays types and pass by reference

**vectors and stl arrays are passed by value and not by reference by default(which is unlike C style array). Now you can pass by reference by doing &arr_name**

eg

```cpp
std::vector<int> lol = {1,2,3};

func (lol){};	// pass by VALUE, COPY values, DONT MODIFY the og vector

func(&lol){};	// pass by REFERECNE, DONT COPY values, MODIFY the og vector

```

#### Range based for loop (for each loop)

```cpp
for(int n : data){
	// do something;
}
```

## IOStreams

Input stream -> buffer (eg console) -> running program

buffer is like a container area which gets filled from the input stream and the is sent to the running program after some event.

to open files:
```cpp
#include<fstream>

std::ofstream file;	// create instance of ofstream class
file.open("filename");  // and open the file

// to write to the file
file << "hey";

// works like cout

file.close();		// close the file
```

if you want to append, you can `file.open("filename", std::ios::app)`. ios stands for input/output stream, and app stands for append

also you can check if the file is open or not using `file.is_open()` method.

and to take filename from the user, do:
```cpp
	std::string filename;
	std::cin >> filename;

	file.open(filename.c_str(), std::ios::app);
```

reading from files: 
```cpp
// to read from a file, you need to make an input file stream object.
std::ifstream file("mcd.txt");
std::vector<std::string> names;
std::string input;

while(file >> input){
	names.push_back(input);
}
```

The get and getline methods for input from files:

- get returns a char value `char temp = file.get();`
- getline returns an entire line:
	```cpp
	std::string temp;
	
	getline(file, line);
	// store the line "from" file into "line"
	```

# Functions

what's in a name?

- A function is a block of code grouped together an excecuted when called upon
- A method is similiar, but a method is attached to an Object rather than being on it's own.
- Static methods are attached to classes but don't need an instance to be called (they are not attached to the object).
- constructor is an initializer for a class.
  - destructor destroys the object and cleans up after the object.

  ### The const keyword

const keyword can be used to pass a variable/array(which is passed by decay to pointer/reference) to a function if you dont want it's value to change by the function

eg:
```cpp
void do_something(const int arr[], int size){{
	// now the value of arr[] will not be able to change
}}
```

Remember, when this is done, if a function exists within the parent function that also uses the const variable, the const variable will have to be passed as const in that function as well, otherwise you will get an error.

Also the const keyword affects method signature so while declaration of the function you also need to specify const with the parameter you want to make const.

## Pass Bys in arguments

1. pass by value.
	
	in this case the value is passed (to the function). most things are passed by value (even custom class types).
2. pass by decay to pointer
	
	in this case the variable decays to a pointer and then that pointer is passed. Mostly used in arrays.
3. pass by reference
	
	we have to explicitly pass by reference using `&` before the variable name *in the function declaration/defination and not in the function call* (for eg &x). In pass by reference, direct memory location is passed.
