#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    for (int i = 0; i < arr.size(); i++)
    {
        if (answer.size() == 0 || answer[answer.size() - 1] != arr[i])       //연속되는 수 중에 같은 수 제외
            answer.push_back(arr[i]);
    }
    return answer;
}