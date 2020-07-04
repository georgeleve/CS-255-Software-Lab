# -----------------------------------
# Georgios Gerasimos Leventopoulos
#   x86asm.s           csd4152
# Compute and print the sum 0+...+N
# -----------------------------------

	.section .data	# Data section
N:	.long 1000	    # long N = 1000;
S:	.long 0		    # long S = 0;    
Msg:	.ascii "The sum from 0 to %d is %d\n\0" # Define a string 


	.section .text	   # Instructions section
.globl main
main:	
        #Stackframe back pointer
	pushl %ebp	   # Store %ebp on stack 
	movl  %esp, %ebp   # Copy contents of %esp to %ebp

 	# Initialize
	movl N, %ebx	# Move the address of N in %ebx (%ebx <- N)

 	# Calculate sum
L1:
        # while (%ebx >=0) { S = S + %ebx;  --%ebx; }
	addl %ebx, S	# %ebx += S;
	decl %ebx       # %ebx -= 1;
	cmpl $0, %ebx   # if(%ebx <=0)
 	jng  L2	    	#     goto L2
	movl $L1, %eax	# eax = L1;  Moves label address to register %eax
	jmp *%eax   	# Jump to register pointed by %eax

L2: 
	# Print the result
	pushl S	    	# Argument S    Copies S value to stack and increases esp(stack pointer)
	pushl N	        # Argument N    same as the previous command : subl $4 %esp;  movl N, (%esp);    
	pushl $Msg  	# Argument Address of Msg  , Copies Msg string to stack and increases esp(stack pointer)
	call printf 	# System call for printf
	popl %eax   	# Undo argument  Address of Msg-Remove address of Msg from the stack
	popl %eax   	# Undo argumnet  N - remove N from the stack
	popl %eax   	# Undo argument  S - remove S from the stack

	# Stackframe cleanup
	movl $0, %eax  	# %eax <- 0, this is the return value for main()

        #mov esp, ebp   ; undo the carving of space for the local variables
        #pop ebp        ; restore the previous stackbase-pointer register
        leave	
    	
	ret             # Return to the caller of main

