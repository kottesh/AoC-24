#include <bits/stdc++.h>

using namespace std;

void parser(const string& line, const string& regx, vector<string>& tokens) {
    regex pattern(regx);

    auto words_begin = sregex_iterator(line.begin(), line.end(), pattern);
    auto words_end = sregex_iterator();
    
    for (sregex_iterator i = words_begin; i != words_end; ++i) {
        smatch match = *i;
        tokens.push_back(match[0]);
    }
}

int findProduct(const string& token) {
    int x = 0, y = 0;
    int start_1 = 0, start_2 = 0;

    for (int i = 0; i < token.length(); i++) {
        // mul(23,2); 
        // 012345678
        if (token[i] == '(') {
            start_1 = i+1;
        }
        if (token[i] == ',') {
            start_2 = i+1;
        }
        if (token[i] == ',') {
            x = stoi(token.substr(start_1, i - start_1));
        }
        if (token[i] == ')') {
            y = stoi(token.substr(start_2, i - start_2));
        }
    }

    return x * y;
}

int part1(const vector<string>& tokens) {
    int ans = 0;

    for (auto &token : tokens) {
        ans += findProduct(token);
    }
    
    return ans;
}


int part2(const vector<string>& tokens) {
    int sum = 0;

    string skip = "";
    for (const auto &it : tokens) {
        if (it == "don't()") {
            skip = "don't()";
        } else if (it == "do()") {
            skip = "";
        }

        if (skip != "don't()" and it != "do()") {
            sum += findProduct(it);
        }
    }

    return sum;
}

int main() {
    freopen("../input/3.input", "r", stdin);

    string s; 

    vector<string> tokens_1; 
    vector<string> tokens_2; 

    string pattern_1 = R"(mul\(\s*(\d+)\s*,\s*(\d+)\s*\))";
    string pattern_2 = R"(mul\(\s*(\d+)\s*,\s*(\d+)\s*\)|do\(\)|don't\(\))";  

    while (cin >> s) {
        parser(s, pattern_1, tokens_1);
        parser(s, pattern_2, tokens_2);
    }

    cout << part1(tokens_1) << "\n";
    cout << part2(tokens_2) << "\n";

    return 0;
}

