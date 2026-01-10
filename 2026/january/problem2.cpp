#include <string>
using namespace std;
int lengthOfLongestSubstring(string s) {
    string currentSubstring = "";
    int maxLength = 0;
    for (int i = 0; i < s.length(); i++){
        currentSubstring += s[i];
        int findIndex = currentSubstring.find(s[i]);
        if(findIndex != currentSubstring.length() - 1){ 
            //remove previous instance of Char s[i] that woudl cause a duplicate and everythign prior to that char.  
            currentSubstring = currentSubstring.substr(findIndex + 1);
        }
        if(currentSubstring.length() > maxLength){
            maxLength = currentSubstring.length();      
        }
    }
    return maxLength;
}
