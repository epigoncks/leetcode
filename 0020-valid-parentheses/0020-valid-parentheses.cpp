class Solution {
public:
    bool isValid(string s) {
        stack<char> b;

        for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                b.push(c);
            } else{
                if(b.empty()){
                    return false;
                }
                if(c == ')' && b.top() != '(' ||
                   c == '}' && b.top() != '{' ||
                   c == ']' && b.top() != '['){
                    return false;
                   }

                b.pop();
            }

            
        }

        return b.empty();
    }
};