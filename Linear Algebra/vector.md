# 1. Vectors, Matrices & Vector Spaces
向量、矩阵与向量空间

---

## 1.1 Column & Row Vectors 列向量与行向量

**列向量 Column Vector：**
$$v = \begin{bmatrix} v_1 \\ v_2 \\ \vdots \\ v_n \end{bmatrix} \in \mathbb{R}^n$$

**行向量 Row Vector：**
$$v^T = \begin{bmatrix} v_1 & v_2 & \cdots & v_n \end{bmatrix}$$

> 📌 金融含义：一支证券在 $n$ 个时间点的收益可以表示为列向量。

---

## 1.2 Matrix Forms 矩阵形式

矩阵 $A \in \mathbb{R}^{m \times n}$ 可以从两个角度理解：

**列视角 Column Form：**
$$A = \begin{bmatrix} | & | & & | \\ a_1 & a_2 & \cdots & a_n \\ | & | & & | \end{bmatrix}$$

**行视角 Row Form：**
$$A = \begin{bmatrix} - & a_1^T & - \\ - & a_2^T & - \\ & \vdots & \\ - & a_m^T & - \end{bmatrix}$$

> 📌 金融含义：$A$ 可以表示 $n$ 支证券在 $m$ 个时间点的收益矩阵，
> 每一列是一支证券，每一行是一个时间点。

---

## 1.3 Matrix-Vector Multiplication 矩阵-向量乘法

$$Ax = \sum_{j=1}^n x_j a_j$$

即 $Ax$ 是 $A$ 的列向量的线性组合。

> 📌 金融含义：$Ax = b$ 中，$x$ 是投资组合权重，
> $b$ 是组合在各时间点的收益。

---

## 1.4 Matrix-Matrix Multiplication 矩阵-矩阵乘法

$$(AB)_{ij} = \sum_k A_{ik} B_{kj}$$

**定理：** 矩阵乘法满足结合律，但**不满足交换律**：
$$AB \neq BA \text{（一般情况下）}$$

---

## 1.5 Transposition 转置

$$(A^T)_{ij} = A_{ji}$$

**定理：**
$$(AB)^T = B^T A^T$$
$$(A^T)^T = A$$

> 📌 金融含义：协方差矩阵 $\Sigma = \frac{1}{T} X X^T$，
> 其中 $X$ 是去均值后的收益矩阵。

---

## 1.6 Covariance & Correlation Matrix 协方差与相关矩阵

**协方差矩阵 Covariance Matrix：**
$$\Sigma_{ij} = \text{Cov}(r_i, r_j) = \frac{1}{T}\sum_{t=1}^T (r_{i,t} - \bar{r}_i)(r_{j,t} - \bar{r}_j)$$

**相关矩阵 Correlation Matrix：**
$$\rho_{ij} = \frac{\Sigma_{ij}}{\sigma_i \sigma_j}$$

**转换关系：**
$$\Sigma = D \cdot C \cdot D$$

其中 $D = \text{diag}(\sigma_1, \dots, \sigma_n)$，$C$ 为相关矩阵。

> 📌 金融含义：$\Sigma$ 是风险管理和组合优化的核心输入。

---

## 1.7 Linear Independence 线性无关

**定义：** 向量组 $\{v_1, \dots, v_k\}$ 线性无关，若：
$$c_1 v_1 + \cdots + c_k v_k = 0 \implies c_1 = \cdots = c_k = 0$$

**定理：** $n$ 个向量在 $\mathbb{R}^n$ 中线性无关 $\iff$ 它们构成 $\mathbb{R}^n$ 的一组基。

> 📌 金融含义：若证券收益线性相关，则存在**冗余证券**，
> 市场不完全，无法对所有风险对冲。

---

## 1.8 Rank, Nullspace & Range 秩、零空间与值域

**秩 Rank：**
$$\text{rank}(A) = \text{列空间的维数} = \text{行空间的维数}$$

**零空间 Nullspace：**
$$\mathcal{N}(A) = \{x \in \mathbb{R}^n : Ax = 0\}$$

**值域 Range：**
$$\mathcal{R}(A) = \{Ax : x \in \mathbb{R}^n\}$$

**秩-零化度定理 Rank-Nullity Theorem：**
$$\text{rank}(A) + \text{nullity}(A) = n$$

> 📌 金融含义：$\text{rank}(A) < n$ 意味着市场不完全，
> 存在无法被复制的收益结构。

---

## 1.9 Nonsingular Matrices & Inverse 非奇异矩阵与逆

**定义：** 方阵 $A$ 非奇异（可逆），若存在 $A^{-1}$ 使得：
$$AA^{-1} = A^{-1}A = I$$

**等价条件：**
- $\det(A) \neq 0$
- $\text{rank}(A) = n$
- $A$ 的列向量线性无关
- $Ax = 0$ 只有零解

**定理：**
$$(AB)^{-1} = B^{-1}A^{-1}$$
$$(A^T)^{-1} = (A^{-1})^T$$

> 📌 金融含义：完全市场中，收益矩阵可逆，
> 任意收益流都可以被复制（Arrow-Debreu 证券）。

---

## 1.10 Special Matrices 特殊矩阵

**单位矩阵 Identity Matrix：**
$$I_{ij} = \begin{cases} 1 & i = j \\ 0 & i \neq j \end{cases}$$

**对角矩阵 Diagonal Matrix：**
$$D = \text{diag}(d_1, \dots, d_n), \quad (DA)_{ij} = d_i A_{ij}$$

**上/下三角矩阵 Triangular Matrix：**
$$U_{ij} = 0 \text{ if } i > j \quad \text{（上三角）}$$

> 📌 金融含义：Arrow-Debreu 证券对应单位矩阵的列，
> 每种证券只在一种状态下支付。

