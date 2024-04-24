#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const long long N = 505;

long long main() {
    long long n;
    cin >> n;

    vector<long long> white_count(N, 0);
    vector<long long> black_count(N, 0);

    // ��ȡ��ɫ��Ϣ��ͳ�Ʊߵ�����
    for (long long i = 1; i <= n; ++i) {
        for (long long j = i + 1; j <= n; ++j) {
            long long color;
            cin >> color;
            if (color == 0) {
                white_count[i]++;
                white_count[j]++;
            } else {
                black_count[i]++;
                black_count[j]++;
            }
        }
    }

    long long count = 0;

    // ͳ��ͬɫ�����ε�����
    for (long long i = 1; i <= n; ++i) {
        count += white_count[i] * (white_count[i] - 1) / 2;  // �������ʽ C(n, 2) = n * (n-1) / 2
        count += black_count[i] * (black_count[i] - 1) / 2;
    }

    cout << count << endl;

    return 0;
}

