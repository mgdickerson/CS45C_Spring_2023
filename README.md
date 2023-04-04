# ICS 45C: Homework 1

Welcome to ICS 45C Homework 1! For more general instructions, please reference the `main` branch.
This repository will focus on instructions relevant to HW1. In this assignment, you will be modifying:

```bash
main.cpp
convert_knots.h
stack.h

# If using GTest:
knot_tests.cpp
stack_tests.cpp
```

### TLDR Build And Run:

```bash
# Target Build Command
cmake --build build   # Will build all of the `targets` described in the `CMake` file

# Build only main.cpp:
cmake --build build --target hw

# Build only Knot tests:
cmake --build build --target knot_gtest

# Build only Stack tests:
cmake --build build --target stack_gtest

./build/hw            # Runs the `main` function from src/main.cpp
./build/knot_gtest    # Runs the 'knot' gtest set of tests
./build/stack_gtest   # Runs the `Stack` gtests
```

## Getting Started

If you are using `GitHub`, then getting started is easy! You will clone this repository, then
checkout the `hw1` branch! If you have already `cloned` this project, then you can skip to
the [Checkout](#checkout) instructions. If you plan to not use `GitHub` and still want to use
our provided tests, follow the instructions under [Directory Structure](#directory-structure).
If you want to manually make the individual files and not use our tests, then you can simply
make a `main.cpp` file and skip ahead to the [Coding](#coding) section.

### Clone

On `Linux` and `Mac`, you can open a new terminal. On Windows you will open `Git BASH` which
should have been installed following the instructions under the `main` branch. On OpenLab,
you are already in a terminal! Next, you will want to copy the repository link as shown in
the image below:

![](docs/clone_link.png)

And then in the terminal, type:

```bash
git clone <LinkCopiedAbove>  # For example: git clone git@github.com:klefstad/CS45C-Template.git 
```

There should now be a folder named `CS45C-Template`. We will move into that directory using the
command:

```bash
cd CS45C-Template
```

Once inside the directory, we will `checkout` the `hw1` branch!

### Checkout

In the same terminal as before, you will type:

```bash
git checkout hw1
```

You are now in the `hw1` branch! You can now make changes to your code as shown in the [Coding](#coding)
section below!

## Directory Structure

If you are not using `GitHub`, and want to use our testing framework, you will need to make a folder
named `hw1` with the following structure:

```bash
├── CMakeLists.txt
├── gtest
│   ├── gtestmain.cpp
│   ├── knot_tests.cpp
│   └── stack_tests.cpp
└── src
    ├── convert_knots.h
    ├── main.cpp
    └── stack.h
```

You should copy everything from the CMakeLists.txt file into your own, as well as the files `gtestmain.cpp`
and `tests.cpp`. This will allow you to build and run the tests for this assignment. If you do not
follow this structure, you will not be able to use the `CMakeLists.txt` file as provided!

## Coding

In this assignment, we will be making a [knots converter](#convert-knots) as well as a [stack](#stack). First,
as in `hw0`, we will be making a basic `main` function in `src/main.cpp`. Open the terminal on your
system of choice (or `ssh` into OpenLab), and use either `vim` or `neovim` to modify our `main.cpp`
file:

```bash
vim src/main.cpp

# Or neovim:
nvim src/main.cpp
```

Once you are in `vim`/`nvim`, you will enter `insert` mode by pressing `i`. Then type the following program
and press `Esc` when you are done:

```cpp
#include <iostream>

using namespace std;

int main() {
  cout << "Hello World!" << endl;
  return 0;
}
```

Once you have finished writing the `main` function,
ensure that you have left `insert` mode by pressing `Esc`, then `write` and `quit` `vim` by typing either
`:wq` or `:x` and then pressing the `Enter` key. This should close `vim`/`nvim` with your changes made.

### Convert Knots

After you have finished making your `main.cpp` file, move on to making the `knots converter`.
For the knots converter, you can modify (or create) the file `src/convert_knots.h` using either
`vim` or `neovim` (it does not matter which you use, both will work).

```bash
vim src/convert_knots.h

# Or neovim:
nvim src/convert_knots.h
```

Now, you will need to add a function named `knots_to_miles_per_minute`
that takes an `integer` named `knots` and returns a `double` value for `miles per minute`:

```cpp
double knots_to_miles_per_minute(int knots) {
  // Write your code here:
}
```

For actually converting, you will need to write code to convert the input of `knots` to
`miles per minute`. To do this, you can use the following conversions:

- 1 knot = 6076 feet per hour
- 1 mile per hour = 5280 feet per hour
- 1 hour = 60 minutes

When you have finished making your conversion function, you will need to leave `insert` mode by pressing
the `Esc` key as you did above, and then `write` and `quit` using either `:wq` or `:x` and pressing `Enter`
just as you did before (NOTE : If you just want to write changes without quitting, you can use just `:w`).
Now that you have written a converter, you need to test it! To do this, you can follow either the
`Knots GTest` or the `Knots Main` instructions below.

#### Knots GTest

To add a test, you will need to modify the file `gtest/knot_tests.cpp`:

```bash
vim gtest/knot_tests.cpp

# Or Neovim
nvim gtest/knot_tests.cpp
```

The file should already contain the following:

```cpp
// ------------------------- Tests File - knot_test.cpp --------------------- //
// This file is for writing your own user tests. Be sure to include your *.h
// files to be able to access the functions that you wrote for unit testing.
// An example has been provided, but more documentation is available here:
// https://github.com/google/googletest/blob/main/docs/primer.md
// -------------------------------------------------------------------------- //

// Include all of your *.h files you want to unit test:
#include "convert_knots.h"

#include <gtest/gtest.h>
#include <cmath>

namespace {

/// Test the equality of two doubles within the precision of 0.01 (or two decimal places)
bool compare_eq(double v1, double v2) {
  return std::abs(v1 - v2) < std::pow(10, -2);
}

TEST(ConvertKnots, Two) {
  EXPECT_TRUE(compare_eq(0.0383593, knots_to_miles_per_minute(2)));
}

// ADD YOUR TESTS HERE:


} // anonymous namespace
```

As you can see in the file, it contains your `conver_knots.h` file you just made, and has
a test for comparing the output of the `knots_to_miles_per_minute` for input `2` with the
output `0.0383593`. If the conversion has been written correctly, that test should succeed,
but just to be sure, lets add another test. This time, we want to test that our output for
`3` is correct. We will add our test just below where it says `// ADD YOUR TEST HERE:`:

```cpp
TEST(ConvertKnots, Three) {
  EXPECT_TRUE(compare_eq(0.057539, knots_to_miles_per_minute(3)));
}
```

This will add a test to the `ConvertKnots` set named `Three` and test that the values of
your function and the number provided are equal. You can either jump to
[Build Instructions](#build-instructions) to test this, or you can continue on to writing
the `stack.h`.

#### Knots Main

If you are not using `GTest`, you can instead write your own tests using the `main.cpp` file
we created above. You will need to modify the file, so first lets open the file with your
preferred text editor:

```bash
nvim src/main.cpp
```

Now, we will need to `include` the file we just made (`convert_knots.h`). To do this,
we will add a new `include` instruction under the one already in our `main.cpp`:

```cpp
#include <iostream>

// Added convert_knots.h here:
#include "convert_knots.h"
```

Next, we will want to try out converter on some values and print them out to make sure they
make sense. We will do this by calling our function in the main, and printing the output
to `cout`:

```cpp
int main() {
  cout << "Hello World" << endl;

  // Add your tests:
  cout << "Knots(2) = " << knots_to_miles_per_minute(2) << endl;

  return 0;
}
```

This will call the function `knots_to_miles_per_minute` with the value `2`, and then
print that value as shown in the format above. The output (after building and running)
should look something like this:

```bash
Hello World
Knots(2) = 0.0383593
```

It is OK if the output is not that exact number, so long as it is accurate within 2
decimal places.

### Stack

Once we have finished writing and testing `convert_knots.h`, we will make our `stack`! You will need
to modify or create the file `src/stack.h`. Your implemention of a stack will hold up to 1000 characters,
using an array of 1000 `char`. Use the member functions given in the class definition below
(a constructor, push, pop, top, isEmpty, isFull, and destructor which does nothing for this assignment):

```cpp
#define STACK_CAPACITY 1000
class Stack {
public:
  Stack();            // Constructor for a Stack
  void push(char c);  // Adds c to the top of the Stack
  char pop();         // Removes top element, returns it
  char top();         // Returns top element without removing it
  bool isEmpty();     // Returns true iff the Stack is empty
  bool isFull();      // Returns true iff the Stack is full
  ~Stack() {}         // Destructor for the Stack, this is done as it does nothing
};
```

Above is a class definition listing those functions. By replacing the semicolons in the class definition
with the body of each of these methods, you will convert the class declaration to a class definition.

```cpp
// Example:
void push(char c);

// Would become:
void push(char c) {
  // Do something here...
}
```

Be sure to do reasonable error checking. `push()` must only add the character to the stack if the stack
is not full. `pop()` and `top()` will only return the top character if the stack is not empty. `top()` or `pop()`
on an empty stack should return `@` the at sign character. You can also print an error messages, but these
will be ignored by the autograder and you do not need to print an error messages.

To ensure that your `Stack` works as you expect it to, you can add tests for it using either `GTest`
with the `gtest/stack_tests.cpp` file or your `main.cpp` file exactly the same way as you did with
[Convert Knots](#convert-knots). For examples of how to test your `Stack`, refer to the tests already
in `gtest/stack_tests.cpp`. Once you have sufficiently added tests for your `Stack`, move on to the
[Build Instructions](#build-instructions)!

## Build Instructions

If you are not already in a terminal (or ssh with OpenLab) from the above instructions, you will need
to open a terminal and move into your project folder as show below:

```bash
cd <YourProjectPath>    # So if we had the project in a folder named Projects: cd Projects/CS45C-Template
```

This time, we are going to go into a little more detail on how `CMake` works. The `CMake` process is
basically comprised of two steps: producing project build files and actually building the project.
To produce the build files for our project we run the first command:

```bash
# Build Generator Command
cmake -B build        # Create a folder named `build` and run `CMake` to produce build files there
```

This command needs to be run at least once. Once it has been run, you will not need to run it again
unless you add new files that were not previously added to the project (or if you change the 
`CMakeLists.txt` file). If you add files or change `CMakeLists.txt`, then you can simply re-run
the command above and it will update the `build` files that it produced before. Once you have the
`build` folder and files, you will want to build the actual program. This can be done two ways.
You can either build everything at once:

```bash
# Target Build Command
cmake --build build   # Will build all of the `targets` described in the `CMake` file
```

Or you can pick a specific target to build. For this homework, there are 3 possible `targets`:
`hw` (which is the `main.cpp` file you created above), `knot_gtest` (`knot_tests.cpp`), and
`stack_gtest` (`stack_tests.cpp`). These `targets` are defined in the `CMakeLists.txt` file
as `project(<name>)`, so if you want to find the `targets` yourself, you can always check that
file. We will also always give you the available `targets` in this class. Below are the individual
`target` commands you can run:

```bash
# Build only main.cpp:
cmake --build build --target hw

# Build only Knot tests:
cmake --build build --target knot_gtest

# Build only Stack tests:
cmake --build build --target stack_gtest
```

NOTE: If you build all targets with the `cmake --build build` command, you DO NOT need to
run the individual commands. The advantage of running the individual build commands is
being able to build only the parts you want to test. Also, unlike the Build Generator 
Command (`cmake -B build`), you will need to run the Target Build Command 
(`cmake --build build <--target target>`) every time you make changes to your `*.cpp` or `*.h`
files. For example, if you build `knot_tests.cpp`, and find out that your conversion does
not work for numbers above `10`, you will need to change `convert_knots.h`. Once you have
changed it, when you want to test it again, you can run:

```bash
cmake --build build --target knot_gtest
```

And it will build just that code with your updated changes! Very handy for testing one task
at a time.

After you have built your intended target, you will have three new executables you can run!
You will have `hw` which will be the code from `main.cpp`, `knot_gtest`, and `stack_gtest`.
You can run each one with the commands shown below:

```bash
./build/hw            # Runs the `main` function from src/main.cpp
./build/knot_gtest    # Runs the 'knot' gtest set of tests
./build/stack_gtest   # Runs the `Stack` gtests
```

Once you have run the code above and it either produces the output you expected or passes
all provided tests, congratulations! You are now ready to [submit](#submission) your homework!

## Submission

All submissions will be done through [Gradescope](https://www.gradescope.com/). Open the Gradescope page
and select `HW1`. Now if you are using a `GitHub` account, follow the [GitHub Submission](#github-submission)
instructions, otherwise follow the [File Submission](#file-submission) instructions.

### GitHub Submission

First, we need to make sure that we commit all of our changes we made! In a terminal inside your project folder,
run the following command:

```bash
git commit -a -m "Submission commit of HW1."
```

Now that we have committed out changes, we need to push them to `GitHub` so that `Gradescope` can see them.

```bash
git push
```

Now on Gradescope, press the submit button, choose the `GitHub` option, and select your project and branch
as shown below:

![](docs/submit_github.png)

Now the autograder will run and give you a score!

### File Submission

On `Gradescope`, press the `submit` button and it will bring up the following window:

![](docs/submit_files.png)

Then you will drag and drop the `main.cpp`, `convert_knots.h`, and `stack.h` files from your `src` folder
(or wherever you have made this file) and press upload. As these are the only files we are changing, they
should be the only files that you upload!
