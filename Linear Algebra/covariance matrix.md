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

Let $n = 3$ stocks: A, B, C, observed over $N = 4$ time periods.
设有 $n = 3$ 支股票：A, B, C，在 $N = 4$ 个时间点上的收益率如下：

| Time $t_i$ | A | B | C |
|---|---|---|---|
| $t_1$ | 0.10 | 0.20 | 0.30 |
| $t_2$ | 0.20 | 0.10 | 0.10 |
| $t_3$ | -0.10 | 0.30 | 0.20 |
| $t_4$ | 0.20 | -0.10 | -0.20 |

Compute the sample covariance matrix $\hat{\Sigma}_X$.
求样本协方差矩阵 $\hat{\Sigma}_X$。

---

### 计算过程 Solution

**Step 1：写出数据矩阵 $T_X$（$4 \times 3$）**

$$
T_X =
\begin{pmatrix}
0.10 & 0.20 & 0.30 \\
0.20 & 0.10 & 0.10 \\
-0.10 & 0.30 & 0.20 \\
0.20 & -0.10 & -0.20
\end{pmatrix}
$$

---

**Step 2：计算样本均值 Compute Sample Means**

$$
\hat{\mu}_{X_k} = \frac{1}{4} \sum_{i=1}^{4} T_X(i,k)
$$

$$
\hat{\mu}_A = \frac{0.10 + 0.20 + (-0.10) + 0.20}{4}
= \frac{0.40}{4} = 0.10
$$

$$
\hat{\mu}_B = \frac{0.20 + 0.10 + 0.30 + (-0.10)}{4}
= \frac{0.50}{4} = 0.125
$$

$$
\hat{\mu}_C = \frac{0.30 + 0.10 + 0.20 + (-0.20)}{4}
= \frac{0.40}{4} = 0.10
$$

| Stock 股票 | A | B | C |
|---|---|---|---|
| $\hat{\mu}$ | 0.100 | 0.125 | 0.100 |

---

**Step 3：去均值 Demean the Matrix**

$$
\bar{T}_X(i,k) = T_X(i,k) - \hat{\mu}_{X_k}
$$

$$
\bar{T}_X =
\begin{pmatrix}
0.10 - 0.10 & 0.20 - 0.125 & 0.30 - 0.10 \\
0.20 - 0.10 & 0.10 - 0.125 & 0.10 - 0.10 \\
-0.10 - 0.10 & 0.30 - 0.125 & 0.20 - 0.10 \\
0.20 - 0.10 & -0.10 - 0.125 & -0.20 - 0.10
\end{pmatrix}
$$

$$
\bar{T}_X =
\begin{pmatrix}
0.00 & 0.075 & 0.20 \\
0.10 & -0.025 & 0.00 \\
-0.20 & 0.175 & 0.10 \\
0.10 & -0.225 & -0.30
\end{pmatrix}
$$

---

**Step 4：计算 $\bar{T}_X^T \bar{T}_X$**

$$
\bar{T}_X^T \bar{T}_X = 
\begin{pmatrix}
0.00 & 0.10 & -0.20 & 0.10 \\
0.075 & -0.025 & 0.175 & -0.225 \\
0.20 & 0.00 & 0.10 & -0.30
\end{pmatrix}
\begin{pmatrix}
0.00 & 0.075 & 0.20 \\
0.10 & -0.025 & 0.00 \\
-0.20 & 0.175 & 0.10 \\
0.10 & -0.225 & -0.30
\end{pmatrix}
$$

逐元素计算：

$(1,1)$：$A$ 与 $A$ 的内积

$$
(0.00)^2 + (0.10)^2 + (-0.20)^2 + (0.10)^2
= 0 + 0.01 + 0.04 + 0.01 = 0.06
$$

$(2,2)$：$B$ 与 $B$ 的内积

$$
(0.075)^2 + (-0.025)^2 + (0.175)^2 + (-0.225)^2
= 0.005625 + 0.000625 + 0.030625 + 0.050625 = 0.0875
$$

$(3,3)$：$C$ 与 $C$ 的内积

$$
(0.20)^2 + (0.00)^2 + (0.10)^2 + (-0.30)^2
= 0.04 + 0 + 0.01 + 0.09 = 0.14
$$

$(1,2) = (2,1)$：$A$ 与 $B$ 的内积

$$
(0.00)(0.075) + (0.10)(-0.025) + (-0.20)(0.175) + (0.10)(-0.225)
= 0 - 0.0025 - 0.035 - 0.0225 = -0.06
$$

$(1,3) = (3,1)$：$A$ 与 $C$ 的内积

$$
(0.00)(0.20) + (0.10)(0.00) + (-0.20)(0.10) + (0.10)(-0.30)
= 0 + 0 - 0.02 - 0.03 = -0.05
$$

$(2,3) = (3,2)$：$B$ 与 $C$ 的内积

$$
(0.075)(0.20) + (-0.025)(0.00) + (0.175)(0.10) + (-0.225)(-0.30)
= 0.015 + 0 + 0.0175 + 0.0675 = 0.10
$$

因此：

$$
\bar{T}_X^T \bar{T}_X =
\begin{pmatrix}
0.06 & -0.06 & -0.05 \\
-0.06 & 0.0875 & 0.10 \\
-0.05 & 0.10 & 0.14
\end{pmatrix}
$$

---

**Step 5：除以 $N-1 = 3$，得到协方差矩阵**

$$
\hat{\Sigma}_X = \frac{1}{3}
\begin{pmatrix}
0.06 & -0.06 & -0.05 \\
-0.06 & 0.0875 & 0.10 \\
-0.05 & 0.10 & 0.14
\end{pmatrix}
$$

$$
\boxed{
\hat{\Sigma}_X =
\begin{pmatrix}
0.0200 & -0.0200 & -0.0167 \\
-0.0200 & 0.0292 & 0.0333 \\
-0.0167 & 0.0333 & 0.0467
\end{pmatrix}
}
$$

---

**结果解读 Interpretation：**

- Diagonal: sample variances of A, B, C.
  对角线：A, B, C 各自的样本方差。
- $\hat{\Sigma}(A,B) = -0.0200 < 0$: A and B tend to move in opposite directions.
  A 与 B 负相关，走势相反。
- $\hat{\Sigma}(B,C) = 0.0333 > 0$: B and C tend to move together.
  B 与 C 正相关，走势相同。
- Matrix is symmetric, confirming $\hat{\Sigma}_X(j,k) = \hat{\Sigma}_X(k,j)$.
  矩阵对称，验证协方差矩阵的对称性。

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
