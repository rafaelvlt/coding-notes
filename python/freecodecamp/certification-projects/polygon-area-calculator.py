class Rectangle:
    def __init__(self, width, height) -> None:
        self._width = width
        self._height = height

    def __str__(self):
        return f"Rectangle(width={self._width}, height={self._height})"

    def set_width(self, new_width) -> None:
        self._width = new_width

    def set_height(self, new_height) -> None:
        self._height = new_height

    def get_perimeter(self):
        return 2 * (self._width + self._height)

    def get_area(self):
        return self._width * self._height

    def get_diagonal(self):
        return (self._width ** 2 + self._height ** 2) ** 0.5

    def get_picture(self):
        if self._width > 50 or self._height > 50:
            return "Too big for picture."

        final_str = ""
        for _ in range(0, self._height):
            final_str += '*' * self._width + '\n'
        return final_str
    
    def get_amount_inside(self, another_shape):
        return self.get_area() // another_shape.get_area()

class Square(Rectangle):
    def __init__(self, side):
        self._width = side
        self._height = side

    def __str__(self):
        return f"Square(side={self._width})"

    def set_width(self, new_width) -> None:
        self._width = new_width
        self._height = new_width

    def set_height(self, new_height) -> None:
        self._width = new_height
        self._height = new_height

    def set_side(self, new_side) -> None:
        self._width = new_side
        self._height = new_side
