# Data Structure and Algorithm

A collection of solutions to LeetCode problems, loosely grouped by concepts, techniques, and data structures.

## Python

The Python dependencies are managed using [uv](https://docs.astral.sh/uv/):

```bash
$ uv sync --frozen --all-groups
```

## C++

#### Platform

The C++ setup supports both ARM64 architecture on MacOS and x86_64 on Debian Linux. Platform-specific configurations are managed through VS Code [workspace](https://code.visualstudio.com/docs/editor/workspaces#_workspace-tasks-and-launch-configurations) settings:

- **MacOS ARM64**: Uses the default `.vscode` configuration

- **Debian GNU/Linux 12 (Bookworm)**: Replace the default files with those in the `.vscode_debian` configuration

#### Tools and Dependencies

- **Compiler**: The code is compiled using `g++` with support for C++17 standard features.

- **Debugger**:

  - MacOS: [lldb](https://lldb.llvm.org/) with [CodeLLDB](https://marketplace.visualstudio.com/items?itemName=vadimcn.vscode-lldb) VSCode extension

  - Debian: [gdb](https://sourceware.org/gdb/) with native VSCode debugging support

- **Build Workflows**: 

  - IDE: The build workflow involves the `tasks.json` and `launch.json` files in the respective `.vscode` and `.vscode_debian` directories. 
  
  - CLI: Each solution has a corresponding `Makefile` for compiling the code without debugging. Ensure that the include path flags in the `Makefile` are updated to match the installed paths on the system if external libraries are used, e.g., Boost and Eigen.

- **IntelliSense**: The [c_cpp_properties.json](https://code.visualstudio.com/docs/cpp/c-cpp-properties-schema-reference) file is used to configure (global level) include paths and other settings for IntelliSense in Visual Studio Code.

#### External Libraries

Some C++ solutions utilize both the [Boost](https://www.boost.org/) and [Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page) libraries. The include paths flags in `task.json` are platform-specific:

#### MacOS

For consistency and flexibility across different build workflows, the include path flags `-I/opt/homebrew/include` and `-I/opt/homebrew/include/eigen3` are specified in `.vscode/tasks.json` and all `Makefile`. This ensures that the compiler’s header search path consistently resolves Boost and Eigen headers across both the IDE‑driven (`tasks.json`) and command‑line (`Makefile`) build workflows.

Note: The directories `/opt/homebrew/include` and `/opt/homebrew/include/eigen3` are Homebrew‑managed symlinks that point to the currently installed versions of Boost and Eigen, so upgrading those libraries should not require manually adjusting the include paths.

```bash
$ brew install boost eigen
```

#### Verifying Symlinked Paths

To confirm that the symlinked paths:

```bash
$ ls -l /opt/homebrew/include/boost
# lrwxr-xr-x  1 user  admin  38 Nov  5 01:20 /opt/homebrew/include/boost -> ../Cellar/boost/1.86.0_2/include/boost

$ ls -l /opt/homebrew/include/eigen3
# lrwxr-xr-x  1 user  admin  38 Jul 19 00:24 /opt/homebrew/include/eigen3 -> ../Cellar/eigen/3.4.0_1/include/eigen3
```

#### Debian GNU/Linux 12 (Bookworm)

The include paths on Linux are set to `-I/usr/include` and `-I/usr/include/eigen3` in the `.vscode_debian/tasks.json` file.

```bash
$ sudo apt-get install libboost-all-dev libeigen3-dev
```

#### Verifying Installed Paths

```bash
$ ls -l /usr/include/boost
  readlink -f /usr/include/boost

$ ls -l /usr/include/eigen3
  readlink -f /usr/include/eigen3
```
