import random
n = 20
trials = 100
deadEnds = 0

move = [(1, 0), (0, 1), (-1, 0), (0, -1)]


def can_move_dir(x, y, check):
    res = []
    for i in range(4):
        dx, dy = move[i]
        if x+dx < 0 or x+dx >= n or y+dy < 0 or y+dy >= n:
            continue
        if not check[x+dx][y+dy]:
            res.append(move[i])
    return res


def is_edge(x, y):
    if x == 0 or y == 0 or x == n-1 or y == n-1:
        return True
    else:
        return False


for t in range(trials):
    check = [[False for __ in range(n)] for _ in range(n)]
    x = n//2
    y = n//2

    while True:
        if is_edge(x, y):
            break

        check[x][y] = True
        dir = can_move_dir(x, y, check)

        if len(dir) == 0:
            deadEnds += 1
            break

        dx, dy = dir[random.randint(0, len(dir)-1)]
        x += dx
        y += dy


print(str(100*deadEnds//trials) + '% dead ends')