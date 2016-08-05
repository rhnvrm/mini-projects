import unittest
from app.parking import Parking
from app.car import Car

class TestParkingLotCreation(unittest.TestCase):
    
    def test_create_new_parking_lot(self):
        park_lot = Parking(6)
        result = park_lot.size
        self.assertEqual(6, result)

    def test_parking_raises_error_if_arg_is_not_a_number(self):
        self.assertRaises(ValueError, Parking, "123")
        self.assertRaises(ValueError, Parking, 1.5)

class TestParkingLotMethods(unittest.TestCase):

    def setUp(self):
        self.lot = Parking(5)

    def test_add_new_cars_to_lot(self):
        self.assertEqual(1, self.lot.newCar("KA-01-HH-1234", "White"))
        self.assertEqual(2, self.lot.newCar("KA-02-HH-1234", "White"))
        self.assertEqual(3, self.lot.newCar("KA-03-HH-1234", "White"))
        self.assertEqual(self.lot.currentCarCount(), 3)

    def test_add_and_remove_multiple_new_cars_to_lot(self):
        self.assertEqual(1, self.lot.newCar("KA-01-HH-1234", "White"))
        self.assertEqual(2, self.lot.newCar("KA-02-HH-1234", "White"))
        self.lot.leave(1)
        self.assertEqual(1, self.lot.newCar("KA-03-HH-1234", "White"))

    def test_new_cars_returns_lot_full_when_lot_full(self):
        self.assertEqual(1, self.lot.newCar("KA-01-HH-1234", "White"))
        self.assertEqual(2, self.lot.newCar("KA-02-HH-1234", "White"))
        self.assertEqual(3, self.lot.newCar("KA-03-HH-1234", "White"))
        self.assertEqual(4, self.lot.newCar("KA-04-HH-1234", "White"))
        self.assertEqual(5, self.lot.newCar("KA-05-HH-1234", "White"))
        print(self.lot.lot)
        self.assertEqual(-1, self.lot.newCar("KA-06-HH-1234", "White"))

    def test_leave_returns_error_if_slot_is_empty(self):
        self.assertEqual(self.lot.leave(3), -1)

    def test_find_cars_by_color(self):
        self.lot.newCar("KA-01-HH-1234", "white")
        self.lot.newCar("KA-02-HH-1234", "White")
        self.lot.newCar("KA-03-HH-1234", "Black")
        self.lot.newCar("KA-04-HH-1234", "black")
        self.lot.newCar("KA-05-HH-1234", "BLACK")
        white_cars = self.lot.find_cars_by_color("WHITE")
        black_cars = self.lot.find_cars_by_color("bLaCk")
        self.assertEqual(len(white_cars), 2)
        self.assertEqual(len(black_cars), 3)
        
        #find_cars_by_color returns a list of tuples having (slot, Car)
        self.assertEqual(white_cars[1][0], 2)
        self.assertEqual(black_cars[1][0], 4)
        self.assertIsInstance(white_cars[0][1], Car)

    def test_find_cars_by_color_raises_error_if_arg_not_str(self):
        self.assertRaises(ValueError, self.lot.find_cars_by_color, 123)

    def test_find_car_by_reg_no(self):
        self.lot.newCar("KA-01-HH-1234", "white")
        self.lot.newCar("KA-02-HH-1234", "red")
        self.lot.newCar("KA-03-HH-1234", "green")
        
        #find_car_by_reg_no returns slot
        self.assertEqual(self.lot.find_car_by_reg_no("KA-02-HH-1234"), 2)
        
