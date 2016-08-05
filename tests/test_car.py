import unittest
from app.car import Car

class TestCarCreation(unittest.TestCase):

    def test_new_car(self):
        car = Car("KA-01-HH-1234", "White")
        reg_no = car.reg_no
        self.assertEqual("KA-01-HH-1234", reg_no)
        color = car.color
        self.assertEqual("White", color)
    
    def test_car_raises_error_if_no_arg_provided(self):
        self.assertRaises(TypeError, Car)

    def test_car_raises_error_if_arg_is_not_string(self):
        self.assertRaises(ValueError, Car, 1234, "White")
        self.assertRaises(ValueError, Car, "KA-1234", 123)
        self.assertRaises(ValueError, Car, 123, 123)

class TestCarMethods(unittest.TestCase):

    def setUp(self):
        self.car1 = Car("KA-01-HH-1234", "White")
        self.car2 = Car("KA-02-HH-1234", "Black")
        self.car3 = Car("KA-03-HH-1234", "black")
    
    def test_get_car_color_is_lowercase(self):
        self.assertEqual(self.car1.getColor(), "white")

    def test_get_car_color_compare_uppercase_and_lowercase(self):
        self.assertEqual(self.car2.getColor(), self.car2.getColor())

    def test_get_car_reg_no(self):
        self.assertEqual(self.car1.getRegNo(), "KA-01-HH-1234")

        
