#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Function to merge two sorted vectors
vector<string> mergeFiles(const vector<string>& file1, const vector<string>& file2) {
    vector<string> merged;
    size_t i = 0, j = 0;

    // Merge the two vectors while maintaining order
    while (i < file1.size() && j < file2.size()) {
        if (file1[i] < file2[j]) {
            merged.push_back(file1[i]);
            i++;
        } else {
            merged.push_back(file2[j]);
            j++;
        }
    }

    // Add remaining elements from file1, if any
    while (i < file1.size()) {
        merged.push_back(file1[i]);
        i++;
    }

    // Add remaining elements from file2, if any
    while (j < file2.size()) {
        merged.push_back(file2[j]);
        j++;
    }

    return merged;
}

int main() {
    ifstream inputFile1("file1.txt");
    ifstream inputFile2("file2.txt");
    ofstream outputFile("output.txt");

    // Check if files opened successfully
    if (!inputFile1.is_open() || !inputFile2.is_open()) {
        cerr << "Error opening input files." << endl;
        return 1;
    }

    vector<string> file1Lines;
    vector<string> file2Lines;
    string line;

    // Read lines from the first file
    while (getline(inputFile1, line)) {
        file1Lines.push_back(line);
    }

    // Read lines from the second file
    while (getline(inputFile2, line)) {
        file2Lines.push_back(line);
    }

    // Merge the lines from both files
    vector<string> mergedLines = mergeFiles(file1Lines, file2Lines);

    // Write the merged lines to the output file
    for (const string& mergedLine : mergedLines) {
        outputFile << mergedLine << endl;
    }

    // Close all files
    inputFile1.close();
    inputFile2.close();
    outputFile.close();

    cout << "Merging completed. Output written to output.txt." << endl;
    return 0;
}