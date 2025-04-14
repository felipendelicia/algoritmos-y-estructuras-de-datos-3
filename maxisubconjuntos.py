matriz = [
    [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
    [2, 11, 12, 13, 14, 15, 16, 17, 18, 19],
    [3, 12, 20, 21, 22, 23, 24, 25, 26, 27],
    [4, 13, 21, 28, 29, 30, 31, 32, 33, 34],
    [5, 14, 22, 29, 35, 36, 37, 38, 39, 40],
    [6, 15, 23, 30, 36, 41, 42, 43, 44, 45],
    [7, 16, 24, 31, 37, 42, 46, 47, 48, 49],
    [8, 17, 25, 32, 38, 43, 47, 50, 51, 52],
    [9, 18, 26, 33, 39, 44, 48, 51, 53, 54],
    [10, 19, 27, 34, 40, 45, 49, 52, 54, 55]
]

k:int = 10
i_max:set = set([])
suma_max:int = 0
memo:list = []

def sumar_matriz(matriz:list, i:set)->int:
    resultado = 0
    i_list = list(i)

    for j in i_list:
        for k in i_list:
            resultado += matriz[j][k]

    return resultado

def suma_optima_matriz(matriz:list, k:int, i_actual:set)->set:
    global i_max
    global suma_max
    global memo

    n = len(matriz)
    len_i = 0 if i_actual == set() else len(i_actual)
    
    if len_i != k:
        for i in range(n):
            if i not in i_actual:
                new_set = set(i_actual)
                new_set.add(i)
                suma_optima_matriz(matriz, k, new_set)

    else:
        if i_actual not in memo:
            memo.append(i_actual)

            suma_matriz_actual = sumar_matriz(matriz, i_actual)
            if i_max == {}: 
                i_max = i_actual
                suma_max = suma_matriz_actual
            else:
                if sumar_matriz(matriz, i_max) < suma_matriz_actual: 
                    i_max = i_actual
                    suma_max = suma_matriz_actual
        
suma_optima_matriz(matriz, k, set())

