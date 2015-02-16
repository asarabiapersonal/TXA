#include "wordInfo.h";
using namespace std;
class phraseInfo : public wordInfo{
public:
	phraseInfo();
	phraseInfo(string startWord);
	phraseInfo(string bef, string startWord);
	phraseInfo(string bef, string startWord, string aft);
	phraseInfo(wordInfo startWord);
	phraseInfo(wordInfo bef, wordInfo startWord);
	phraseInfo(wordInfo bef, wordInfo startInfo, wordInfo aft);

private:
	wordInfo *before;
	wordInfo *after;
	wordInfo *tWord;
	int phrase_occur;
};

phraseInfo::phraseInfo(){
	before = new wordInfo();
	after = new wordInfo();
	tWord = new wordInfo();
	phrase_occur = 0;
}

phraseInfo::phraseInfo(string startWord){
	before = new wordInfo();
	tWord = new wordInfo(startWord);
	after = new wordInfo();
}

phraseInfo::phraseInfo(string bef, string startWord){
	before = new wordInfo(bef);
	tWord = new wordInfo(startWord);
	after = new wordInfo();
}

