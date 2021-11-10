#include <iostream>
#include <iomanip>

using namespace std;

int T, N, M;
int main() {
    cin >> T;
    for (int i=0; i<T; i++) {
        cin >> N >> M;

        int arr[N][N] = {0};
        int left = -1, right = N, top = -1, down = N;
        int currNum = 1;
        
        while (currNum <= N*N) {
            for (int l=left+1; l<right; l++) {
                arr[top+1][l] = currNum;
                currNum ++;

                if (l == right - 1) {
                    top ++;
                    break;
                }               
            }

            if (left + 1 == right - 1) break;

            for (int t=top+1; t<down; t++) {
                arr[t][right-1] = currNum;
                currNum ++;

                if (t == down - 1) {
                    right --;
                    break;
                }
            }

            for (int r=right - 1; r>left; r--) {
                arr[down-1][r] = currNum;
                currNum ++;

                if (r == left + 1) {
                    down --;
                    break;
                }                            
            }

            for (int d=down - 1; d>top; d--) {
                arr[d][left+1] = currNum;
                currNum ++;

                if (d == top + 1) {
                    left ++;
                    break;
                }
            }
        }

        if (M == 1) {
            for (int i=0; i<N; i++) {
                for (int j=0; j<N; j++) {
                    cout << setw(5) << arr[i][j];
                }
                cout << endl;
            }
        }else {
            for (int i=0; i<N; i++) {
                for (int j=0; j<N; j++) {
                    cout << setw(5) << arr[j][i];
                }
                cout << endl;
            }            
        }
        
    }
}