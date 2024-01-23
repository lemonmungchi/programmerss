#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {

    sort(phone_book.begin(), phone_book.end());          //이렇게 정렬을 하면 사전순으로 정렬된다 즉 1 1 처럼  같은 숫자대로 정렬
    for (int i = 0; i < phone_book.size() - 1; i++) {
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size())) {
            return false;
        }
    }

    return true;
}


//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//bool solution(vector<string> phone_book) {                    //기존에 생각한 코드 시간이 너무 오래걸림 
//    bool answer = true;
//
//    sort(phone_book.begin(), phone_book.end());
//    for (int i = 0; i < phone_book.size(); i++) {
//        string check = phone_book[i];
//        for (int j = i + 1; j < phone_book.size(); j++) {
//            if (phone_book[j].substr(0, check.length()) == check) {
//                return false;
//            }
//        }
//    }
//
//    return true;
//}