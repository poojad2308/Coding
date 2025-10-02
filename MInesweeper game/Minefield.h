#pragma once
#include <iostream>
#include <vector>

class Minefield {
public:
    Minefield(int w, int h);

    void setBomb(int x, int y);
    bool reveal(int x, int y);   // returns false if bomb hit
    void print(bool gameOver=false) const;
    bool allSafeRevealed() const;

private:
    int width, height;
    std::vector<std::vector<bool>> bomb;
    std::vector<std::vector<bool>> revealed;
    std::vector<std::vector<int>> adj;

    bool inBounds(int x,int y) const;
    void computeAdj();
    void floodReveal(int x,int y);
};
