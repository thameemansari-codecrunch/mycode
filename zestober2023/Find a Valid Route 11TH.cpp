
//Author:S.Thameem Ansari
//including necessary header file
//landmarks is a vector of strings representing the names of the landmarks
//roads is a vector of tuples, where each tuple contains three elements
//We create an unordered map graph to represent the connections between landmarks
//We use permutations to generate all possible orders in which landmarks can be visited
//if these conditions are met, we have found a valid route.
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Function to find a valid route that visits all landmarks exactly once and returns to the starting point
vector<string> findRoute(const vector<string>& landmarks, const vector<tuple<string, string, int>>& roads) {
    // Create a graph to represent connections between landmarks
    unordered_map<string, vector<string>> graph;
    for (const auto& road : roads) {
        string source, destination;
        tie(source, destination, ignore) = road;
        graph[source].push_back(destination);
        graph[destination].push_back(source);
    }

    // Find a valid route using permutations
    vector<string> route = landmarks;
    vector<string> validRoute;
    do {
        bool isValidRoute = true;
        for (size_t i = 0; i < route.size() - 1; ++i) {
            const string& currentLandmark = route[i];
            const string& nextLandmark = route[i + 1];
            if (find(graph[currentLandmark].begin(), graph[currentLandmark].end(), nextLandmark) == graph[currentLandmark].end()) {
                isValidRoute = false;
                break; // No road between current and next landmarks, route is invalid
            }
        }
        if (isValidRoute && find(graph[route.back()].begin(), graph[route.back()].end(), route.front()) != graph[route.back()].end()) {
            validRoute = route; // Valid route found
            break;
        }
    } while (next_permutation(route.begin(), route.end()));

    return validRoute; // Return the valid route
}

int main() {
    // Example landmarks and roads
    vector<string> landmarks = {"Park", "Cafe", "Museum", "Library"};
    vector<tuple<string, string, int>> roads = {
        {"Park", "Museum", 5}, {"Park", "Cafe", 3}, {"Park", "Library", 6},
        {"Museum", "Cafe", 2}, {"Museum", "Library", 4}, {"Cafe", "Library", 7}
    };

    // Find a valid route
    vector<string> route = findRoute(landmarks, roads);

    // Print the route
    if (!route.empty()) {
        cout << "Route: ";
        for (const auto& landmark : route) {
            cout << landmark << " -> ";
        }
        cout << route[0] << endl; // Print the starting landmark to complete the cycle
    } else {
        cout << "No valid route found." << endl;
    }

    return 0;
}
