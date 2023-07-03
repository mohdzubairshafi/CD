#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    string name;
    vector<Node *> children;
};

struct Graph
{
    vector<Node *> nodes;
};

Node *create_node(string name)
{
    Node *node = new Node();
    node->name = name;
    return node;
}

void add_edge(Graph *graph, Node *parent, Node *child)
{
    parent->children.push_back(child);
}

void generate_sdt(Graph *graph)
{
    for (auto node : graph->nodes)
    {
        for (auto child : node->children)
        {
            cout << node->name << " -> " << child->name << endl;
        }
    }
}

int main()
{
    Graph *graph = new Graph();
    Node *a = create_node("A");
    Node *b = create_node("B");
    Node *c = create_node("C");
    Node *d = create_node("D");
    Node *e = create_node("E");

    add_edge(graph, a, b);
    add_edge(graph, a, c);
    add_edge(graph, b, d);
    add_edge(graph, c, e);

    graph->nodes.push_back(a);
    graph->nodes.push_back(b);
    graph->nodes.push_back(c);
    graph->nodes.push_back(d);
    graph->nodes.push_back(e);

    generate_sdt(graph);

    return 0;
}
