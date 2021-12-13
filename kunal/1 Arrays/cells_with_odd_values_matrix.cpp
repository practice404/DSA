// https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {

	vector<int> row(m);
	vector<int> col(n);

	int odd_count = 0;

	for(auto i : indices)
	{
		row[i[0]]++;
		col[i[1]]++;
	}

	int odd_rows = 0;
	int even_rows = 0;

	for(auto i : row)
		if(i%2)
			odd_rows++;
		else
			even_rows++;

	odd_count += n*odd_rows;

    // plan is: original odd_cont + newly_created_odds - odd_common_cells;
	for(auto i : col)
	{
		if(i%2)
		{
			odd_count = odd_count + even_rows - odd_rows;
		}
		else
		{
			odd_count = odd_count + odd_rows - odd_rows;
		}
	}

	return odd_count;
    }
};