import matplotlib.pyplot as plt
import numpy as np
from load_image import ft_load


def zoom_image(image, zoom_size=(400, 400)):
    """zoom_image(image, zoom_size=(400, 400))

    Args:
        image (Array): original image
        zoom_size (tuple, optional): size to zoom. Defaults to (400, 400).

    Returns:
        Array: zoomed image
    """
    height, width = image.shape[:2]
    if height - zoom_size[0] < 0 or width - zoom_size[1] < 0:
        return None
    x = np.random.randint(0 + zoom_size[0] // 2, width - zoom_size[0] // 2)
    y = np.random.randint(0 + zoom_size[1] // 2, height - zoom_size[1] // 2)

    crop_size_x, crop_size_y = zoom_size[0] // 2, zoom_size[1] // 2
    cropped = image[
        y - crop_size_y : y + crop_size_y,
        x - crop_size_x : x + crop_size_x,
    ]

    return cropped


def main():
    """main()"""
    image_path = "animal.jpeg"
    loaded_image = ft_load(image_path)

    if loaded_image is not None and zoom_image(loaded_image) is not None:
        print("The shape of image is:", loaded_image.shape)
        print(loaded_image)

        zoomed_image = zoom_image(loaded_image, zoom_size=(800, 800))

        print("New shape after slicing:", zoomed_image.shape)
        print(zoomed_image)

        # Displaying the zoomed image
        plt.imshow(zoomed_image, cmap="gray" if len(zoomed_image.shape) == 2 else None)
        plt.show()


if __name__ == "__main__":
    main()
