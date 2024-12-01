#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>


struct pair {
	int left;
	int right;
	int distance;
	pair(int l, int r) :left(l), right(r) {}
};
bool containsElement(std::vector<int>& vec, int& element) {
	for (int i = 0, j = vec.size(); i < j; i++)
		if (vec[i] == element)
			return true;
	return false;
}
int abs(int a) {
	if (a < 0)
		return -a;
	return a;
}

int main() {

	std::fstream input("input.txt", std::ios::in);
	std::vector<pair> pairVec;
	std::vector<int> left, right;

	for (std::string firstNo, secondNo; input >> firstNo >> secondNo;)
		left.push_back(stoi(firstNo)), right.push_back(stoi(secondNo));

	std::sort(left.begin(), left.end());
	std::sort(right.begin(), right.end());

	int totalSimilarityScore = 0;
	
	for (int i = 0, j = left.size(); i < j; i++) {
		int number = left[i];
		int similarityScore = 0;
		for (int q = 0, w = right.size(); q < w; q++) {
			if (right[q] == number)
				similarityScore++;
		}
		totalSimilarityScore += (number * similarityScore);
	}

	std::cout << "Total similarity score: " << totalSimilarityScore << std::endl;
	system("PAUSE");
	return 0;
}