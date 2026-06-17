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

Let $n = 3$ stocks: A, B, C. The adjusted closing prices over 5 trading days
are given below. Compute the sample covariance matrix $\hat{\Sigma}_X$.

设有 $n = 3$ 支股票：A, B, C，5个交易日的调整收盘价如下，
求样本协方差矩阵 $\hat{\Sigma}_X$。

| Date | A | B | C |
|---|---|---|---|
| 2024/01/02 | 100.00 | 50.00 | 200.00 |
| 2024/01/03 | 102.00 | 49.00 | 204.00 |
| 2024/01/04 | 99.00 | 51.00 | 198.00 |
| 2024/01/05 | 103.00 | 52.00 | 206.00 |
| 2024/01/08 | 101.00 | 50.00 | 202.00 |

---

### 计算过程 Solution

**Step 1：计算日收益率 Compute Daily Returns**

The daily return is defined as:

日收益率公式：

$$
r_t = \frac{S(t_2) - S(t_1)}{S(t_1)}
$$

逐个计算 Calculating each return：

Stock A：

$$
r_{A,1} = \frac{102.00 - 100.00}{100.00} = 0.0200
$$

$$
r_{A,2} = \frac{99.00 - 102.00}{102.00} = -0.0294
$$

$$
r_{A,3} = \frac{103.00 - 99.00}{99.00} = 0.0404
$$

$$
r_{A,4} = \frac{101.00 - 103.00}{103.00} = -0.0194
$$

Stock B：

$$
r_{B,1} = \frac{49.00 - 50.00}{50.00} = -0.0200
$$

$$
r_{B,2} = \frac{51.00 - 49.00}{49.00} = 0.0408
$$

$$
r_{B,3} = \frac{52.00 - 51.00}{51.00} = 0.0196
$$

$$
r_{B,4} = \frac{50.00 - 52.00}{52.00} = -0.0385
$$

Stock C：

$$
r_{C,1} = \frac{204.00 - 200.00}{200.00} = 0.0200
$$

$$
r_{C,2} = \frac{198.00 - 204.00}{204.00} = -0.0294
$$

$$
r_{C,3} = \frac{206.00 - 198.00}{198.00} = 0.0404
$$

$$
r_{C,4} = \frac{202.00 - 206.00}{206.00} = -0.0194
$$

得到日收益率矩阵 $T_X$（$4 \times 3$）：

| Date | A | B | C |
|---|---|---|---|
| 2024/01/03 | 0.0200 | -0.0200 | 0.0200 |
| 2024/01/04 | -0.0294 | 0.0408 | -0.0294 |
| 2024/01/05 | 0.0404 | 0.0196 | 0.0404 |
| 2024/01/08 | -0.0194 | -0.0385 | -0.0194 |

$$
T_X =
\begin{pmatrix}
0.0200 & -0.0200 & 0.0200 \\
-0.0294 & 0.0408 & -0.0294 \\
0.0404 & 0.0196 & 0.0404 \\
-0.0194 & -0.0385 & -0.0194
\end{pmatrix}
$$

---

**Step 2：计算样本均值 Compute Sample Means**

$$
\hat{\mu}_{X_k} = \frac{1}{4} \sum_{i=1}^{4} T_X(i,k)
$$

$$
\hat{\mu}_A = \frac{0.0200 + (-0.0294) + 0.0404 + (-0.0194)}{4}
= \frac{0.0116}{4} = 0.0029
$$

$$
\hat{\mu}_B = \frac{(-0.0200) + 0.0408 + 0.0196 + (-0.0385)}{4}
= \frac{0.0019}{4} = 0.0005
$$

$$
\hat{\mu}_C = \frac{0.0200 + (-0.0294) + 0.0404 + (-0.0194)}{4}
= \frac{0.0116}{4} = 0.0029
$$

| Stock 股票 | A | B | C |
|---|---|---|---|
| $\hat{\mu}$ | 0.0029 | 0.0005 | 0.0029 |

---

**Step 3：去均值 Demean the Matrix**

$$
\bar{T}_X(i,k) = T_X(i,k) - \hat{\mu}_{X_k}
$$

$$
\bar{T}_X =
\begin{pmatrix}
0.0200 - 0.0029 & -0.0200 - 0.0005 & 0.0200 - 0.0029 \\
-0.0294 - 0.0029 & 0.0408 - 0.0005 & -0.0294 - 0.0029 \\
0.0404 - 0.0029 & 0.0196 - 0.0005 & 0.0404 - 0.0029 \\
-0.0194 - 0.0029 & -0.0385 - 0.0005 & -0.0194 - 0.0029
\end{pmatrix}
$$

