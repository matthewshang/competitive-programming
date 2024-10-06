#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<std::pair<int, int>> pos;
    std::vector<std::pair<int, int>> dir;
    
    int M, N;
    std::cin >> M >> N;
    std::vector<std::string> g(M);
    for (int i = 0; i < M; i++) {
        std::cin >> g[i];
        for (int j = 0; j < N; j++) {
            if (g[i][j] == 'C') {
                int vy = (i == 0) ? 1 : ((i == M - 1) ? -1 : 0);
                int vx = (j == 0) ? 1 : ((j == N - 1) ? -1 : 0);
                pos.emplace_back(i * 2, j * 2);
                dir.emplace_back(vy, vx);
                g[i][j] = 'X';
            }
        }
    }

    int ans_bells = 0;
    int ans_holy = 0;
    std::map<std::pair<int, int>, int> pos_to_idx;
    std::set<int> rem;
    for (int step = 1; !pos.empty(); step++) {
        for (int i = 0; i < int(pos.size()); i++) {
            pos[i].first += dir[i].first;
            pos[i].second += dir[i].second;
            if (auto it = pos_to_idx.find(pos[i]); it != pos_to_idx.end()) {
                rem.insert(i);
                rem.insert(it->second);
            } else if (step % 2 == 0 && g[pos[i].first / 2][pos[i].second / 2] == 'X') {
                rem.insert(i);
            }
            pos_to_idx[pos[i]] = i;
        }

        std::vector<std::pair<int, int>> new_pos;
        std::vector<std::pair<int, int>> new_dir;
        for (int i = 0; i < int(pos.size()); i++) {
            if (rem.count(i)) {
                continue;
            }

            if (step % 2 == 1) {
                new_pos.push_back(pos[i]);
                new_dir.push_back(dir[i]);
                continue;
            }

            int y = pos[i].first / 2;
            int x = pos[i].second / 2;
            if (g[y][x] == 'D') {
                ans_holy++;
            } else if (g[y][x] == 'B') {
                ans_bells++;
                g[y][x] = 'X';
                auto [vy, vx] = dir[i];
                new_pos.push_back(pos[i]);
                new_dir.push_back({-vx, vy});
                new_pos.push_back(pos[i]);
                new_dir.push_back({vx, -vy});
            } else {
                new_pos.push_back(pos[i]);
                new_dir.push_back(dir[i]);
            }
        }

        pos = std::move(new_pos);
        dir = std::move(new_dir);

        pos_to_idx.clear();
        rem.clear();
    }
    std::cout << ans_bells << " " << ans_holy << std::endl;

    return 0;
}