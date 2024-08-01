#include <fstream>
#include <iostream>
using namespace std;

#include "GPU/graph_v_of_v/graph_v_of_v_generate_random_graph_test.h"
#include "GPU/graph_v_of_v/graph_v_of_v_update_vertexIDs_by_degrees_large_to_small.h"
#include "GPU/build_in_progress/HL/HL4GST/HOP_maintain/HOP_maintain_hop_constrained_two_hop_labels.h"
#include "GPU/build_in_progress/HL/HL4GST/HOP_maintain/HOP_maintain_hop_constrained_two_hop_labels_generation.h"
/**
 * A- 3 -B- 3 -E
 * | \   |   / |
 * 6  2  1  5  2
 * |   \ |  |  |
 * F- 2 -D  |  c
 *   \——————
 */

graph_v_of_v<int> buildDefaultGraph()
{
    graph_v_of_v<int> graph = graph_v_of_v<int>(6);
    graph.add_edge(0, 1, 3);
    graph.add_edge(0, 3, 2);
    graph.add_edge(0, 5, 6);
    graph.add_edge(1, 3, 1);
    graph.add_edge(1, 4, 3);
    graph.add_edge(2, 4, 2);
    graph.add_edge(2, 5, 3);
    graph.add_edge(3, 4, 1);
    graph.add_edge(3, 5, 2);
    graph.add_edge(4, 5, 5);
    return graph;
}

int main()
{
    /* generate a graph with 100 V and 500 E and random weight between 1-20 */
    graph_v_of_v graph = buildDefaultGraph();
    vector<int> is_mock(graph.size());
    for(int i=0;i<graph.size();i++){
        is_mock[i] = false;
    }
    graph = graph_v_of_v_update_vertexIDs_by_degrees_large_to_small_mock(graph, is_mock);
    /* hop bounded info */
    hop_constrained_case_info mm;
    mm.upper_k = 10;
    mm.max_bit_size = 6e9;
    mm.use_2M_prune = 1;
    mm.use_rank_prune = 1; // set true
    mm.use_2023WWW_generation = 0;
    mm.use_canonical_repair = 0;
    mm.max_run_time_seconds = 1e2;
    mm.thread_num = 2;
    hop_constrained_two_hop_labels_generation(graph, mm);
    graph.print();
    mm.print_L();
    mm.print_PPR();
}