import networkx as nx
import matplotlib.pyplot as plt
from networkx.drawing.nx_agraph import graphviz_layout
from collections import deque
#from networkx.algorithms.centrality import betweeness_centrality

G = nx.Graph()

graph_text = open("approx1m.txt", "r")

i = 0
node_pages = list()

for line in graph_text:
    pages = line.split()
    node_pages.clear()
    G.add_nodes_from(pages)
    first_page = pages[0]
    del pages[0]
    for url in pages:
        edge = (first_page, url)
        G.add_edge(*edge)
        edge = (url, first_page)
        G.add_edge(*edge)


graph_text.close()

#nx.draw(G)
#plt.savefig("labels.pdf")
#plt.savefig("backup_graph.png")
#plt.show()

print("Nodes: " + str(len(G.nodes())))
print("Edges: " + str(len(G.edges())))

C = nx.algorithms.centrality.betweenness_centrality(G)
centrality = list()

GNodes = len(G.nodes())

for val in C.values():
    centrality.append(val * (GNodes-1) * (GNodes - 2) )

#print(C.values())
print(centrality)
