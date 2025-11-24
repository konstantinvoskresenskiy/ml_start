import sys


def main():

    matrix = []
    
    for line in sys.stdin:
        row = list(map(int, line.split()))
        if row:  
            matrix.append(row)
    
    n = len(matrix)
    loops = []
    
    for i in range(n):
        if matrix[i][i] == 1: 
            loops.append(i)
    
    if loops:
        for vertex in loops:
            print(vertex)
    else:
        print("NO LOOPS")


if __name__ == '__main__':
    main()