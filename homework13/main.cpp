#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<vector<int>> graph = { {1, 2}, {0, 2, 3}, {0, 1, 4}, {1, 4}, {2, 3} };


void findDatingCouples(int startNode) {
    queue<int> q;
    unordered_set<int> visited;
    unordered_set<pair<int, int>> datingCouples;

    q.push(startNode);
    visited.insert(startNode);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
            }
            else {

                for (int mutualFriend : graph[node]) {
                    if (graph[neighbor].size() > 1 && neighbor != mutualFriend &&
                        find(graph[neighbor].begin(), graph[neighbor].end(), mutualFriend) != graph[neighbor].end()) {

                        pair<int, int> couple = make_pair(node, neighbor);
                        datingCouples.insert(couple);
                        break;
                    }
                }
            }
        }
    }


    for (auto couple : datingCouples) {
        cout << couple.first << " and " << couple.second << " are dating!" << endl;
    }
}

int main() {
    findDatingCouples(0);
    return 0;
}