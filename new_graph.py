f = open("graph.txt", "r")
new_file = open("approx1m.txt", 'w')

lines = 3400
i = 0

for line in f:
	if (i > lines):
		break
	new_file.write(line)
	i+=1
