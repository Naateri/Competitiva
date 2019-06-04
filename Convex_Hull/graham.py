import point
from random import randint
import math
from operator import methodcaller
import matplotlib.pyplot as plt
import numpy as np

origin = point.Point(0,0)
refvec = point.Point(0,1)

def find_leftmost(points):
    min_x = 99999
    min_y = 99999
    i = 0
    for pt in points:
        if pt.x < min_x:
            leftmost = pt
            index = i
            min_x = pt.x
        """    min_y = pt.y
        elif pt.x == min_x:
            if pt.y < min_y:
                leftmost = pt
                min_y = pt.y
                index = i """
        i += 1 
    return leftmost, index
    

def graham(points):
    temp_points = points.copy()
    leftmost, index = find_leftmost(temp_points)
    leftmost.print()
    print()
    temp_points.pop(index)

    def slope(pt_y):
        pt_x = leftmost
        if (pt_y.x - pt_x.x) == 0:
            return 0
        return (pt_y.y - pt_x.y) / (pt_y.x - pt_x.x)
    
    new_list = sorted(temp_points, key = slope)
    for pt in new_list:
        pt.print()
    my_stack = list()
    my_stack.append(leftmost)
    for pt in new_list:
        #plt.scatter(np.array(x_values), np.array(y_values))
        #plt.scatter(np.array([pt.x]), np.array([pt.y]), c = "tab:red")
        flag = True
        while flag and len(my_stack) > 1:
            flag = False
            C = pt
            B = my_stack[-1]
            A = my_stack[-2]
            if point.ccw(A,B,C) <= 0:
                my_stack.pop()
                flag = True
        my_stack.append(pt)

    return my_stack

total_points = 20
max_num = 30

x_values = list()
y_values = list()
pts = list()
for i in range(total_points):
    x = randint(1,max_num)
    y = randint(1,max_num)
    x_values.append(x)
    y_values.append(y)
    pt = point.Point(x,y)
    pts.append(pt)

c_hull = graham(pts)

ch_x = list()
ch_y = list()
for pt in c_hull:
    ch_x.append(pt.x)
    ch_y.append(pt.y)
    
print("Convex hull points: " + str(len(c_hull)))
#for pt in c_hull:
#    pt.print()
    
plt.scatter(np.array(x_values), np.array(y_values))
plt.scatter(np.array(ch_x), np.array(ch_y), c = "tab:red")
plt.show()
