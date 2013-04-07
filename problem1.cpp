
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;

int main(void)
{

    int T;
    int N, M;

    while (cin >> T) {
        for (int i = 0; i < T; i++) {
            cin >> N >> M;

            map<string, string> map_say;
            string str1, str2;
            while (M--) {
                cin >> str1 >> str2;
                map_say[str1] = str2;
            }

            string input;
            string line;
            getline(cin, line);
            getline(cin, line);
            istringstream stream(line);
            string result;
            map<string, string>::const_iterator iter;

            stream >> input;
            for (int j = 0; j < N-1; j++) {
                    if (map_say.end() != (iter = map_say.find(input))) {
                        input = iter->second;
                    } else {
                        break;
                    }
            }
            result += input;

            while (stream >> input) {
                for (int j = 0; j < N-1; j++) {
                    if (map_say.end() != (iter = map_say.find(input))) {
                        input = iter->second;
                    } else {
                        break;
                    }
                }
                result += " ";
                result += input;
            }
            cout << "Case #" << (i+1) << ": " << result << endl;
        }
    }
    return 0;
}
