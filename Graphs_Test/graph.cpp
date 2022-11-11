/* Graph read from file, and represnted as adjacency list. 
 * Each entry in the file is an edge represented as <source vertex, destination vertex, edge weight>
To implement DFS and BFS traversals on the graph. 
Note that there is more than one right order of BFS and DFS vertices
*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

// Each vertex has an integer id. 

typedef vector<vector<pair<int,int>>> adjlist; // Pair: (head vertex, edge weight)

adjlist makeGraph(ifstream& ifs);
void printGraph(const adjlist& alist);
vector<int> BFS(const adjlist& alist, int source); // Return vertices in BFS order
vector<int> DFS(const adjlist& alist, int source);  // Return vertices in DFS order
vector<int> topologicalSort(const adjlist& alist, int source); // Return vertices in topological order.
void topoHelper(const adjlist& alist, vector<int>& topolist, vector<bool>& visited, stack<int>& stack, int source);
void DFSHelper(const adjlist& alist, vector<int>& dfslist, vector<bool>& visited, int source);
void printQ(queue<int> qcopy);


// DFS - returns list of nodes in DFS order starting from source vertex
vector<int> DFS(const adjlist& alist, int source) {
// Your code here
    vector<int> dfslist;
    // Vertices visited, initially none.
    vector<bool> visited(alist.size(), false);

    // Using a DFS helper function.
    DFSHelper(alist, dfslist, visited, source);
    return dfslist;

}

void DFSHelper(const adjlist& alist, vector<int>& dfslist, vector<bool>& visited, int source) {
// Your code here
    // Mark current vertex as visited.
    visited[source] = true;
    dfslist.push_back(source);

    for (auto adjecent: alist[source]) {
        // Check if a vertex had not been visited and recursion.
        if (!visited[adjecent.first]) {
            DFSHelper(alist, dfslist, visited, adjecent.first);
        }
    }
}

// BFS - returns list of nodes in BFS order starting from source vertex
vector<int> BFS(const adjlist& alist, int source) {
// Your code here
    // Vertices visited, initially none.
    vector<bool> visited(alist.size(), false);
    // Return bfslist.
    vector<int> bfslist;
    // Created a Queue for BFS.
    queue<int> list;
    
    // Push source into list.
    // Mark as visited.
    list.push(source);
    visited[source] = true;
    
    while(!list.empty()) {
        int curr = list.front();
        bfslist.push_back(curr);
        list.pop();
        
        for (auto adjecent: alist[curr]) {
            // Check if vertex is not visited.
            if(!visited[adjecent.first]) {
                visited[adjecent.first] = true;  // Mark visited.
                list.push(adjecent.first);  // Push vertex into queue.
            }
        }
    }
    return bfslist;
}

vector<int> topologicalSort(const adjlist& alist, int source) {
    vector<int> topolist; // Return topolist.
    vector<bool> visited(alist.size(), false); // Vertices visited, initially none.
    stack<int> stack; // Push to the stack, then return. 

    // Called a topoHelper function for recursive. 
    topoHelper(alist, topolist, visited, stack, source);
    // Empty stack and push them into topolist.
    while (!stack.empty()) {
        topolist.push_back(stack.top());
        stack.pop();
    }
    return topolist;
}

void topoHelper(const adjlist& alist, vector<int>& topolist, vector<bool>& visited, stack<int>& stack, int source) {
    // Mark current node as visited
    visited[source] = true;
    
    // Recur to all vertices, if a vertex does not exist yet.
    for (auto adjecent: alist[source]) {
        if (!visited[adjecent.first]) {
            topoHelper(alist, topolist, visited, stack, adjecent.first);
        }
    }
    // Push current vertex to stack.
    stack.push(source);
}


// Reads a csv graph from file and returns an adjacency list
adjlist makeGraph(ifstream& ifs) {
    int vh, vt, wt;
    string line;
    unordered_multimap<int, pair<int, int>> elist;
    set<int> vlist;
    
    while (getline(ifs, line)) {
        stringstream ss(line);
        ss >> vt;
        if (ss.peek() == ',')
            ss.ignore();
        ss >> vh;
        if (ss.peek() == ',')
            ss.ignore();
        ss >> wt;

        elist.emplace(vt, make_pair(vh, wt));   
        vlist.insert(vt);
        vlist.insert(vh);
    }
    
    adjlist res(vlist.size()); // Preallocate vector
    
    for (auto& ele : elist) {
        res.at(ele.first).push_back(make_pair(ele.second.first, ele.second.second));
    }
    return res;
}

// Prints the adjacency list (only vertices, not edge weights)
void printGraph(const adjlist& alist) {
    int i = 0;
    for (auto& v : alist) {
        cout << i++ << ": ";
        for (auto& av : v) {
            cout << av.first << " ";
        }
        cout << endl;
    }
}

// Prints queue for debugging
void printQ(queue<int> qcopy) {
    while (!qcopy.empty()) {
        cout << qcopy.front();
        qcopy.pop();
    }
    cout << endl;
}

int main() {
    ifstream ifs("sample_edges.txt");
    adjlist alist = makeGraph(ifs);
    printGraph(alist);
    vector<int> dfslist = DFS(alist, 0);
    for (auto& ele : dfslist) // Prints 0 2 4 5 1 3. Other answers possible 
        cout << ele << " ";
    cout << endl;
    
    vector<int> bfslist = BFS(alist, 0);
    for (auto& ele : bfslist) // Prints 0 2 1 4 3 5. Other answers possible 
        cout << ele << " ";
    cout << endl;

    vector<int> topolist = topologicalSort(alist, 0);
    for (auto& ele : topolist) // Prints 0 2 1 4 3 5. Other answers possible 
        cout << ele << " ";
    cout << endl;
}



