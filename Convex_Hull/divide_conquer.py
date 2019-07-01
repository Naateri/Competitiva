import point
from graham import graham_scan
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
    n1 = len(lh)
    n2 = len(rh)
    
    leftmost, l_index = find_leftmost(rh)
    rightmost, r_index = find_rightmost(lh)

    p = point.Point(leftmost.x, leftmost.y)
    q = point.Point(rightmost.x, rightmost.y)

    #upper tangent 
    index_a = r_index
    index_b = l_index
    done = False 
    while not done:
        done = True
        while (point.ccw(rh[index_b], lh[index_a], lh[(index_a+1)%n1]) <= 0):
            index_a = (index_a + 1) % n1
  
        while (point.ccw(lh[index_a], rh[index_b], rh[(n2+index_b-1)%n2]) >= 0):    
            index_b = (n2+index_b-1)%n2
            done = False 
  
    upper_a = index_a
    upper_b = index_b 
    #lower tangent

    index_a = l_index
    index_b = r_index
    
    done = False
    while not done:
        done = True
        while (point.ccw(lh[index_a], rh[index_b], rh[(index_b+1)%n2])<=0):
            index_b=(index_b+1) % n2
  
        while (point.ccw(rh[index_b], rh[index_a], lh[(n1+index_a-1)%n1])>=0):
            index_a=(n1+index_a-1) % n1 
            done=False
  
    lower_a = index_a
    lower_b = index_b 

    result = list()

    #result: current convex_hull
      
    result.append(lh[upper_a])
    index = upper_a
    while index != lower_a:
        index = (index+1)%n1
        result.append(lh[index])
  
    result.append(rh[lower_b])
    index = lower_b
    while (index != upper_b):
        index = (index+1)%n2
        result.append(rh[index])
    return result

def divide_and_conquer(points): #assumes points sorted by x
    #convex_hull = list()
    print(len(points))
    if len(points) <= 5:
        return graham_scan(points)
        #return points
    left = points[0:int(len(points)/2)]
    right = points[:int(len(points)/2)]
    left_half = divide_and_conquer(left)
    right_half = divide_and_conquer(right)
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
