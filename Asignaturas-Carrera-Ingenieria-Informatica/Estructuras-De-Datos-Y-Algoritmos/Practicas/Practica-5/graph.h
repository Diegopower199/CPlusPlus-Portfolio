#ifndef GRAPH_H
#define GRAPH_H

#include <memory>
#include <functional>
#include <ostream>
#include <iostream>
#include <queue>
#include <array>

using namespace std;

template <int N>
class Graph
{
public:
    Graph();

    void add_node(int node, const std::string &dato_node);

    void remove_node(int node);

    bool add_edge(int origin, int target, int dato_edge);

    void remove_edge(int origin, int target);

    template <int NN>
    friend std::ostream &operator<<(std::ostream &os, const Graph<NN> &graph);

    int find_node(const std::string &dato_node) const;
    const std::string &get_node(int node) const;

    Graph mst_prim() const;
    std::vector<int> adj(int node) const;

    bool are_connected(string city1, string city2) const;
    void bfs(std::function<void(int &, std::string &)> action);

    Graph<N> telephone() const;
    int sum_kilometers() const;

    int num_components() const;

protected:
    std::array<std::shared_ptr<std::string>, N> nodes;
    std::array<std::array<std::shared_ptr<int>, N>, N> edges;
};

template <int N>
Graph<N>::Graph()
{
    // Nodes
    for (int i = 0; i < N; i++)
    {
        nodes.at(i) = nullptr;
    }

    // Edges
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            edges.at(i).at(j) = nullptr;
        }
    }
}

template <int N>
void Graph<N>::add_node(int node, const std::string &dato_node)
{
    auto dato = std::make_shared<std::string>(dato_node);
    nodes.at(node) = dato;
}

template <int N>
void Graph<N>::remove_node(int node)
{
    nodes.at(node) = nullptr;

    for (int i = 0; i < N; i++)
    {
        this->remove_edge(node, i);
    }
}

template <int N>
bool Graph<N>::add_edge(int origin, int target, int dato_edge)
{
    // Check if nodes exists:
    if (!nodes.at(origin) || !nodes.at(target))
    {
        return false;
    }
    auto edge = std::make_shared<int>(dato_edge);
    edges.at(origin).at(target) = edge;
    edges.at(target).at(origin) = edge;
    return true;
}

template <int N>
void Graph<N>::remove_edge(int origin, int target)
{
    edges.at(origin).at(target) = nullptr;
    edges.at(target).at(origin) = nullptr;
}

template <int N>
int Graph<N>::find_node(const std::string &dato_node) const
{
    for (int i = 0; i < N; i++)
    {
        if (this->get_node() == dato_node)
        {
            return this->get_node();
        }
    }
}

template <int N>
Graph<N> Graph<N>::mst_prim() const
{
    // Distance from the MST already computed to the node indicated by the index
    std::array<int, N> distances;
    // Node inside the MST that is closer to node-at-index
    std::array<int, N> origins;
    std::array<bool, N> added;
    // Initialize
    for (int i = 0; i < N; i++)
    {
        distances[i] = std::numeric_limits<int>::max();
        origins[i] = -1;
        added[i] = false;
    }

    distances[0] = 0;
    while (!all_of(added.begin(), added.end(), [](bool item)
                   { return item; }))
    {

        auto result = min_element(distances.begin(), distances.end());
        auto idx = std::distance(distances.begin(), result);
        added[idx] = true;
        distances[idx] = std::numeric_limits<int>::max();

        for (int i = 0; i < N; i++)
        {
            if (!added[i] && edges[idx][i] != nullptr)
            {
                if (distances[i] > *edges[idx][i])
                {
                    distances[i] = *edges[idx][i];
                    origins[i] = idx;
                }
            }
        }
    }

    Graph<N> ret;
    for (int i = 1; i < N; i++)
    {
        auto origin = origins[i];
        std::cout << origin << " -> " << i << std::endl;
        ret.add_edge(origin, i, *edges[origin][i]);
    }
    return ret;
}

template <int NN>
std::ostream &operator<<(std::ostream &os, const Graph<NN> &graph)
{
    os << "\n\n\nCiudades";
    for (auto elem : graph.nodes)
    {
        os << *elem << "\n";
    }

    os << "|";
    for (int i{0}; i < NN; i++)
    {
        os << " " << i;
    }
    std::cout << "\n";

    for (int fila = 0; fila < NN; fila++)
    {
        os << fila << " | ";
        for (int columna = 0; columna < NN; columna++)
        {
            if (graph.edges[fila][columna] == nullptr)
            {
                os << "0" << " ";
            }
            else
            {
                os << *graph.edges[fila][columna] << " ";
            }
        }
        os << "\n";
    }

    return os;
}

template <int N>
bool Graph<N>::are_connected(string city1, string city2) const
{

    int pos1{0};
    int pos2{0};

    for (int j{0}; j < nodes.size(); j++)
    {
        if (*nodes[j] == city1)
        {
            pos1 = j;
        }
        else if (*nodes[j] == city2)
        {
            pos2 = j;
        }
    }

    if (edges[pos1][pos2] != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <int N>
int Graph<N>::num_components() const
{
    return nodes.size();
}

template <int N>
Graph<N> Graph<N>::telephone() const
{
}

template <int N>
int Graph<N>::sum_kilometers() const
{
    int sumKilometers = sumKilometers + mst_prim();
    return sumKilometers;
}

#endif
