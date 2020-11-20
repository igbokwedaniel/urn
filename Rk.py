import math

#This function is the generic runge-kutta
#Calculates for each y_i
#y_n+1 = y_n + 1/6[k_1 + 2k_2 + 2k_3 + k_4]

def runge_kutta(func, Y, t , h, y_index):

  y_n = Y[y_index]
  k_1  = func(t, Y)
  
  
  
  t_2, y_2= t + 0.5*h , y_n + 0.5*h*k_1
  Y_2 = Y.copy()
  Y_2[y_index] = y_2
  k_2 = func(t_2, Y_2)
  
  
  
  
  t_3 , y_3 = t + 0.5*h , y_n + 0.5*h*k_2
  Y_3 = Y.copy()
  Y_3[y_index] = y_3
  k_3 = func(t_3, Y_3)
  
  
  t_4 , y_4 = t + h , y_n + h*k_3
  Y_4 = Y.copy()
  Y_4[y_index] = y_4
  k_4 = func(t_4, Y_4)
  
  
  
  
  y_n_1 = y_n + (k_1 + 2*k_2 + 2*k_3 + k_4)/6
  
  return y_n_1
  
def func_beta(t):
   return 1580*(1 + math.cos(2*math.pi*t))
   
 
def func_y_1(t,Y):
   #Dont know what alpha should be
   alpha = 1-0.05-0.02-0.01
   return alpha - func_beta(t)*Y[1]*Y[3]
   
def func_y_2(t,Y):
   return func_beta(t)*Y[1]*Y[3] - 50*Y[2]
   
def func_y_3(t,Y):
   return 50*Y[2] - 100*Y[3]
   
#default 1000 time steps
   
def solver(h, Y, t,  final = 1000):
   funcs  = [None, func_y_1, func_y_2, func_y_3]
   for i in range (final):
     t_n = t + h*i
     Y_n = [0,0,0,0]
     for j in range (1,4):
       Y_n[j] = runge_kutta(funcs[j], Y[i], t_n , h, j)
     Y.append(Y_n)
     
   return Y
   
Y_res = solver(0.00002, [[0,0.01,0.02,0.05]], 0)
f = open("result.csv", "a")
for y in Y_res:
  f.write(str(y[1]) + "," + str(y[2]) + "," + str(y[3]) +",,\n")
  
f.close() 
   
   
   
   
