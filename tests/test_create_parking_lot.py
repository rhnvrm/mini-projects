import unittest
from app.parking import Parking


class TestParkingLot(unittest.TestCase):
    
    def test_create_new_parking_lot(self):
        park_lot = Parking(6)
        result = park_lot.size
        self.assertEqual(6, result)

    def test_parking_raises_error_if_arg_is_not_a_number(self):
        self.assertRaises(ValueError, Parking, "123")
        self.assertRaises(ValueError, Parking, 1.5)
