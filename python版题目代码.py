import random
sum = 0
tube=[0]*100
#检测函数从l开始，连续测tmp个人
def test(l,tmp):
    sum = 0
    for i in range(l, l + tmp):
        sum = (sum or tube[i])
    return sum
#l为本组最左侧样本编号，t为本组样本数量，p为几等分
def find(l,t,p):
#递归结束条件：本组结果呈阴性,或可以确定阳性样本编号
    if (test(l,t) == 0):
        return
    else:
        if(t == 1):
            print(l,'号核酸检测呈阳性') 
            return
#当前组不满足解决条件，则将当前组继续拆分
    tmpf = t // p
    for i in range(p):
        if(test(l + i * tmpf, tmpf) != 0):
            find(l + i * tmpf, tmpf, p)
    return

if __name__ == "__main__":
    n = 27
#一共进行检测的人数
    print('输入进行检测的人数n=27') 
    x = random.randint(1, 27)
#随机生成阳性个体编号
    tube[x] = 1
    print(tube) 
#为了方便验证，我们将随机生成的阳性个体编号输出，以便与之后作比较
    print('随机得到的阳性编号为：',x) 
#检测结果
    find(1, n, 3)