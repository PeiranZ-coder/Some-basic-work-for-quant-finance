#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    
    vector<vector<double>> Sigma = {
        { 1,     -0.525,  1.375,  -0.075, -0.75 },
        {-0.525,  2.25,   0.1875,  0.1875,-0.675},
        { 1.375,  0.1875, 6.25,    0.4375,-1.875},
        {-0.075,  0.1875, 0.4375,  0.25,   0.3  },
        {-0.75,  -0.675, -1.875,   0.3,    9.0  }
    };

    int n = Sigma.size();

    // 计算标准差
    vector<double> std_dev(n);
    for (int k = 0; k < n; k++)
        std_dev[k] = sqrt(Sigma[k][k]);

    // 计算相关矩阵
    vector<vector<double>> Omega(n, vector<double>(n, 0.0));
    for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
            Omega[j][k] = Sigma[j][k] /
                          (std_dev[j] * std_dev[k]);

    // 输出标准差
    cout << "Standard Deviations:" << endl;
    for (int k = 0; k < n; k++)
        cout << "  sigma_" << k+1 << " = " << std_dev[k] << endl;

    // 输出协方差矩阵
    cout << "\nCovariance Matrix:" << endl;
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++)
            cout << Sigma[j][k] << "\t";
        cout << endl;
    }

    // 输出相关矩阵
    cout << "\nCorrelation Matrix:" << endl;
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++)
            cout << Omega[j][k] << "\t";
        cout << endl;
    }

    return 0;
}
