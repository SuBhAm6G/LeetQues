class Solution {
public:
    int countdiff(string s1, string s2){
        int count = 0;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]) count++;
        }
        return count;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary){
        vector<string> op;
        for(int x = 0; x < queries.size(); x++){
            string s1 = queries[x];
            for(int y = 0; y < dictionary.size(); y++){
                if(countdiff(s1, dictionary[y]) <= 2){
                    op.push_back(s1);
                    break;
                }
            }
        }
        return op;
    }
};