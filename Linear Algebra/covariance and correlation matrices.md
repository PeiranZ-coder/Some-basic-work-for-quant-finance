Converting Between Covariance and Correlation Matrices
协方差矩阵与相关矩阵的转换

---

## Part 1：核心概念与公式 Core Concepts & Formulas

### 1. 协方差矩阵与相关矩阵的定义

$n$ 个随机变量 $X_1, X_2, \dots, X_n$ 的协方差矩阵 $\Sigma_X$ 
和相关矩阵 $\Omega_X$ 均为 $n \times n$ 矩阵：

$$
\Sigma_X(j,k) = \text{cov}(X_j, X_k), \quad \forall \; 1 \leq j,k \leq n
$$

$$
\Omega_X(j,k) = \text{corr}(X_j, X_k), \quad \forall \; 1 \leq j,k \leq n
$$

### 2. 协方差与相关系数的关系

$$
\text{cov}(X_j, X_k) = \sigma_j \sigma_k \cdot \text{corr}(X_j, X_k)
$$

因此：

$$
\Sigma_X(j,k) = \sigma_j \sigma_k \cdot \Omega_X(j,k), \quad \forall \; 1 \leq j,k \leq n
$$

### 3. 标准差对角矩阵 Diagonal Standard Deviation Matrix

$$
D_{\sigma X} = \text{diag}(\sigma_i)_{i=1:n}
= \text{diag}\left(\sqrt{\Sigma_X(i,i)}\right)_{i=1:n}
$$

注意：$\sigma_i^2 = \text{cov}(X_i, X_i) = \Sigma_X(i,i)$，
即对角线元素直接从 $\Sigma_X$ 提取。

### 4. 核心转换公式 Key Conversion Formulas

**协方差矩阵 → 相关矩阵：**

$$
\boxed{\Sigma_X = D_{\sigma X} \Omega_X D_{\sigma X}}
$$

**相关矩阵 → 协方差矩阵：**

$$
\boxed{\Omega_X = (D_{\sigma X})^{-1} \Sigma_X (D_{\sigma X})^{-1}}
$$

其中：

$$
(D_{\sigma X})^{-1} = \text{diag}\left(\frac{1}{\sigma_i}\right)_{i=1:n}
$$

### 5. 样本版本 Sample Version

样本标准差对角矩阵：

$$
\hat{D}_{\sigma X} = \text{diag}(\hat{\sigma}_i)_{i=1:n}
= \text{diag}\left(\sqrt{\hat{\Sigma}_X(i,i)}\right)_{i=1:n}
$$

样本相关系数：

$$
\widehat{\text{corr}}(X_j, X_k) =
\frac{\widehat{\text{cov}}(X_j, X_k)}{\hat{\sigma}_j \hat{\sigma}_k}
$$

样本转换公式：

$$
\hat{\Sigma}_X = \hat{D}_{\sigma X} \hat{\Omega}_X \hat{D}_{\sigma X}
$$

$$
\hat{\Omega}_X = (\hat{D}_{\sigma X})^{-1}
\hat{\Sigma}_X (\hat{D}_{\sigma X})^{-1}
$$

---

## Part 2：例题与计算过程 Example & Solution

### 例题 1：已知协方差矩阵，求相关矩阵

**原题：** 设三个随机变量的协方差矩阵为：

$$
\Sigma_X =
\begin{pmatrix}
1 & 0.1 & -0.6 \\
0.1 & 0.25 & 0.5 \\
-0.6 & 0.5 & 4
\end{pmatrix}
$$

求相关矩阵 $\Omega_X$。

**计算过程：**

**Step 1：提取标准差**

$$
\sigma_1 = \sqrt{\Sigma_X(1,1)} = \sqrt{1} = 1
$$

$$
\sigma_2 = \sqrt{\Sigma_X(2,2)} = \sqrt{0.25} = 0.5
$$

$$
\sigma_3 = \sqrt{\Sigma_X(3,3)} = \sqrt{4} = 2
$$

**Step 2：构造 $D_{\sigma X}$ 和 $(D_{\sigma X})^{-1}$**

$$
D_{\sigma X} =
\begin{pmatrix} 1 & 0 & 0 \\ 0 & \frac{1}{2} & 0 \\ 0 & 0 & 2 \end{pmatrix}
\quad
(D_{\sigma X})^{-1} =
\begin{pmatrix} 1 & 0 & 0 \\ 0 & 2 & 0 \\ 0 & 0 & \frac{1}{2} \end{pmatrix}
$$

**Step 3：代入公式**

$$
\Omega_X = (D_{\sigma X})^{-1} \Sigma_X (D_{\sigma X})^{-1} =
\begin{pmatrix}
1 & 0.2 & -0.3 \\
0.2 & 1 & 0.5 \\
-0.3 & 0.5 & 1
\end{pmatrix}
$$

> 注意：相关矩阵对角线恒为 1，验证结果正确。 $\square$

---



### Practice Problem

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

**(1)** 求各资产的样本标准差 $\hat{\sigma}_1, \hat{\sigma}_2, \hat{\sigma}_3, \hat{\sigma}_4$

**(2)** 构造标准差对角矩阵 $\hat{D}_{\sigma X}$ 和其逆矩阵 $(\hat{D}_{\sigma X})^{-1}$

**(3)** 求样本相关矩阵 $\hat{\Omega}_X$

**(4)** 验证：相关矩阵对角线是否全为 1？

---

**解答 Solution：**

**Step 1：提取标准差**

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

**Step 2：构造对角矩阵**

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

**Step 3：计算相关矩阵**

$$
\hat{\Omega}_X = (\hat{D}_{\sigma X})^{-1} \hat{\Sigma}_X (\hat{D}_{\sigma X})^{-1}
$$

每个元素的计算公式：

$$
\hat{\Omega}_X(j,k) = \frac{\hat{\Sigma}_X(j,k)}{\hat{\sigma}_j \cdot \hat{\sigma}_k}
$$

逐个计算：

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

最终相关矩阵：

$$
\hat{\Omega}_X =
\begin{pmatrix}
1 & 0.1 & -0.4 & 0.04 \\
0.1 & 1 & 0.4 & -0.04 \\
-0.4 & 0.4 & 1 & 0.04 \\
0.04 & -0.04 & 0.04 & 1
\end{pmatrix}
$$

**Step 4：验证**

对角线全为 1 ✓

矩阵对称 ✓

所有相关系数 $\in [-1, 1]$ ✓

**结果解读：**

| 资产对 | 相关系数 | 含义 |
|---|---|---|
| A & B | 0.1 | 弱正相关 |
| A & C | -0.4 | 中等负相关 |
| B & C | 0.4 | 中等正相关 |
| A & D | 0.04 | 几乎不相关 |

> 📌 A 与 C 负相关，在投资组合中搭配可以起到对冲效果。
$\square$
