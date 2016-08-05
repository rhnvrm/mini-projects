import fileinput
from app.parking import Parking

parking = None

for line in fileinput.input():
    line = line.split(' ')
    command = line[0]
    args = line[1: ]
    print(command)
    if command == 'create_parking_lot':
        parking = Parking(int(args[0]))
        print("Created a parking lot with " + str(parking.size) + " slots")

    elif command == 'park':
        slot = parking.newCar(args[0], args[1])
        if slot == -1:
            print("Sorry, parking lot is full")
        else:
            print("Allocated slot number: " + str(slot))

    elif command == 'leave':
        result = parking.leave(int(args[0]))
        print("Slot number " + str(result[0]) + " is free")

    elif command == 'registration_numbers_for_cars_with_colour':
        cars = parking.find_cars_by_color(args[0])
        for i in cars:
            print(i[1].getRegNo(), end = ' ')
        print('')

    elif command == 'slot_numbers_for_cars_with_colour':
        cars = parking.find_cars_by_color(args[0])
        if cars == None:
            print('Not found')
        else:
            for i in cars:
                print(i[0], end=' ')
            print('')

    elif command == 'slot_number_for_registration_number':
        slot = parking.find_car_by_reg_no(args[0])
        print(slot)
        if slot:
            print(slot)

    elif command == 'status':
        print('Slot No.\tRegistration No\tColor')
        for i in len(parking.lot):
            print('%d\t%s\t%s'%(i, parking.lot[i].reg_no,
                parking.lot[i].color))
                    
