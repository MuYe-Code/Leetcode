/*
https://leetcode.cn/problems/word-ladder/solution/

字典 wordList 中从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列 beginWord -> s1 -> s2 -> ... -> sk：

每一对相邻的单词只差一个字母。
 对于 1 <= i <= k 时，每个 si 都在 wordList 中。注意， beginWord 不需要在 wordList 中。
sk == endWord
给你两个单词 beginWord 和 endWord 和一个字典 wordList ，返回 从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。如果不存在这样的转换序列，返回 0
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        buildMap(wordList);
        if(wordList.size() == 0 || wordId.find(endWord) == wordId.end()) { return 0; }
        
        int cnt = 1;
        //分别将beginWord和endWord插入对应集合
        beginVec.insert(beginWord);
        endVec.insert(endWord);

        while(!beginVec.empty() && !endVec.empty())
        {
            unordered_set<string> nextBegin;    //存放下一轮的单词
            for(auto word: beginVec)
            {
                if(getNextSet(beginVec, endVec, nextBegin, word)) { return cnt + 1; }
                visited.insert(word);           //将访问过的单词加入visited集合
            }
            ++cnt;                              //计数加一
            beginVec = nextBegin;               //丢弃原beginVec集合
            
            unordered_set<string> nextEnd;
            for(auto word: endVec)
            {
                if(getNextSet(endVec, beginVec, nextEnd, word)) { return cnt + 1; }
                visited.insert(word);
            }
            ++cnt;
            endVec = nextEnd; 
        }
        return 0;
    }
private:
    void buildMap(vector<string>& wordList)
    {
        for(size_t idx = 0; idx != wordList.size(); ++idx)
        { wordId[wordList[idx]] = idx; }
    }

    //将单词word的后续放入next中
    bool getNextSet(unordered_set<string> &vec1, unordered_set<string> &vec2, 
                 unordered_set<string> &next, string word)
    {
        //若该单词已经访问过，则跳过
        if(visited.find(word) != visited.end()) { return false; }   
        //变化单词，使得变化后的单词与原单词只差一个字母  
        for(auto &ch : word)  
        {
            char tmp = ch;
            for(char elem = 'a'; elem <= 'z'; ++elem)
            {
                ch = elem;
                if(elem != tmp && wordId.find(word) != wordId.end())
                { 
                    //word将加入vec1的集合，但若word正处于vec2的集合中，则找到了从beginWord到endWord的转换
                    if(vec2.find(word) != vec2.end()) { return true; }
                    //若word已访问过，则跳过
                    if(visited.find(word) == visited.end()) { next.insert(word); } 
                }
            }
            ch = tmp;
        }
        return false;
    }

private:
    unordered_map<string, int> wordId;
    unordered_set<string> visited;      //已访问过的单词
    unordered_set<string> beginVec;     //当前正向访问的单词下标
    unordered_set<string> endVec;       //当前逆向访问的单词下标
};
