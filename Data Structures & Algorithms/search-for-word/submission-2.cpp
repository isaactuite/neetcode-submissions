class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        set<vector<int>> v;
        for (int i = 0; i<board.size(); i++){
            for (int j = 0; j <board[0].size(); j++){
                if (backtrack(board, word, i, j, 0, v)){
                    return true;
                }
            }
        }
        return false;
    }


    bool backtrack(vector<vector<char>>& board, const string& word, int i, int j, int word_index, set<vector<int>>& visited_indices){
        if (board[i][j] == word.back() && word_index == word.size()-1 && !visited_indices.contains({i,j})){

            return true;
        }
        if (board[i][j] == word[word_index] && !visited_indices.contains({i,j})){
            visited_indices.insert({i,j});
            if (i-1 >= 0 && backtrack(board, word, i-1, j, word_index+1,visited_indices)){
                return true;
            }
            if (i+1 < board.size() && backtrack(board, word, i+1, j, word_index+1,visited_indices)){
                return true;
            }
            if (j-1 >= 0 && backtrack(board, word, i, j-1, word_index+1,visited_indices)){
                return true;
            }
            if (j+1 < board[0].size() && backtrack(board, word, i, j+1, word_index+1,visited_indices)){
                return true;
            }
            visited_indices.erase({i,j});
        }

        return false;
    }
};