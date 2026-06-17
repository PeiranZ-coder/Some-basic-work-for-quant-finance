# 1.4.1 Converting Between Covariance and Correlation Matrices
# 1.4.1 协方差矩阵与相关矩阵的转换

---

## Part 1：Core Concepts & Formulas 核心概念与公式

### 1. Definitions 定义

For $n$ random variables $X_1, X_2, \dots, X_n$, the covariance matrix
$\Sigma_X$ and correlation matrix $\Omega_X$ are both $n \times n$ matrices:

对于 $n$ 个随机变量 $X_1, X_2, \dots, X_n$，协方差矩阵 $\Sigma_X$
和相关矩阵 $\Omega_X$ 均为 $n \times n$ 矩阵：

$$
\Sigma_X(j,k) = \text{cov}(X_j, X_k), \quad \forall \; 1 \leq j,k \leq n
$$

$$
\Omega_X(j,k) = \text{corr}(X_j, X_k), \quad \forall \; 1 \leq j,k \leq n
$$

---

### 2. Relationship Between Covariance and Correlation
### 协方差与相关系数的关系

The covariance and correlation are related by the standard deviations:

协方差与相关系数通过标准差联系：

$$
\text{cov}(X_j, X_k) = \sigma_j \sigma_k \cdot \text{corr}(X_j, X_k)
$$

Therefore 因此：

$$
\Sigma_X(j,k) = \sigma_j \sigma_k \cdot \Omega_X(j,k),
\quad \forall \; 1 \leq j,k \leq n
$$

---

### 3. Diagonal Standard Deviation Matrix 标准差对角矩阵

$$
D_{\sigma X} = \text{diag}(\sigma_i)_{i=1:n}
= \text{diag}\left(\sqrt{\Sigma_X(i,i)}\right)_{i=1:n}
$$

Note that $\sigma_i^2 = \text{cov}(X_i, X_i) = \Sigma_X(i,i)$,
so the entries of $D_{\sigma X}$ can be obtained directly from $\Sigma_X$.

注意 $\sigma_i^2 = \Sigma_X(i,i)$，即标准差可直接从协方差矩阵对角线提取。

---

### 4. Key Conversion Formulas 核心转换公式

**Covariance → Correlation 协方差矩阵 → 相关矩阵：**

$$
\boxed{\Sigma_X = D_{\sigma X} \Omega_X D_{\sigma X}}
$$

**Correlation → Covariance 相关矩阵 → 协方差矩阵：**

$$
\boxed{\Omega_X = (D_{\sigma X})^{-1} \Sigma_X (D_{\sigma X})^{-1}}
$$

Where 其中：

$$
(D_{\sigma X})^{-1} = \text{diag}\left(\frac{1}{\sigma_i}\right)_{i=1:n}
$$

---

### 5. Sample Version 样本版本

Sample standard deviation diagonal matrix 样本标准差对角矩阵：

$$
\hat{D}_{\sigma X} = \text{diag}(\hat{\sigma}_i)_{i=1:n}
= \text{diag}\left(\sqrt{\hat{\Sigma}_X(i,i)}\right)_{i=1:n}
$$

Sample correlation coefficient 样本相关系数：

$$
\widehat{\text{corr}}(X_j, X_k) =
\frac{\widehat{\text{cov}}(X_j, X_k)}{\hat{\sigma}_j \hat{\sigma}_k}
$$

Sample conversion formulas 样本转换公式：

$$
\hat{\Sigma}_X = \hat{D}_{\sigma X} \hat{\Omega}_X \hat{D}_{\sigma X}
$$

$$
\hat{\Omega}_X = (\hat{D}_{\sigma X})^{-1}
\hat{\Sigma}_X (\hat{D}_{\sigma X})^{-1}
$$

---

## Part 2：Examples & Solutions 例题与计算过程

### Example 1 例题 1：Covariance → Correlation 已知协方差矩阵，求相关矩阵

**Problem 原题：**

Given the covariance matrix of three random variables:
设三个随机变量的协方差矩阵为：

