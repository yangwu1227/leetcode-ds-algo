# Data Structure and Algorithm

A collection of solutions to LeetCode problems, loosely grouped by concepts, techniques, and data structures.

## Python 

The Python dependencies are managed using [uv](https://docs.astral.sh/uv/):

```bash
$ uv sync --frozen --all-groups
```

## C++

### Platform

The C++ setup supports both ARM64 architecture on MacOS and x86_64 on Debian Linux. Platform-specific configurations are managed through VS Code [workspace](https://code.visualstudio.com/docs/editor/workspaces#_workspace-tasks-and-launch-configurations) settings:

- **MacOS ARM64**: Uses the default `.vscode` configuration

- **Debian GNU/Linux 12 (Bookworm)**: Replace the default files with those in the `.vscode_debian` configuration

### Tools and Dependencies
 
- **Compiler**: The code is compiled using `g++` with support for C++17 standard features.

- **Debugger**: 

  - MacOS: [lldb](https://lldb.llvm.org/) with [CodeLLDB](https://marketplace.visualstudio.com/items?itemName=vadimcn.vscode-lldb) VSCode extension

  - Debian: [gdb](https://sourceware.org/gdb/) with native VSCode debugging support

- **Build Configuration**: The build system is set up using the `tasks.json` and `launch.json` files in the respective `.vscode` directories. Additionally, each solution has a corresponding `Makefile` for compiling the code without debugging if preferred. Ensure that the include paths in the `Makefile` are updated to match the system configuration.

- **IntelliSense**: The [c_cpp_properties.json](https://code.visualstudio.com/docs/cpp/c-cpp-properties-schema-reference) file is used to configure include paths and other settings for IntelliSense in Visual Studio Code.

### External Libraries

Some C++ solutions utilize both the [Boost](https://www.boost.org/) and [Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page) libraries. The include paths are platform-specific:

#### MacOS

For consistency and flexibility across different build systems, the include paths `-I/opt/homebrew/include` and `-I/opt/homebrew/include/eigen3` are specified in the build configurations. This ensures compatibility across both the vs code setup (using `tasks.json`) and `Makefile` builds, automatically incorporating updates to library versions installed via [homebrew](https://brew.sh/).

```bash
$ brew install boost eigen
```

##### Verifying Symlinked Paths

To confirm that the symlinked paths:

```bash
$ ls -l /opt/homebrew/include/boost
# lrwxr-xr-x  1 user  admin  38 Nov  5 01:20 /opt/homebrew/include/boost -> ../Cellar/boost/1.86.0_2/include/boost

$ ls -l /opt/homebrew/include/eigen3
# lrwxr-xr-x  1 user  admin  38 Jul 19 00:24 /opt/homebrew/include/eigen3 -> ../Cellar/eigen/3.4.0_1/include/eigen3
```

#### Debian GNU/Linux 12 (Bookworm)

The include paths are set to `-I/usr/include` and `-I/usr/include/eigen3` in the `.vscode_debian/c_cpp_properties.json` file. 

```bash
$ sudo apt-get install libboost-all-dev libeigen3-dev
```

##### Verifying Installed Paths

```bash
$ ls -l /usr/include/boost
$ readlink -f /usr/include/boost

$ ls -l /usr/include/eigen3
$ readlink -f /usr/include/eigen3
```
