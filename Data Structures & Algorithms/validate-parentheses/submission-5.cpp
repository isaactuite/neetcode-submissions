class Solution {
public:
    bool isValid(string s) {
        if (s.size()%2!=0)return false;
        stack<char> st;
        unordered_set<char> openers = {'(', '{', '['};
        unordered_set<char> closers = {')', '}', ']'};
        for (int i = 0; i<s.size(); i++){

            char c1 = s[i];
            char c2;

            if (openers.contains(c1)){
                st.push(c1);
            }
            else if (closers.contains(c1)){
                if (st.empty()) return false;
                c2=st.top();
                st.pop();
                if ((c2 == '(' && c1!= ')') || (c2 == '{' && c1!= '}' )|| (c2 == '[' && c1!= ']')){
                    cout << "c1 is " << c1 << " and c2 is " << c2;
                    return false;
                }
            }

        }
        if (st.empty()){
            return true;
        } else{
            return false;
        }
    }
};
