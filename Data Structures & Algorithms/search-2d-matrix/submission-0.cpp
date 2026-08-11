#include <vector>

using namespace std;

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m_left = 0;
        int m_right = matrix.size() - 1;

        int row_idx = 0;
        while (m_left <= m_right) {
            int mid = m_left + (m_right - m_left) / 2;
            int s_val = matrix[mid][0];
            int e_val = matrix[mid].back();

            if (s_val == target || e_val == target) {
                return true;
            }

            if (s_val < target && e_val > target) {
                row_idx = mid;
                break;
            }

            if (s_val < target) {
                m_left = mid + 1;
            } else {
                m_right = mid - 1;
            }
        }

        int n_left = 0;
        int n_right = matrix[row_idx].size() - 1;
        while (n_left <= n_right) {
            int mid = n_left + (n_right - n_left) / 2;
            if (matrix[row_idx][mid] == target) {
                return true;
            }

            if (matrix[row_idx][mid] < target) {
                n_left = mid + 1;
            } else {
                n_right = mid - 1;
            }
        }

        return false;
    }
};