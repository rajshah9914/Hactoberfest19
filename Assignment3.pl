factorial(0,1).
factorial(N,Result):- N>0,N1 is N-1,factorial(N1,R1),Result is N*R1.
fib(1,1).
fib(2,1).
fib(N,X):- N>0,N1 is N-1,N2 is N-2,fib(N1,X1),fib(N2,X2),X is X1+X2.
gcd(0,X,X):- X is X.
gcd(X,0,X):- X is X.
gcd(X,X,X):- X is X.
gcd(N,M,X):- N>M,Y is N-M, gcd(Y,M,X).
gcd(N,M,X):- M>N,Y is M-N, gcd(N,Y,X).

lcm(N,M,X):- N1 is N*M, gcd(N,M,X1),X is N1/X1.

length1([],X):- X is 0.
length1([H|T],X):- length1(T,X1),X is X1+1.


firsty([H|T],X):- nth0(0,[H|T],X).
first([H|T],X):- X is H.
last([X|T]):- last([T]).

find_nth_element_of_list( 0 , X , [X|_]  ) .
find_nth_element_of_list( N , X , [_|Xs] ) :-
  N > 0 ,
  N1 is N-1 ,
  find_nth_element_of_list( N1 , X , Xs )
  .

removei([],_,[]).
removei([_|T],0,T) :- !.
removei([H|T],N,[H|TR]) :-
    N1 is N-1,
    removei(T,N1,TR).

insertAt(Element,0,L,[Element|L]). % ok
insertAt(Element,Pos,[E|L],[E|ZL]):- % you forgot to cons back E
    Pos1 is Pos-1,
    insertAt(Element,Pos1,L,ZL).

insert(Val,P,L,X):- nth0(P,X,Val,L).

sum([],0).
sum([H|T],X):-  sum(T,X1), X is X1+H.

find(X,[X|_]).
find(X,[_|T]) :- find(X,T).

issorted([]).
issorted([_]).
issorted([X,Y|T]):- X=<Y, issorted([Y|T]). 

quick_sort2(List,Sorted):-q_sort(List,[],Sorted).
q_sort([],Acc,Acc).
q_sort([H|T],Acc,Sorted):-
    pivoting(H,T,L1,L2),
    q_sort(L1,Acc,Sorted1),q_sort(L2,[H|Sorted1],Sorted).

q_sort(L,X) :- sort(L,X).
inc([],[]).
inc([H|T],[X|X1]):- X is H+1,inc(T,X1).


reverse([])     --> [].
reverse([L|Ls]) --> reverse(Ls), [L].
% phrase(reverse([a,b,c]), Ls).
even([]).
odd([H|T]):- even(T).
even([H|T]):- odd(T).

concat([],L2,L2).
concat([H|T],L2,[H|L3]) :- concat(T,L2,L3).

vowel(X):- member(X,[a,e,i,o,u]).
nvowel([],0).
nvowel([H|T],N):-
(
    vowel(H)
    -> (
        nvowel(T,N1),
        N is N1+1
        );
        nvowel(T,N)
).

notvowelm(X):- member(X,[b,c,d,f,g,h,j,k,l,m,n,p,q,r,s,t,v,w,x,y,z]).
notvowel([],0).
notvowel([H|T],N):-
(
    notvowelm(H)
    -> (
        notvowel(T,N1),
        N is N1+1
        );
        notvowel(T,N)
).

rmvdup(L,X):- solve(L,[],X).
solve([],X1,X1).
solve([H|T],X1,X):- member(H,X1),solve(T,X1,X).
solve([H|T],X1,X):- solve(T,[H|X1],X).

rd([H|T],X):- sort([H|T],X),
                length1([H|T],Y),
                write(Y),nl.
                