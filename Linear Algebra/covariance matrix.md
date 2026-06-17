## 1.1.1 Covariance Matrix Computation from Time Series Data
协方差矩阵的时间序列计算

---

## Part 1：核心概念与公式 Core Concepts & Formulas

### 1. 样本均值 Sample Mean

Let $X_1, X_2, \dots, X_n$ be $n$ random variables observed at $N$ time points
$t_i, i = 1:N$. The sample mean of $X_k$ is defined as:

设 $X_1, X_2, \dots, X_n$ 为 $n$ 个随机变量，在 $N$ 个时间点上有观测值，
$X_k$ 的样本均值定义为：

$$
\hat{\mu}_{X_k} = \frac{1}{N} \sum_{i=1}^N X_k(t_i), \quad k = 1:n
$$

---

### 2. 无偏样本协方差 Unbiased Sample Covariance

The unbiased sample covariance between random variables $X_j$ and $X_k$ is:

随机变量 $X_j$ 和 $X_k$ 的无偏样本协方差为：

$$
\widehat{\text{cov}}(X_j, X_k) =
\frac{1}{N-1} \sum_{i=1}^N
(X_j(t_i) - \hat{\mu}_{X_j})(X_k(t_i) - \hat{\mu}_{X_k})
$$

> Note: The denominator is $N-1$ (unbiased estimator), not $N$.
> 注意：分母为 $N-1$（无偏估计），而非 $N$。

---

### 3. 样本协方差矩阵 Sample Covariance Matrix

The $n \times n$ sample covariance matrix $\hat{\Sigma}_X$ has entries:

$n \times n$ 的样本协方差矩阵 $\hat{\Sigma}_X$，其第 $(j,k)$ 元素为：

$$
\hat{\Sigma}_X(j,k) = \widehat{\text{cov}}(X_j, X_k),
\quad \forall \; 1 \leq j, k \leq n
$$

**Property 1 — Symmetry 对称性：**

$$
\hat{\Sigma}_X(j,k) = \hat{\Sigma}_X(k,j)
$$

**Property 2 — Diagonal = Variance 对角线为方差：**

$$
\hat{\Sigma}_X(k,k) = \widehat{\text{var}}(X_k) = \hat{\sigma}_k^2
$$

---

### 4. 去均值矩阵 Demeaned Matrix

Define the raw data matrix $T_X$ of size $N \times n$:

定义原始数据矩阵 $T_X$（$N \times n$）：

$$
T_X(i,k) = X_k(t_i), \quad 1 \leq i \leq N, \; 1 \leq k \leq n
$$

Define the demeaned matrix $\bar{T}_X$ of size $N \times n$ by subtracting
the sample mean from each column:

定义去均值矩阵 $\bar{T}_X$（$N \times n$），每列减去对应均值：

$$
\bar{T}_X(i,k) = X_k(t_i) - \hat{\mu}_{X_k}
$$

---

### 5. 核心公式 Key Formula

The sample covariance matrix can be computed efficiently as:

样本协方差矩阵可以通过矩阵乘法高效计算：

$$
\boxed{\hat{\Sigma}_X = \frac{1}{N-1} \bar{T}_X^T \bar{T}_X}
$$

**Proof 证明：**

The $(j,k)$ entry of $\bar{T}_X^T \bar{T}_X$ is:

$\bar{T}_X^T \bar{T}_X$ 的第 $(j,k)$ 元素为：

$$
(\bar{T}_X^T \bar{T}_X)(j,k)
= \sum_{i=1}^N \bar{T}_X(i,j) \cdot \bar{T}_X(i,k)
$$

$$
= \sum_{i=1}^N
(X_j(t_i) - \hat{\mu}_{X_j})(X_k(t_i) - \hat{\mu}_{X_k})
$$

Dividing by $N-1$ gives exactly $\hat{\Sigma}_X(j,k)$. $\square$

除以 $N-1$ 正好等于 $\hat{\Sigma}_X(j,k)$，证毕。 $\square$

---

## Part 2：例题与计算过程 Example & Solution

