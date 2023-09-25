def is_rectangle_2D_array(array: list) -> bool:
    """is_rectangle_2D_array(array)

    Args:
        array (list): array to check

    Returns:
        bool: True if array is a rectangle 2D array, False otherwise
    """
    if type(array) is not list:
        return False
    if len(array) == 0:
        return False
    width = len(array[0])
    for row in array:
        if type(row) is not list:
            return False
        if len(row) != width:
            return False
    return True


def print_shape(array: list) -> None:
    """print_shape(array)

    Args:
        array (list): array to print shape
    """
    width = len(array[0])
    height = len(array)
    print(f"({height}, {width})")


def slice_me(family: list, start: int, end: int) -> list:
    """slice_me(family, start, end)

    Args:
        family (list): original list
        start (int): index to start slicing
        end (int): index to end slicing

    Returns:
        list: sliced list
    """
    if type(family) is not list or not is_rectangle_2D_array(family):
        return None
    if abs(start) > len(family) or abs(end) > len(family):
        return None
    calculated_start = len(family) + start if start < 0 else start
    calculated_end = len(family) + end if end < 0 else end
    if calculated_start > calculated_end:
        return None
    print("My shape is : ", end="")
    print_shape(family)
    print("My new shape is : ", end="")
    print_shape(family[calculated_start:calculated_end])
    return family[calculated_start:calculated_end]


def main():
    """main function"""
    family = [[1.80, 78.4], [2.15, 102.7], [2.10, 98.5], [1.88, 75.2]]
    print("Normal case: ", family)
    print(slice_me(family, 0, 2))
    print(slice_me(family, 1, -2))
    print()

    family = [[1.80, 78.4], [2.15, 102.7, 1], [2.10, 98.5], [1.88, 75.2]]
    print("Not rectangle case: ", family)
    print(slice_me(family, 0, 2))
    print(slice_me(family, 1, -2))
    print()

    family = [[1.80, 78.4], [2.15, 102.7], [2.10, 98.5], 1]
    print("Not rectangle case: ", family)
    print(slice_me(family, 0, 2))
    print(slice_me(family, 1, -2))
    print()

    family = [[1.80, 78.4], [2.15, 102.7], [2.10, 98.5], [1.88, 75.2]]
    print("Out of range case: ", family)
    print(slice_me(family, 0, 10))
    print(slice_me(family, 1, -10))
    print()

    print("Not list case: ", 1, "test test test")
    print(slice_me(1, 0, 2))
    print(slice_me("test test test", 1, -2))
    print()

    family = [[1.80, 78.4], [2.15, 102.7], [2.10, 98.5], [1.88, 75.2]]
    print("End < start case: ", family)
    print(slice_me(family, 2, 1))
    print(slice_me(family, -2, -3))


if __name__ == "__main__":
    main()
