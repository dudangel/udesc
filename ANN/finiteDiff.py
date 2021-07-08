




def f(x):
    # a função f(x) = x^x
    return x ** x

x0 = 2
ordem = 1

#pontos para contruir a formula
num_pontos = 5
a = x0 - 0.25
b = x0 + 0.25
xs = [a + (b - a) * random.random() for _ in range(num_pontos)]

r = finiteDiff(xs, ordem, x0, f)

print(f'aproximação para a derivada {ordem} de f no ponto {x0}', r)