### 原题 Problem

Let $n = 5$ stocks: AAPL, FB, GOOG, MSFT, YHOO.
The adjusted closing prices from 1/10/2013 to 1/29/2013 are given below.
Compute the sample covariance matrix $\hat{\Sigma}_X$.

设有 $n = 5$ 支股票：AAPL, FB, GOOG, MSFT, YHOO。
给定 1/10/2013 至 1/29/2013 的收盘价，求样本协方差矩阵 $\hat{\Sigma}_X$。

| Date | AAPL | FB | GOOG | MSFT | YHOO |
|---|---|---|---|---|---|
| 1/10/2013 | 523.51 | 31.30 | 741.48 | 26.46 | 18.99 |
| 1/11/2013 | 520.30 | 31.72 | 739.99 | 26.83 | 19.29 |
| 1/14/2013 | 501.75 | 30.95 | 723.25 | 26.89 | 19.43 |
| 1/15/2013 | 485.92 | 30.10 | 724.93 | 27.21 | 19.52 |
| 1/16/2013 | 506.09 | 29.85 | 715.19 | 27.04 | 20.07 |
| 1/17/2013 | 502.68 & 30.14 | 711.32 | 27.25 | 20.13 |
| 1/18/2013 | 500.00 | 29.66 | 704.51 | 27.25 | 20.02 |
| 1/22/2013 | 504.77 | 30.73 | 702.87 | 27.15 | 19.90 |
| 1/23/2013 | 514.01 | 30.82 | 741.50 | 27.61 | 20.11 |
| 1/24/2013 | 450.50 | 31.08 | 754.21 | 27.63 | 20.44 |
| 1/25/2013 | 439.88 | 31.54 | 753.67 | 27.88 | 20.37 |
| 1/28/2013 | 449.83 | 32.47 | 750.73 | 27.91 | 20.31 |
| 1/29/2013 | 458.27 | 30.79 | 753.68 | 28.01 | 19.70 |

---

### 计算过程 Solution

**Step 1：计算日收益率 Compute Daily Returns**

The daily return is defined as:

日收益率公式：

$$
r_t = \frac{S(t_2) - S(t_1)}{S(t_1)}
$$

For example, the daily return of GOOG on 1/24/2013:

例：GOOG 在 1/24/2013 的日收益率：

$$
T_X(9,3) = \frac{754.21 - 741.50}{741.50} = 0.0171
$$

The resulting return matrix $T_X$ ($12 \times 5$):

得到日收益率矩阵 $T_X$（$12 \times 5$）：

$$
T_X =
\begin{pmatrix}
-0.0061 & 0.0134 & -0.0020 & 0.0140 & 0.0158 \\
-0.0357 & -0.0243 & -0.0226 & 0.0022 & 0.0073 \\
-0.0315 & -0.0275 & 0.0023 & 0.0119 & 0.0046 \\
0.0415 & -0.0083 & -0.0134 & -0.0062 & 0.0282 \\
-0.0067 & 0.0097 & -0.0054 & 0.0078 & 0.0030 \\
-0.0053 & -0.0159 & -0.0096 & 0.0000 & -0.0055 \\
0.0095 & 0.0361 & -0.0023 & -0.0037 & -0.0060 \\
0.0183 & 0.0029 & 0.0550 & 0.0169 & 0.0106 \\
-0.1236 & 0.0084 & 0.0171 & 0.0007 & 0.0164 \\
-0.0236 & 0.0148 & -0.0007 & 0.0090 & -0.0034 \\
0.0226 & 0.0295 & -0.0039 & 0.0011 & -0.0029 \\
0.0188 & -0.0517 & 0.0039 & 0.0036 & -0.0300
\end{pmatrix}
$$

**Step 2：计算样本均值 Compute Sample Means**

$$
\hat{\mu}_{X_k} = \frac{1}{12} \sum_{i=1}^{12} T_X(i,k)
$$

