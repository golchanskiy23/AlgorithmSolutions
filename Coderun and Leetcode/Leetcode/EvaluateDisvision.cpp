class Solution {
public:
    std::map<std::string, std::vector<std::pair<std::string, double>>> m;
    double dist = 1.0;

    bool dfs(const std::string& start, const std::string& end, std::unordered_set<std::string>& u){
        if(start == end && m[start].size() != 0){
            return true;
        }
        u.insert(start);
        for(auto& a : m[start]){
            if(!u.count(a.first)){
                if(dfs(a.first, end, u)) {
                    dist *= a.second;
                    return true;
                }
            }
        }
        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i = 0;i  < equations.size(); i++){
            std::string from=equations[i][0],to=equations[i][1];
            m[from].push_back({to, values[i]});
            m[to].push_back({from, 1.0 / values[i]});
        }
        std::vector<double> ans;

        for(int i = 0; i < queries.size(); i++){
            std::string start=queries[i][0], end=queries[i][1];
            dist = 1.0;
            std::unordered_set<std::string> visited;
            if (!dfs(start, end, visited)){
                ans.push_back(-1.0);
            } else{
                ans.push_back(dist);
            }
        }
        return ans;
    }
};