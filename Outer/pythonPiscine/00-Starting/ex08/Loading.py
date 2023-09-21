def ft_tqdm(lst: range) -> None:
    """ft_tqdm(lst)

    Args:
        lst (range): range of numbers

    Yields:
        item: item of the range
    """
    total = len(lst)
    width = 40
    for i, item in enumerate(lst, 1):
        progress = int(width * i / total)
        print(
            f"\r{round(i/total*100)}%|{'█' * progress}{' ' * (width - progress)}| {i}/{total}",
            end="",
        )
        yield item
