def count_in_list(lst, element):
    """Returns the count of an element in the given list.

    Args:
        lst (list): List of elements.
        element (Any): Element to count.

    Returns:
        int: Number of occurrences of the element in the list.
    """
    return lst.count(element)


def main():
    """main() -> None"""
    print(count_in_list(["toto", "tata", "toto"], "toto"))  # output: 2
    print(count_in_list(["toto", "tata", "toto"], "tutu"))  # output: 0


if __name__ == "__main__":
    main()
