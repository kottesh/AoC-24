#include <bits/stdc++.h>

bool validate(const std::vector<int> &report) {
    bool isInc = true, isDec = true;
    for (int i = 1; i < report.size(); i++) {
        if (std::abs(report[i] - report[i-1]) > 3) {
            return false;
        }
        if (report[i] >= report[i-1])
            isInc = false;
        if (report[i] <= report[i-1])
            isDec = false;
    }

    return isInc or isDec;
}

bool revalidate(std::vector<int> report) {
    for (int i = 0; i < report.size(); i++) { 
        std::vector<int> mod_report;

        for (int j = 0; j < report.size(); j++) {
            if (i != j)
                mod_report.push_back(report[j]);
        }

        if (validate(mod_report))
            return true;
    }

    return false;
}

int part_2(std::vector<std::vector<int>> &reports) {
    int count = 0;

    for (const auto& report : reports) {
        if (validate(report) or revalidate(report))
            count++;
    }

    return count;
}

int part_1(const std::vector<std::vector<int>> &reports) {
    int count = 0;

    for (const auto& report : reports) {
        if (validate(report)) {
            count++;
        }
    }

    return count;
}

int main() {
    freopen("../input/2.input", "r", stdin);
    std::vector<std::vector<int>> reports;

    std::string line;
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        std::vector<int> levels;

        int num;
        while (ss >> num)
            levels.push_back(num);
        
        reports.push_back(levels);
    }

    std::cout << part_1(reports) << "\n";
    std::cout << part_2(reports);

    return 0;
}