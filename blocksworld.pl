member_eq(X,[X|_]) :- !.
member_eq(X,[_|T]) :- member_eq(X,T).

action(pickup(X), [clear(X), ontable(X), holding(none)], 
       [ontable(X), clear(X), holding(none)], [holding(X)]).

action(putdown(X), [holding(X)], [holding(X)], 
       [ontable(X), clear(X), holding(none)]).

action(unstack(X,Y), [on(X,Y), clear(X), holding(none)], 
       [on(X,Y), clear(X), holding(none)], [holding(X), clear(Y)]).

action(stack(X,Y), [holding(X), clear(Y)], [holding(X), clear(Y)], 
       [on(X,Y), clear(X), holding(none)]).

applicable(Action, State) :-
    action(Action, Pre, _, _),
    forall(member(P, Pre), member_eq(P, State)).

apply(Action, State, NewState) :-
    action(Action, Pre, Del, Add),
    forall(member(P, Pre), member_eq(P, State)),
    subtract(State, Del, S1),
    append(Add, S1, NewState).

goal_satisfied([], _).
goal_satisfied([G|Gs], State) :-
    member_eq(G, State),
    goal_satisfied(Gs, State).

block(a). block(b). block(c).

action_schema_instance(pickup(X)) :- block(X).
action_schema_instance(putdown(X)) :- block(X).
action_schema_instance(unstack(X,Y)) :- block(X), block(Y), X \= Y.
action_schema_instance(stack(X,Y)) :- block(X), block(Y), X \= Y.

plan(Init, Goal, Plan) :-
    search(Init, Goal, [], Plan).

search(State, Goal, Actions, Plan) :-
    goal_satisfied(Goal, State),
    reverse(Actions, Plan).

search(State, Goal, Actions, Plan) :-
    length(Actions, Len), Len < 10,  % depth limit
    action_schema_instance(Action),
    applicable(Action, State),
    \+ redundant_move(Action, Actions),
    apply(Action, State, NewState),
    search(NewState, Goal, [Action|Actions], Plan).

redundant_move(pickup(X), [putdown(X)|_]).
redundant_move(putdown(X), [pickup(X)|_]).
redundant_move(stack(X,Y), [unstack(X,Y)|_]).
redundant_move(unstack(X,Y), [stack(X,Y)|_]).

test_simple :-
    Init = [ontable(a), ontable(b), ontable(c), clear(a), clear(b), clear(c), holding(none)],
    Goal = [on(a,b)],
    writeln('Testing simple stacking...'),
    ( plan(Init, Goal, Plan) ->
        format('SUCCESS! Plan: ~w~n', [Plan])
    ;
        writeln('FAILED - no plan found')
    ).

test_tower :-
    Init = [ontable(a), ontable(b), ontable(c), clear(a), clear(b), clear(c), holding(none)],
    Goal = [on(a,b), on(b,c)],
    writeln('Testing tower building...'),
    ( plan(Init, Goal, Plan) ->
        format('SUCCESS! Plan: ~w~n', [Plan])
    ;
        writeln('FAILED - no plan found')
    ).

test_complex :-
    Init = [ontable(a), on(b,a), ontable(c), clear(b), clear(c), holding(none)],
    Goal = [on(c,b)],
    writeln('Testing complex rearrangement...'),
    ( plan(Init, Goal, Plan) ->
        format('SUCCESS! Plan: ~w~n', [Plan])
    ;
        writeln('FAILED - no plan found')
    ).

run_tests :- test_simple, test_tower, test_complex.
