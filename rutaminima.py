min_value = float("inf")
cheap_route = []

def min_route(matrix:list, n:int, cost:int=0, route:list=[0]):
    global min_value
    global cheap_route
    
    route_len = len(route)
    actual_node = route[route_len - 1]

    if actual_node == n - 1:
        
        cost += matrix[actual_node][n - 1] # Sumo el ultimo paso

        if cost < min_value: 
            min_value = cost
            cheap_route = route

    else:
        for i in range(actual_node + 1, n):
            min_route(matrix, n, cost + matrix[actual_node][i], route + [i])