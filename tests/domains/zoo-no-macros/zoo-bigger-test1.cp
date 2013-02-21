% File 'zoo-bigger-test1': The Big Cage Shuffle

:- sorts
  animal >> (elephant; horse; dog).

:- variables
  SP                           :: species;
  E                            :: elephant;
  HR                           :: horse;
  D                            :: dog.
  
:- objects
  elephantSpecies, 
  horseSpecies,
  dogSpecies                   :: species.

caused sp(E)=elephantSpecies.
constraint sp(ANML)=elephantSpecies ->> [\/E | ANML=E].

caused sp(HR)=horseSpecies.
constraint sp(ANML)=horseSpecies ->> [\/HR | ANML=HR].

caused sp(D)=dogSpecies.
constraint sp(ANML)=dogSpecies ->> [\/D | ANML=D].

caused -largeSpecies(dogSpecies).


:- objects
  homer                        :: human;
  jumbo                        :: elephant;
  silver                       :: horse;
  snoopy                       :: dog.

:- begin_asp.
#hide h(eql(accessible(_,_),_),_).
#hide h(eql(adult(_),_)).
#hide h(eql(largeSpecies(_),_)).
#hide h(eql(loc(_),_)).
#hide h(eql(neighbor(_,_),_)).
#hide h(eql(side1(_),_)).
#hide h(eql(side2(_),_)).
#hide h(eql(sides(_,_,_),_)).
#hide h(eql(sp(_),_)).
:- end_asp.

% All gates are closed, there's an animal in each cage 
% except cage A, and homer is outside. 
% How quickly can everyone visit every cage?

:- variables
  T      :: step.

:- query 
label :: 0;
maxstep :: 19;    
0: -opened(G),
    pos(homer)=11,
    pos(jumbo)=8,
    pos(silver)=20,
    pos(snoopy)=21;
[\/ T | T:loc(pos(ANML))=C].


