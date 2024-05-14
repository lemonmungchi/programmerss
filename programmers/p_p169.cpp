#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
//m: ����� ��ε� music: ��۵� �� ���� ���� : ��ġ�ϴ� ���� 
//�ٽ� : ��۵� �� ������ ����ϰ��ִ� ��ε����Ͽ� �ִ���
string change(string& m, map<string, char>& s) {               //#���� ���� �ٲ��ֱ�
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
        time = (bHour + bMin) - (aHour + aMin);     //���߽ð�- �� �ð�

        for (int j = 12; j < musicinfos[i].size(); j++) { //�� �������
            if (musicinfos[i][j] == ',') {
                title = musicinfos[i].substr(12, j - 12);
                tmp = musicinfos[i].substr(j + 1);             //���� �� ����
                break;
            }
        }
        music = change(tmp, s);
        if (music.size() < time)            //����ð��� �� �ð����� Ŭ��� �ݺ�
        {
            tmp = music;

            for (int j = 1; j < time / tmp.size(); j++)
                music += tmp;
            for (int j = 0; j < time % tmp.size(); j++)
                music += tmp[j];
        }
        else                //��ð����� ����ð��� ª���� �ڸ���
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