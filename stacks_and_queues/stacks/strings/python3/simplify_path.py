from typing import List


def simplify_path(path: str) -> str:
    """
    Given an absolute path for a Unix-style file system, which begins with a slash '/', transform
    this path into its simplified canonical path.

    Parameters
    ----------
    path : str
        A valid absolute Unix path

    Returns
    -------
    str
        The simplified canonical path
    """
    if len(path) == 1:
        return "/"

    split_paths = path.split("/")
    paths_stack: List[str] = []
    for split_path in split_paths:
        # If current directory, do nothing
        if split_path == ".":
            continue
        # If ".." and the stack is not empty, simulate moving one directory level up by popping the top of the stack
        elif paths_stack and split_path == "..":
            paths_stack.pop(-1)
        # If no an empty "" string and not "..", push to the top of the stack
        elif split_path and split_path != "..":
            paths_stack.append(split_path)

    return "/" + "/".join(paths_stack)


def main() -> int:
    test_paths = [
        "/.../a/../b/c/../d/./",
        "/home/",
        "/home//foo/",
        "/home/user/Documents/../Pictures",
        "/.../a/../b/c/../d/./",
        "/../",
        "/",
    ]

    for path in test_paths:
        simplified_path = simplify_path(path)
        print("Original path:")
        print(path)
        print("Simplified path:")
        print(simplified_path)
        print("\n")

    return 0


if __name__ == "__main__":
    main()