$$
\bar{T}_X =
\begin{pmatrix}
0.0171 & -0.0205 & 0.0171 \\
-0.0323 & 0.0403 & -0.0323 \\
0.0375 & 0.0191 & 0.0375 \\
-0.0223 & -0.0390 & -0.0223
\end{pmatrix}
$$

---

**Step 4：计算 $\bar{T}_X^T \bar{T}_X$**

逐元素计算 Calculating each entry：

$(1,1)$：A 与 A 的内积 Inner product of A with A

$$
(0.0171)^2 + (-0.0323)^2 + (0.0375)^2 + (-0.0223)^2
$$

$$
= 0.000292 + 0.001043 + 0.001406 + 0.000497 = 0.003238
$$

$(2,2)$：B 与 B 的内积 Inner product of B with B

$$
(-0.0205)^2 + (0.0403)^2 + (0.0191)^2 + (-0.0390)^2
$$

$$
= 0.000420 + 0.001624 + 0.000365 + 0.001521 = 0.003930
$$

$(3,3)$：C 与 C 的内积 Inner product of C with C

$$
(0.0171)^2 + (-0.0323)^2 + (0.0375)^2 + (-0.0223)^2 = 0.003238
$$

> Note: A and C have identical returns, so their variance is the same.
> 注意：A 与 C 收益率完全相同，因此方差相等。

$(1,2) = (2,1)$：A 与 B 的内积 Inner product of A with B

$$
(0.0171)(-0.0205) + (-0.0323)(0.0403) + (0.0375)(0.0191) + (-0.0223)(-0.0390)
$$

$$
= -0.000351 - 0.001302 + 0.000716 + 0.000870 = -0.000067
$$

$(1,3) = (3,1)$：A 与 C 的内积 Inner product of A with C

$$
(0.0171)^2 + (-0.0323)^2 + (0.0375)^2 + (-0.0223)^2 = 0.003238
$$

$(2,3) = (3,2)$：B 与 C 的内积 Inner product of B with C

$$
(-0.0205)(0.0171) + (0.0403)(-0.0323) + (0.0191)(0.0375) + (-0.0390)(-0.0223)
$$

$$
= -0.000351 - 0.001302 + 0.000716 + 0.000870 = -0.000067
$$

因此 Therefore：

$$
\bar{T}_X^T \bar{T}_X =
\begin{pmatrix}
0.003238 & -0.000067 & 0.003238 \\
-0.000067 & 0.003930 & -0.000067 \\
0.003238 & -0.000067 & 0.003238
\end{pmatrix}
$$

---

**Step 5：除以 $N-1=3$，得到协方差矩阵**

$$
\hat{\Sigma}_X = \frac{1}{3}
\begin{pmatrix}
0.003238 & -0.000067 & 0.003238 \\
-0.000067 & 0.003930 & -0.000067 \\
0.003238 & -0.000067 & 0.003238
\end{pmatrix}
$$

$$
\boxed{
\hat{\Sigma}_X =
\begin{pmatrix}
0.001079 & -0.000022 & 0.001079 \\
-0.000022 & 0.001310 & -0.000022 \\
0.001079 & -0.000022 & 0.001079
\end{pmatrix}
}
$$

---

**结果解读 Interpretation：**

- Diagonal entries are the sample variances of A, B, C.
  对角线元素为各股票的样本方差。
- $\hat{\Sigma}(A,C) = 0.001079$: A and C are perfectly correlated —
  they have identical returns throughout the period.
  A 与 C 完全正相关，两者收益率完全一致。
- $\hat{\Sigma}(A,B) = \hat{\Sigma}(B,C) = -0.000022 \approx 0$:
  A, B and B, C have near-zero covariance.
  A 与 B、B 与 C 协方差接近 0，几乎不相关。
- Matrix is symmetric, confirming $\hat{\Sigma}_X(j,k) = \hat{\Sigma}_X(k,j)$.
  矩阵对称，验证协方差矩阵的对称性。

---

Summary
> Financial Insight 金融含义：The covariance matrix captures the
> co-movement between securities and is the key input for
> Markowitz portfolio optimization and risk management.
> 协方差矩阵描述证券之间的联动关系，是 Markowitz
> 组合优化和风险管理的核心输入。
> 协方差矩阵描述证券之间的联动关系，是 Markowitz
> 组合优化和风险管理的核心输入。
