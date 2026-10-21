#include <iostream>
using namespace std;

int main() {
    int n, amount;
    int coin[100], dp[1000];

    cout << "Enter number of coins: ";
    cin >> n;

    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    cout << "Enter amount: ";
    cin >> amount;

    for (int i = 0; i <= amount; i++) {
        dp[i] = 9999;
    }

    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coin[j] <= i && dp[i - coin[j]] != 9999) {
                if (dp[i - coin[j]] + 1 < dp[i]) {
                    dp[i] = dp[i - coin[j]] + 1;
                }
            }
        }
    }

    if (dp[amount] == 9999) {
        cout << "Change cannot be made";
    } else {
        cout << "Minimum coins required: " << dp[amount];
    }

    return 0;
}
