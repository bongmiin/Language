class Calculator:
    def plus(self, x, y):
        return  x+y
    def minus(self, x, y):
        return x-y
    def multiply(self, x, y):
        return x*y
    def divide(self, x, y):
        return x/y

calc = Calculator()

print(calc.plus(10, 5))
print(calc.minus(10, 5))
print(calc.multiply(10, 5))
print(calc.divide(10, 5))
