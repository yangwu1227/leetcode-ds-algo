def is_path_crossing(path: str) -> bool:
    """
    Given a string path, where `path[i] = 'N', 'S', 'E' or 'W'`, each representing moving one unit north, south, east, or west, respectively.
    Start at the origin `(0, 0)` on a 2D plane and walk on the path specified by `path`.

    Parameters
    ----------
    path : str
        A string containing characters of either 'N', 'S', 'E' or 'W'

    Returns
    -------
    bool
        True if the path crosses itself at any point, i.e. returning to a point previously visited, False otherwise
    """
    x, y = (0, 0)
    coordinates = set()
    coordinates.add((x, y))

    # O(n)
    for direction in path:
        match direction:
            case "N":
                y += 1
            case "S":
                y -= 1
            case "E":
                x += 1
            case "W":
                x -= 1
        # Check if the point has been visited before O(1)
        if (x, y) in coordinates:
            return True
        # If not, add it to the set of coordinates O(1)
        coordinates.add((x, y))

    return False


def main() -> int:
    paths = ("NESWW", "SSWEN", "SNEWSNEW", "NES", "NNE")
    for path in paths:
        crossed = is_path_crossing(path)
        print(f"The path {path} {'crosses' if crossed else 'does not cross'} itself")

    return 0


if __name__ == "__main__":
    main()