| Stock 股票 | AAPL | FB | GOOG | MSFT | YHOO |
|---|---|---|---|---|---|
| $\hat{\mu}$ | -0.0101 | -0.0011 | 0.0015 | 0.0048 | 0.0032 |

**Step 3：去均值 Demean the Matrix**

Subtract the sample mean from each column:

每列减去对应均值：

$$
\bar{T}_X(i,k) = T_X(i,k) - \hat{\mu}_{X_k}
$$

$$
\bar{T}_X =
\begin{pmatrix}
0.0040 & 0.0145 & -0.0035 & 0.0092 & 0.0126 \\
-0.0255 & -0.0232 & -0.0242 & -0.0025 & 0.0041 \\
-0.0214 & -0.0264 & 0.0008 & 0.0071 & 0.0015 \\
0.0517 & -0.0072 & -0.0150 & -0.0110 & 0.0250 \\
0.0034 & 0.0108 & -0.0069 & 0.0030 & -0.0002 \\
0.0048 & -0.0149 & -0.0111 & -0.0048 & -0.0086 \\
0.0197 & 0.0371 & -0.0039 & -0.0084 & -0.0092 \\
0.0285 & 0.0040 & 0.0534 & 0.0122 & 0.0074 \\
-0.1134 & 0.0095 & 0.0156 & -0.0041 & 0.0132 \\
-0.0134 & 0.0159 & -0.0022 & 0.0043 & -0.0066 \\
0.0328 & 0.0306 & -0.0054 & -0.0037 & -0.0061 \\
0.0289 & -0.0507 & 0.0024 & -0.0012 & -0.0332
\end{pmatrix}
$$

**Step 4：代入核心公式 Apply Key Formula**

With $N = 12$:

$$
\hat{\Sigma}_X = \frac{1}{N-1} \bar{T}_X^T \bar{T}_X
= \frac{1}{11} \bar{T}_X^T \bar{T}_X
$$

**Step 5：最终结果 Final Result**

$$
\hat{\Sigma}_X =
\begin{pmatrix}
0.0018 & 0.0000 & -0.0001 & 0.0000 & -0.0001 \\
0.0000 & 0.0006 & 0.0001 & 0.0000 & 0.0001 \\
-0.0001 & 0.0001 & 0.0004 & 0.0001 & 0.0000 \\
0.0000 & 0.0000 & 0.0001 & 0.0001 & 0.0000 \\
-0.0001 & 0.0001 & 0.0000 & 0.0000 & 0.0002
\end{pmatrix}
$$

**结果解读 Interpretation：**

- Diagonal entries represent the sample variance of each stock.
  对角线元素为各股票的样本方差。
- AAPL has the largest variance (0.0018), indicating the highest volatility.
  AAPL 方差最大（0.0018），波动最剧烈。
- Off-diagonal entries are close to 0, indicating low correlation between stocks.
  非对角线元素接近 0，说明五支股票之间相关性较低。
- The matrix is symmetric, confirming $\hat{\Sigma}_X(j,k) = \hat{\Sigma}_X(k,j)$.
  矩阵对称，验证了协方差矩阵的对称性。

---

### 总结 Summary

| Step 步骤 | Operation 操作 | Formula 公式 |
|---|---|---|
| 1 | Daily return 日收益率 | $r_t = \frac{S(t_2)-S(t_1)}{S(t_1)}$ |
| 2 | Sample mean 样本均值 | $\hat{\mu}_{X_k} = \frac{1}{N}\sum_{i=1}^N X_k(t_i)$ |
| 3 | Demean 去均值 | $\bar{T}_X(i,k) = X_k(t_i) - \hat{\mu}_{X_k}$ |
| 4 | Matrix formula 矩阵公式 | $\hat{\Sigma}_X = \frac{1}{N-1}\bar{T}_X^T\bar{T}_X$ |

> 📌 Financial Insight 金融含义：The covariance matrix captures the
> co-movement between securities and is the key input for
> Markowitz portfolio optimization and risk management.
> 协方差矩阵描述证券之间的联动关系，是 Markowitz
> 组合优化和风险管理的核心输入。
