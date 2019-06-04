import point
from graham import graham
from random import randint
import math
from operator import methodcaller
import matplotlib.pyplot as plt
import numpy as np

def find_leftmost(points):
    min_x = 99999
    i = 0
    for pt in points:
        if pt.x < min_x:
            leftmost = pt
            index = i
            min_x = pt.x
        i += 1
    return leftmost, index

def find_rightmost(points):
    max_x = 0
    i = 0
    for pt in points:
        if pt.x > max_x:
            rightmost = pt
            index = i
            min_x = pt.x
        i += 1
    return rightmost, index


def merge(lh, rh):
    leftmost, l_index = find_leftmost(lh)
    rightmost, r_index = find_rightmost(rh)

    p = point.Point(leftmost.x, leftmost.y)
    q = point.Point(rightmost.x, rightmost.y)

    
    

def divide_and_conquer(points): #assumes points sorted by x
    #convex_hull = list()
    if len(points) <= 5:
        return graham(points)
    left_half = divide_and_conquer(points[0:int((len(points)/2))])
    right_half = divide_and_conquer(points[int(len(points)/2):len(points)])
    return merge(left_half, right_half)
    
total_points = 30
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

sorted(pts, key = lambda pt: pt.x)

c_hull = divide_and_conquer(pts)

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
