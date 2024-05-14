#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
//m: 기억한 멜로디 music: 방송된 곡 정보 정답 : 일치하는 음악 
//핵심 : 방송된 곡 정보가 기억하고있는 멜로디패턴에 있는지
string change(string& m, map<string, char>& s) {               //#붙은 음들 바꿔주기
    string out = "";
    for (int i = 0; i < m.size(); i++) {
        if (m[i + 1] == '#') {
            out += s[m.substr(i, 2)];
            i++;
        }
        else {
            out += m[i];
        }
    }
    return out;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int aHour = 0, bHour = 0, aMin = 0, bMin = 0, time = 0, btime = 0;
    string melody = "", title = "";
    map<string, char> s;

    s["C#"] = 'c';
    s["D#"] = 'd';
    s["F#"] = 'f';
    s["G#"] = 'g';
    s["A#"] = 'a';

    melody = change(m, s);

    for (int i = 0; i < musicinfos.size(); i++) {
        string tmp = "", music = "";

        aHour = stoi(musicinfos[i].substr(0, 2)) * 60;
        aMin = stoi(musicinfos[i].substr(3, 2));
        bHour = stoi(musicinfos[i].substr(6, 2)) * 60;
        bMin = stoi(musicinfos[i].substr(9, 2));
        time = (bHour + bMin) - (aHour + aMin);     //나중시간- 전 시간

        for (int j = 12; j < musicinfos[i].size(); j++) { //곡 제목부터
            if (musicinfos[i][j] == ',') {
                title = musicinfos[i].substr(12, j - 12);
                tmp = musicinfos[i].substr(j + 1);             //곡의 음 패턴
                break;
            }
        }
        music = change(tmp, s);
        if (music.size() < time)            //재생시간이 곡 시간보다 클경우 반복
        {
            tmp = music;

            for (int j = 1; j < time / tmp.size(); j++)
                music += tmp;
            for (int j = 0; j < time % tmp.size(); j++)
                music += tmp[j];
        }
        else                //곡시간보다 재생시간이 짧으면 자르기
            music = music.substr(0, time);

        if (music.find(melody) != string::npos) {
            if (btime < time) {
                answer = title;
                btime = time;
            }
        }
    }
    return answer;
}