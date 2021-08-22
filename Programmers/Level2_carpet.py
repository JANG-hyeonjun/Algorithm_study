def solution(brown, yellow):
    answer = []
    total_box = brown + yellow
    for predict in range(3,total_box,1):
        if total_box % predict == 0:
            width = predict
            height = int(total_box/ predict)
            print(height," ",width)
            if (width - 2) * (height - 2) == yellow:
                answer.append(width)
                answer.append(height)
                break


    return sorted(answer,reverse=True)