import os
from typing import Callable, List, Tuple

import matplotlib.pyplot as plt
import numpy as np


def generate_n_values(max_n: int) -> np.ndarray:
    """
    Generate an array of values from 0 to max_n.

    Parameters
    ----------
    max_n : int
        The maximum value for n

    Returns
    -------
    np.ndarray
        An array of values from 0 to `max_n`
    """
    return np.arange(1, max_n + 1)  # Start from 1 to avoid log(0) issues


def plot_functions(
    n_values: np.ndarray,
    functions: List[Tuple[str, Callable[[np.ndarray], np.ndarray]]],
    title: str,
    filename: str,
) -> None:
    """
    Plot the given functions over the range of n_values and save as a PNG file.

    Parameters
    ----------
    n_values : np.ndarray
        Array of n values
    functions : List[Tuple[str, Callable[[np.ndarray], np.ndarray]]]
        List of tuples containing function names and the corresponding functions to plot
    title : str
        The title of the plot
    filename : str
        The filename for saving the plot
    """
    plt.figure(figsize=(10, 6))

    for name, func in functions:
        plt.plot(n_values, func(n_values), label=name)

    plt.xlabel("n")
    plt.ylabel("f(n)")
    plt.title(title)
    plt.legend()
    plt.grid(True)
    plt.yscale("log")

    # Create the diagrams directory if it doesn't exist
    script_dir = os.path.dirname(__file__)
    os.makedirs(f"{script_dir}/diagrams", exist_ok=True)
    plt.savefig(f"{script_dir}/diagrams/{filename}.png")


def main() -> int:
    n_values = generate_n_values(10**4)

    # First set of functions
    functions_set1 = [
        ("n^3", lambda n: n**3),
        ("n^0.3", lambda n: n**0.3),
        ("n", lambda n: n),
        ("sqrt(n)", lambda n: np.sqrt(n)),
        ("n^2 / sqrt(n)", lambda n: n**2 / np.sqrt(n)),
        ("n^2", lambda n: n**2),
    ]

    # Second set of functions
    functions_set2 = [
        ("n log2(n)", lambda n: n * np.log2(n)),
        ("log4(n)", lambda n: np.log(n) / np.log(4)),
        ("n", lambda n: n),
        ("5^(log2(n))", lambda n: 5 ** (np.log2(n))),
        ("n^2", lambda n: n**2),
        ("sqrt(n)", lambda n: np.sqrt(n)),
        ("3^n", lambda n: 3**n),
        ("2^(2n)", lambda n: 2 ** (2 * n)),
    ]

    plot_functions(n_values, functions_set1, "Plot of First Set of Functions", "functions_set_1")
    # Use smaller ranges due to floating point arithmetic
    plot_functions(
        n_values[5:20],
        functions_set2,
        "Plot of Second Set of Functions",
        "functions_set_2",
    )

    return 0


if __name__ == "__main__":
    main()
