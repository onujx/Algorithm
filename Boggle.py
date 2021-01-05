rl = lambda: input().strip()  # 입력받아서 양쪽의 공백과 \n 모두 삭제
cases = int(rl())   # 첫번째 줄의 값이 해당
seen = set()


def find(board, y, x, word, s):
    if (y, x, s) in seen: return False  
    seen.add((y, x, s))
    if s == len(word): return True
    if not (0 <= y < 5 and 0 <= x < 5): return False
    if word[s] != board[y][x]: return False
    for dx in range(-1, 2):
        for dy in range(-1, 2):
            if dx or dy:
                if find(board, y + dy, x + dx, word, s + 1):
                    return True
    return False


for cc in range(cases):
    board = [rl() for i in range(5)]
    w = int(rl()) # 단어의 개수
    for i in range(w):
        word = rl()
        seen = set()
        if any(find(board, i, j, word, 0) for i in range(5) for j in range(5)):
            # 5x5 격자에서 찾으므로
            print(word, 'YES')
        else:
            print(word, 'NO')
