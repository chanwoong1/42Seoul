def validate_input(lst: list[int | float]) -> bool:
    return type(lst) == list and sum(
        [1 for i in lst if type(i) == int or type(i) == float]
    ) == len(lst)


def give_bmi(height: list[int | float], weight: list[int | float]) -> list[int | float]:
    """give_bmi(height, weight)

    Args:
        height (list[int  |  float]): array of heights
        weight (list[int  |  float]): array of weights

    Returns:
        list[int | float]: array of bmi values
    """
    if len(height) != len(weight):
        return None
    if validate_input(height) is False or validate_input(weight) is False:
        return None
    return [w / (h**2) for h, w in zip(height, weight)]


def apply_limit(bmi: list[int | float], limit: int) -> list[bool]:
    """apply_limit(bmi, limit)

    Args:
        bmi (list[int | float]): array of bmi values
        limit (int): limit to apply

    Returns:
        list[bool]: array of bools
    """
    if validate_input(bmi) is False or type(limit) != int:
        return None
    return [b > limit for b in bmi]


def main():
    """main function"""
    height = [2.71, 1.15]
    weight = [165.3, 38.4]
    bmi = give_bmi(height, weight)
    print(bmi, type(bmi))
    print(apply_limit(bmi, 26))


if __name__ == "__main__":
    main()
