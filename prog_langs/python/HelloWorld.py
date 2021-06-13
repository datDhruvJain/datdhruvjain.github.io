class Employee:

    def __init__(self, first, last, pay):
        self.first = first
        self.last = last
        #self.email = first + '.' + last + "@company.com"
    
    @property
    def email(self):
        return("{}.{}@email.com".format(self.first, self.last)) 

    @property
    def fullname(self):
        return("{} {}".format(self.first, self.last)) 
    
    @fullname.setter
    def fullname(self, name):
        first, last = name.split(" ")
        self.first = first
        self.last = last

    @fullname.deleter
    def fullname(self):
        print("Deleting name")
        self.first = None
        self.last = None


emp1 = Employee("shriyas","Iyer", 50000)
emp2 = Employee("Vikrant", "Tiru", 70000)

# emp1.fullname = "Dhurv Jain"

# print(emp1.email)

del emp1.fullname
print(emp1.fullname)
