#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

// ============================================================
// Covariance Matrix Computation from Time Series Data
// 协方差矩阵的时间序列计算
// Core Formula: Sigma = (1 / N-1) * T_X_bar.T @ T_X_bar
// ============================================================

// Matrix type
using Matrix = std::vector<std::vector<double>>;

// Print Matrix 打印矩阵
void printMatrix(const Matrix& M, 
                 const std::vector<std::string>& labels) {
    std::cout << std::setw(8) << " ";
    for (const auto& l : labels) 
        std::cout << std::setw(10) << l;
    std::cout << "\n";

    for (int i = 0; i < M.size(); i++) {
        std::cout << std::setw(8) << labels[i];
        for (double v : M[i])
            std::cout << std::setw(10) << std::fixed 
                      << std::setprecision(6) << v;
        std::cout << "\n";
    }
}

// Compute Daily Returns 计算日收益率
// r_t = (S(t2) - S(t1)) / S(t1)
Matrix dailyReturns(const Matrix& prices) {
    int N = prices.size() - 1;
    int n = prices[0].size();
    Matrix T_X(N, std::vector<double>(n));

    for (int i = 0; i < N; i++)
        for (int k = 0; k < n; k++)
            T_X[i][k] = (prices[i+1][k] - prices[i][k]) / prices[i][k];

    return T_X;
}

// Compute Sample Mean 计算样本均值
std::vector<double> sampleMean(const Matrix& T_X) {
    int N = T_X.size();
    int n = T_X[0].size();
    std::vector<double> mu(n, 0.0);

    for (int i = 0; i < N; i++)
        for (int k = 0; k < n; k++)
            mu[k] += T_X[i][k];

    for (double& m : mu) m /= N;
    return mu;
}

// Demean Matrix 去均值矩阵
Matrix demean(const Matrix& T_X, const std::vector<double>& mu) {
    int N = T_X.size();
    int n = T_X[0].size();
    Matrix T_bar(N, std::vector<double>(n));

    for (int i = 0; i < N; i++)
        for (int k = 0; k < n; k++)
            T_bar[i][k] = T_X[i][k] - mu[k];

    return T_bar;
}

// Covariance Matrix 协方差矩阵
// Sigma = (1 / N-1) * T_bar.T @ T_bar
Matrix covarianceMatrix(const Matrix& T_bar) {
    int N = T_bar.size();
    int n = T_bar[0].size();
    Matrix Sigma(n, std::vector<double>(n, 0.0));

    for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < N; i++)
                Sigma[j][k] += T_bar[i][j] * T_bar[i][k];
            Sigma[j][k] /= (N - 1);
        }

    return Sigma;
}

int main() {
    // Adjusted Closing Prices 调整收盘价
    // Stocks: A, B, C
    // Dates: 2024/01/02 - 2024/01/08
    Matrix prices = {
        {100.00, 50.00, 200.00},  // 2024/01/02
        {102.00, 49.00, 204.00},  // 2024/01/03
        {99.00,  51.00, 198.00},  // 2024/01/04
        {103.00, 52.00, 206.00},  // 2024/01/05
        {101.00, 50.00, 202.00}   // 2024/01/08
    };

    std::vector<std::string> labels = {"A", "B", "C"};

    // Step 1: Daily Returns 日收益率
    Matrix T_X = dailyReturns(prices);

    // Step 2: Sample Mean 样本均值
    std::vector<double> mu = sampleMean(T_X);

    // Step 3: Demean 去均值
    Matrix T_bar = demean(T_X, mu);

    // Step 4: Covariance Matrix 协方差矩阵
    Matrix Sigma = covarianceMatrix(T_bar);

    // Output 输出
    std::cout << "Covariance Matrix 协方差矩阵\n";
    std::cout << "Sigma = (1 / N-1) * T_bar.T @ T_bar\n\n";
    printMatrix(Sigma, labels);

    return 0;
}
