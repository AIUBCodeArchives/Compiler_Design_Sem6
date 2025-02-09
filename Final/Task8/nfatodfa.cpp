#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

class NFA {
public:
    int numStates;
    set<int> finalStates;
    map<pair<int, char>, set<int>> transitions;
    map<int, set<int>> epsilonTransitions;

    NFA(int n) : numStates(n) {}

    void addTransition(int from, char input, int to){
        transitions[{from, input}].insert(to);
    }

    void addEpsilonTransition(int from, int to){
        epsilonTransitions[from].insert(to);
    }
    void addFinalState(int state){ finalStates.insert(state); }

    set<int> getEpsilonClosure(int state){
        set<int> closure;
        queue<int> q;
        q.push(state);
        closure.insert(state);

        while (!q.empty()){
            int current = q.front();
            q.pop();
            for (int next : epsilonTransitions[current]) {
                if (closure.find(next) == closure.end()) {
                    closure.insert(next);
                    q.push(next);
                }
            }
        }return closure;
    }

    set<int> getEpsilonClosure(const set<int>& states) {
        set<int> closure;
        for (int state : states) {
            set<int> stateClosure = getEpsilonClosure(state);
            closure.insert(stateClosure.begin(), stateClosure.end());
        }return closure;
    }
};

class DFA {
public:
    int numStates;
    set<int> finalStates;
    map<pair<int, char>, int> transitions;

    DFA(int n) : numStates(n) {}

    void addTransition(int from, char input, int to) {
        transitions[{from, input}] = to;
    }

    void addFinalState(int state) {
        finalStates.insert(state);
    }

    void print() {
        cout << "DFA States: " << numStates << endl;
        cout << "DFA Final States: ";
        for (int state : finalStates) {
            cout << state << " ";
        }cout << endl;
        cout << "DFA Transitions: " << endl;
        for (auto &trans : transitions) {
            cout << "From state " << trans.first.first << " on input " << trans.first.second << " to state " << trans.second << endl;
        }
    }
};

DFA convertNFAtoDFA(NFA &nfa) {
    map<set<int>, int> stateMapping;
    queue<set<int>> stateQueue;
    int dfaStateCount = 0;

    set<int> startState = nfa.getEpsilonClosure(0);
    stateQueue.push(startState);
    stateMapping[startState] = dfaStateCount++;

    DFA dfa(dfaStateCount);

    while (!stateQueue.empty()) {
        set<int> currentState = stateQueue.front();
        stateQueue.pop();

        for (char input = 'a'; input <= 'z'; ++input) {
            set<int> newState;
            for (int state : currentState) {
                if (nfa.transitions.find({state, input}) != nfa.transitions.end()) {
                    newState.insert(nfa.transitions[{state, input}].begin(), nfa.transitions[{state, input}].end());
                }
            }

            newState = nfa.getEpsilonClosure(newState);

            if (!newState.empty()) {
                if (stateMapping.find(newState) == stateMapping.end()) {
                    stateMapping[newState] = dfaStateCount++;
                    stateQueue.push(newState);
                }
                dfa.addTransition(stateMapping[currentState], input, stateMapping[newState]);
            }
        }

        for (int state : currentState) {
            if (nfa.finalStates.find(state) != nfa.finalStates.end()) {
                dfa.addFinalState(stateMapping[currentState]);
                break;
            }
        }
    }dfa.numStates = dfaStateCount;
    return dfa;
}

int main() {
    int numStates, numTransitions, numFinalStates, numEpsilonTransitions;
    cout << "Enter the number of states in the NFA: ";
    cin >> numStates;

    NFA nfa(numStates);

    cout << "Enter the number of transitions: ";
    cin >> numTransitions;
    cout << "Enter the transitions (from_state input to_state):" << endl;
    for (int i = 0; i < numTransitions; ++i) {
        int from, to;
        char input;
        cin >> from >> input >> to;
        nfa.addTransition(from, input, to);
    }

    cout << "Enter the number of epsilon transitions: ";
    cin >> numEpsilonTransitions;
    cout << "Enter the epsilon transitions (from_state to_state):" << endl;
    for (int i = 0; i < numEpsilonTransitions; ++i) {
        int from, to;
        cin >> from >> to;
        nfa.addEpsilonTransition(from, to);
    }

    cout << "Enter the number of final states: ";
    cin >> numFinalStates;
    cout << "Enter the final states:" << endl;
    for (int i = 0; i < numFinalStates; ++i) {
        int finalState;
        cin >> finalState;
        nfa.addFinalState(finalState);
    }

    DFA dfa = convertNFAtoDFA(nfa);
    dfa.print();

    return 0;
}