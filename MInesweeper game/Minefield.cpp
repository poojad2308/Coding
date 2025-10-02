#include "Minefield.h"
#include <queue>
using namespace std;

Minefield::Minefield(int w, int h) : width(w), height(h) {
    bomb.assign(height, vector<bool>(width,false));
    revealed.assign(height, vector<bool>(width,false));
    adj.assign(height, vector<int>(width,0));
}

bool Minefield::inBounds(int x,int y) const {
    return x>=0 && x<width && y>=0 && y<height;
}

void Minefield::setBomb(int x,int y) {
    if (!inBounds(x,y) || bomb[y][x]) return;
    bomb[y][x]=true;
    computeAdj();
}

void Minefield::computeAdj() {
    for(int y=0;y<height;y++)
        for(int x=0;x<width;x++) {
            adj[y][x]=0;
            if (bomb[y][x]) continue;
            for(int dy=-1;dy<=1;dy++)
                for(int dx=-1;dx<=1;dx++) {
                    if (dx||dy) {
                        int nx=x+dx, ny=y+dy;
                        if (inBounds(nx,ny) && bomb[ny][nx])
                            adj[y][x]++;
                    }
                }
        }
}

bool Minefield::reveal(int x,int y) {
    if (!inBounds(x,y) || revealed[y][x]) return true;
    revealed[y][x]=true;
    if (bomb[y][x]) return false;
    if (adj[y][x]==0) floodReveal(x,y);
    return true;
}

void Minefield::floodReveal(int sx,int sy) {
    queue<pair<int,int>> q;
    q.push({sx,sy});
    while(!q.empty()) {
        auto [x,y]=q.front(); q.pop();
        for(int dy=-1;dy<=1;dy++)
            for(int dx=-1;dx<=1;dx++) {
                int nx=x+dx, ny=y+dy;
                if (!inBounds(nx,ny)) continue;
                if (!revealed[ny][nx] && !bomb[ny][nx]) {
                    revealed[ny][nx]=true;
                    if (adj[ny][nx]==0)
                        q.push({nx,ny});
                }
            }
    }
}

void Minefield::print(bool gameOver) const {
    std::cout<<"  ";
    for(int x=0;x<width;x++) std::cout<<x;
    std::cout<<"\n";
    for(int y=height-1;y>=0;y--) {
        std::cout<<y<<"|";
        for(int x=0;x<width;x++) {
            if (revealed[y][x]) {
                if (bomb[y][x]) std::cout<<"X";
                else if (adj[y][x]==0) std::cout<<" ";
                else std::cout<<adj[y][x];
            } else {
                if (gameOver && bomb[y][x]) std::cout<<"X";
                else std::cout<<"?";
            }
        }
        std::cout<<"\n";
    }
}

bool Minefield::allSafeRevealed() const {
    for(int y=0;y<height;y++)
        for(int x=0;x<width;x++)
            if (!bomb[y][x] && !revealed[y][x])
                return false;
    return true;
}
