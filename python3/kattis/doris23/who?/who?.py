import copy

board = [input().split() for _ in range(3)]

def do(board):    
    for i in range(3):
        if board[i][0] == board[i][1] and board[i][1] == board[i][2]:
            if board[i][0] == "X": return 0
            if board[i][0] == "O": return 1
        if board[0][i] == board[1][i] and board[1][i] == board[2][i]:
            if board[0][i] == "X": return 0
            if board[0][i] == "O": return 1   

    if board[0][0] == board[1][1] and board[1][1] == board[2][2]:
        if board[0][0] == "X": return 0
        elif board[0][0] == "O": return 1
    if board[0][2] == board[1][1] and board[1][1] == board[2][0]:
        if board[0][2] == "X": return 0
        elif board[0][2] == "O": return 1


    a = 0
    for i in range(3):
        for j in range(3):
            if board[i][j] != "_":
                a += 1

    if a == 9:
        return 4

    win = []

    if a % 2 == 0:
        for i in range(3):
            for j in range(3):
                if board[i][j] != "_":
                    continue
                b = copy.deepcopy(board)
                b[i][j] = "X"
                c = do(b)
                if len(win) == 0:
                    if c == 3:
                        return 3
                    elif c == 1:
                        win.append(1)
                    elif c == 0: 
                        win.append(0)

                elif c != 4 and c not in win:
                    return 3

                else:
                    win.append(c)
    else:
        for i in range(3):
            for j in range(3):
                if board[i][j] != "_":
                    continue
                b = copy.deepcopy(board)
                b[i][j] = "O"
                c = do(b)
                if len(win) == 0:
                    if c == 3:
                        return 3
                    elif c == 1:
                        win.append(1)
                    elif c == 0: 
                        win.append(0)

                elif c != 4 and c not in win:
                    return 3

                else:
                    win.append(c)

    if 0 in win:
        return 0
    elif 1 in win:
        return 1

    return 4

e = do(board)

if e == 0:
    print("Johan kan vinna")
elif e == 1:
    print("Abdullah kan vinna")
elif e == 3:
    print("Abdullah och Johan kan vinna")
else: 
    print("ingen kan vinna")
