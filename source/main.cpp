#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/graph_traits.hpp>

#include <iostream>
#include <vector>

using boost::add_edge;
using std::cout;
using std::endl;

// Typedef for DirectedGraph
typedef boost::property<boost::edge_weight_t, int> EdgeWeightProperty;
// Declaring an adjacency list for a directed graph
typedef boost::adjacency_list<boost::listS, boost::vecS, boost::directedS, boost::no_property, EdgeWeightProperty> DirectedGraph;
typedef boost::graph_traits<DirectedGraph>::edge_iterator edge_iterator;
typedef boost::graph_traits<DirectedGraph>::vertex_descriptor vertex_descriptor;

int main() {

    // Weights of edges
    uint a = 3;
    uint b = 5;
    uint c = 2;
    uint d = 4;
    uint e = 3;
    uint f = 1;
    uint g = 4;
    uint h = 3;
    uint i = 3;
    uint j = 2;
    uint k = 5;

    DirectedGraph graph;

    // Adding edges
    add_edge(1, 2, a, graph);
    add_edge(1, 3, b, graph);
    add_edge(2, 3, c, graph);
    add_edge(3, 8, h, graph);
    add_edge(2, 4, d, graph);
    add_edge(4, 5, g, graph);
    add_edge(4, 6, f, graph);
    add_edge(4, 7, e, graph);
    add_edge(5, 6, i, graph);
    add_edge(6, 7, j, graph);
    add_edge(7, 8, k, graph);

    // Iterator for printing
    std::pair<edge_iterator, edge_iterator> ei = edges(graph);

    cout << "Graph successfully created" << endl;
    cout << "Number of edges: " << num_edges(graph) << endl;
    cout << "List of edges: " << endl;
    for (auto it = ei.first; it != ei.second; ++it ) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Vectors for finding shortest path
    std::vector<vertex_descriptor> p(num_vertices(graph));
    std::vector<int> d_vert(num_vertices(graph));

    auto start = vertex(1, graph);
    auto final = vertex(8, graph);

    boost::dijkstra_shortest_paths(graph, start, boost::predecessor_map(&p[0]).distance_map(&d_vert[0]));

    // Shortest path
    std::vector<boost::graph_traits<DirectedGraph>::vertex_descriptor> path;
    auto current = final;

    while (current != start) {
        path.push_back(current);
        current = p[current];
    }

    path.push_back(start);

    cout << "Path from " << 1 << " to " << 8 << endl;
    cout << "Shortest path: ";
    for (auto it = path.rbegin(); it != path.rend(); it++) {
        cout << *it << " ";
    }
    cout << endl << "Shortest path size: " << path.size() << endl;

    return 0;
}
