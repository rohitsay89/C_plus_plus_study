# Program to create a stack data structure in Python using list

a = [0,0,0,0,0]		# create a default list of all zeros
top = 0
print "Program to create a stack data structure in Python using list \n"

def Push(n):		# Push function: Push data on the stack
	global top		# specify the 'top' variable is global
	a[top] = n		# store the value at the top of stack
	top = top+1		# increment the top
	print top		# print the top position number after each Push operation
	
def Pop():			# Pop function: remove data from top of stack
	global top		# specify the 'top' variable is global
	top = top-1		# decrement the top variable
	print top		# print the top position number in array

Push(5)				# Push and Pop operation
Push(6)
Push(27)
Pop()
Pop()

print a				# Print the updated list after all operations