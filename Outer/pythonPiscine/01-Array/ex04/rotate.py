from load_image import ft_load
from matplotlib import pyplot as plt
import numpy as np


# def rotate():
#     loaded_image = ft_load("animal.jpeg")
#     if loaded_image is not None:
#         height, width = loaded_image.shape[:2]
#         x = width // 2
#         y = height // 2
#         cropped = loaded_image[
#             y - 200 : y + 200,
#             x - 200 : x + 200,
#         ]
#         rotated_image = np.rot90(cropped)
#         print(rotated_image.shape)
#         print(rotated_image)
#         plt.imshow(
#             rotated_image, cmap="gray" if len(rotated_image.shape) == 2 else None
#         )
#         plt.show()
#     else:
#         print("Error loading image")


def main():
    """main()"""
    loaded_image = ft_load("animal.jpeg")


if __name__ == "__main__":
    main()
