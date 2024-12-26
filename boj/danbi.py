# cuty_name = "Danbi"  

# def my_function(name):
#     sexy_name = "Hyeonho"
#     print(sexy_name,"Park")
    
# def my_function2(name):
#     print(sexy_name, "Kim")

# def my_function3(name):
#     print(name, "Lee")
    
    
# my_function("Danbi")
# my_function2("Hyeonho")
# # my_function3("Candy")

# a = 10 # 전역 변수
# def calc():
#     a = 20 # 지역 변수
#     print(a) # calc의 지역 변수 출력
# calc()
# print(a)

# a=10
# def calc():
#     global a
#     a = 20 # calc의 지역 변수
#     # print(a) # calc의 지역 변수 출력
#     return a
# calc()
# print(a)

# def calculate_area (radius):
#     area = 3.14 * radius**2 # 전역변수 area에 계산값을 저장하려고 했다!
#     return area
# area = 0
# r = float(input("원의 반지름: "))
# area = calculate_area(r)
# print(area)

# def calculate_area (radius):
#     global r
    
#     r = 3.14 * radius**2
#     return
# r = float(input("원의 반지름: "))
# calculate_area(r)
# print(r)

a = [[11,22,33],[44,55,99,[66,77]]]
b = [1, 2, 3]
c = ['Life', 'is', 'too', 'short']
d = [1, 2, 'Life', 'is']
e = [1, 2, ['Life', 'is']]
# print(e[2][2])
l = [e,d,c,b,a]
print(l[4][1][3][1])

# a = [1, 2, 3, ['a', 'b', 'c'], ['d', 'e', 'f']]
# print(a[3][1])
