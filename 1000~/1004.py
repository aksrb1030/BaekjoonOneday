T = int(input())

for i in range(T):
    
    start_x, start_y, end_x, end_y = map(int,input().split())
    num = int(input())
    cnt=0

    for i in range(num):
        art_x, art_y, art_r = map(int,input().split())
        start_dis = (((start_x - art_x) ** 2) + ((start_y - art_y) ** 2)) ** 0.5
        end_dis = (((end_x - art_x) ** 2) + ((end_y - art_y) ** 2)) ** 0.5

        if (start_dis<art_r and end_dis>art_r) or (start_dis>art_r and end_dis<art_r):
            cnt += 1
            
    print(cnt)