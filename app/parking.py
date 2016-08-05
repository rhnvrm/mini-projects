from app.car import Car

class Parking(object):

    size = 0
    lot = []

    def __init__(self, size):
        if isinstance(size, int):
            self.size = size
            self.lot = [None] * size 
        else:
            raise ValueError

    def currentCarCount(self):
        count = 0
        for i in self.lot:
            if i: count+=1
        return count

    def newCar(self, reg_no, color):
        car = Car(reg_no, color)
        try:
            slot = self.lot.index(None)
            self.lot[slot] = car
            return slot + 1
        except ValueError:
            return -1

    def leave(self, slot):
        if self.lot[slot-1] == None:
            return -1
        else:
            car = self.lot[slot-1]
            self.lot[slot-1] = None
            return (slot, car)

    def find_car_by_reg_no(self, reg_no):
        for i in range(0,self.size):
            if self.lot[i] and self.lot[i].getRegNo() == reg_no:
                return i + 1
    
    def find_cars_by_color(self, color):
        if isinstance(color, str):
            color = color.lower()
            cars = []
            for i in range(0, self.size):
                if self.lot[i] and self.lot[i].getColor() == color:
                    cars.append((i+1, self.lot[i]))
            return cars
        else:
            raise ValueError

