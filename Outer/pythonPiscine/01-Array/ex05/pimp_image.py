import numpy as np
import matplotlib.pyplot as plt


def ft_invert(array) -> np.array:
    """Invert using - method"""
    inverted_array = [255, 255, 255] - array
    plt.imshow(inverted_array)
    plt.title("Inverted")
    plt.axis("off")
    plt.show()
    return inverted_array


def ft_red(array) -> np.array:
    """Red using *"""
    red_mask = np.array([1, 0, 0])
    red_array = array * red_mask
    plt.imshow(red_array)
    plt.title("Red")
    plt.axis("off")
    plt.show()
    return red_array


def ft_green(array) -> np.array:
    """Green using ="""
    green_array = np.zeros_like(array)  # create empty array
    green_array[:, :, 1] = array[:, :, 1]
    # [height(rows), width(columns), color channels] Red 0, Green 1, Blue 2
    plt.imshow(green_array)
    plt.title("Green")
    plt.axis("off")
    plt.show()
    return green_array


def ft_blue(array) -> np.array:
    """Blue using ="""
    blue_array = np.zeros_like(array)  # create empty array
    blue_array[:, :, 2] = array[:, :, 2]
    # [height(rows), width(columns), color channels] Red 0, Green 1, Blue 2
    plt.imshow(blue_array)
    plt.title("Blue")
    plt.axis("off")
    plt.show()
    return blue_array


def ft_grey(array) -> np.array:
    """Grey using =, /"""
    grey_intensity_array = np.mean(array, axis=2, dtype="i")
    # axis2=color channel | data type is 32-bit signed integer
    grey_array = np.zeros_like(array)
    # assigning grey intensity to Red channel
    grey_array[:, :, 0] = grey_intensity_array
    grey_array[:, :, 1] = grey_intensity_array
    grey_array[:, :, 2] = grey_intensity_array
    # or
    # grey_intensity_array = grey_intensity_array.reshape(
    #         grey_intensity_array.shape[0], grey_intensity_array.shape[1], 1)
    # grey_array[:, :, :] = grey_intensity_array

    plt.imshow(grey_array)
    plt.title("grey")
    plt.axis("off")
    plt.show()
    return grey_array


if __name__ == "__main__":
    array = plt.imread("animal.jpeg")
    ft_invert(array)
    ft_red(array)
    ft_green(array)
    ft_blue(array)
    ft_grey(array)
    print(ft_invert.__doc__)
