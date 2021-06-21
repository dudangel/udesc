from matplotlib import pyplot as plt
import numpy as np

def lagrange(x, y):
    #Eq do polinomio de lagrange
    n = len(x)
    if n == len(y):
        eq = ''
        for k in range(n):
            numer = '*'.join([f'(x{-xi:+})' for i, xi in enumerate(x) if i != k])
            denom = '*'.join([f'({x[k]}{-xi:+})' for i, xi in enumerate(x) if i != k])
            eq += f'{y[k]:+}*({numer})/({denom})'
        return eq
    else:
        raise TypeError('O número de coordenadas x é diferente do número de coordenadas y')


if __name__ == '__main__':

    x = [1, 2, 3, 3.2, 4.1, 5.7] #coordenadas x dos pontos
    y = [2, 5, 1, 2, 1, 10] #coordenadas y dos pontos

    eq = lagrange(x,y)

    # def subs(x):
    #     return eval(eq)

    # print('p(x) = ', eq)

    # print(subs(1), subs(2), subs(3))

    def f(x):
        return 1 / (1 + 25 * x ** 2)
    
    num = 20 
    #As vezes colocar mais pontos apenas afasta o polinomio interpolador do grafico da funcao, isso é chamado de fenomeno de runge (num = 20)
    #portanto, aumentar o nro de pontos para obter uma melhor aproximação nao é uma boa ideia por conta do fenomeno de runge

    x2 = [-1 + (2/(num - 1)) * i for i in range(num)]
    y2 = [f(i) for i in x2]
    # print(x2)
    # print(y2)
    eq2 = lagrange(x2,y2)  #eq do polinomio interpolador de lagrande na lista de pontos dada por x2,y2

    def subs(x):
        return eval(eq2)

    print('p(x) =', eq2)

    #vamos plotar os graficos
    # t da o dominio e por isso ao alterar as coordenadas deve-se alterar o dominio informado em t
    t = np.linspace(-1, 1, 200)  #cria uma lista de 100 pontos espaçados igualmente dentro do intervalo [1,3]

    #plotando o grafico do polinomio interpolador
    plt.plot(t, subs(t), label='lagrange')  #representa as coordenadas x,y

    plt.plot(t, f(t), label='funcao') #grafico da funcao

    plt.scatter(x2,y2) #plotando os pontos das coordenadas x,y
    
    plt.legend()

    plt.savefig('lagrange.png')
