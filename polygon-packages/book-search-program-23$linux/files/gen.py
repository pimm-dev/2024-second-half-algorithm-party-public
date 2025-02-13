from random import randrange

n, maxBookLength = 200, 200 # N과 각 book의 최대 길이 
m, maxQueryLength = 500, 500 # M과 각 Query의 최대 길이
maxTagLength = 20 # 각 name, author, tag의 최대 길이
t = 2 # 랜덤 생성되는 트리의 복잡도
dn, da, dt = 50, 50, 500

fileName = "max_size(20, 2)"
# f = open(f"C:/Youngdo/개발/2024 하반기 핌파티/{fileName}.txt", 'w')

def randStrGen(length):
    s = ""
    chrs = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_"
    for _ in range(length):
        s += "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_"[randrange(len(chrs))]
    return s

def genBook(length):
    s = ""
    while not s or len(s) > length:
        s = randStrGen(randrange(1, maxTagLength)) + " " + randStrGen(randrange(1, maxTagLength))
    while len(s) < length:
        tag = randStrGen(randrange(1, maxTagLength))
        if len(s) + len(tag) + 1 > length:
            break
        s += " " + tag
    return s

def genQuery(cur, cnt, tree, lower, visit):
    visit[cur] = True
    ran = randrange(4)
    ret = ""

    nxt = []
    for i in tree[cur]:
        if not visit[i]:
            nxt.append(i)

    if lower[cur] == 0:
        if ran == 0:
            ret += "n:" + names[randrange(1, len(names))]
        elif ran == 1:
            ss = names[randrange(1, len(names))]
            ret += "ni:" + ss
        elif ran == 2:
            ret += "a:" + authors[randrange(1, len(authors))]
        else:
            ret += "t:" + tags[randrange(1, len(tags))]

    elif lower[cur] == 1:
        if ran == 0:
            ret += "A("
        elif ran == 1:
            ret += "O("
        else:
            ret += "N("
        for i in range(len(nxt)):
            ret += genQuery(nxt[i], len(nxt)-i-1, tree, lower, visit)
        ret += ")"

    else:
        if ran%2:
            ret += "A("
        else:
            ret += "O("
        for i in range(len(nxt)):
            ret += genQuery(nxt[i], len(nxt)-i-1, tree, lower, visit)
        ret += ")"

    if cnt:
        ret += ", "

    return ret


# f.write(str(n)+"\n")
print(n)

v = True
cnt = 0
while v:
    v = False
    books = []
    strBooks = []
    for i in range(n):
        book = genBook(maxBookLength)
        books.append(book.split())
        strBooks.append(book)
    for i in range(n):
        for j in range(i+1, n):
            if books[i][:2] == books[j][:2]:
                v = True
                cnt += 1
                if cnt > 100:
                    print("book duped")
                    exit(0)
                break
for i in range(n):
    # f.write(strBooks[i]+"\n")
    print(strBooks[i])
        

names = [randStrGen(randrange(1, maxTagLength)) for _ in range(dn)]
for i in range(n):
    names.append(books[i][0])
authors = [randStrGen(randrange(1, maxTagLength)) for _ in range(da)]
for i in range(n):
    authors.append(books[i][1])
tags = [randStrGen(randrange(1, maxTagLength)) for _ in range(dt)]
for i in range(n):
    tags += books[i][2:]
tags = list(set(tags))

#f.write(str(m)+"\n")
print(m)

tsize = int(maxQueryLength//(4.5+maxTagLength))

for _ in range(m):
    arr = [0] * tsize
    for i in range(1, tsize):
        arr[i] = min([randrange(i) for _ in range(t)])

    lower = [0] * tsize
    for i in range(1, tsize):
        lower[arr[i]] += 1

    tree = [[] for _ in range(tsize)]
    for i in range(1, tsize):
        tree[i].append(arr[i])
        tree[arr[i]].append(i)

    visit = [False] * tsize
    res = ""
    while not res or len(res) > maxQueryLength:
        res = genQuery(0, 0, tree, lower, visit)
    #f.write(res+"\n")
    print(res)

#f.close()
