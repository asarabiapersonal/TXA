// Text Analysis 0.1.3

#include <iostream>
#include <exception>
#include <dirent.h>
#include <string>
#include <list>
#include <fstream>
#include <regex>

using namespace std;

list<string> process_directory();
list<string> process_file(string file);


int main(){
	list<string> filesToProcess;
	list<string> allWords;
	filesToProcess = process_directory();

	if (filesToProcess.size() <= 0){
		cout << "No valid files found." << endl;
	}
	else{
		for each (string file in filesToProcess){
			allWords = process_file(file);
		}
	}

	for each(string word in allWords){
		cout << word << endl;
	}

	system("PAUSE");
	return 0;
}


list<string> process_directory(){
	// Regex variables
	regex re("tokens");
	list<string> filesInDir;
	string result;
	smatch match;

	// Read current directory for file names containing 'tokens' and push them to file list
	DIR *dir;
	dirent* pdir;
	struct dirent *ent;
	dir = opendir(".");
	while (pdir = readdir(dir)){
		string file = pdir->d_name;
		if (regex_search(file, match, re)){
			filesInDir.push_back(file);
		}
	}

	return filesInDir;
}


list<string> process_file(string file){
	list<string> wordsInFile;
	ifstream wordFile;
	string line;
	try{
		wordFile.open(file);
	}
	catch(exception e){
		cout << "Unable to open file " << file << ". Error " << e.what() << endl;
		return wordsInFile;
	}

	if (wordFile.is_open()){
		while (getline(wordFile, line)){
			if (line != ""){
				wordsInFile.push_back(line);
			}
		}
	}
	return wordsInFile;

}
