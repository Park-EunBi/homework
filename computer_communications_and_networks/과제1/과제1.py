import random
n = 0

def RandomBackOff(retry_count):
    m = min(retry_count, 10)
    k = random.randint(0, (2 ** m) -1)
    print("retry_count = {}". format(retry_count))
    print("m = {0}, 범위: [0, {1}], k = {2}".format(m, (2 ** m)-1, k))
    return k * 512


while (True):
    n += 1
    if (n <= 10):
        result = RandomBackOff(n)
        print("backoff 시간: {}".format(result))
        print()

    else:
        print("프로그램 종료")
        break

