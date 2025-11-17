from collections import deque

def bfs_shortest_path(adj_matrix, start, end):
    n = len(adj_matrix)
    
    # Если начальная и конечная вершины совпадают
    if start == end:
        return 0
    
    # Массив для отслеживания посещенных вершин
    visited = [False] * n
    # Массив для хранения расстояний от start до каждой вершины
    distance = [-1] * n
    
    # Очередь для BFS
    queue = deque()
    
    # Начинаем с начальной вершины
    visited[start] = True
    distance[start] = 0
    queue.append(start)
    
    while queue:
        current = queue.popleft()
        
        # Проверяем всех соседей текущей вершины
        for neighbor in range(n):
            # Если есть ребро и вершина еще не посещена
            if adj_matrix[current][neighbor] == 1 and not visited[neighbor]:
                visited[neighbor] = True
                distance[neighbor] = distance[current] + 1
                queue.append(neighbor)
                
                # Если достигли конечной вершины
                if neighbor == end:
                    return distance[neighbor]
    
    # Если путь не найден
    return -1

def main():
    import sys
    
    # Чтение входных данных
    data = sys.stdin.read().split()
    
    # Количество вершин
    n = int(data[0])
    
    # Чтение матрицы смежности
    matrix = []
    index = 1
    for i in range(n):
        row = list(map(int, data[index:index + n]))
        matrix.append(row)
        index += n
    
    # Чтение начальной и конечной вершин
    s = int(data[index])
    t = int(data[index + 1])
    
    # Поиск кратчайшего пути
    result = bfs_shortest_path(matrix, s, t)
    print(result)

if __name__ == "__main__":
    main()