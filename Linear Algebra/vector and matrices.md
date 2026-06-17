# 1. Vectors, Matrices & Vector Spaces
# 1. 向量、矩阵与向量空间

---

## 1.1 Column & Row Vectors
## 1.1 列向量与行向量

**列向量 Column Vector：**

$$
v = \begin{bmatrix} v_1 \\ v_2 \\ \vdots \\ v_n \end{bmatrix} \in \mathbb{R}^n
$$

**行向量 Row Vector：**

$$
v^T = \begin{bmatrix} v_1 & v_2 & \cdots & v_n \end{bmatrix}
$$

> 📌 **金融含义 Financial Meaning：** 一支证券在 $n$ 个时间点的收益可以表示为列向量。  
> A single security's returns over $n$ time periods can be represented as a column vector.

---

## 1.2 Matrix Forms
## 1.2 矩阵形式

矩阵 $A \in \mathbb{R}^{m \times n}$ 可以从两个角度理解：  
A matrix $A \in \mathbb{R}^{m \times n}$ can be understood from two perspectives:

**列视角 Column Form：**

$$
A = \begin{bmatrix} a_1 & a_2 & \cdots & a_n \end{bmatrix}
$$

**行视角 Row Form：**

$$
A = \begin{bmatrix} a_1^T \\ a_2^T \\ \vdots \\ a_m^T \end{bmatrix}
$$

> 📌 **金融含义 Financial Meaning：** $A$ 表示 $n$ 支证券在 $m$ 个时间点的收益矩阵，每一列是一支证券，每一行是一个时间点。  
> $A$ represents the return matrix of $n$ securities over $m$ time periods, where each column is a security and each row is a time period.

---

## 1.3 Matrix-Vector Multiplication
## 1.3 矩阵-向量乘法

$$
Ax = \sum_{j=1}^n x_j a_j
$$

即 $Ax$ 是 $A$ 的列向量的线性组合。  
That is, $Ax$ is a linear combination of the column vectors of $A$.

> 📌 **金融含义 Financial Meaning：** $x$ 是投资组合权重向量，$Ax$ 是组合在各时间点的收益。  
> $x$ is the portfolio weight vector, and $Ax$ is the portfolio's returns at each time period.

---

## 1.4 Matrix-Matrix Multiplication
## 1.4 矩阵-矩阵乘法

$$
(AB)_{ij} = \sum_k A_{ik} B_{kj}
$$

**定理 Theorem：** 矩阵乘法满足结合律，但不满足交换律：  
Matrix multiplication is associative but not commutative:

$$
AB \neq BA \quad \text{（一般情况下 / in general）}
$$

---

## 1.5 Transposition
## 1.5 转置

$$
(A^T)_{ij} = A_{ji}
$$

**定理 Theorem：**

$$
(AB)^T = B^T A^T
$$

$$
(A^T)^T = A
$$

> 📌 **金融含义 Financial Meaning：** 协方差矩阵通过转置计算，$\Sigma = \frac{1}{T} X X^T$。  
> The covariance matrix is computed via transposition: $\Sigma = \frac{1}{T} X X^T$.

---

## 1.6 Covariance & Correlation Matrix
## 1.6 协方差与相关矩阵

**协方差矩阵 Covariance Matrix：**

$$
\Sigma_{ij} = \frac{1}{T}\sum_{t=1}^T (r_{i,t} - \bar{r}_i)(r_{j,t} - \bar{r}_j)
$$

> ⚠️ **注 Note：** 此处使用总体协方差（除以 $T$）。实际金融应用中，样本协方差通常使用无偏估计量（除以 $T-1$）。  
> This uses the population covariance (dividing by $T$). In practice, sample covariance typically uses the unbiased estimator (dividing by $T-1$).

**相关矩阵 Correlation Matrix：**

$$
\rho_{ij} = \frac{\Sigma_{ij}}{\sigma_i \sigma_j}
$$

**协方差与相关矩阵转换 Conversion between Covariance and Correlation Matrices：**

$$
\Sigma = D \cdot C \cdot D
$$

其中 $D = \text{diag}(\sigma_1, \dots, \sigma_n)$，$C$ 为相关矩阵。  
where $D = \text{diag}(\sigma_1, \dots, \sigma_n)$ and $C$ is the correlation matrix.

> 📌 **金融含义 Financial Meaning：** $\Sigma$ 是风险管理和投资组合优化的核心输入。  
> $\Sigma$ is a core input for risk management and portfolio optimization.

---

## 1.7 Linear Independence
## 1.7 线性无关

**定义 Definition：** 向量组 $\{v_1, \dots, v_k\}$ 线性无关，若：  
A set of vectors $\{v_1, \dots, v_k\}$ is linearly independent if:

