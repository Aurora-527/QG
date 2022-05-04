import numpy as np
import pandas as pd
#梯度下降
class LinearRegression1:
    def __init__(self):
        self.alpha = 0.001 #步长
        self.num = 1000 #迭代次数
        self.w = None
        
 
    def fit(self,X,y):
        X = np.hstack((X,np.ones(X.shape[0]).reshape(-1,1)))
        N, m = X.shape
        self.w = np.zeros(m)
        for i in range(self.num):
            grad = 2*X.T @ (X @ self.w - y)/N
            self.w -= self.alpha * grad 
        return self    
 
    def predict(self,X):
        x_b = np.hstack([np.ones((len(X),1)),X]) #第一个特征为1，故须创建一个矩阵与其拼接
        return x_b.dot(self.w)
        
#最小二乘
class LinearRegression2:
    def __init__(self):
        self.w_=None
    def fit(self,X,y):
        '''根据提提供的训练数据X，对模型进行训练。'''
        
        X = np.asmatrix(X.copy())  #这里创建X的拷贝对象，避免转换成矩阵时候失败
        y = np.asmatrix(y).reshape(-1,1)    #把数组转换为一列，依据数据自定义行的矩阵
        # 通过最小二乘公式，求解出最佳的权重值
        self.w_ = (X.T * X ).I * X.T * y
        return self
    def predict(self,X):
        '''根据参数传递的样本X数据进行预测。'''
        # 将X转换为矩阵
        X = np.asmatrix(X.copy())
        result = X * self.w_
        # 将矩阵转换为ndarray数组 ，进行扁平化处理(拉成一维数组) ，然后返回结果
        return np.array(result).ravel()
