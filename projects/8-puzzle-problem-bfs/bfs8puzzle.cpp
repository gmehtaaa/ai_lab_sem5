#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>

using namespace std;

bool is_soln(vector<vector<int>> state) {
    vector<vector<int>> soln = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    return state == soln;
}

pair<int, int> findblank(const vector<vector<int>>& state) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (state[i][j] == 0)
                return make_pair(i, j);
    return make_pair(-1, -1);
}

vector<vector<vector<int>>> genmoves(vector<vector<int>> state) {
    vector<vector<vector<int>>> moves;
    pair<int, int> zeroPos = findblank(state);
    int x = zeroPos.first;
    int y = zeroPos.second;

    if (x > 0) {
        swap(state[x][y], state[x - 1][y]);
        moves.push_back(state);
        swap(state[x][y], state[x - 1][y]);
    }
    if (x < 2) {
        swap(state[x][y], state[x + 1][y]);
        moves.push_back(state);
        swap(state[x][y], state[x + 1][y]);
    }
    if (y > 0) {
        swap(state[x][y], state[x][y - 1]);
        moves.push_back(state);
        swap(state[x][y], state[x][y - 1]);
    }
    if (y < 2) {
        swap(state[x][y], state[x][y + 1]);
        moves.push_back(state);
        swap(state[x][y], state[x][y + 1]);
    }

    return moves;
}

void bfsQueue(vector<vector<int>> problem) {
    set<string> visited;
    queue<pair<vector<vector<int>>, vector<vector<vector<int>>>>> q;
    q.push(make_pair(problem, vector<vector<vector<int>>>()));

    while (!q.empty()) {
        auto frontElement = q.front();
        q.pop();

        vector<vector<int>> curr = frontElement.first;
        vector<vector<vector<int>>> path = frontElement.second;

        string key = "";
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                key += to_string(curr[i][j]);

        if (visited.count(key) > 0) continue;
        visited.insert(key);

        path.push_back(curr);

        if (is_soln(curr)) {
            cout << "\n--- Solution Found ---\n";
            for (int k = 0; k < path.size(); ++k) {
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j)
                        cout << path[k][i][j] << " ";
                    cout << endl;
                }
                cout << "---\n";
            }
            return;
        }

        vector<vector<vector<int>>> moves = genmoves(curr);
        for (int i = 0; i < moves.size(); ++i) {
            string move_key = "";
            for (int r = 0; r < 3; ++r)
                for (int c = 0; c < 3; ++c)
                    move_key += to_string(moves[i][r][c]);

            if (visited.count(move_key) == 0) {
                q.push(make_pair(moves[i], path));
            }
        }
    }

    cout << "No solution found.\n";
}

int main() {
    cout << "Enter the puzzle values (0 for blank), row-wise:\n";

    vector<vector<int>> problem(3, vector<int>(3));
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> problem[i][j];

    cout << "\nProblem Matrix:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            cout << problem[i][j] << " ";
        cout << endl;
    }

    bfsQueue(problem);

    return 0;
}