$$
\Sigma_X =
\begin{pmatrix}
1 & 0.1 & -0.6 \\
0.1 & 0.25 & 0.5 \\
-0.6 & 0.5 & 4
\end{pmatrix}
$$

Find the correlation matrix $\Omega_X$.
求相关矩阵 $\Omega_X$。

**Solution 解答：**

**Step 1：Extract standard deviations 提取标准差**

$$
\sigma_1 = \sqrt{\Sigma_X(1,1)} = \sqrt{1} = 1
$$

$$
\sigma_2 = \sqrt{\Sigma_X(2,2)} = \sqrt{0.25} = 0.5
$$

$$
\sigma_3 = \sqrt{\Sigma_X(3,3)} = \sqrt{4} = 2
$$

**Step 2：Construct $D_{\sigma X}$ and $(D_{\sigma X})^{-1}$
构造对角矩阵及其逆**

$$
D_{\sigma X} =
\begin{pmatrix} 1 & 0 & 0 \\ 0 & 0.5 & 0 \\ 0 & 0 & 2 \end{pmatrix}
\qquad
(D_{\sigma X})^{-1} =
\begin{pmatrix} 1 & 0 & 0 \\ 0 & 2 & 0 \\ 0 & 0 & \frac{1}{2} \end{pmatrix}
$$

**Step 3：Apply formula 代入公式**

$$
\Omega_X = (D_{\sigma X})^{-1} \Sigma_X (D_{\sigma X})^{-1} =
\begin{pmatrix}
1 & 0.2 & -0.3 \\
0.2 & 1 & 0.5 \\
-0.3 & 0.5 & 1
\end{pmatrix}
$$

> Note: The diagonal entries of a correlation matrix are always 1. ✓
> 注意：相关矩阵对角线恒为 1，验证结果正确。 $\square$

---

### Practice Problem 练习题

**Problem 原题：**

Given the sample covariance matrix of four assets A, B, C, D:
设四个资产 A, B, C, D 的样本协方差矩阵为：

$$
\hat{\Sigma}_X =
\begin{pmatrix}
0.04 & 0.006 & -0.008 & 0.002 \\
0.006 & 0.09 & 0.012 & -0.003 \\
-0.008 & 0.012 & 0.01 & 0.001 \\
0.002 & -0.003 & 0.001 & 0.0625
\end{pmatrix}
$$

**(1)** Find the sample standard deviations
$\hat{\sigma}_1, \hat{\sigma}_2, \hat{\sigma}_3, \hat{\sigma}_4$

求各资产的样本标准差 $\hat{\sigma}_1, \hat{\sigma}_2, \hat{\sigma}_3, \hat{\sigma}_4$

**(2)** Construct $\hat{D}_{\sigma X}$ and $(\hat{D}_{\sigma X})^{-1}$

构造标准差对角矩阵及其逆矩阵

**(3)** Find the sample correlation matrix $\hat{\Omega}_X$

求样本相关矩阵 $\hat{\Omega}_X$

**(4)** Verify that the diagonal entries of $\hat{\Omega}_X$ are all 1

验证相关矩阵对角线是否全为 1

---

**Solution 解答：**

**Step 1：Extract standard deviations 提取标准差**

$$
\hat{\sigma}_1 = \sqrt{0.04} = 0.2
$$

$$
\hat{\sigma}_2 = \sqrt{0.09} = 0.3
$$

$$
\hat{\sigma}_3 = \sqrt{0.01} = 0.1
$$

$$
\hat{\sigma}_4 = \sqrt{0.0625} = 0.25
$$

**Step 2：Construct diagonal matrices 构造对角矩阵**

$$
\hat{D}_{\sigma X} =
\begin{pmatrix}
0.2 & 0 & 0 & 0 \\
0 & 0.3 & 0 & 0 \\
0 & 0 & 0.1 & 0 \\
0 & 0 & 0 & 0.25
\end{pmatrix}
$$

