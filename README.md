# Deterministic-Finite-Automaton

Finite automaton that has 3 states - q1, q2 and q3.

The automaton accepts the language defined {0,1}.

## The automaton is as follows:
q1 is the start state 

q2 is the accept state - true is to be returned if the automaton ends with q2, false if not.

### Transitions:
q1 -> q1 when given command 0, q1 -> q2 when given command 1

q2 -> q3 when given command 0, q2 -> q2 when given command 1

q3 -> q2 when given command 0, q3 -> q2 when given command 1

