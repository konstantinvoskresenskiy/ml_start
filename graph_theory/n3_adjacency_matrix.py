import sys


def main():
    
    n = int(sys.stdin.readline().strip())
    
    
    matrix = [[0] * n for _ in range(n)]
    
    
    for i in range(n):
        line = sys.stdin.readline().strip()
        if line:  
            neighbors = list(map(int, line.split()))
            for j in neighbors:
                matrix[i][j] = 1
    
    for i in range(n):
        print(" ".join(map(str, matrix[i])))


if __name__ == '__main__':
    main()