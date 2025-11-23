//yandex task 9. Длина кратчайшего пути

/* 
input:
5
0,1,0,0,1,
1,0,1,0,0,
0,1,0,0,0,
0,0,0,0,0,
1,0,0,0,0,
3,5
output:
3

input:
10
0,1,0,0,0,0,0,0,0,0
1,0,0,1,1,0,1,0,0,0
0,0,0,0,1,0,0,0,1,0
0,1,0,0,0,0,1,0,0,0
0,1,1,0,0,0,0,0,0,1
0,0,0,0,0,0,1,0,0,1
0,1,0,1,0,1,0,0,0,0
0,0,0,0,0,0,0,0,1,0
0,0,1,0,0,0,0,1,0,0
0,0,0,0,1,1,0,0,0,0
5,4
output:
2
*/

#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <stack>
#include <span>

using namespace std;

//!yandex's delimiter (whitespace) doesn't work with online compilers. use comma to see the result!
constexpr char delimiter = ',';

using vertex_id = int;

struct Edge {
    vertex_id start; 
    vertex_id end;
    Edge(vertex_id _start, vertex_id _end): start(_start), end(_end) {};
    Edge(): start(-1), end(-1) {};
};

bool operator<(const Edge& edge1, const Edge& edge2) {
    return tie(edge1.start, edge1.end) < tie(edge2.start, edge2.end);
}

set<Edge> input_adjacency_matrix(int vertices_amount) {
    set<Edge> edges;
    string input_line;
    for (int i_line = 0; i_line < vertices_amount; i_line++) {
        cin >> input_line;
        stringstream ss(input_line);
        for (int i_column = 0; i_column < vertices_amount; i_column++) {
            //int is_connected;
            string str_is_connected;
            getline(ss, str_is_connected, delimiter);
            if (str_is_connected == "1") {
               edges.insert(Edge(i_line+1, i_column+1));
            }
        }
    }
    return edges;
}

string format_edges(const set<Edge>& edges) {
    stringstream ss;
    for (const auto& edge: edges) {
        ss << edge.start << " -- " << edge.end << endl;
    }
    return ss.str();
}

tuple<vertex_id, vertex_id> input_searched_vertices() {
    string input; cin >> input;
    stringstream ss(input);
    string str_buffer;
    getline(ss, str_buffer, delimiter);
    vertex_id start = stoi(str_buffer);
    getline(ss, str_buffer, delimiter);
    vertex_id end = stoi(str_buffer);
    return make_tuple(start, end);
}

int find_path(
    set<vertex_id>& reached_vertices,
    int total_vertices_amount,
    int path_length,
    const set<Edge>& edges,
    vertex_id start,
    vertex_id final_end
) {
    reached_vertices.insert(start);
    cout 
        << "find_path, start= " << start 
        << " end= " << final_end 
        << " path_length=" << path_length
        << " reached_vertices.size() = " << reached_vertices.size()
        << endl;
    if (start == final_end) {
        cout << "return from find_path, path_length= " << path_length << endl;
        return path_length;
    } 
    // else if (reached_vertices.size() == total_vertices_amount) {
    //     cout 
    //         << "return from find_path, -1 (not found, reached_vertices.size = " 
    //         << reached_vertices.size() << endl;
    //     return -1;
    // }
    
    for (const auto& edge: edges) {
        if (edge.start == start) {
            if (!reached_vertices.contains(edge.end)) {
                int found_path = 
                    find_path(
                        reached_vertices,
                        total_vertices_amount,
                        path_length+1,
                        edges,
                        edge.end,
                        final_end
                    );
                if (found_path > -1) {
                    return found_path;
                }
            }   
        }
    }
    return -1;
}

int get_path_length(
    const set<Edge>& edges,
    int total_vertices_amount,
    vertex_id start,
    vertex_id end
) {
    set<vertex_id> reached_vertices;
    return find_path(
        reached_vertices, 
        total_vertices_amount, 
        0,
        edges, 
        start, 
        end
    );
}

int main() {
    string str_vertices_amount; cin >> str_vertices_amount;
    int vertices_amount = stoi(str_vertices_amount);
    
    auto edges = input_adjacency_matrix(vertices_amount);
    
    cout << "edges:" << endl << format_edges(edges) << endl;
    
    const auto [start, end] = input_searched_vertices();
    
    cout << "searched_start: " << start << " searched_end: " << end << endl;
    
    int path_length = get_path_length(edges, vertices_amount, start, end);
    
    cout << path_length;
    
    return 0;
}
