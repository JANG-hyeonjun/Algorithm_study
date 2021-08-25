def solution(s):

    answer = s.split(' ')
    answer = [int(a) for a in answer]
    return str(min(answer)) +" "+str(max(answer))