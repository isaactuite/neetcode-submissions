class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<int, bool>>rows(9);
        vector<unordered_map<int, bool>>columns(9);
        vector<unordered_map<int, bool>>squares(9);

        for (int i = 0; auto& row : board){
            
            for (int j = 0; auto& c : row){
                if (c == '.') {
                    j++;
                    continue;
                }

                if (rows[i].contains(c)){
                    cout << "returned false at "<<i<<j<<"for row";
                    return false;
                }
                else rows[i][c] = true;

                if (columns[j].contains(c)){
                    cout << "returned false at "<<i<<j<<"for column";
                    return false;
                }
                else columns[j][c] = true;

                int index = (i/3)*3 + j/3;
                if (squares[index].contains(c)){
                    cout << "returned false at "<<i<<j<<"for square";
                    return false;
                }
                else squares[index][c] = true;
                j++;
            }
            i++;
        }

        return true;
    }
};
