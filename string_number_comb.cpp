/*

If a=1, b=2, c=3,....z=26. Given a string, find all possible codes that string can generate. Give a count as well as print the strings. 

For example: 
Input: "1123". You need to general all valid alphabet codes from this string. 

Output List 
aabc //a = 1, a = 1, b = 2, c = 3 
kbc // since k is 11, b = 2, c= 3 
alc // a = 1, l = 12, c = 3 
aaw // a= 1, a =1, w= 23 
kw // k = 11, w = 23

*/
#include <vector>
#include <iostream>

using namespace std;

void  string_number(vector<char> str,vector<int>num, int idx);
void print(vector<char>str);
int main(){

vector<char>str;
vector<int>num = {2,1,2};
string_number(str,num,0);

return 0;
}

void string_number(vector<char> str,vector<int>num, int idx){

        if( idx < num.size()){
                str.push_back(num[idx]+64);
                string_number(str,num,idx+1);
                str.pop_back();
        }
        if( idx +2 <= num.size()){
                int number = num[idx]*10 + num[idx+1];
                if(number < 26 )
                {str.push_back(number+64);
                string_number(str,num,idx+2);}
        }
        if(idx >= num.size())
        {
                print(str);
                return;
        }

}

void print(vector<char>str){

        for(int i = 0; i < str.size();i++){
                cout<<str[i];
        }
cout<<endl;
}
