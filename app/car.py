class Car(object):

    reg_no = None
    color = None

    def __init__(self, reg_no, color):
        
        if(reg_no is None or color is None):
            raise TypeError

        if(isinstance(reg_no, str)):
            self.reg_no = reg_no
        else:
            raise ValueError

        if(isinstance(color, str)):
            self.color = color
        else:
            raise ValueError

    def getColor(self):
        return self.color.lower()

    def getRegNo(self):
        return self.reg_no
        
