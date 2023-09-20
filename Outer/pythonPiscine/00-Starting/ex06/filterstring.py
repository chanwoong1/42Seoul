from ft_filter import ft_filter
import sys


def filterstring(S, N):
    """filterstring(S, N)

    Args:
        S (string): text to filter
        N (int): number of characters to filter

    Returns:
        list: list of words with more than N characters
    """
    return [word for word in ft_filter(lambda x: len(x) > N, S.split())]


def validate_string(S) -> bool:
    """validate_string(S)

    Args:
        S (string): text to validate

    Returns:
        bool: True or False
    """
    return True if sum(
        [1 for c in S if c in [".", ",", ":", ";", "!", "?", "-", "'", '"']]
            ) == 0 else False


def main():
    """
    Main function about Exercice 06
    """
    args = sys.argv[1:]
    if len(args) != 2:
        print("AssertionError: the arguments are bad", file=sys.stderr)
        return 1
    if not args[1].isdigit():
        print("AssertionError: the arguments are bad", file=sys.stderr)
        return 1
    if not validate_string(args[0]):
        print("AssertionError: the arguments are bad", file=sys.stderr)
        return 1
    print(filterstring(args[0], int(args[1])))
    return 0


if __name__ == "__main__":
    # print(filter.__doc__)
    # print(ft_filter.__doc__)
    main()
