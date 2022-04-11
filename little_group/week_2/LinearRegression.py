import numpy as np
import pandas as pd
#梯度下降
class LinearRegression1:
    def __init__(self):
        self.interception = None #截距
        self.coef = None #即w，权重
        self._theta = None

    def fit(self, xtrain, ytrain):
        x_b = np.hstack([np.ones((len(xtrain), 1)), xtrain])#添加样本特征数据
        self._theta = np.linalg.inv(x_b.T.dot(x_b)).dot(x_b.T).dot(ytrain)#梯度下降公式
        self.coef = self._theta[1:]
        self.interception = self._theta[0]
        return self

    def predict(self, xtest):
        x_b = np.hstack([np.ones((len(xtest), 1)), xtest])
        return x_b.dot(self._theta)
        
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
        '''根据参数传递的样本X，delattr样本数据进行预测。
        '''
        # 将X转换为矩阵
        X = np.asmatrix(X.copy())
        result = X * self.w_
        # 将矩阵转换为ndarray数组 ，进行扁平化处理(拉成一维数组) ，然后返回结果
        return np.array(result).ravel()
