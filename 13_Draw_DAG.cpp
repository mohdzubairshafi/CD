#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class DAG
{
public:
    void addNode(const string &nodeName)
    {
        if (nodes.find(nodeName) == nodes.end())
        {
            nodes[nodeName] = unordered_set<string>();
        }
    }
    void addDependency(const string &from, const string &to)
    {
        nodes[from].insert(to);
    }
    void printDependencies() const
    {
        cout << "Dependency graph:" << endl;
        for (const auto &entry : nodes)
        {
            const string &from = entry.first;
            const unordered_set<string> &toSet = entry.second;
            for (const string &to : toSet)
            {
                cout << from << " -> " << to << endl;
            }
        }
    }

private:
    unordered_map<string, unordered_set<string>> nodes;
};
int main()
{
    DAG dag;
    dag.addNode("A");
    dag.addNode("B");
    dag.addNode("C");
    dag.addNode("D");
    dag.addNode("E");
    dag.addDependency("A", "B");
    dag.addDependency("A", "C");
    dag.addDependency("B", "D");
    dag.addDependency("C", "D");
    dag.addDependency("D", "E");
    dag.printDependencies();
    return 0;
}
