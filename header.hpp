#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iomanip>

using namespace std;


using WORD = std::string;
using WORD_LIST = std::set<WORD>;
using WORD_FREQ_LIST = std::map<char,int>;
using FREQ_WORD_LIST = std::multimap<int,WORD>;
using COUNTER = std::tuple<int,int,int>;

struct funcObj
{
    bool operator()(const WORD& a, const WORD& b) { 
        return a.length() < b.length(); }
};
using LONGEST = std::priority_queue<WORD,std::vector<WORD>,funcObj>;


struct DICTION {
 COUNTER stats;
 WORD_LIST words;
 WORD_FREQ_LIST wordFreq;
 FREQ_WORD_LIST freqWord;
 LONGEST longWord;
};
void showStats(const DICTION& d);
void drawHistograms(const DICTION& d);
void buildDictionary(DICTION& d);
