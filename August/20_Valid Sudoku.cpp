class Solution {
public:
	bool check_subbox(vector<vector<char>>& board) {
		for (int i = 0; i < n; i += 3) {
            for (int j = 0; j < n; j += 3) {
                int freq[9] = {0};
                
                for (int r = 0; r < n / 3; r++) {
                    for (int c = 0; c < n / 3; c++) {
						int x = r + i;
						int y = c + j;
                        if (board[x][y] == '.') {
                            continue;
                        }
                        
                        freq[board[x][y] - '1']++;
                        if (freq[board[x][y] - '1'] > 1) {
                            return false;
                        }
                    }    
                }
            }
        }
        
        return true;
	}
	
	bool check_row(vector<vector<char>>& board) {
		for (int j = 0; j < n; j++) {
            int freq[9] = {0};
            for (int i = 0; i < n; i++) {
                if (board[i][j] == '.') {
                    continue;
                }
                
                int indx = board[i][j] - '1';
                freq[indx]++;
                if (freq[indx] > 1) {
                    return false;
                }
            }
        }
        return true;
	}
	
	bool check_column(vector<vector<char>>& board) {
	    for (int i = 0; i < n; i++) {
            int freq[9] = {0};
            for (int j = 0; j < n; j++) {
				if (board[i][j] == '.') {
                    continue;
                }
                
                int indx = board[i][j] - '1';
                freq[indx]++;
                if (freq[indx] > 1) {
                    return false;
                }
            }
        }
        return true;
	}
	
    bool isValidSudoku(vector<vector<char>>& board) {
		if (check_column(board) && check_row(board) && check_subbox(board)) {
			return true;
		}
		
		return false;
    }
};
