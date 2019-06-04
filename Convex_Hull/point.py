class Point:
	
	def __init__(self, x, y):
		self.x = x
		self.y = y
		#self.yx = y/x

	def print(self):
		print("(" + str(self.x) + ", " + str(self.y) + ")")
	
	def get_y(self):
		return self.y
	
	def get_x(self):
		return self.x

def ccw(a, b, c):
	return (b.x - a.x)*(c.y - a.y) - (b.y - a.y) * (c.x - a.x)


def sort_by_y(pt_a):
	return pt_a.y
	
