#include "Assistance.h"				// 辅助软件包
#include "TriSparseMatrix.h"		// 稀疏矩阵的三元组顺序表

int main()
{

	try								// 用try封装可能出现异常的代码
	{
		const int rs = 7, cs = 6;
		TriSparseMatrix<int> a(rs, cs);	// 定义一个n行n列稀疏矩阵
		TriSparseMatrix<int> c(rs, cs);	// 定义一个n行n列稀疏矩阵
		int m[rs][cs] = {
			15,	 0,	 0,	22,	 0, -5,
			 0,	11,	 3,	 0,	 0,  0,
			 0,	 0,	 0,	 6,	 0,  0,
			 0,	 0,	 0,	 0,	 0,  0,
			91,	 0,	 0,	 0,	 0,  0,
			 0,  7,  0,  0,  0,  0,
			 0,  0, 28,  0,  0,  0
		};
		int n[rs][cs] = {
			15,	 0,	 0,	 8,	 0,  5,
			 0,	-1,	-3,	 0,	 0,  0,
			 0,	 0,	 0,	14,	 0,  0,
			 0,	 0,	 0,	 0,	 0,  0,
			 9,	 0,	 0,	 0,	 0,  7,
			 0, 13,  0,  0,  0,  0,
			 0,  0, -8,  0,  0,  0
		};
		int i, j, v;					// 临时变量	

		// 设置稀疏矩阵a的元素值
		for (i = 0; i < rs; i++)
			for (j = 0; j < cs; j++)
				a.SetElem(i, j, m[i][j]);	// 设置元素值

		// 显示稀疏矩阵a
		cout << "显示稀疏矩阵a" << endl;
		for (i = 0; i < a.GetRows(); i++) {
			for (j = 0; j < a.GetCols(); j++) {
				a.GetElem(i, j, v);		// 取元素值
				cout << v << "\t";		// 显示元素值
			}
			cout << endl;
		}
		cout << endl;
		TriSparseMatrix<int> b(a);		// 复制构造函数
		cout << endl;
		// 设置稀疏矩阵c的元素值
		for (i = 0; i < rs; i++)
			for (j = 0; j < cs; j++)
				c.SetElem(i, j, n[i][j]);	// 设置元素值

		// 显示稀疏矩阵c
		cout << "显示稀疏矩阵c" << endl;
		for (i = 0; i < c.GetRows(); i++) {
			for (j = 0; j < c.GetCols(); j++) {
				c.GetElem(i, j, v);		// 取元素值
				cout << v << "\t";		// 显示元素值
			}
			cout << endl;
		}

		cout << endl;
		cout << "简单转置" << endl;
		a.SimpleTranspose(b);
		for (i = 0; i < b.GetRows(); i++) {
			for (j = 0; j < b.GetCols(); j++) {
				b.GetElem(i, j, v);		// 求元素值
				cout << v << "\t";		// 显示元素值
			}
			cout << endl;
		}

		cout << endl;
		cout << "快速转置" << endl;
		a.FastTranspose(b);
		for (i = 0; i < b.GetRows(); i++) {
			for (j = 0; j < b.GetCols(); j++) {
				b.GetElem(i, j, v);		// 求元素值
				cout << v << "\t";		// 显示元素值
			}
			cout << endl;
		}

		cout << endl;
		cout << "矩阵相加" << endl;
		TriSparseMatrix<int> d(a+c);
		cout << endl;
		for (i = 0; i < d.GetRows(); i++) {
			for (j = 0; j < d.GetCols(); j++) {
				d.GetElem(i, j, v);		// 求元素值
				cout << v << "\t";		// 显示元素值
			}
			cout << endl;
		}

	}
	catch (Error err)		// 捕捉并处理异常
	{
		err.Show();			// 显示异常信息
	}

	system("PAUSE");        // 调用库函数system()
	return 0;               // 返回值0, 返回操作系统
}


