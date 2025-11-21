// yandex task 8. Поиск в глубину
#include <iostream>
#include <sstream>
#include <tuple>
#include <vector>
#include <set>

using namespace std;

using vertex_id = int;

constexpr char delimiter = ',';

tuple<int,int> input_graph_size() {
    
    int vertices_number, edges_number;
    string buffer;
    string input; 
    cin >> input;
    stringstream ss(input);
    getline(ss, buffer, delimiter);
    vertices_number = stoi(buffer);
    getline(ss, buffer, delimiter);
    edges_number = stoi(buffer);
    return tuple<int, int>(vertices_number, edges_number);
    
}


vector<tuple<vertex_id, vertex_id>> input_graph_edges(int edges_number) {
    vector<tuple<vertex_id,vertex_id>> edges(edges_number);
    for (int i_edge=0; i_edge < edges_number; i_edge++) {
        int start, end;
        string buffer;
        string input; 
        cin >> input;
        stringstream ss(input);
        getline(ss, buffer, delimiter);
        start = stoi(buffer);
        getline(ss, buffer, delimiter);
        end = stoi(buffer);
        edges[i_edge] = make_tuple(start, end);
    }
    return edges;
}

string format_collection_elements(set<vertex_id> elements) {
    stringstream ss;
    for (auto element: elements) {
        ss << element << ", ";
    }
    ss << endl;
    return ss.str();
}

void find_connected_components(
    const vector<tuple<vertex_id,vertex_id>>& edges,
    set<vertex_id>& reached_vetices,
    vertex_id starting_vertex
) {
    reached_vetices.insert(starting_vertex);
    //cout << endl << "reached_vetices: " << format_collection_elements(reached_vetices);
    
    set<vertex_id> neighbours;
    
    for(auto edge: edges) {
        const auto [tail, head] = edge;
        //cout << "checking edge: " << tail << " -> " << head << endl;
        if (tail == starting_vertex) {
            neighbours.insert(head);
        } else if (head == starting_vertex) {
            neighbours.insert(tail);
        }
        

    }
    
    for(auto neighbour: neighbours) {
        //cout << "checking neighbour "<< neighbour << " of starting_vertex " << starting_vertex << endl;
        if (!reached_vetices.contains(neighbour)) {
            //cout << "recursion into: "<< neighbour << endl;
            find_connected_components(edges, reached_vetices, neighbour);
        }
    }
}



int main() {
    const auto [vertices_number, edges_number] = input_graph_size();
    
    //cout << "vertices_number=" << vertices_number << endl;
    //cout << "edges_number=" << edges_number << endl;
    
    const auto edges = input_graph_edges(edges_number);
    
    
    
    set<vertex_id> components;
    find_connected_components(edges, components, 1);
    
    cout << components.size() << endl;
    for(auto vertex: components) {
        cout << vertex << " ";
    }
    
    return 0;
}
