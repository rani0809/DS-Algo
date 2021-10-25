class Solution {
public:
    void findPath(string currNode, list <string> &path, map <string, 
                    vector <string>>& graph, map <string, int> &outDegree)
    {
	    while (outDegree[currNode]) {
            findPath(graph[currNode][--outDegree[currNode]],path, graph, outDegree);
	    }
	    path.push_front(currNode);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        list <string> path;
	    string startNode = "JFK";
	    map <string, vector <string>> graph;
        map <string, int> outDegree;

	    for (auto e : tickets) {
		    graph[e[0]].push_back(e[1]);
		    outDegree[e[0]]++;
	    }
       
        for (auto &g: graph) {
            sort(g.second.begin(), g.second.end(), greater<string>());
        }

	    findPath(startNode, path, graph, outDegree);
	    return vector <string> (path.begin(), path.end());
    }
};