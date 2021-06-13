# C/C++
## The very basics
`std::cout<<"lol"` cout stands for console statement and like the unix format, `<<` stands for write to or append to.

`std` stands for std and is a namespace. namespace is just like a block and allows you to create multiple things under the same header name. We can create two functions with the same name under two different libraries and use the one that we want using namespaces. eg here we use function name cout of std/standard namespace.

you can eliminate the `std::cout` by using the keywords using namespace std. you can also use "using declaration" wherein you specify the exact function that you want to use instead of the entire thing.

Here cout is an object(!!!). cout comes under the class ostream.

you can add to what is to be added to cout by adding more `<< statements, eg: std::cout << "You have" << slices << of pizza. << std::endl`. Here endl stands for endline (which if you don't put, you will get a %. idk why)

to take in input, you need `std::cin >> varname`. cin is a object of istream.

## Dynamic Arrays/Memory Allocation

```cpp
int * p;
// Stuffs
p = new int[size];
```

Another Example

```cpp
class Stack {
	int  stk;
	public:
	Stack(int size = 5) {
		stk = new int[size];
	}
};
```

## Vectors
Vectors are akin to lists or arraylists. They are dynamic in nature and can increase memory use when adding new elements

to use vectors you need to pass a flag during compilation, g++ -std=c++11 file.cpp
to declare a vector:

```cpp
std::vector<int> items = {1,2};

items.push_back(100); // add element 100 to the list
// now items will become {1,2,100}

items[2] // returns the third element
items.size() // returns the size of vector
// will return 2

// Remove from the end of the list
data.pop_back();
```
vectors are pass by value rather than pass by value

## STL Arrays (standard template lib arrays)
is a template
to create a stl array,
```cpp
std::array<type,size> lol;
std::array<int, 4> lol;
```

- they are statically sized
- they are passed by value
- they remember their own size

#### arrays types and pass by reference
vectors and stl arrays are passed by value and not by reference by default(which is unlike C style array). Now you can pass by reference by doing &arr_name

eg

```cpp
std::vector<int> lol = {1,2,3};
func (lol){}; // pass by VALUE, COPY values, DONT MODIFY the og vector
func(&lol){}; // pass by REFERECNE, DONT COPY values, MODIFY the og vector
```


### Range based for loops
```cpp
for(int n : data){
// do something;
}
```
## IOstreams
Input stream -> buffer (eg console) -> running program
buffer is like a container area which gets filled from the input stream and the is sent to the running program after some event.
to open files:
```cpp
#include<fstream>

std::ofstream file; // create instance of ofstream class
file.open("filename"); // and open the file

// to write to the file
file << "hey";
// works like cout

file.close(); // close the file
```

if you want to append, you can file.open("filename", std::ios::app). ios stands for input/output stream, and app stands for append

also you can check if the file is open or not using file.is_open() method.

and to take filename from the user, do:
```cpp
std::string filename;
std::cin >> filename;
// Appends instead of overwriting
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
- get returns a char value char temp = file.get();
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

#### The const keyword
const keyword can be used to pass a variable/array(which is passed by decay to pointer/reference) to a function if you dont want it's value to change by the function
eg:
```cpp
void do_something(const int arr[], int size){{

// now the value of arr[] will not be able to change

}}
```

Remember, when this is done, if a function exists within the parent function that also uses the const variable, the const variable will have to be passed as const in that function as well, otherwise you will get an error.

Also the const keyword affects method signature so while declaration of the function you also need to specify const with the parameter you want to make const.

### Pass Bys in arguments
1. pass by value.
    In this case the value is passed (to the function). most things are passed by value (even custom class types).
2. pass by decay to pointer. 
    In this case the variable decays to a pointer and then that pointer is passed. Mostly used in arrays.
3. pass by reference 
    we have to explicitly pass by reference using & before the variable name in the function declaration/defination and not in the function call (for eg &x). In pass by reference, direct memory location is passed.

### Defualt parameters
A default parameter is the default value taken if the value of a parameter is not given.

```cpp
// to demostrate default parameters
double pow(double num, int power = 2){
double ans=1;
for (int i=0; i<power; i++){
ans=num;
}
return ans;
}

pow(3) 	 // returns 9
pow(3,3) // returns 27
```

It is recommended that default parameters be declared.

you can use it in definations too, but that is redundant

Also then it is recommended to define default parameter in header files instead of in the main files itself.

## Namespaces
Purpose is to give scope to the identifiers

Used to avoid naming conflict

two libraries can have the same variable name/function name, and you can do that with namespaces

defining namespaces:
```cpp
namespace utilz
{
	// blah blah
	double pow(double num, int power){
	double ans=1;
	for (int i=0; i<power; i++){
		ans=num;
	}
	return ans;
}
}

int main(){
	utilz::pow(2,3);
}
```
When using namespaces in mutiple files, remember to define namespaces in both the header file as well as the utility file, in the same locations/blocks

## Templetized functions

Used for a function that should work on multiple datatypes, or a function whose datatype isn't immediately known

```cpp
template <typename T>
void swap(T &a, T &b)
{
T temp = a;
a = b;
b = temp;
```

Main function for this

```cpp
#include<iostream>

int main()
{
int a,b;
a = 10;
b = 12;
std::cout << a << " " << b << std::endl;
swap(a,b);
std::cout << a << " " << b << std::endl;
std::string c,d;
c = " Hello ";
d = " world ";
std::cout << c << " " << d << std::endl;
swap(c,d);
std::cout << c << " " << d << std::endl;
}
```

# Pointers

The . (dot) operator and the -> (arrow) operator are used to reference individual members of classes, structures, and unions.

The dot operator is applied to the actual object. The arrow operator is used with a pointer to an object. For example, consider the following structure −

```cpp
struct Employee {
   char first_name[16];
   int  age;
}  emp;
```

### The (.) dot operator
To assign the value "zara" to the first_name member of object emp, you would write something as follows −
```cpp
strcpy(emp.first_name, "zara");
```

### The (->) arrow operator
If p_emp is a pointer to an object of type Employee, then to assign the value "zara" to the first_name member of object emp, you would write something as follows −

##### These operators work on classes as well
eg
```cpp
class Node{
    public:
    int data;
    Node* next;
    void printer(){
        std::cout << "Hello" << std::endl;
    }
};

Node n;
Node* temp;
temp = &n;

// Prints hello world!!!
// This means that the arrow operator works on functions too
temp -> printer();
```

```cpp
strcpy(p_emp->first_name, "zara");
// This is same as
strcpy((*p_emp).first_name, "zara");
```

The -> is called the arrow operator. It is formed by using the minus sign followed by a greater than sign.

Simply saying: To access members of a structure, use the dot operator. To access members of a structure through a pointer, use the arrow operator.

This is the same as strcpy(*p_emp).first_name, "zara")

---

# OOPS

**Remember whenever the class file is different from the main file, you need to follow multifile compilation
`g++ class_file.cpp main.cpp`**

### A note about access modifiers 

By defualt the members in classes are private, and members in structs are public.
to modify the access we need to do:

```cpp
class User
{
	std::string status;

	public:
		std::string first_name;
		std::string last_name;
			
		void set_status(std::string st){
			status = st;
		}
		std::string get_status(){
			return status;
		}
}
```

```cpp
struct User
	{
		std::string first_name;
		std::string last_name;
		
		void set_status(std::string st){
			status = st;
		}
		std::string get_status(){
			return status;
		}
	
		private:
			std::string status;
};
```

The ; in the end is mandatory in both

### Static stuff
static variables can be used only in a static context (static functions)
the values of static variables need to be declared outside the class, after the class defination and with the `class_name::stat_var`

```cpp
class User
{
	public:
		static int count;
		// blah blah
}

User::count = 0;
```

## Constructors

A function within the class with the same name as the class and no return types

If we create a parameterized constructor, then we cannot call the default constructor, in fact if ever you override the constructor, then you cannot call the default constructor.

Default values are valid though, ie

```cpp
User(std::string fn ="John", std::string ln ="Doe")
{
	std::cout << "Hello from the parameterized constructor" << std::endl;
	first_name = fn;
	last_name = ln;
}
```

Is perfectly valid

## Destructor 
Just prefix the class name with ~ as a function.

For example if we had the class name as User, our destructor will be named as `~User()`  or with parameters and stuff.

## Operator Overloading

```cpp
#include <iostream>

class Position
{
	public:
		int x = 10;
		int y = 20;

		Position operator + (Position p)
		// pos1 calls this operator,
		// and the operator see pos2, and adds it to pos1
		// it returns the object of Position
		{
			Position new_pos;
			new_pos.x = x + new_pos.x;
			new_pos.y = y + new_pos.y;

			return new_pos;
		}

};

int main()
{
	Position pos1, pos2, pos3;
	pos3 = pos1 + pos2;
	std::cout << pos3.x  << " " << pos3.y << std::endl; 
	return 0;
}
```

### << and >> overloading
Needs to be done outside the class only

```cpp
std::ostream& operator << (std::ostream& output, const Position pos)
		{
			output << "X: " << pos.x << " Y: " << pos.y;
			return output;
		}
```

## Friend Functions

Functions that are declared within the class, defined outside the class and have access to data inside the class including private variables.

```cpp
class User
{
	// status is private,
	// output_status come under public
	friend void output_status(User user);

};

void output_status(User user)
{
	std::cout << user.status << std::endl;
}
```

Remember, the defination does not contain friend, only declaration does.

## Inheritence

```cpp
class User {//blah blah}
class Teacher : public User {//blah blah}
```

## Polymorphism

use keyword `virtual`

Using virtual we say that it is allowed to override this method. Also you dont have to define the method in the parent with virtual.

remeber now

**parent p = child** is possible but ~~child c = parent is not~~


# Multifile compilation

#### ifndef - if not defined

Used as a safeguard so that the same variables are not declared by two different header files (need to look this up)

```cpp
#ifndef hello_h
#define hello_h
// declarations
#endif
```

**.h Files are just like interfaces**

**.o files are c++ object files which hide the source code, but still need to be compiled.**

## Makefiles

Makefiles are used for when one of the files has changed, and you dont want to recompile the whole project. In here, you relink with the updated source code, instead of recompiling.

Makefiles are freaking cool!!

makefiles are named makefile dont let the name fool you though.

```makefile
path/to/target: path/to/dependencies
  command

shape: shapes.o shapes_util.o
	g++ shapes.o shapes_util.o -o math

shapes.o: shapes.cpp
	g++ -c shapes.cpp

shapes_util.o: shapes_util.cpp
	g++ -c shapes_util.cpp

clean:
	rm .o
```

finally execute make in the terminal (unix) and watch it gooooo!!! It will list out all the commands that will take place.

Here, the final executable is linked to shapes.o and shapes_util.o, and you get shape from running the command `g++ shapes.o shapes_util.o -o math`

next, shapes.o is linked to shapes.cpp and is generated by executing the command `g++ -c shapes.cpp`

same for shapes_util.o

`clean` is a post run instruction on what to do, here we remove the .o files.