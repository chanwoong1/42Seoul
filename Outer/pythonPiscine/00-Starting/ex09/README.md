```
# FT Package

## Overview

ft_package is a simple Python package that calculates the occurrence count of a specific item in a list.

## Installation

To install the package, you can build it locally and then use pip:

pip install ./dist/ft_package-0.0.1.tar.gz

Or

pip install ./dist/ft_package-0.0.1-py3-none-any.whl

## Usage

Here's how to use the package:

from ft_package import count_in_list

# Calculate the occurrence of 'toto' in the list
print(count_in_list(["toto", "tata", "toto"], "toto"))  # Output: 2

# Calculate the occurrence of 'tutu' in the list (returns 0 since it doesn't exist)
print(count_in_list(["toto", "tata", "toto"], "tutu"))  # Output: 0

## License

This package is distributed under the MIT license. For more details, please refer to the LICENSE file.

## Contact

- Author: chanwjeo
- Email: chanwjeo@student.42seoul.kr
- GitHub: https://github.com/chanwoong1
```
