#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

struct LineFrequency {
      string line;
    int frequency;
};



  string extractRelevantData(const   string& line) {
    size_t pos = line.find(" - ", line.find(" - ", line.find(" - ") ,line.find(" - ", line.find(" - ") + 1)+ 1) + 1);
    if (pos !=   string::npos) {
        return line.substr(pos + 4);
    }
    return "";
}


void sortLineFrequencies(LineFrequency* lineFrequencies, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (lineFrequencies[j].frequency < lineFrequencies[j + 1].frequency) {
                LineFrequency temp = lineFrequencies[j];
                lineFrequencies[j] = lineFrequencies[j + 1];
                lineFrequencies[j + 1] = temp;
            }
        }
    }
}

bool containsWord(const   string& line, const   string& word) {
    return line.find(word) !=   string::npos;
}

int main() {
	int c;
      	cin>>c;
	if(c==2)
{
      ifstream file("log.txt");
    if (!file.is_open()) {
          cerr << "Error opening file!" <<   endl;
        return 1;
    }

    const int MAX_LINES = 1000; // Adjust this as needed
    LineFrequency lineFrequencies[MAX_LINES];
    int uniqueLines = 0;

      string wordToSearch;
      cout << "Enter the word to search for: ";
      cin >> wordToSearch;

      string line;
    while (  getline(file, line)) {
          string relevantData = extractRelevantData(line);
        if (relevantData.empty() || !containsWord(relevantData, wordToSearch)) {
            continue;
        }

        bool found = false;
        for (int i = 0; i < uniqueLines; ++i) {
            if (lineFrequencies[i].line == relevantData) {
                lineFrequencies[i].frequency++;
                found = true;
                break;
            }
        }
        if (!found) {
            lineFrequencies[uniqueLines].line = relevantData;
            lineFrequencies[uniqueLines].frequency = 1;
            uniqueLines++;
        }
    }

    file.close();

    sortLineFrequencies(lineFrequencies, uniqueLines);

    if (uniqueLines > 0) {
          cout << "The line with the highest frequency (" << lineFrequencies[0].frequency << " occurrences):" <<   endl;
          cout << lineFrequencies[0].line <<   endl <<   endl;

          cout << "All lines containing the word \"" << wordToSearch << "\" sorted by frequency:" <<   endl;
        for (int i = 0; i < uniqueLines; ++i) {
              cout << lineFrequencies[i].frequency << " - " << lineFrequencies[i].line <<   endl;
        }
    } else {
          cout << "No lines containing the word \"" << wordToSearch << "\" were found." <<   endl;
    }
}
    if(c==1)
{
  ifstream file("log.txt");
				if (!file.is_open()) {
					  cerr << "Error opening file!" <<   endl;

				}

				const int MAX_LINES = 1000; // Adjust this as needed
				LineFrequency lineFrequencies[MAX_LINES];
				int uniqueLines = 0;

				  string line;
				while (  getline(file, line)) {
					  string relevantData = extractRelevantData(line);
					if (relevantData.empty()) {
						continue;
					}

					bool found = false;
					for (int i = 0; i < uniqueLines; ++i) {
						if (lineFrequencies[i].line == relevantData) {
							lineFrequencies[i].frequency++;
							found = true;
							break;
						}
					}
					if (!found) {
						lineFrequencies[uniqueLines].line = relevantData;
						lineFrequencies[uniqueLines].frequency = 1;
						uniqueLines++;
					}
				}

				file.close();

				sortLineFrequencies(lineFrequencies, uniqueLines);

				  cout << "The line with the highest frequency (" << lineFrequencies[0].frequency << " occurrences):" <<   endl;
				  cout << lineFrequencies[0].line <<   endl <<   endl;

				  cout << "All lines sorted by frequency:" <<   endl;
				for (int i = 0; i < uniqueLines; ++i) {
					  cout << lineFrequencies[i].frequency << " - " << lineFrequencies[i].line <<   endl;
				}
				
			}

    return 0;
}
