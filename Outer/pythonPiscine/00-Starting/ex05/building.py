import sys


def print_length_of_text(text: str):
    """
    Prints the length of the text.
    """
    print(f"The text contains {len(text)} characters:")


def print_number_of_uppercase(text: str):
    """
    Prints the number of uppercase characters in the text.
    """
    print(f"{sum(1 for c in text if c.isupper())} upper letters")


def print_number_of_lowercase(text: str):
    """
    Prints the number of lowercase characters in the text.
    """
    print(f"{sum(1 for c in text if c.islower())} lower letters")


def print_number_of_punctuation(text: str):
    """
    Prints the number of punctuation characters in the text.
    """
    number_of_punctuation = sum(
        [1 for c in text if c in [".", ",", ":", ";", "!", "?", "-", "'", '"']]
    )
    print(f"{number_of_punctuation} punctuation marks")


def print_number_of_spaces(text: str):
    """
    Prints the number of spaces in the text.
    """
    print(f"{sum(1 for c in text if c.isspace())} spaces")


def print_number_of_digits(text: str):
    """
    Prints the number of digits in the text.
    """
    print(f"{sum(1 for c in text if c.isdigit())} digits")


def main():
    """
    The main function.
    """
    args = sys.argv[1:]
    if len(args) > 1:
        print("AssertionError: more than one argument is provided")
        return 1
    if len(args) == 0:
        final_text = ""
        text = ""
        while True:
            final_text = text
            text = sys.stdin.readline()
            if text == "":
                break
        object = final_text
    else:
        object = args[0]
    print_length_of_text(object)
    print_number_of_uppercase(object)
    print_number_of_lowercase(object)
    print_number_of_punctuation(object)
    print_number_of_spaces(object)
    print_number_of_digits(object)


if __name__ == "__main__":
    main()
