class Solution {
public:
    bool isValid(string st) {
        int n=st.size();
        stack<char>s;
        for(char c:st){
            if (c=='}' || c == ')' || c == ']') {
                if (s.empty()) return false;
                char top = s.top();
                if ((c == '}' && top != '{') || 
                    (c == ')' && top != '(') || 
                    (c == ']' && top != '[')) {
                    return false;
                }
                s.pop();
            } else s.push(c);
        }
        return s.empty();
    }
};
