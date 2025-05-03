# For c++/clangd/vscode user
Since Leetcode uses the standard library implementation of g++ 14, you need to disable default Clang's include paths and add the include paths of g++- 14 instead.
To achieve this easily, you can use just `clangdw`, a Clangd wrapper that automatically generates `compile_flags.txt` file for you.

**Note g++-14 must be installed on your system to use this tool.**
If you want to customize `compile_flags.txt`, you can just edit this file manually once it is generated.
