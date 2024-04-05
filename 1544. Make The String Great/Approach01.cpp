#include <string>
using namespace std;

class Solution {
public:
    string makeGood(string data) {
        string result = "";
        for(char &ch : data){
            if(!result.empty() && (result.back() - 'A' == ch - 'a' || result.back() - 'a' == ch - 'A')){
                result.pop_back();
            }
            else{
                result.push_back(ch);
            }
        }
        return result;
    }
};
