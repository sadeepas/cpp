#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 5;

int dx[] = {0, 1, 0, -1,0};
int dy[] = {1, 0, -1, 0, 0};

struct Point {
    int x;
    int y;
};

bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

int bfs(vector<vector<char>>& grid) {
    queue<Point> q;
    vector<vector<bool>> visited(N, vector<bool>(N));
    Point start = {0, 0};
    q.push(start);
    visited[0][0] = true;
    int count = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Point curr = q.front();
            q.pop();
            if (grid[curr.x][curr.y] == 'd') {
                grid[curr.x][curr.y] = '-';
                cout << "Clean" << endl;
                return count;
            }
            for (int j = 0; j < 5; j++) {
                int nx = curr.x + dx[j];
                int ny = curr.y + dy[j];
                if (isValid(nx, ny) && !visited[nx][ny] && grid[nx][ny] != '-') {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        count++;
    }
    return count;
}

void moveRobot(Point& currPos, Point& nextPos) {
    if (nextPos.x > currPos.x) {
        cout << "Down" << endl;
    } else if (nextPos.x < currPos.x) {
        cout << "Up" << endl;
    } else if (nextPos.y > currPos.y) {
        cout << "Right" << endl;
    } else if (nextPos.y < currPos.y) {
        cout << "Left" << endl;
    }
}

void cleanRoom(vector<vector<char>>& grid) {
    while (true) {
        int steps = bfs(grid);
        if (steps == N * N) break;
        Point currPos = {0, 0};
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 'b') {
                    currPos.x = i;
                    currPos.y = j;
                    break;
                }
            }
        }
        for (int i = 0; i < steps; i++) {
            vector<Point> candidates;
            for (int j = 0; j < 5; j++) {
                int nx = currPos.x + dx[j];
                int ny = currPos.y + dy[j];
                if (isValid(nx, ny) && grid[nx][ny] == 'd') {
                    candidates.push_back({nx, ny});
                }
            }
            Point nextPos = candidates[0];
            int minDist = abs(currPos.x - nextPos.x) + abs(currPos.y - nextPos.y);
            for (int j = 1; j < candidates.size(); j++) {
                Point candidate = candidates[j];
                int dist = abs(currPos.x - candidate.x) + abs(currPos.y - candidate.y);
                if (dist < minDist) {
                    minDist = dist;
                    nextPos = candidate;
                }
            }
            moveRobot(currPos, nextPos);
            currPos = nextPos;
        }
    }
}

int main() {
    vector<vector<char>> grid = {
        {'b', '-', '-', '-', 'd'},
        {'-', 'd', '-', '-', 'd'},
        {'-', '-', 'd', 'd', '-'},
        {'-', '-', 'd', '-', '-'},
        {'-', '-', '-', '-', 'd'}
    };
    cleanRoom(grid);
    return 0;
}