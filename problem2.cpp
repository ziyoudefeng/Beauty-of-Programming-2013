
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

inline int getResult(int width, int length)
{
    int result = 0;
    for (int i = 1; i < width; i++) {
        result += i * (length) * (length - 1) / 2;
    }
    return result;
}

int main(void)
{
    int T, N, M, K;
    int result = 0;
    int result2 = 0;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> M >> K;
        result2 = 0;
        int sqrt_k, dim_k, rim_k;

        for (int j = 2; j <= sqrt(K); j++) {
            if (j > min(N, M)) {
                break;
            }
            sqrt_k = j;
            dim_k = K / j > max(N, M) ? max(N, M) : K / j;
            rim_k = K - (sqrt_k * dim_k);

            result = getResult(sqrt_k, dim_k);
            if (rim_k <= sqrt_k && dim_k < max(N, M)) {
                int tmp = result + getResult(rim_k, dim_k + 1) - getResult(rim_k, dim_k);
                if (result < tmp) result = tmp;
            } else if (rim_k <= dim_k && sqrt_k < min(N, M)) {
                int tmp = result + getResult(rim_k, sqrt_k + 1) - getResult(rim_k, sqrt_k);
                if (result < tmp) result = tmp;
            }
            if (result > result2) {
                result2 = result;
            }
        }
        cout << "Case #" << (i+1) << ": " << result2 << endl;

    }
    return 0;
}

