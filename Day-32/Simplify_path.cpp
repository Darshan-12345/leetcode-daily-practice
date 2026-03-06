#include<iostream>
#include<vector>
#include<string>
using namespace std;



string simplyfy_path(string path) {
    vector<string> takens;
    string temp = "";
    for(int i = 0; i< path.length(); i++) {
        if(i == path.size() || path[i] == '/') {
            if(temp == "" || temp == ".") {

            }
            else if(temp == "..") {
                if(!takens.empty()) {
                    takens.pop_back();
                }
            }
            else {
                takens.push_back(temp);
            }
            temp = "";
        }else {
            temp += path[i];
        }
    }
    string result = "";
    for(int i = 0; i<takens.size(); i++) {
        result += "/";
        result += takens[i];
    }
    if(result == "") {
        return "/";
    }
    return result;
}

int main() {
    string path = "/a/./b/../../c/";
    cout<<simplyfy_path(path);
}