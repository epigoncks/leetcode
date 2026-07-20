class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> c;
        int n = tokens.size();
        int i = 2;
        int ans = 0;

        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "*" || tokens[i] == "/" || tokens[i] == "-"){
                int f = (c.top());
                c.pop();
                int s = (c.top());
                c.pop();
                if (tokens[i] == "+")
                    c.push(s + f);
                    
                else if (tokens[i] == "-")
                    c.push(s - f);
                    
                else if (tokens[i] == "*")
                    c.push(s * f);
                    
                else
                    c.push(s / f);
            }
            else{
                c.push(stoi(tokens[i]));
            }
        }
        return c.top();
    }
};