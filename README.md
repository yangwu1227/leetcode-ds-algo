# Data Structure and Algorithm

A collection of solutions to LeetCode problems, loosely grouped by concepts, techniques, and data structures.

## Python 

The Python dependencies are managed using [pdm](https://pdm-project.org/latest/) and [conda](https://conda.io/projects/conda/en/latest/user-guide/install/index.html):

```bash
# Search for python version
$ conda search python
# The specified python version in `pyproject.toml` is requires-python = ">=3.11"
$ yes | conda create --name leetcode_ds_algo python=3.11.9
$ conda activate leetcode_ds_algo
# Use the conda-installed python interpreter
$ pdm use $(which python3)
$ pdm install --prod
```

Using `conda` is not necessary, and any other tools, e.g., [pyenv](https://github.com/pyenv/pyenv), can be used to specify the Python interpreter to use for the project.

## C++

### Platform

The C++ setup is tailored for the ARM64 architecture on macOS. It can be adapted for other target platforms with adjustments to the build configurations and library paths.

### Tools and Dependencies
 
- **Compiler**: The code is compiled using `g++` with support for C++17 standard features.

- **Debugger**: The debugger used is [lldb](https://lldb.llvm.org/) with the [CodeLLDB](https://marketplace.visualstudio.com/items?itemName=vadimcn.vscode-lldb) extension in Visual Studio Code.

- **Build System**: The build system is set up using the `tasks.json` and `launch.json` files in the `.vscode` directory. Additionally, each solution has a corresponding `Makefile` for compiling the code without debugging if preferred.

- **IntelliSense**: The [c_cpp_properties.json](https://code.visualstudio.com/docs/cpp/c-cpp-properties-schema-reference) file is used to configure include paths and other settings for IntelliSense in Visual Studio Code.

### External Libraries

Some C++ solutions utilize both the [Boost](https://www.boost.org/) and [Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page) libraries. For consistency and flexibility across different build systems, the include paths `-I/opt/homebrew/include` and `-I/opt/homebrew/include/eigen3` are specified in the build configurations. This ensures compatibility across both the vs code setup (using `tasks.json`) and `Makefile` builds, automatically incorporating updates to library versions installed via [homebrew](https://brew.sh/).

#### Verifying Symlinked Paths

To confirm that the symlinked paths:

```bash
ls -l /opt/homebrew/include/boost
# lrwxr-xr-x  1 user  admin  38 Nov  5 01:20 /opt/homebrew/include/boost -> ../Cellar/boost/1.86.0_2/include/boost

ls -l /opt/homebrew/include/eigen3
# lrwxr-xr-x  1 user  admin  38 Jul 19 00:24 /opt/homebrew/include/eigen3 -> ../Cellar/eigen/3.4.0_1/include/eigen3
```
