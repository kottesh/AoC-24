#include <bits/stdc++.h>

int part_1(std::vector<int> locations_1, std::vector<int> locations_2) {
    std::sort(locations_1.begin(), locations_1.end());
    std::sort(locations_2.begin(), locations_2.end());

    int distance = 0;
    for (int i = 0; i < locations_1.size(); i++)
        distance += std::abs(locations_1[i] - locations_2[i]);
    
    return distance;
}

int part_2(std::vector<int> &locations, std::unordered_map<int, int> &locations_freq) {
    int similarity_score = 0;

    for (const auto& loc : locations)
        similarity_score += loc * locations_freq[loc];

    return similarity_score;
}

int main () {
    freopen("../../input/1.input", "r", stdin);
    
    std::vector<int> locations_1;
    std::vector<int> locations_2;
    std::unordered_map<int, int> store;
    
    std::string line;
    while (std::getline(std::cin, line)) {
        int num1, num2;
        std::stringstream curr(line);

        while (curr >> num1 >> num2) {
            locations_1.push_back(num1);
            locations_2.push_back(num2);
            store[num2]++;
        }
    }

    std::cout << part_1(locations_1, locations_2) << "\n";
    std::cout << part_2(locations_1, store);

    return 0;
}

