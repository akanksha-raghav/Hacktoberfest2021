if __name__ == '__main__':
    n = int(input())
    student_marks = {}
    for i in range(n):
        name, *line = input().split()
        scores = list(map(float, line))
        student_marks[name] = scores
    query_name = input()
    x = student_marks[query_name]
    # y = len(x)
    summ = 0
    for i in range(3):
        summ = x[i] + summ
    print("{0:.2f}".format(summ/3))
