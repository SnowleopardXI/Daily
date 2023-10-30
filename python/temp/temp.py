def decode(code):
    for i in range(len(code)-2, -1, -1):
        code[i] += code[i+1]
    return [int(x) for x in code]

def encode(code):
    for i in range(len(code)-2, -1, -1):
        code[i] -= code[i+1]
    return [int(x) for x in code]

if __name__ == '__main__':
    code = [1, 0, 1, 1, 0, 1, 0, 0, 1, 1]
    print(decode(code.copy()))  # Using copy() to prevent modification of original code list
    print(encode(code.copy()))
