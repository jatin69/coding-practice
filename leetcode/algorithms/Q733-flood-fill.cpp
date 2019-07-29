/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor){
        if(image[sr][sc] == oldColor){
            image[sr][sc] = newColor;
            if(sr-1 >= 0) { backtrack(image, sr-1, sc, oldColor, newColor); }
            if(sr+1 < image.size()) { backtrack(image, sr+1, sc, oldColor, newColor); }
            if(sc-1 >= 0) { backtrack(image, sr, sc-1, oldColor, newColor); }
            if(sc+1 < image[0].size()) { backtrack(image, sr, sc+1, oldColor, newColor); }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if(oldColor != newColor){
            backtrack(image, sr, sc, oldColor, newColor);
        }
        return image;
    }
};

