def generateCRC(code, div):
    rem = div.copy()
    for ctr in range(0, len(div)):
        rem[ctr] = code[ctr] ^ div[ctr]
        code.append(0)
    code = code[0:-1]
    for ctr in range(len(div), len(code)):
        remainder = rem.copy()
        remainder = remainder[1:]  #Removes the first 0
        remainder.append(code[ctr])
        while remainder[
                0] == 0 and ctr < len(code) - 1:  #borrows one zero of next bit
            remainder = remainder[1:]
            ctr += 1
            remainder.append(code[ctr])
        if remainder[0] != 0:
            for t in range(0, len(div)):
                rem[t] = remainder[t] ^ div[t]
        ctr += 1
    return rem[1:]


def checkCRC(code, div):
    remainder_size = len(div) - 1
    if code.copy()[-remainder_size:] == generateCRC(
            code.copy()[:-remainder_size], div):
        print("No error")
    else:
        print("Error")


code = list(map(int, input("Enter Code: ")))
div = list(map(int, input("Enter Divisor: ")))
option = input("Enter \n 0 for Generate \n 1 for Check\n")
if option == "0":
    print("Generated Code is: ",
          ''.join(str(x) for x in code + generateCRC(code.copy(), div)))
else:
    checkCRC(code.copy(), div)
