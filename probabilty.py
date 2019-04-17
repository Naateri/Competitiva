########################
###TAL VEZ TENGA BUGS###
########################

from random import randint
import random
import math

competitive_class = [
    "Adriana",
    "Alejandrito",
    "Bryan",
    "Fabrizio",
    "Alexandra",
    "Manuelón",
    "Paulo",
    "Renato",
    "Rodrigo",
    "Sebastián",
    "Victor"
]

"""competitive_class = [
    "uno",
    "dos",
    "tres"
    ]"""

mates = len(competitive_class)

chances_mates = list()

chances = [1/mates] * mates

for i in range(mates):
    chances_mates.append(competitive_class[i] + str(chances[i]))

alfa = 0.05
alfa_x = 1

def get_alfa():
    global alfa_x
    alfa_x += 0.1
    return 1/math.exp(alfa_x)

def random_class(limit = mates-1):
    return randint(0,limit)

def build_new_array(rand_val):
    new_array = list()
    names = list()
    for i in range(len(chances)):
        if chances[i] >= rand_val:
            new_array.append(chances[i])
            names.append(competitive_class[i])
    if len(new_array) == 0:
        return build_new_array(random.random())
    return new_array,names

def find_in_array(value, array):
    for i in range(len(array)):
        if value == array[i]:
            return i

    return -1
        
def probability():
    #global alfa
    rand_var = random.random()
    #rand_var = random.uniform(min(chances), max(chances))
    print('rand_var: ' + str(rand_var))
    new_array,names = build_new_array(rand_var)
    r = random_class(len(new_array)-1)
    res = names[r]
    
    r = find_in_array(res, competitive_class)
    alfa = (get_alfa()/100)
    chances[r] -= alfa
    for i in range(mates):
        if (i == r):
            continue
        chances[i] += (alfa/(mates-1))
    
    return res

def update_chances_mates():
    for i in range(mates):
        chances_mates[i] = (competitive_class[i] + ' '+ str(chances[i]))

def print_sum(array):
    suma = 0
    for element in array:
        suma += element
    print(suma)

while True:
    input()
    print(probability())
    update_chances_mates()
    print(chances_mates)
    print_sum(chances)
