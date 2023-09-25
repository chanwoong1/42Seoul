def ft_tqdm(lst: range) -> None:
    """ft_tqdm(lst)

    Args:
        lst (range): range of numbers

    Yields:
        item: item of the range
    """
    t = len(lst)
    w = 40
    for i, item in enumerate(lst, 1):
        p = int(w * i / t)
        print(
            f"\r{round(i/t*100)}%|{'█' * p}{' ' * (w - p)}| {i}/{t}",
            end="",
        )
        yield item


def main():
    """main() -> None"""
    for _ in ft_tqdm(range(3333)):
        pass
    print()


if __name__ == "__main__":
    main()
