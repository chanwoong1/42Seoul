# from ft_filter import filter
import sys


def main():
    """
    Main function about Exercice 06
    """

    args = sys.argv[1:]
    if len(args) != 2:
        print("AssertionError: the arguments are bad")
        return 1
    if not args[1].isdigit():
        print("AssertionError: the arguments are bad")
        return 1
    print(filter.__doc__)


if __name__ == "__main__":
    # print(main.__doc__)
    main()
