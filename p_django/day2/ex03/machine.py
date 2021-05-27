#!/usr/bin/python3

import random
from beverages import HotBeverage, Coffee, Tea, Chocolate, Cappuccino

class CoffeeMachine:
	class EmptyCup(HotBeverage):
		def __init__(self) -> None:
			self.name = "empty cup"
			self.price = 0.90
		def description(self):
			return "An empty cup?! Gimme my money back!"
	class BrokenMachineException(Exception):
		def __init__(self) -> None:
			super().__init__("This coffee machine has to be repaired.")

	def __init__(self) -> None:
		self.cnt = 10

	def serve(self, kind: HotBeverage) -> HotBeverage():
		if (self.cnt <= 1):
			raise CoffeeMachine.BrokenMachineException()
		else:
			if (random.randrange(1, 10) == 1):
				return self.EmptyCup()
			else:
				self.cnt -= 1
				return kind()

	def repair(self):
		self.cnt = 10

def main():
	kind = [Coffee, Tea, Chocolate, Cappuccino]
	coffeeMachine = CoffeeMachine()
	for _ in range(10):
		try:
			print(coffeeMachine.serve(random.choice(kind)))
		except CoffeeMachine.BrokenMachineException as e:
			coffeeMachine.repair()
			print(e)


if __name__ == '__main__':
	main()