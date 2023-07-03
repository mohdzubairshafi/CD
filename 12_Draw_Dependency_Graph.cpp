#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class DependencyGraph
{
public:
    void addDependency(const string &from, const string &to)
    {
        dependencies[from].insert(to);
    }
    void printDependencies() const
    {
        cout << "Dependency graph:" << endl;
        for (const auto &entry : dependencies)
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
    unordered_map<string, unordered_set<string>> dependencies;
};
int main()
{
    DependencyGraph dependencyGraph;
    dependencyGraph.addDependency("A", "B");
    dependencyGraph.addDependency("A", "C");
    dependencyGraph.addDependency("A", "D");
    dependencyGraph.addDependency("C", "E");
    dependencyGraph.addDependency("D", "E");
    dependencyGraph.printDependencies();
    return 0;
}
