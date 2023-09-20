import sys


NEST_MORSE = {
    " ": "/",
    "A": ".-",
    "B": "-...",
    "C": "-.-.",
    "D": "-..",
    "E": ".",
    "F": "..-.",
    "G": "--.",
    "H": "....",
    "I": "..",
    "J": ".---",
    "K": "-.-",
    "L": ".-..",
    "M": "--",
    "N": "-.",
    "O": "---",
    "P": ".--.",
    "Q": "--.-",
    "R": ".-.",
    "S": "...",
    "T": "-",
    "U": "..-",
    "V": "...-",
    "W": ".--",
    "X": "-..-",
    "Y": "-.--",
    "Z": "--..",
    "0": "-----",
    "1": ".----",
    "2": "..---",
    "3": "...--",
    "4": "....-",
    "5": ".....",
    "6": "-....",
    "7": "--...",
    "8": "---..",
    "9": "----."
}


def validate_args(args) -> bool:
    """validate_args(args)

    Args:
        args (string): the string to validate

    Returns:
        bool: True or False
    """
    return True if sum(
        [1 for c in args if c.isalnum() or c == " "]) == len(args) else False


def sos(args) -> str:
    """sos(args)

    Args:
        args (string): the string to convert

    Returns:
        str: the string converted to morse
    """
    return " ".join(
        [NEST_MORSE[c.upper()] for c in args if c.isalpha() or c in NEST_MORSE]
            )


def main():
    """main function

    Returns:
        int: 0 if success, 1 if error
    """
    args = sys.argv[1:]
    if len(args) != 1:
        print("AssertionError: the arguments are bad", file=sys.stderr)
        return 1
    if validate_args(args[0]) is False:
        print("AssertionError: the arguments are bad", file=sys.stderr)
        return 1
    print(sos(args[0]))


if __name__ == "__main__":
    main()
