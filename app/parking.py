class Parking(object):

    size = 0

    def __init__(self, size):
        if isinstance(size, int):
            self.size = size
        else:
            raise ValueError