$$
(\hat{D}_{\sigma X})^{-1} =
\begin{pmatrix}
\frac{1}{0.2} & 0 & 0 & 0 \\
0 & \frac{1}{0.3} & 0 & 0 \\
0 & 0 & \frac{1}{0.1} & 0 \\
0 & 0 & 0 & \frac{1}{0.25}
\end{pmatrix}
=
\begin{pmatrix}
5 & 0 & 0 & 0 \\
0 & \frac{10}{3} & 0 & 0 \\
0 & 0 & 10 & 0 \\
0 & 0 & 0 & 4
\end{pmatrix}
$$

**Step 3：Compute correlation matrix 计算相关矩阵**

$$
\hat{\Omega}_X = (\hat{D}_{\sigma X})^{-1} \hat{\Sigma}_X (\hat{D}_{\sigma X})^{-1}
$$

Each entry is computed as 每个元素的计算公式：

$$
\hat{\Omega}_X(j,k) = \frac{\hat{\Sigma}_X(j,k)}{\hat{\sigma}_j \cdot \hat{\sigma}_k}
$$

Computing each entry 逐个计算：

$$
\hat{\Omega}_X(1,2) = \frac{0.006}{0.2 \times 0.3} = \frac{0.006}{0.06} = 0.1
$$

$$
\hat{\Omega}_X(1,3) = \frac{-0.008}{0.2 \times 0.1} = \frac{-0.008}{0.02} = -0.4
$$

$$
\hat{\Omega}_X(1,4) = \frac{0.002}{0.2 \times 0.25} = \frac{0.002}{0.05} = 0.04
$$

$$
\hat{\Omega}_X(2,3) = \frac{0.012}{0.3 \times 0.1} = \frac{0.012}{0.03} = 0.4
$$

$$
\hat{\Omega}_X(2,4) = \frac{-0.003}{0.3 \times 0.25} = \frac{-0.003}{0.075} = -0.04
$$

$$
\hat{\Omega}_X(3,4) = \frac{0.001}{0.1 \times 0.25} = \frac{0.001}{0.025} = 0.04
$$

Final correlation matrix 最终相关矩阵：

$$
\hat{\Omega}_X =
\begin{pmatrix}
1 & 0.1 & -0.4 & 0.04 \\
0.1 & 1 & 0.4 & -0.04 \\
-0.4 & 0.4 & 1 & 0.04 \\
0.04 & -0.04 & 0.04 & 1
\end{pmatrix}
$$

**Step 4：Verification 验证**

- Diagonal entries all equal 1 对角线全为 1 ✓
- Matrix is symmetric 矩阵对称 ✓
- All entries $\in [-1, 1]$ 所有相关系数在合理范围内 ✓

**Interpretation 结果解读：**

| Asset Pair 资产对 | Correlation 相关系数 | Meaning 含义 |
|---|---|---|
| A & B | 0.1 | Weak positive 弱正相关 |
| A & C | -0.4 | Moderate negative 中等负相关 |
| B & C | 0.4 | Moderate positive 中等正相关 |
| A & D | 0.04 | Nearly uncorrelated 几乎不相关 |

> 📌 A and C are negatively correlated — combining them in a portfolio
> provides a hedging effect.
> A 与 C 负相关，在投资组合中搭配可以起到对冲效果。 $\square$

---

## Summary 总结

| Given 已知 | Find 求 | Formula 公式 |
|---|---|---|
| $\Sigma_X$ | $\Omega_X$ | $\Omega_X = (D_{\sigma X})^{-1} \Sigma_X (D_{\sigma X})^{-1}$ |
| $\Omega_X$ | $\Sigma_X$ | $\Sigma_X = D_{\sigma X} \Omega_X D_{\sigma X}$ |
| $\Sigma_X$ | $D_{\sigma X}$ | $D_{\sigma X} = \text{diag}\left(\sqrt{\Sigma_X(i,i)}\right)$ |

> 📌 The correlation matrix removes the effect of scale, making it easier
> to compare the linear relationships between assets.
> 相关矩阵剔除了量纲影响，更直观地反映资产之间的线性关系强弱，
> 是风险模型和因子分析的重要工具。
