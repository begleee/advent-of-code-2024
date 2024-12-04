#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <unordered_map>

//function for secondTask
int calcSimilarutyScore(std::vector<int>& firstList, std::vector<int>& secondList) {
    std::unordered_map<int, int> secondCount;
    for(int num : secondList) {
        secondCount[num]++;
    }

    int similarityScore = 0;
    for(int num : firstList) {
        similarityScore += num * secondCount[num];
    }
    return similarityScore;
};
//

int main() {
    //First Task
    std::ifstream inputFile("input.txt");
    int value;
    bool isLeft = true;
    std::vector<int> firstList, secondList;

    while(inputFile >> value) {
        if(isLeft) {
            firstList.push_back(value);
        } else {
            secondList.push_back(value);
        }
        isLeft = !isLeft;
    }

    std::sort(firstList.begin(), firstList.end());
    std::sort(secondList.begin(), secondList.end());

    int total = 0;
    for(int i = 0; i < firstList.size(); i++) {
        total += std::abs(firstList[i] - secondList[i]);
    }
    std::cout << total << '\n';

    //Second Task
    std::cout << calcSimilarutyScore(firstList, secondList);
}