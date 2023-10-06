from load_image import ft_load
import numpy as np
from matplotlib import pyplot as plt


def crop(image: np.array) -> np.array:
    """crop(image)

    Args:
        image (np.array): Input image to be cropped.

    Returns:
        np.array: Cropped image with shape (400, 400, 1) or (400, 400).
    """
    height, width = image.shape[:2]
    x = width // 2 + 150
    y = height // 2 - 50

    cropped = image[y - 200 : y + 200, x - 200 : x + 200, :3]
    res = np.mean(cropped, axis=2, keepdims=True).astype(np.uint8)
    print(f"The shape of the image is: {res.shape}")
    print(res)
    return res


def transpose(image: np.array) -> np.array:
    """transpose(image)

    Args:
        image (np.array): Input image to be transposed.

    Returns:
        np.array: Transposed image.
    """
    cols, rows, channels = image.shape
    tr = np.empty((rows, cols, channels), dtype=image.dtype)

    for i in range(cols):
        for j in range(rows):
            tr[j][i] = image[i][j]
    print(f"New shape after transpose: {tr.shape[0], tr.shape[1]}")
    print(tr[:, :, 0])
    return tr


def main():
    """main()

    Main function to execute the image processing pipeline.
    Loads the image, crops, transposes, and displays it.
    """
    try:
        img_file = "animal.jpeg"
        err_msg = "AssertionError: Unable to rotate"
        loaded_image = ft_load(img_file)
        if loaded_image is None:
            raise AssertionError(err_msg)

        crop_img = crop(loaded_image)
        tr = transpose(crop_img)
        plt.imshow(tr[:, :, 0:], cmap="gray")
        plt.show()

    except AssertionError as msg:
        print(msg)


if __name__ == "__main__":
    main()
