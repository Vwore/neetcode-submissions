class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        int n = s.size();

        for(int i =0 ;i< n; i++)
        {
            char c = s[i];
            if(c== '}'|| c== ']' || c== ')')
            {
                if(st.empty()) return false;
                if(c== '}')
                {
                    if(st.top()=='{')
                    {
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else if(c== ']')
                {
                    if(st.top()=='[')
                    {
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else if(c== ')')
                {
                    if(st.top()=='(')
                    {
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
            else{
                st.push(c);
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};
