#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int>> rules;
vector<vector<int>> updates;
vector<vector<int>> incorrect_updates;

int part_1() {
    int sum = 0; 

    for (auto& update : updates) {
        for (int i = 1; i < update.size(); i++) {
            if (find(rules[update[i]].begin(), rules[update[i]].end(), update[i-1]) == rules[update[i]].end()) {
                incorrect_updates.push_back(update);
                update.clear();
                break; 
            }
        }
        if (!update.empty()) {
            sum += update[update.size() / 2];
        }
    }

    return sum;
}

void fixUpdate(vector<int> &update, int i, int j) {
    if (j != update.size()) {

        if (find(rules[update[j]].begin(), rules[update[j]].end(), update[i]) == rules[update[j]].end()) {
            swap(update[i], update[j]);
        }

        fixUpdate(update, i, j+1);
    }
}

int part_2() {
    int sum = 0;

    for (auto& update : incorrect_updates) {
        for (int i = 0; i < update.size() - 1; i++) {
            fixUpdate(update, i, i + 1);
        }
        sum += update[update.size() / 2];
    }

    return sum;
}

int main() {
    freopen("../input/5.input", "r", stdin);

    string line;

    while (getline(cin, line) and !line.empty()) {
        int x, y;
        
        int pos = line.find('|');

        x = stoi(line.substr(0, pos));
        y = stoi(line.substr(pos + 1));

        rules[y].push_back(x);
    }

    while (getline(cin, line)) {
        stringstream ss(line);
        string num;
        vector<int> update;

        while (getline(ss, num, ',')) {
            update.push_back(stoi(num)); 
        }
        
        updates.push_back(update);
    }

    cout << part_1() << "\n";
    cout << part_2() << "\n";
    
    // for debugging purposes

    //for (auto update : incorrect_updates) {
    //    for (int page : update) {
    //        cout << page << ", ";
    //    }
    //    cout << "\n";
    //}

    //for (auto& [key, item] : rules) {
    //    cout << key << ": " ;
    //    for (auto num : item) {
    //        cout << num << ", ";
    //    }

    //    std::cout << "\n";
    //}

    return 0;
}

