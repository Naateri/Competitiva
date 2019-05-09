//based on the code found at www.geeksforgeeks.org/heavy-light-decomposition-set-2-implementation/

#include <iostream> 
#include <stdio.h>
#include <cstring>
using namespace std; 
  
#define N 11

struct Tree_node 
{ 
    int parent, depth, size, pos_seg_base, chain; 
}; 

struct Edge{
    int weight, deeper_end;
};
  
struct Graph{
    int** G = 0;
	int n;
    Tree_node* nodes_info;
    Edge* edges;
	Graph(){
		;
	}
    Graph(int n){
		this->n = n;
        G = new int*[n];
        for(int i = 0; i < n; i++){
			G[i] = new int[n];
		}
        nodes_info = new Tree_node[n];
        edges = new Edge[n];
		memset(G, -1, sizeof(G));
		cout << "Created Graph\n";
    }
    ~Graph(){
        for(int i = 0; i < n; i++) delete[] G[i];
        delete[] G;
        delete[] nodes_info;
        delete[] edges;     
    }
    void add_edge(int a, int b, int w, int e){
		cout << "e: " << e << endl;
		cout << "a: " << a << ", b: " << b << endl;
        G[a][b] = e-1; G[b][a] = e-1;
        edges[e-1].weight = w;
    }

    void dfs(int cur, int prev, int depth){
		cout << "cur: " << cur << endl;
        nodes_info[cur].parent = prev;
        nodes_info[cur].depth = depth;
        nodes_info[cur].size = 1;

        for(int j = 0; j < n; j++){
			cout << "j " << j << endl;
            if (j != cur && j != nodes_info[cur].parent && G[cur][j] != -1){
                edges[G[cur][j]].deeper_end = j;

                dfs(j, cur, depth+1);

                nodes_info[cur].size += nodes_info[j].size;
            }
        }
    }

    int LCA(int u, int v){
        int* LCA_aux = new int[n+5];
        
        if (nodes_info[u].depth < nodes_info[v].depth) swap(u, v); 
    
        memset(LCA_aux, -1, sizeof(LCA_aux)); 
  
        while (u!=-1){ 
            LCA_aux[u] = 1; 
            u = nodes_info[u].parent; 
        } 
  
        while (v){ 
            if (LCA_aux[v]==1) break; 
            v = nodes_info[v].parent; 
        } 
		delete[] LCA_aux;
        return v; 

    }

};

struct Segment_Tree{
    int* base_array, *tree;
    int construct(int start, int end, int cur){
        if (start == end-1){
            tree[cur] = base_array[start];
            return base_array[start];
        }

        int mid = (start + end) >> 1;
        tree[cur] = max(construct(start, mid, cur<<1), 
                construct(mid, end, cur<<1 + 1));
        return tree[cur];
    }
	Segment_Tree(){
		;
	}
    Segment_Tree(int* base_array, int n, int edges){
        this->base_array = base_array;
        tree = new int[6*n];
        construct(0, edges, 0);
    }
    ~Segment_Tree(){
        delete[] base_array;
        delete[] tree;
    }
    int update(int start, int end, int cur, int x, int val){
        if(start > x || end <= x);   
        else if(start == x && start == end-1) tree[cur] = val; 
        else { 
        int mid = (start + end)/2; 
        tree[cur] =  max(update(start, mid, start*2, x, val), 
                         update(mid, end, cur*2+1, x, val)); 
        } 
  
        return tree[cur];     
    }
    //functions for crawltree
    //Query -> query range
    int RMQUtil(int start, int end, int query_start, int query_end, int index){
        if (query_start <= start && query_end >= end-1) return tree[index];
        if (start-1 < query_end || start > query_end) return -1;

        int mid = (start + end) >> 1;
        return max(RMQUtil(start, mid, query_start, query_end, index << 1),
                RMQUtil(mid, end, query_start, query_end, (index << 1) + 1));
    }
    
    int RMQ(int query_start, int query_end, int n){
        if (query_start < 0 || query_end > n-1 || query_start > query_end){
            cout << "Invalid input\n";
            return -1;
        }
        return RMQUtil(0, n, query_start, query_end, 1);
    }

