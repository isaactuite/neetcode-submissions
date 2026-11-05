class Solution {
public:
    bool isPalindrome(string s) {
        int j = s.size()-1;
        for (int i = 0; i<j; i++){

            while (!isalnum(s[i])) {
                i++;
                if (i>j) return true;
            }
            while (!isalnum(s[j])){
                j--;
                if (i>j) return true;
            } 
            cout << s[i] << " " << s[j]<<endl;
            if (tolower(s[i])!=tolower(s[j])) return false;
            j--;
        }

        return true;
    }
};
