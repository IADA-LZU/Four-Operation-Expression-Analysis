#include <stdio.h>
#include <stdlib.h>
#include "stack-lib.h"


int check_precedence(char input);
int check_operator(char input);
void convert_to_RPN(char *input,int length);
void shunting(list *operate,list *output,char c);
void calculate_value(list *input);

list operator_stack;
list output_stack;
list calculate_stack;
list_int result;

/***********************************************************
Function Name: check_operator
Function Description: Check a character if it is a number or a operator.
Inputs: A variable of char.
Outputs: A variable of int. 0 means it is a operator. 1 means it is a number.
Notes: -
************************************************************/  


int check_operator(char input){
	if (input=='+'||input=='-'||input=='*'||input=='/' \
		||input=='('||input==')'){
		return 0;
	} else{
		return 1;
	}
}

/***********************************************************
Function Name: convert_to_RPN
Function Description: Convert a expression from infix notation to RPN.
Inputs: A pointer of char to a array which contains the expression of infix notation.
		A variable of int which is the length of the char array.
Outputs:Nothing.
Notes: Require function shunting() push() pop()
************************************************************/  


void convert_to_RPN(char *input,int length){

	for (int i = 0; i < length; ++i){
		if (check_operator(input[i]))
		{
			push(&output_stack,input[i]);
		} else{
			shunting(&operator_stack,&output_stack,input[i]);
		}

	}		
	do{
		push(&output_stack,operator_stack.array[operator_stack.top-1]);
		pop(&operator_stack);
		if(operator_stack.array[operator_stack.top-1]=='('){
			pop(&operator_stack);
		}
	}while(operator_stack.top!=0);
}

/***********************************************************
Function Name: shunting
Function Description: Deal with the operator in the expression.
Inputs: A pointer of list to a struct which save the operator of infix notation.
		A pointer of list to a struct which save the output of RPN expression.
		A variable of char which is the charactor in the input expression array.
Outputs:Nothing.
Notes: Require function push() pop() check_precedence()
************************************************************/  

void shunting(list *operate,list *output,char c){
	if (c=='('){
		push(operate,c);
	}else if (c==')'){
		do{
			push(output,operate->array[operate->top-1]);
			pop(operate);
		}while(operate->array[operate->top-1]!='(');
	}else if (check_precedence(c) < check_precedence(operate->array[operate->top-1])&&operate->array[operate->top-1] !='('){
		do{
			push(output,operate->array[operate->top-1]);
			pop(operate);
		}while(check_precedence(output->array[output->top])!=check_precedence(c));
		push(operate,c);
		
	} else{
		push(operate,c);
	}
}

/***********************************************************
Function Name: check_precedence
Function Description: Check the precedence fo a character.
Inputs: A variable of char.
Outputs: A variable of int. 0 means lower precedence. 1 means higher precedence.
Notes: -
************************************************************/  


int check_precedence(char input){
	if (input=='+'||input=='-')
	{
		return 0;
	}else if(input=='*'||input=='/'){
		return 1;
	}
}

/***********************************************************
Function Name: calculate_RPN_value
Function Description: Calculate the value of the RPN expression.
Inputs: A pointer to a struct list which contains the RPN expression.
Outputs: Print value on the screen.
Notes: Require functon push_int() check_operator()
************************************************************/

void calculate_RPN_value(list *input){
	int l=0;
	for (int j = 0; j < STACKLEN; ++j)
	{
		if (output_stack.array[j]=='\0'){
			l=j;
			break;
		}
	}
	for (int i = 0; i < l; ++i)
	{
		if (check_operator(input->array[i]))
		{
//			push(&calculate_stack,input->array[i]);
			push_int(&result,(int)input->array[i]-48);
			
		} else{
			switch(input->array[i]){
				case '+':result.array[result.top-2]=(result.array[result.top-2])+(result.array[result.top-1]);pop_int(&result);break;
				case '-':result.array[result.top-2]=(result.array[result.top-2])-(result.array[result.top-1]);pop_int(&result);break;
				case '*':result.array[result.top-2]=(result.array[result.top-2])*(result.array[result.top-1]);pop_int(&result);break;
				case '/':result.array[result.top-2]=(result.array[result.top-2])/(result.array[result.top-1]);pop_int(&result);break;
			}
		}
	}
	printf("%d",result.array[0]);
	
}

int main(int argc, char const *argv[])
{
	char expression[STACKLEN];
	int l=0;
	scanf("%s",&expression);
	init_stack(&output_stack);
	init_stack(&operator_stack);
	init_stack(&calculate_stack);
	for (int i = 0; i < STACKLEN; ++i)
	{
		if (expression[i]=='\0'){
			l=i;
			break;
		}
	}
	convert_to_RPN(expression,l);
	print_stack(&output_stack,(output_stack.top));
//	print_stack(&operator_stack,(output_stack.top));
	calculate_RPN_value(&output_stack);
	return 0;
}
