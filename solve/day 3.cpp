#include <bits/stdc++.h>

using namespace std;

void parser(string &line, vector<string>& tokens) {
    std::regex pattern(R"(mul\(\s*(\d+)\s*,\s*(\d+)\s*\))");

    auto words_begin = std::sregex_iterator(line.begin(), line.end(), pattern);
    auto words_end = std::sregex_iterator();
    
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        tokens.push_back(match[0]);
    }
}

int part_1(vector<string> tokens) {
    int ans = 0;

    for (auto &token : tokens) {
        // mul(23,2); 
        // 012345678
        int x = 0, y = 0;
        int start_1 = 0, start_2 = 0;

        for (int i = 0; i < token.length(); i++) {
            if (token[i] == '(')
                start_1 = i+1;
            if (token[i] == ',')
                start_2 = i+1;
            if (token[i] == ',')
                x = stoi(token.substr(start_1, i - start_1));
            if (token[i] == ')')
                y = stoi(token.substr(start_2, i - start_2));
        }

        ans += (x * y);
    }
    
    return ans;
}

int main() {
    freopen("../input/3.input", "r", stdin);

    vector<string> tokens; 
    string s; 
    while (cin >> s) {
        parser(s, tokens);
    }

    cout << part_1(tokens) << "\n";
    return 0;
}

