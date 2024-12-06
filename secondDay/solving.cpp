#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>

bool isSafe(std::vector<int>& row) {
    bool incr = true, decr = true;
    for(int val = 1; val < row.size(); val++) {
        int diff = row[val] - row[val - 1];
        if(std::abs(diff) < 1 || std::abs(diff) > 3) {
            return false;
        }
        if (diff > 0) decr = false;
        if(diff < 0) incr = false;
    }
    return incr || decr;
}

//Second task
bool isSafeWithRemoval(std::vector<int>& row) {
    if(isSafe(row)){
        return true;
    }

    for(int i = 0; i < row.size(); i++) {
        std::vector<int> modifiedRow = row;
        modifiedRow.erase(modifiedRow.begin() + i);
        if(isSafe(modifiedRow)){
            return true;
        }
    }
    return false;
}

int main() {
    std::ifstream inputFile("input.txt");
    std::vector<std::vector<int>> arr;
    
    std::string line;
    while(std::getline(inputFile, line)) {
        std::vector<int> row;
        std::stringstream ss(line);
        int num;

        while(ss >> num) {
            row.push_back(num);
        }
        if(!row.empty()) {
            arr.push_back(row);
        }
    }

    inputFile.close();
    
    int countSafe = 0;
    for(std::vector<int>& row : arr) {
        if(isSafe(row)) {
            countSafe++;
        }
    }
    int countSafeModif = 0;
    
    for(std::vector<int> row : arr) {
        if(isSafeWithRemoval(row)) {
            countSafeModif++;
        }
    }
    std::cout << countSafe << "\n";
    std::cout << countSafeModif;
}