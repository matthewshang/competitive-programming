#include <iostream>
#include <map>
#include <set>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int M;
    std::cin >> M;
    std::vector<std::vector<int>> packs(M);
    std::map<int, std::vector<int>> Ns;
    for (int i = 0; i < M; i++) {
        int N;
        std::cin >> N;
        Ns[N].push_back(i);
        packs[i].resize(N);
        for (int j = 0; j < N; j++) {
            std::cin >> packs[i][j];
        }
    }

    for (auto&& [N, pos] : Ns) {
        if (pos.size() >= 2) {
            std::cout << "Okayge" << std::endl;
            std::cout << (pos[0] + 1) << " " << (pos[1] + 1) << std::endl;
            return 0;
        }
    }

    std::set<int> used;
    int last_pack = 0;
    for (auto&& [N, pos] : Ns) {
        auto&& pack = packs[pos[0]];
        if (used.empty()) {
            for (int u : pack) {
                used.insert(u);
            }
        } else {
            int contained = 0;
            int last_size = used.size();
            for (int u : pack) {
                contained += used.count(u);
                used.insert(u);
            }
            if (contained != last_size) {
                std::cout << "Okayge" << std::endl;
                std::cout << (pos[0] + 1) << " " << (last_pack + 1) << std::endl;
                return 0;
            }
        }
        last_pack = pos[0];
    }
    std::cout << "Madge" << std::endl;

    return 0;
}