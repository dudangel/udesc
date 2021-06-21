#Metodo das diferenças divididas (de Newton)
import matplotlib.pyplot as plt
import numpy as np

#(1,2), (2,5), (3,1), (4,3)
#com 4 pontos, teremos um polinomio de grau 3
x = [1, 2, 3, 4, 4.2, 4.7, 5, 7]
y = [2, 5, 1, 3, 1, 2, 10, -3]

def dividedDiff(x,y):
    Y = [item for item in y] #vai mudando a cada iteração
    n = len(y)
    coeffs = [y[0]] + [0] * (n-1)
    for i in range(n - 1):
        for j in range(n - 1 - i):
            numer = Y[j+1] - Y[j]
            denom = x[j+1+i] - x[j]
            Y[j] = numer / denom
        coeffs[i + 1] = Y[0]
    return coeffs


#equação do polinomio é gerada por essa funcao
#formato do polinomio: p(x) = a0 + a1*(x-x1) + a2*(x-x1)*(x-x2) + a3*(x-x1)*(x-x2)*(x-x3)
def eq(x, coeffs):
    n = len(x)
    equation = ''
    for i in range(n):
        sign = ''
        if i != 0:
            sign = "*"
        equation += f'{coeffs[i]:+}{sign}' + '*'.join([f'(x{-xj:+})' for j, xj in enumerate(x) if j < i])
    return equation

coeffs = dividedDiff(x, y)

print(coeffs) #4 elementos da coluna y
poly = eq(x, coeffs)

print('p(x) =', poly)

#plotando o grafico

#dominio
t = np.linspace(min(x), max(x), 100)

def p(x):
    return eval(poly)


plt.plot(t, p(t))
plt.scatter(x,y, zorder=10)
plt.savefig("divdiff.png")