    int crawl_tree(int u, int v, int n, int* chain_heads, Tree_node* nodes_info){
        int chain_u;
        int chain_v = nodes_info[v].chain, ans = 0;

        while(1){
            chain_u = nodes_info[u].chain;
            if (chain_u == chain_v){
                if (u == v);
                else 
                    ans = max(RMQ(nodes_info[v].pos_seg_base+1, nodes_info[u].pos_seg_base, n),
                        ans);
                break;
            } else {
                ans = max(RMQ(nodes_info[chain_heads[chain_u]].pos_seg_base, 
                    nodes_info[u].pos_seg_base, n), ans);
            }
        }
        return ans;
    }
};

struct HLD{
    Graph* G;
    Segment_Tree tree;
    int* nodes; //nodes stored in leaf (in order)
	int* chain_heads;
	void decompose(int cur_node, int id, int& cur_edge, int* cur_chain, int n){ //decomposes the tree into chains
		int special_child, heavy_edge_id;
		if (chain_heads[*cur_chain] == -1) chain_heads[*cur_chain] = cur_node;
		G->nodes_info[cur_node].chain = *cur_chain;
		G->nodes_info[cur_node].pos_seg_base = cur_edge;
		nodes[cur_edge++] = G->edges[id].weight;
		
		special_child = -1;
		for(int j = 0; j < n; j++){
			if (j != cur_node && j!= G->nodes_info[cur_node].parent
				&& G->G[cur_node][j] != -1){
				if (special_child == -1 || G->nodes_info[special_child].size < G->nodes_info[j].size){
					special_child = j;
					heavy_edge_id = G->G[cur_node][j];
				}
			}
		}		
		if (special_child != -1) {//special_child found
			decompose(special_child, heavy_edge_id, cur_edge, cur_chain, n);
		}
		//every other normal child, separation on child subtree
		for(int j = 0; j < n; j++){
			if (j != cur_node && j != G->nodes_info[cur_node].parent &&
				j != special_child && G->G[cur_node][j] != -1){
				(*cur_chain)++;
				decompose(j, G->G[cur_node][j], cur_edge, cur_chain, n);
			}
		}
	}
	
    HLD(Graph* G){
        this->G = G;
		nodes = new int[G->n];
		chain_heads = new int[G->n];
		memset(chain_heads, -1, sizeof(chain_heads)); //initializes chain_heads with -1
		int cur_edge = 0, cur_chain = 0;
		decompose(0, G->n-1, cur_edge, &cur_chain, G->n);
		Segment_Tree le_tree(nodes, G->n, G->n); //Segment_Tree(base_array, nodes, edges)
		//A tree has, as maximum, n-1 edges (n because we need to store the root)
		this->tree = le_tree;
    }

    void change(int e, int val){
		tree.update(0, G.n, 0, G->nodes_info[G->edges[e].deeper_end].pos_seg_base, val);
	}

    int max_edge(int u, int v, int n){
        int lca = G->LCA(u,v);
        int ans = max(tree.crawl_tree(u, lca, n, chain_heads, G->nodes_info),
            tree.crawl_tree(v, lca, n, chain_heads, G->nodes_info));
        return ans;
    }
};

// driver function 
int main() 
{ 
    

	Graph* tree = new Graph(N);
	
	tree->add_edge(0,1,13,1);
	tree->add_edge(0,2,9,2);
	tree->add_edge(0,3,23,3);
	tree->add_edge(1,4,4,4);
	tree->add_edge(1,5,25,5);
	tree->add_edge(2,6,29,6);
	tree->add_edge(5,7,5,7);
	tree->add_edge(6,8,30,8);
	tree->add_edge(7,9,1,9);
	tree->add_edge(7,10,6,10);
	
	int root = 0, parent_of_root = -1, depth_of_root = 0;
	
	tree->dfs(root, parent_of_root, depth_of_root);
	
	HLD* hld = new HLD(tree);
	
    delete tree;
  
    return 0; 
} 
