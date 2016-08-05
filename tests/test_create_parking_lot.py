import unittest

class TestParkingLot(unittest.TestCase):
    
    def test_create_new_parking_lot(self):
        park_lot = Parking(6)
        result = park_lot.size
        self.assertEqual(6, result)
