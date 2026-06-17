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

### 例题 2：已知相关矩阵，求协方差矩阵

**原题：** 设三个随机变量的标准差为
$\sigma_1 = 2, \sigma_2 = 1, \sigma_3 = 0.9$，相关矩阵为：

$$
\Omega_X =
\begin{pmatrix}
1 & 0.15 & -0.2 \\
0.15 & 1 & 0.1 \\
-0.2 & 0.1 & 1
\end{pmatrix}
$$

求协方差矩阵 $\Sigma_X$。

**计算过程：**

**Step 1：构造 $D_{\sigma X}$**

$$
D_{\sigma X} =
\begin{pmatrix} 2 & 0 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 0.9 \end{pmatrix}
$$

**Step 2：代入公式**

$$
\Sigma_X = D_{\sigma X} \Omega_X D_{\sigma X} =
\begin{pmatrix}
4 & 0.3 & -0.36 \\
0.3 & 1 & 0.09 \\
-0.36 & 0.09 & 0.81
\end{pmatrix}
\quad \square
$$

---

## 总结 Summary

| 已知 | 求 | 公式 |
|---|---|---|
| $\Sigma_X$ | $\Omega_X$ | $\Omega_X = (D_{\sigma X})^{-1} \Sigma_X (D_{\sigma X})^{-1}$ |
| $\Omega_X$ | $\Sigma_X$ | $\Sigma_X = D_{\sigma X} \Omega_X D_{\sigma X}$ |
| $\Sigma_X$ | $D_{\sigma X}$ | $D_{\sigma X} = \text{diag}\left(\sqrt{\Sigma_X(i,i)}\right)$ |

> 📌 金融含义：相关矩阵剔除了量纲影响，
> 更直观地反映资产之间的线性关系强弱，
> 是风险模型和因子分析的重要工具。
