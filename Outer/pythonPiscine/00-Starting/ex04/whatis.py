import sys


def is_digit(object: str):
    if object.isdigit():
        return True
    if object[0] == "-" and object[1:].isdigit():
        return True
    return False


def main():
    args = sys.argv[1:]
    if len(args) == 0:
        return 1
    if len(args) > 1:
        print("AssertionError: more than one argument is provided")
        return 1
    object = args[0]
    if is_digit(object) is False:
        print("AssertionError: argument is not an integer")
        return 1
    print("I'm Even.") if int(object) % 2 == 0 else print("I'm Odd.")
    return 0


if __name__ == "__main__":
    main()