$$
c_1 v_1 + \cdots + c_k v_k = 0 \implies c_1 = \cdots = c_k = 0
$$

**定理 Theorem：** $n$ 个向量在 $\mathbb{R}^n$ 中线性无关 $\iff$ 它们构成 $\mathbb{R}^n$ 的一组基。  
$n$ vectors in $\mathbb{R}^n$ are linearly independent $\iff$ they form a basis for $\mathbb{R}^n$.

> 📌 **金融含义 Financial Meaning：** 若证券收益线性相关，则存在冗余证券，市场不完全，无法对所有风险对冲。  
> If security returns are linearly dependent, then there exist redundant securities, the market is incomplete, and not all risks can be hedged.

---

## 1.8 Rank, Nullspace & Range
## 1.8 秩、零空间与值域

**秩 Rank：**

$$
\text{rank}(A) = \text{列空间的维数} = \text{行空间的维数}
$$

$$
\text{rank}(A) = \dim(\text{column space}) = \dim(\text{row space})
$$

**零空间 Nullspace：**

$$
\mathcal{N}(A) = \{x \in \mathbb{R}^n : Ax = 0\}
$$

**值域 Range：**

$$
\mathcal{R}(A) = \{Ax : x \in \mathbb{R}^n\}
$$

**秩-零化度定理 Rank-Nullity Theorem：**

$$
\text{rank}(A) + \text{nullity}(A) = n
$$

> 📌 **金融含义 Financial Meaning：** $\text{rank}(A) < n$ 意味着市场不完全，存在无法被复制的收益结构。  
> $\text{rank}(A) < n$ implies that the market is incomplete, and there exist return structures that cannot be replicated.

---

## 1.9 Nonsingular Matrices & Inverse
## 1.9 非奇异矩阵与逆

**定义 Definition：** 方阵 $A$ 可逆，若存在 $A^{-1}$ 使得：  
A square matrix $A$ is invertible if there exists $A^{-1}$ such that:

$$
AA^{-1} = A^{-1}A = I
$$

**等价条件 Equivalent Conditions：**

- $\det(A) \neq 0$
- $\text{rank}(A) = n$
- $A$ 的列向量线性无关 / The columns of $A$ are linearly independent
- $Ax = 0$ 只有零解 / $Ax = 0$ has only the zero solution

**定理 Theorem：**

$$
(AB)^{-1} = B^{-1}A^{-1}
$$

$$
(A^T)^{-1} = (A^{-1})^T
$$

> 📌 **金融含义 Financial Meaning：** 完全市场中收益矩阵可逆，任意收益流都可以被复制。  
> In a complete market, the return matrix is invertible, and any payoff stream can be replicated.

---

## 1.10 Special Matrices
## 1.10 特殊矩阵

**单位矩阵 Identity Matrix：**

$$
I_{ij} = \begin{cases} 1 & i = j \\ 0 & i \neq j \end{cases}
$$

**对角矩阵 Diagonal Matrix：**

$$
D = \text{diag}(d_1, \dots, d_n), \quad (DA)_{ij} = d_i A_{ij}
$$

**上三角矩阵 Upper Triangular Matrix：**

$$
U_{ij} = 0 \quad \text{if } i > j
$$

> 📌 **金融含义 Financial Meaning：** Arrow-Debreu 证券对应单位矩阵的列，每种证券只在一种状态下支付。  
> Arrow-Debreu securities correspond to the columns of the identity matrix, where each security pays off in only one state.


## Summary

| 概念 Concept | 核心公式 Core Formula | 金融应用 Financial Application |
|:---|:---|:---|
| 列向量 Column Vector | $v \in \mathbb{R}^n$ | 证券收益序列 Security return series |
| 矩阵 Matrix | $A \in \mathbb{R}^{m \times n}$ | 多资产收益矩阵 Multi-asset return matrix |
| 转置 Transpose | $(A^T)_{ij} = A_{ji}$ | 协方差矩阵计算 Covariance matrix computation |
| 协方差矩阵 Covariance Matrix | $\Sigma = \frac{1}{T}XX^T$ | 风险度量 Risk measurement |
| 线性无关 Linear Independence | $c_1v_1+\cdots+c_kv_k=0 \Rightarrow c_i=0$ | 无冗余证券 No redundant securities |
| 秩 Rank | $\text{rank}(A)$ | 市场完全性判断 Market completeness assessment |
| 可逆矩阵 Invertible Matrix | $AA^{-1}=I$ | 完全市场复制 Complete market replication |
| Arrow-Debreu | 单位矩阵的列 Columns of identity matrix | 状态价格定价 State-price pricing |


