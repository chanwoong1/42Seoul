def count_in_list(lst, element):
    """Returns the count of an element in the given list.

    Args:
        lst (list): List of elements.
        element (Any): Element to count.

    Returns:
        int: Number of occurrences of the element in the list.
    """
    return lst.count(element)


if __name__ == "__main__":
    # Test the function
    print(count_in_list(["toto", "tata", "toto"], "toto"))  # output: 2
    print(count_in_list(["toto", "tata", "toto"], "tutu"))  # output: 0
