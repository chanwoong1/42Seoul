from .count_in_list import count_in_list


if __name__ == "__main__":
    # Test the function
    print(count_in_list(["toto", "tata", "toto"], "toto"))  # output: 2
    print(count_in_list(["toto", "tata", "toto"], "tutu"))  # output: 0
