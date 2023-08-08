#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int size;
    int top;
    char *arr;
};
void createstack(struct stack *st)
{
    st->size = 100;
    st->top = -1;
    st->arr = (char *)malloc(st->size * sizeof(char));
}

void push(struct stack *s, char data)
{

    if (s->top == s->size - 1)
    {
        printf("overflow");
    }

    else
    {
        s->top++;
        s->arr[s->top] = data;
    }
}

int pop(struct stack *s)
{

    char val = -1;
    if (s->top == -1)
    {
        printf("empty");
    }
    else
    {
        val = s->arr[s->top];
        s->top--;
    }
    return val;
}

int peak(struct stack *s)
{

    char cal = -1;
    if (s->top == -1)
    {
    }
    else
    {
        cal = s->arr[s->top];
    }
    return cal;
}

void display(struct stack s)
{
    int i = 0;
    while (s.top >= 0)
    {

        printf("%c\n", s.arr[i++]);
        s.top--;
    }
}

int pre(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/' || ch == '%')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isoperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^' || ch == '=')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char *inftopos(char *infix)
{
    struct stack *st = (struct stack *)malloc(sizeof(struct stack));
    createstack(st);

    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; // traverse through infix
    int j = 0; // traverse through postfix
    while (infix[i] != '\0')
    {
        if (!isoperator(infix[i]))
        {
            postfix[j++] = infix[i++];
        }

        else
        {
            if (pre(infix[i]) > pre(peak(st)))
            {
                push(st, infix[i]);
                i++;
            }

            else
            {
                postfix[j++] = pop(st);
            }
        }
    }
    while (st->top >= 0)
    {
        postfix[j++] = pop(st);
        st->top--;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{

    char *infix = "p*q+r-t";
    puts(infix);
    printf("the ans is %s\n", inftopos(infix));

    return 0;
}