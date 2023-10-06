from load_image import ft_load
import numpy as np
from matplotlib import pyplot as plt


def plotting(imgarr: np.array):
    plt.imshow(imgarr[:, :, 0:], cmap="gray")
    plt.show()


def crop(image: np.array) -> np.array:
    height, width = image.shape[:2]

    mid_h = height // 2
    mid_w = width // 2

    offset_x = 150
    offset_y = -220

    left = mid_w - 200 + offset_x
    right = mid_w + 200 + offset_x
    top = mid_h - 200 + offset_y
    bottom = mid_h + 200 + offset_y

    crop_img = image[top:bottom, left:right, :3]
    res = np.mean(crop_img, axis=2, keepdims=True).astype(np.uint8)
    print(f"The shape of the image is: {res.shape}")
    print(res)
    return res


def transpose(img_arr: np.array) -> np.array:
    rows, cols, channels = img_arr.shape
    tr = np.empty((cols, rows, channels), dtype=img_arr.dtype)

    for i in range(rows):
        for j in range(cols):
            tr[j][i] = img_arr[i][j]
    print(f"New shape after transpose: {tr.shape[0], tr.shape[1]}")
    print(tr[:, :, 0])
    return tr


def rotate():
    try:
        img_file = "animal.jpeg"
        err_msg = "AssertionError: Unable to rotate"
        loaded_image = ft_load(img_file)
        assert loaded_image is not None, err_msg

        crop_img = crop(loaded_image)
        tr = transpose(crop_img)
        plotting(tr)

    except AssertionError as msg:
        print(msg)


if __name__ == "__main__":
    rotate()
