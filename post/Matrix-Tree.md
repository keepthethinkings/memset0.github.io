# Matrix-Tree定理

> Matrix-Tree定理用于图的生成树计数。复杂度为$O(n^3)$.

## 离散拉普拉斯算子

给定了一个图，我们先求出它的度数矩阵$D$和邻接矩阵$A$：

> 度数矩阵：`D[x][x]`表示点$x$的度数，其它元素为$0$.  
> 邻接矩阵：`A[i][j]`代表$i$到$j$是否有边。有边则为$1$，否则为$0$.

由此计算出**基尔霍夫矩阵**`C`：$C=D-A$

例子：三个点的完全图：

它的D矩阵（度数矩阵）是：
```
2 0 0
0 2 0
0 0 2
```

它的A矩阵（邻接矩阵）是：
```
0 1 1
1 0 1 
1 1 0
```

它的C矩阵（基尔霍夫矩阵）是：
```
2 -1 -1
-1 2 -1
-1 -1 2
```

我们把计算出基尔霍夫矩阵的运算称作**离散拉普拉斯算子**。

## Matrix-Tree定理

Matrix-Tree定理的内容是：

> 对于一个基尔霍夫矩阵，随意去掉第`r`行和第`r`列（$r \in [1,n]$），留下的这个矩阵的行列式的**绝对值**，就是生成树的个数。

一般这样操作：对于一个基尔霍夫矩阵，扔掉最后一行和最后一列，算出它的行列式值即可。

还是看上面的例子。扔掉最后一行和最后一列，C矩阵变成：
```
2 -1
-1 2
```
它的行列式值为$2\times 2 - (-1) \times (-1) = 3$.  
所以这个图共有3个生成树。

## 行列式求值

如何求行列式的值？

我们只需要像高斯消元那样，把行列式弄成上三角矩阵，然后算出$C[1][1]\times C[2][2] \times \cdots \times C[n][n]$，它就是行列式的值。

一个$3\times 3$的例子：

行列式：
```
 2    -1    -1
-1     2    -1
-1    -1     2
```

第一次消元之后：
```
 2    -1    -1
 0     3    -3
 0    -3     3
```

第二次消元之后：
```
 2    -1    -1
 0     3    -3
 0     0     0
```

然后算出$2 \times 3 \times 0 = 0$，它就是行列式的值。

附上代码：
```cpp
void getValue()
{
	int a,i,j;
	double v;
	
	for(a=1;a<n;a++)
		for(i=a+1;i<=n;i++)
		{
			v=C[i][a]/C[a][a];
			for(j=a;j<=n;j++)
				C[i][j]-=v*C[a][j];
		}
	
	v=1;
	for(i=1;i<=n;i++)
		v*=C[i][i];
	if(v<0) v=-v;
	
	printf("%.0f",v);
}
```

## 一些值得考虑的问题

### 如何保证消元的精度？

采用**列主元法**消元。  
假设我们现在考虑元$p$，我们就把$p$的系数**绝对值最大**的那一行，拿来消其他的行。

### 如果消元时遇到所有列都为0怎么办？

正常情况下，不会遇到这种事情。  
如果遇到了，说明整个图根本**不连通**，那生成树的个数显然是$0$了。



