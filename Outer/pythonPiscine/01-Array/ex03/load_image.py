import numpy as np
import matplotlib.pyplot as plt
import sys


def ft_load(path: str) -> np.array:
    """ft_load(path)

    Args:
        path (str): path to image

    Returns:
        np.array: array of image
    """
    try:
        if type(path) is not str:
            raise TypeError("path is not a string")
        if path.split(".")[-1] not in ["jpg", "jpeg"]:
            raise Exception("path is not a valid image")
        if plt.imread(path) is None:
            raise Exception("path is not a valid image")
        print("The shape of image is:", np.array(plt.imread(path)).shape)
        return np.array(plt.imread(path))
    except Exception as e:
        print("Error:", e, file=sys.stderr)
        return None


def main():
    """main()"""
    print("Test 1: Normal case")
    print(ft_load("landscape.jpg"))
    print()
    print("Test 2: Not a string case")
    print(ft_load(1))
    print()
    print("Test 3: Not a valid image case")
    print(ft_load("landscape.png"))
    print()
    print("Test 4: Not a valid image case")
    print(ft_load("test.jpg"))
    print()


if __name__ == "__main__":
    main()
