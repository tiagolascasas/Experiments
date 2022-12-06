#include <chrono>
#include <iostream>
using namespace std::chrono;
using namespace std;

#define N1 1000
#define N2 100000
#define N3 1000000

void foo(int *X, int n, int *res)
{
    int c = 0;
    for (int i = 0; i < n; i++)
        c += i;
    *res = c;
}

void bar(int *X, int *Y, int *Z, int n, int *res)
{
    int c = 0;
    for (int i = 0; i < n; i++)
        c += i;
    *res = c;
}

int main()
{
    int res = 0;

    int A[N1] = {0};
    auto start = high_resolution_clock::now();
    foo(A, N1, &res);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "{" << N1 << "} : " << duration.count() << endl;

    int B[N1] = {0};
    int C[N1] = {0};
    int D[N1] = {0};
    start = high_resolution_clock::now();
    bar(B, C, D, N1, &res);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "{" << N1 << "," << N1 << "," << N1 << "} : " << duration.count() << endl;

    int E[N2] = {0};
    start = high_resolution_clock::now();
    foo(E, N2, &res);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "{" << N2 << "} : " << duration.count() << endl;

    int F[N2] = {0};
    int G[N2] = {0};
    int H[N2] = {0};
    start = high_resolution_clock::now();
    bar(F, G, H, N2, &res);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "{" << N2 << "," << N2 << "," << N2 << "} : " << duration.count() << endl;

    int I[N3] = {0};
    start = high_resolution_clock::now();
    foo(I, N3, &res);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "{" << N3 << "} : " << duration.count() << endl;

    int J[N3] = {0};
    int K[N3] = {0};
    int L[N3] = {0};
    start = high_resolution_clock::now();
    bar(J, K, L, N3, &res);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "{" << N3 << "," << N3 << "," << N3 << "} : " << duration.count() << endl;

    return 0;
}