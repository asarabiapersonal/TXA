using namespace std;
#include<string>;

class wordInfo{
public:
	wordInfo();
	wordInfo(string startWord);
	string get_tWord();
	void set_tWord(string newWord);
	int get_occur();
	void inc_occur();
	bool is_same_tWord(wordInfo otherWord);
	bool is_same_tWord(string otherWord);

private:
	string tWord;
	int occur;
};

wordInfo::wordInfo(){
	tWord = "";
	occur = 0;
}

wordInfo::wordInfo(string startWord){
	tWord = startWord;
	occur = 1;
}

string wordInfo::get_tWord(){
	return tWord;
}

void wordInfo::set_tWord(string newWord){
	tWord = newWord;
}

int wordInfo::get_occur(){
	return occur;
}

void wordInfo::inc_occur(){
	occur++;
}

bool wordInfo::is_same_tWord(wordInfo otherWord){
	if (tWord == otherWord.get_tWord()){
		return true;
	}
	else{
		return false;
	}

	return false;
}

bool wordInfo::is_same_tWord(string word){
	if (tWord == word){
		return true;
	}
	else{
		return false;
	}

	return false;
}

