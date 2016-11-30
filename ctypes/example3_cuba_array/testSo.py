from ctypes import cdll, c_int, c_double, pointer 

#Here is my lists of coordinates for my gaussian centroid:
mu_x_list = [0.3,0.124,5.5,0.76]
mu_y_list = [0.3,0.5  ,0.0,0.1]
n_element_x = len(mu_x_list)
n_element_y = len(mu_y_list)
if(n_element_x!=n_element_y):
  print 'Error: list must have same lenght.'
  exit()

#Define a new type:
c_ArrayDoubleN = c_double * n_element_x

#Create new instances: 
muxList = c_ArrayDoubleN()
muyList = c_ArrayDoubleN()
integral= c_ArrayDoubleN()
error   = c_ArrayDoubleN()

#Assign values to these instances:
for i in range(0,n_element_x): 
  muxList[i] = c_double(mu_x_list[i])
  muyList[i] = c_double(mu_y_list[i])

#Loading and using our home made module:
hello = cdll.LoadLibrary('./exampleCuba.so')
result = hello.method(c_int(n_element_x), pointer(muxList), \
                       pointer(muyList), pointer(integral), pointer(error))  

######## printing result ###########

print 'You have inputed %d gaussian coordinates.' % n_element_x
print 'Here are the result of integaration for each of them:\n'

for i in range(0,n_element_x):
  print 'gaussian %d:% 8.6f +/-% 8.6e' % (i, integral[i], error[i])
print '\ndone.'
