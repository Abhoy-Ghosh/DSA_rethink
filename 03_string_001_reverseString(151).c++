class Solution {
public:
    string reverseWords(string s) {

        string result = "";
        string x = "";

 for(int i = s.size()-1; i >= 0; i--){

    if(s[i] != ' ') x.push_back(s[i]);

    if((s[i] == ' ' || i == 0) && !x.empty()){
        reverse(x.begin(), x.end());

        if(!result.empty())
            result += " ";

        result += x;
        x.clear();
    }
}

        return result;
    }
};
