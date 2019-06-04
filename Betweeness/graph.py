from collections import deque, namedtuple
from time import process_time
import matplotlib.pyplot as plt

class Node:
    def __init__(self, data):
        self.data = data
        self.neighbours = list()

class Graph:

    def __init__(self):
        self.nodes = list()
        self.data = list()

    def add_node(self, data):
        n_node = Node(data)
        if data not in self.data:
            self.data.append(data)
            self.nodes.append(n_node)
            return len(self.nodes)-1 #pos
        else:
            return self.data.index(data)

    def add_edge(self, node_a, node_b):
        self.nodes[node_a].neighbours.append(node_b)
        self.nodes[node_b].neighbours.append(node_a)

    def get_edges(self):
        edges = 0
        for node in self.nodes:
            edges += len(node.neighbours)
        return edges



    def brandes(self):
        V = len(self.nodes)
        
        C = [0 for v in range (V)] #centrality
        for s in range(V):
            S = [] #stack
            #P = dict((w,[]) for w in range(V)) #pred
            P = [[] for w in range(V)]
            
            g = [0 for t in range (V)] #sigma
            g[s] = 1
            
            d = [-1 for t in range (V)]
            d[s] = 0
        
            Q = deque([])
            Q.append(s)

            while Q:
                v = Q.popleft()
                S.append(v)

                for w in self.nodes[v].neighbours:
                    if d[w] < 0:
                        Q.append(w)
                        d[w] = d[v] + 1
                    if d[w] == d[v] + 1:
                        g[w] += g[v]
                        P[w].append(v)

            dis = [0 for v in range (V)]

            while S:
                w = S.pop()
                for v in P[w]:
                    dis[v] = dis[v] + (g[v]/g[w]) * (1 + dis[w])
                if w != s:
                    C[w] += dis[w]
        return C

graphs = ["smallest_graph.txt", "even_smaller_graph.txt",
          "smaller_graph.txt", "small_graph.txt"]

big_graph = "backup_graph.txt"
big_graph_t = "backup_graph"

huge_graph = "approx1m.txt"
huge_graph_t = "approx1m"

x = [i for i in range(len(graphs))]
my_xticks = ["smallest_graph", "even_smaller_graph",
          "smaller_graph", "small_graph"]

times = list()

time_file = open("times.txt", "w")    

def read_graph(file):

    graph_text = open(file, "r")

    G = Graph()

    i = 0
    node_pages = list()
    node_set = set()

    for line in graph_text:
        pages = line.split()
        node_pages.clear()
        node_set.clear()
        for url in pages:
            node_set.add(url) #no repetition

        for url in node_set:
            node_pages.append(G.add_node(url)) #positions

        first_page = node_pages[0]
        del node_pages[0]
    
        for url in node_pages:
            G.add_edge(first_page, url)
        

    print("Nodes: " + str(len(G.nodes)))
    print("Edges: " + str(G.get_edges()))

    graph_text.close()

    time1 = process_time()
    G.brandes()
    time2 = process_time()
    time = time2 - time1
    times.append(time)
    line_to_write = file + " " + str(time)
    time_file.write(line_to_write + "\n")
    print(line_to_write)

    graph_text.close()

for graph in graphs:
    read_graph(graph)

plt.xticks(x, my_xticks)
plt.plot(x, times)
plt.savefig("without_big_graph.png")

my_xticks.append(big_graph_t)
x.append(x[-1]+1)
read_graph(big_graph)
plt.xticks(x, my_xticks)
plt.plot(x, times)
plt.savefig("without_huge_graph.png")

my_xticks.append(huge_graph_t)
x.append(x[-1]+1)
read_graph(huge_graph)
plt.xticks(x, my_xticks)
plt.plot(x, times)
plt.savefig("all_graphs.png")

time_file.close() 

"""graph_text = open("approx1m.txt", "r")

G = Graph()

i = 0
node_pages = list()
node_set = set()

for line in graph_text:
    pages = line.split()
    node_pages.clear()
    node_set.clear()

    for url in pages:
        node_set.add(url) #no repetition

    for url in node_set:
        node_pages.append(G.add_node(url)) #positions

    first_page = node_pages[0]
    del node_pages[0]
    
    for url in node_pages:
        G.add_edge(first_page, url)

    i += 1
    print(str(i))
        

print("Nodes: " + str(len(G.nodes)))
print("Edges: " + str(G.get_edges()))

graph_text.close() """

