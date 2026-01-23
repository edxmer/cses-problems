
a = """0 3 2 3 2 3 2 3
3 4 1 2 3 2 3 4
2 1 4 3 2 3 4 3
3 2 3 2 3 4 3 4
2 3 2 3 4 3 4 5
3 2 3 4 3 4 5 4
2 3 4 3 4 5 4 5
3 4 3 4 5 4 5 6"""

b = """0 3 2 3 2 3 4 5 
3 4 1 2 3 4 3 4 
2 1 4 3 2 3 4 5 
3 2 3 2 3 4 3 4 
2 3 2 3 4 3 4 5 
3 4 3 4 3 4 5 4 
4 3 4 3 4 5 4 5 
5 4 5 4 5 4 5 6"""



xss = a.split('\n')
xss = [[int(x) for x in xs.split()] for xs in xss]

yss = b.split('\n')
yss = [[int(y) for y in ys.split()] for ys in yss]


for i in range(8):
    for j in range(8):
        print(str(abs(xss[i][j]-yss[i][j])) + " ", end="")
    print()
