import sys, pdb
from app.parking import Parking

parking = None

def process_line(line):
    global parking
    line = line.split(' ')
    command = line[0]
    args = line[1: ]

    try:
	    if 'create_parking_lot' in command:
	        parking = Parking(int(args[0]))
	        print("Created a parking lot with " + str(parking.size) + " slots")

	    elif 'park' in command:
	        slot = parking.newCar(args[0], args[1])
	        if slot == -1:
	            print("Sorry, parking lot is full")
	        else:
	            print("Allocated slot number: " + str(slot))

	    elif 'leave' in command:
	        result = parking.leave(int(args[0]))
	        print("Slot number " + str(result[0]) + " is free")

	    elif 'registration_numbers_for_cars_with_colour' in command:
	        cars = parking.find_cars_by_color(args[0])
	        for i in cars:
	            print(i[1].getRegNo(), end=' ')
	        print('')

	    elif 'slot_numbers_for_cars_with_colour' in command:
	        cars = parking.find_cars_by_color(args[0])
	        if cars == None:
	            print('Not found')
	        else:
	            for i in cars:
	                print(i[0], end=' ')
	            print('')

	    elif 'slot_number_for_registration_number 'in command:
	        slot = parking.find_car_by_reg_no(args[0])
	        print(slot)
	        if slot:
	            print(slot)

	    elif 'status' in command:
	        print('Slot No\tReg No\tColour')
	        for i in range(0,len(parking.lot)):
	            if parking.lot[i]:
	                print('%d\t%s\t%s'%(i+1, parking.lot[i].reg_no, parking.lot[i].color), end='')

    except ValueError:
        print("Invalid Data Entered!")
    except TypeError:
        print("Datatype Mismatch!")
                 
if len(sys.argv) == 2:  
    lines = list(open(sys.argv[1]))
    for i in lines:
        process_line(i)
else:
    while True:
        process_line(input())
