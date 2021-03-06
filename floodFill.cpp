// floodFill.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		if (newColor== image[sr][sc]) return image;
		int t = image[sr][sc];
		image[sr][sc] = newColor;
		if (sr && image[sr - 1][sc] == t) image= floodFill(image, sr - 1, sc, newColor);
		if (sr + 1<image.size() && image[sr + 1][sc] == t) image = floodFill(image, sr + 1, sc, newColor);
		if (sc && image[sr][sc-1] == t) image = floodFill(image, sr, sc-1, newColor);
		if (sc + 1<image[0].size() && image[sr][sc+1] == t) image = floodFill(image, sr, sc+1, newColor);
		return image;
	}
};

int main()
{
	vector<vector<int>> image=
	{
		{ 0, 0, 0 }, { 0, 1, 1 } 
	};
	Solution a;
	a.floodFill(image, 1, 1, 1);
    return 0;
}

