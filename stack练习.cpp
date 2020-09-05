typedef int element;
typedef struct{
	element date[MAXSIZE];
	int top;
}Sqstack;

status push(Sqstack*S,element e)
{
	if(S->top==MAXSIZE-1){
		return error;
	} 
	S->top++;
	S->date[S->top] = e;
	return ok;
}

status pop(Sqstack*S,element*e){
	if(S->top==-1){
		return error;
	}
	*e=S->date[S->top];
	S->top--;
	return ok;
} 

typedef struct stacknode{
	element date;
	struct stacknode*next;
}stacknode,linkstackptr;

typedef struct linkstack{
	linkstackptr top;
	int count;
}linkstack;
status push(linkstack*S,element e){
	linkstackptr a=(linkstackptr)malloc(sizeof(stacknode));
	a->date = e;
	a->next = S->top;
	S->top = a;
	S->count++;
	return ok;
}
status pop(linkstack*S,element*e){
	lintstackptr p;
	if(stackempty(*S)){
		return error;
	}
	*e = S->top->date;
	p = S->top;
	S->top=S->top->next;
	free(p);
	S->count--;
	return ok;
}

