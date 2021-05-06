class Solution
{
public:

    int recurse(vector<vector<int>>& graph, bool visited1[], bool visited2[], int n) { //bfs for CC count
        if (graph[n].size() >= 1) {
            visited1[n] = true;       
            for (int i = 0; i < graph[n].size(); ++i) {
                if (visited2[graph[n][i]] == false) {
                    recurse(graph, visited2, visited1, graph[n][i]);
                }
            }
            return 0;
        }
        
        else {
            visited1[n] = true;
            return 0;
        }
        
        
    }

    bool isBipartite(vector<vector<int>>& graph)
    {


        bool Gcheck[286] = {false};
        bool GprimeCheckL[286]= {false};
        bool GprimeCheckR[286]= {false};
        
        int Gprime = 0; 
        int G = 0;
        
        for (int i = 0; i < graph.size(); ++i) {
            if (GprimeCheckL[i] == false) 
            {
                recurse(graph, GprimeCheckL, GprimeCheckR, i);
                Gprime++;     // track CC in G'
            }
            if (GprimeCheckR[i] == false) {
                recurse(graph, GprimeCheckR, GprimeCheckL, i);
                Gprime++;     // track CC in G'
            }
        }

        for (int i = 0; i < graph.size(); ++i) {
            if (Gcheck[i] == false) {
                recurse(graph, Gcheck, Gcheck, i);
                G++;          // track CC in G
            }
        }
        
        if (Gprime == 2*G) {
            //theory 1
            return true;
        }  
        
        return false;
    }
};
