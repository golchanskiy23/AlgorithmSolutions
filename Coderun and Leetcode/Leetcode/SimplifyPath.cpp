class Solution {
public:
    string simplifyPath(string path) {
        std::stack<std::string> stack;
        std::stringstream ss(path);
        std::string token, ans;

        while (getline(ss, token, '/')) {
            std::cout << token << "\t";
            if (token == "" || token == ".") 
                continue;

            if (token == "..") {
                if (!stack.empty()) 
                    stack.pop();
            } else {
                stack.push(token);
            }
        }

        while (!stack.empty()) {
            ans = "/" + stack.top() + ans;
            stack.pop();
        }

        return ans.empty() ? "/" : ans;
    }
};