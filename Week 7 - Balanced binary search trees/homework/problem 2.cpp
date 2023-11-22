#include <set>
#include <iostream>
#include <vector>

using namespace std;

int main() {

    int N, M; cin >> N >> M;

    set<int> s;
    vector<int> vec;

    for (int i = 1; i <= N; i++) {
        s.insert(i);
    }

    for (int i = 0; i < M; i++) {
        int num; cin >> num;
        vec.push_back(num);
        s.erase(num);
    }

    int i = 0;
    auto it = s.begin();
    while (i < vec.size()) {
        while(it != s.end() && *it < vec[i]) {
            cout << *it << ' ';
            ++it;
        }
        cout << vec[i++] << ' ';
    }

    while (it != s.end()) {
        cout << *it << ' ';
        ++it;
    }

    return 0;
}
