<h1>C / C++ shared library workshop</h1>
<!-- TABLE OF CONTENTS -->
  <ol>
    <li>
      <a href="#About-shared-libraries">About shared libraries</a>
      <ul>
        <li><a href="#inner-working">Main usage</a>
        <li><a href="#compiling">Compiling your own library</a>
      </ul>
    </li>
    <li>
      <a href="#about-the-workshop">About the workshop</a>
      <ul> 
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#testing">Testing</a></li>
      </ul>
    </li>
  </ol>
      
# About shared libraries


# Main usage
Shared library are a way to store compiled functions in a non-executable file to use them with other executable file.    
Take any graphical library (_sfml_ in this example). You can link the sfml library using the `-lsfml` flag in gcc to gain access to all the provided function.

# Compiling
Compiling a shared library is really straighforward: compile your source `.c`/ `.cpp` into object file `.o` using both the `-c` and the `-fPIC` flag of gcc. Then compile all your object file into a `.so` file using the `-shared -fPIC` flags.    
You can also use the provided Makefile as long as you update the `SRC_FILES` variable.    
Here are the steps to link a library to a binary:
1. `export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./_path_your_library_` This will update the list of path that stores libraries.
2. `gcc -L./_path_to_your_so_lib_ -l_name_of_your_library_ ...` Link the library to your binary. (`-L. -llinked` for this project)

# About the workshop
This workshop will teach you about shared libraries and how helpful they can be in your C / C++ project by creating a simple library that manages linked lists !    
We will code the function in the `src` folder.    
The `linked_handler` and `linked` structures, the `Makefile` and some tests are provided.    
Refer to the #Compiling section if you want to compile your own program with the library.

# Prerequisites
Gcc and make installed.

# Testing
Simply run `make tests_run` to execute my unit tests.
