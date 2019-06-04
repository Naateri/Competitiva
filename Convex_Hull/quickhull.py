import point
from random import randint
import math
from operator import methodcaller
import matplotlib.pyplot as plt
import numpy as np

def find_min_max_x(points):
    min_x = 99999
    max_x = 0
    i = 0
    for pt in points:
        if pt.x < min_x:
            leftmost = pt
            min_index = i
            min_x = pt.x
        if pt.x > max_x:
            rightmost = pt
            max_index = i
            max_x = pt.x
        i += 1
    return leftmost, rightmost, min_index, max_index

def pick_side(p, p1, p2): #where does p belong between line by p1
    # and p2
    val = (p.y - p1.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p.x - p1.x)
    if val > 0: #right
        return 1
    if val < 0: #left
        return -1

def line_dist(p, p1, p2):
    return abs( (p.y - p1.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p.x - p1.x) )

def find_hull(sk, p1, p2, convex_hull):
    if len(sk) == 0:
        return

    if len(sk) == 1:
        convex_hull.append(sk[0])
        return

    s1 = list()
    s2 = list()
    max_dist = 0

    i = 0
    for pt in sk:
        dist = line_dist(pt, p1, p2)
        if (dist > max_dist):
            c = pt
            max_dist = dist
            index = i
        i += 1

    convex_hull.append(c)
    sk.pop(index)

    for pt in sk:
        if pick_side(pt, p1, c) == 1:
            s1.append(pt)
        elif pick_side(pt, c, p2) == 1:
            s2.append(pt)
    
    find_hull(s1, p1, c, convex_hull)
    find_hull(s2, c, p2, convex_hull)


def quick_hull(points):
    convex_hull = list()
    a,b,index_a,index_b = find_min_max_x(points)
    convex_hull.append(a)
    convex_hull.append(b)
    points.pop(index_a)
    points.pop(index_b)
    #finding groups
    s1 = list()
    s2 = list()
    for pt in points:
        if pick_side(pt, a, b) == 1:
            s1.append(pt)
        elif pick_side(pt, a, b) == -1:
            s2.append(pt)
    find_hull(s1, a, b, convex_hull)
    find_hull(s2, b, a, convex_hull)
    return convex_hull

    
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

c_hull = quick_hull(pts)

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
