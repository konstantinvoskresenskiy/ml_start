import sys

def main():
    matrix=[]
    
    for line in sys.stdin:
        row=list(map(int,line.split()))
        if row:
            matrix.append(row)

    n=len(matrix)             

    for i in range(n):
        neighbors = []
        for j in range(n):
            if matrix[i][j] == 1:  
                neighbors.append(str(j))
        
        print(" ".join(neighbors))


if __name__ == '__main__':
    main()