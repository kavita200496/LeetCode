class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
         vector<string> result;
        vector<string> current;
        int numOfLetters = 0;
        
        for (string word : words) {
            string w = word;
            if (numOfLetters + current.size()+w.size() > maxWidth) {
                for (int i = 0; i < (maxWidth - numOfLetters); i++) {
                    if (current.size() == 1) {
                        current[0] = current[0] + " ";
                    } else {
                        current[i%(current.size()-1)] = current[i%(current.size()-1)]+ " ";
                    }
                }
                string tmp;
                for (auto i : current) tmp += i;
                result.push_back(tmp);
                
                current.clear();
                numOfLetters = 0;
            }
            current.push_back(w);
            numOfLetters += w.size();
        }
        string tmp;
        for (auto i : current) tmp += i+" ";
        if (tmp.size() >= maxWidth) tmp.pop_back();
        while (tmp.size() < maxWidth) tmp += " ";
        result.push_back(tmp);
        
        return result;
    }
};
