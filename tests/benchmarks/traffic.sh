#!/bin/sh

# Traffic World Benchmarking Script


# ----------------------------------------------------------------------------------------------------------------------
# Cplus2ASP v2 (incremental)
# ----------------------------------------------------------------------------------------------------------------------

cplus2asp traffic-benchmark.cp query=0 --mode=incremental

 cplus2asp -soopts "--istats" traffic-benchmark.cp query=0
% Pragma: Running Query 'Query 0'.
% Pragma: Minimum Step = '0', Maximum Step = '100'.
% Pragma: Searching for 1 solutions.
No solution.

Models   : 0
Time     : 1.660 (g: 0.830, p: 0.830, s: 0.000)
Rules    : 452235
Choices  : 0
Conflicts: 0
=============== step 2 ===============
Models   : 0
Time     : 1.000 (g: 0.600, p: 0.400, s: 0.000)
Rules    : 231420
Choices  : 0
Conflicts: 0
=============== step 3 ===============
Models   : 0
Time     : 1.060 (g: 0.620, p: 0.440, s: 0.000)
Rules    : 231420
Choices  : 0
Conflicts: 0
=============== step 4 ===============
Models   : 0
Time     : 1.120 (g: 0.630, p: 0.490, s: 0.000)
Rules    : 231420
Choices  : 0
Conflicts: 0
=============== step 5 ===============
Models   : 0
Time     : 1.220 (g: 0.670, p: 0.550, s: 0.000)
Rules    : 231420
Choices  : 0
Conflicts: 0
=============== step 6 ===============
Models   : 0
Time     : 1.280 (g: 0.670, p: 0.590, s: 0.020)
Rules    : 231420
Choices  : 11
Conflicts: 11
=============== step 7 ===============
Models   : 0
Time     : 1.380 (g: 0.670, p: 0.610, s: 0.100)
Rules    : 231420
Choices  : 182
Conflicts: 90
=============== step 8 ===============
Models   : 0
Time     : 1.570 (g: 0.730, p: 0.650, s: 0.180)
Rules    : 231420
Choices  : 410
Conflicts: 267
=============== step 9 ===============
Models   : 0
Time     : 1.820 (g: 0.710, p: 0.660, s: 0.440)
Rules    : 231420
Choices  : 872
Conflicts: 586
=============== step 10 ===============
Models   : 0
Time     : 2.130 (g: 0.740, p: 0.690, s: 0.680)
Rules    : 231420
Choices  : 1411
Conflicts: 825
=============== step 11 ===============
Answer: 1
Models   : 1
Time     : 2.760 (g: 0.760, p: 0.760, s: 1.220)
Rules    : 231420
Choices  : 2560
Conflicts: 1695
=============== Summary ===============
SATISFIABLE
Models      : 1+
Total Steps : 11
Time        : 17.030
Prepare   : 7.630
Prepro.   : 6.670
Solving   : 2.640



# ----------------------------------------------------------------------------------------------------------------------
# Cplus2ASP v2 (static)
# ----------------------------------------------------------------------------------------------------------------------

cplus2asp traffic-benchmark.cp query=0 --mode=static-auto

% Pragma: Running Query 'Query 0'.
% Pragma: Maximum Step = '0'.
% Pragma: Searching for 1 solutions.
% Pragma: No solutions found.

Models      : 0
Time        : 0.640
  Prepare   : 0.380
  Prepro.   : 0.260
  Solving   : 0.000
No solution.

% Pragma: Running Query 'Query 0'.
% Pragma: Maximum Step = '1'.
% Pragma: Searching for 1 solutions.
% Pragma: No solutions found.

Models      : 0
Time        : 1.760
  Prepare   : 0.840
  Prepro.   : 0.920
  Solving   : 0.000
No solution.

% Pragma: Running Query 'Query 0'.
% Pragma: Maximum Step = '2'.
% Pragma: Searching for 1 solutions.
% Pragma: No solutions found.

Models      : 0
Time        : 2.810
  Prepare   : 1.320
  Prepro.   : 1.490
  Solving   : 0.000
No solution.

% Pragma: Running Query 'Query 0'.
% Pragma: Maximum Step = '3'.
% Pragma: Searching for 1 solutions.
% Pragma: No solutions found.

Models      : 0
Time        : 3.850
  Prepare   : 1.780
  Prepro.   : 2.070
  Solving   : 0.000
No solution.

% Pragma: Running Query 'Query 0'.
% Pragma: Maximum Step = '4'.
% Pragma: Searching for 1 solutions.
% Pragma: No solutions found.

Models      : 0
Time        : 4.870
  Prepare   : 2.220
  Prepro.   : 2.650
  Solving   : 0.000
No solution.

% Pragma: Running Query 'Query 0'.
% Pragma: Maximum Step = '5'.
% Pragma: Searching for 1 solutions.
% Pragma: No solutions found.

Models      : 0
Time        : 6.000
  Prepare   : 2.750
  Prepro.   : 3.250
  Solving   : 0.000
No solution.

% Pragma: Running Query 'Query 0'.
% Pragma: Maximum Step = '6'.
% Pragma: Searching for 1 solutions.
% Pragma: No solutions found.

Models      : 0
Time        : 7.480
  Prepare   : 3.260
  Prepro.   : 4.150
  Solving   : 0.070
No solution.

% Pragma: Running Query 'Query 0'.
% Pragma: Maximum Step = '7'.
% Pragma: Searching for 1 solutions.
% Pragma: No solutions found.

Models      : 0
Time        : 9.190
  Prepare   : 3.790
  Prepro.   : 4.790
  Solving   : 0.610
No solution.

% Pragma: Running Query 'Query 0'.
% Pragma: Maximum Step = '8'.
% Pragma: Searching for 1 solutions.
% Pragma: No solutions found.

Models      : 0
Time        : 11.670
  Prepare   : 4.300
  Prepro.   : 5.340
  Solving   : 2.030
No solution.

% Pragma: Running Query 'Query 0'.
% Pragma: Maximum Step = '9'.
% Pragma: Searching for 1 solutions.
% Pragma: No solutions found.

Models      : 0
Time        : 13.920
  Prepare   : 4.990
  Prepro.   : 6.130
  Solving   : 2.800
No solution.

% Pragma: Running Query 'Query 0'.
% Pragma: Maximum Step = '10'.
% Pragma: Searching for 1 solutions.
% Pragma: No solutions found.

Models      : 0
Time        : 19.150
  Prepare   : 5.270
  Prepro.   : 6.760
  Solving   : 7.120
No solution.

% Pragma: Running Query 'Query 0'.
% Pragma: Maximum Step = '11'.
% Pragma: Searching for 1 solutions.
Solution: 1
         endNode(seg_ac)=c endNode(seg_bc)=c endNode(seg_cd)=d length(seg_ac)=6 length(seg_bc)=6 length(seg_cd)=12 speedLimit(seg_ac)=1 speedLimit(seg_bc)=1 speedLimit(seg_cd)=1 startNode(seg_ac)=a startNode(seg_bc)=b startNode(seg_cd)=c topSpeed(blackcar(1))=1 topSpeed(blackcar(2))=1 topSpeed(blackcar(3))=1 topSpeed(redcar(1))=2 topSpeed(redcar(2))=2 topSpeed(redcar(3))=2

        0:  ahead(blackcar(2),blackcar(1)) ahead(blackcar(3),blackcar(1)) ahead(blackcar(3),blackcar(2)) ahead(redcar(2),redcar(1)) ahead(redcar(3),redcar(1)) ahead(redcar(3),redcar(2)) distance(blackcar(1))=2 distance(blackcar(2))=4 distance(blackcar(3))=6 distance(redcar(1))=2 distance(redcar(2))=4 distance(redcar(3))=6 maxDistance(blackcar(1))=3 maxDistance(blackcar(2))=5 maxDistance(blackcar(3))=1 maxDistance(redcar(1))=3 maxDistance(redcar(2))=5 maxDistance(redcar(3))=1 maxSpeed(blackcar(1))=1 maxSpeed(blackcar(2))=1 maxSpeed(blackcar(3))=1 maxSpeed(redcar(1))=1 maxSpeed(redcar(2))=1 maxSpeed(redcar(3))=1 modifiedDistance(blackcar(1))=2 modifiedDistance(blackcar(2))=4 modifiedDistance(blackcar(3))=0 modifiedDistance(redcar(1))=2 modifiedDistance(redcar(2))=4 modifiedDistance(redcar(3))=0 modifiedOrientation(blackcar(1)) modifiedOrientation(blackcar(2)) modifiedOrientation(blackcar(3)) modifiedOrientation(redcar(1)) modifiedOrientation(redcar(2)) modifiedOrientation(redcar(3)) modifiedSegment(blackcar(1))=seg_bc modifiedSegment(blackcar(2))=seg_bc modifiedSegment(blackcar(3))=seg_cd modifiedSegment(redcar(1))=seg_ac modifiedSegment(redcar(2))=seg_ac modifiedSegment(redcar(3))=seg_cd nextSegment(blackcar(3))=seg_cd nextSegment(redcar(3))=seg_cd node(blackcar(3))=c node(redcar(3))=c positiveOrientation(blackcar(1)) positiveOrientation(blackcar(2)) positiveOrientation(blackcar(3)) positiveOrientation(redcar(1)) positiveOrientation(redcar(2)) positiveOrientation(redcar(3)) segment(blackcar(1))=seg_bc segment(blackcar(2))=seg_bc segment(blackcar(3))=seg_bc segment(redcar(1))=seg_ac segment(redcar(2))=seg_ac segment(redcar(3))=seg_ac speed(blackcar(1))=1 speed(blackcar(2))=1 speed(blackcar(3))=1 speed(redcar(1))=0 speed(redcar(2))=0 speed(redcar(3))=0 varsigmaAhead(blackcar(2),blackcar(1)) varsigmaAhead(blackcar(3),blackcar(2)) varsigmaAhead(redcar(2),redcar(1)) varsigmaAhead(redcar(3),redcar(2)) willLeave(blackcar(3))

        1:  ahead(blackcar(2),blackcar(1)) ahead(blackcar(3),redcar(3)) ahead(redcar(2),redcar(1)) ahead(redcar(3),redcar(1)) ahead(redcar(3),redcar(2)) distance(blackcar(1))=3 distance(blackcar(2))=5 distance(blackcar(3))=1 distance(redcar(1))=2 distance(redcar(2))=4 distance(redcar(3))=6 maxDistance(blackcar(1))=4 maxDistance(blackcar(2))=6 maxDistance(blackcar(3))=2 maxDistance(redcar(1))=3 maxDistance(redcar(2))=5 maxDistance(redcar(3))=1 maxSpeed(blackcar(1))=1 maxSpeed(blackcar(2))=1 maxSpeed(blackcar(3))=1 maxSpeed(redcar(1))=1 maxSpeed(redcar(2))=1 maxSpeed(redcar(3))=1 modifiedDistance(blackcar(1))=3 modifiedDistance(blackcar(2))=5 modifiedDistance(blackcar(3))=1 modifiedDistance(redcar(1))=2 modifiedDistance(redcar(2))=4 modifiedDistance(redcar(3))=0 modifiedOrientation(blackcar(1)) modifiedOrientation(blackcar(2)) modifiedOrientation(blackcar(3)) modifiedOrientation(redcar(1)) modifiedOrientation(redcar(2)) modifiedOrientation(redcar(3)) modifiedSegment(blackcar(1))=seg_bc modifiedSegment(blackcar(2))=seg_bc modifiedSegment(blackcar(3))=seg_cd modifiedSegment(redcar(1))=seg_ac modifiedSegment(redcar(2))=seg_ac modifiedSegment(redcar(3))=seg_cd nextSegment(redcar(3))=seg_cd node(redcar(3))=c positiveOrientation(blackcar(1)) positiveOrientation(blackcar(2)) positiveOrientation(blackcar(3)) positiveOrientation(redcar(1)) positiveOrientation(redcar(2)) positiveOrientation(redcar(3)) segment(blackcar(1))=seg_bc segment(blackcar(2))=seg_bc segment(blackcar(3))=seg_cd segment(redcar(1))=seg_ac segment(redcar(2))=seg_ac segment(redcar(3))=seg_ac speed(blackcar(1))=1 speed(blackcar(2))=1 speed(blackcar(3))=1 speed(redcar(1))=0 speed(redcar(2))=0 speed(redcar(3))=0 varsigmaAhead(blackcar(2),blackcar(1)) varsigmaAhead(blackcar(3),redcar(3)) varsigmaAhead(redcar(2),redcar(1)) varsigmaAhead(redcar(3),redcar(2))

        ACTIONS:  chooseSegment(blackcar(2),seg_cd)

        2:  ahead(blackcar(2),blackcar(1)) ahead(blackcar(3),blackcar(2)) ahead(blackcar(3),redcar(3)) ahead(redcar(2),redcar(1)) ahead(redcar(3),redcar(1)) ahead(redcar(3),redcar(2)) distance(blackcar(1))=4 distance(blackcar(2))=6 distance(blackcar(3))=2 distance(redcar(1))=2 distance(redcar(2))=4 distance(redcar(3))=6 maxDistance(blackcar(1))=5 maxDistance(blackcar(2))=1 maxDistance(blackcar(3))=3 maxDistance(redcar(1))=3 maxDistance(redcar(2))=5 maxDistance(redcar(3))=1 maxSpeed(blackcar(1))=1 maxSpeed(blackcar(2))=1 maxSpeed(blackcar(3))=1 maxSpeed(redcar(1))=1 maxSpeed(redcar(2))=1 maxSpeed(redcar(3))=1 modifiedDistance(blackcar(1))=4 modifiedDistance(blackcar(2))=0 modifiedDistance(blackcar(3))=2 modifiedDistance(redcar(1))=2 modifiedDistance(redcar(2))=4 modifiedDistance(redcar(3))=0 modifiedOrientation(blackcar(1)) modifiedOrientation(blackcar(2)) modifiedOrientation(blackcar(3)) modifiedOrientation(redcar(1)) modifiedOrientation(redcar(2)) modifiedOrientation(redcar(3)) modifiedSegment(blackcar(1))=seg_bc modifiedSegment(blackcar(2))=seg_cd modifiedSegment(blackcar(3))=seg_cd modifiedSegment(redcar(1))=seg_ac modifiedSegment(redcar(2))=seg_ac modifiedSegment(redcar(3))=seg_cd nextSegment(blackcar(2))=seg_cd nextSegment(redcar(3))=seg_cd node(blackcar(2))=c node(redcar(3))=c positiveOrientation(blackcar(1)) positiveOrientation(blackcar(2)) positiveOrientation(blackcar(3)) positiveOrientation(redcar(1)) positiveOrientation(redcar(2)) positiveOrientation(redcar(3)) segment(blackcar(1))=seg_bc segment(blackcar(2))=seg_bc segment(blackcar(3))=seg_cd segment(redcar(1))=seg_ac segment(redcar(2))=seg_ac segment(redcar(3))=seg_ac speed(blackcar(1))=0 speed(blackcar(2))=0 speed(blackcar(3))=1 speed(redcar(1))=1 speed(redcar(2))=1 speed(redcar(3))=1 varsigmaAhead(blackcar(2),blackcar(1)) varsigmaAhead(blackcar(3),blackcar(2)) varsigmaAhead(blackcar(3),redcar(3)) varsigmaAhead(redcar(2),redcar(1)) varsigmaAhead(redcar(3),redcar(2)) willLeave(redcar(3))

        3:  ahead(blackcar(2),blackcar(1)) ahead(blackcar(3),blackcar(2)) ahead(blackcar(3),redcar(3)) ahead(redcar(2),redcar(1)) ahead(redcar(3),blackcar(2)) distance(blackcar(1))=4 distance(blackcar(2))=6 distance(blackcar(3))=3 distance(redcar(1))=3 distance(redcar(2))=5 distance(redcar(3))=1 maxDistance(blackcar(1))=5 maxDistance(blackcar(2))=1 maxDistance(blackcar(3))=4 maxDistance(redcar(1))=4 maxDistance(redcar(2))=6 maxDistance(redcar(3))=2 maxSpeed(blackcar(1))=1 maxSpeed(blackcar(2))=1 maxSpeed(blackcar(3))=1 maxSpeed(redcar(1))=1 maxSpeed(redcar(2))=1 maxSpeed(redcar(3))=1 modifiedDistance(blackcar(1))=4 modifiedDistance(blackcar(2))=0 modifiedDistance(blackcar(3))=3 modifiedDistance(redcar(1))=3 modifiedDistance(redcar(2))=5 modifiedDistance(redcar(3))=1 modifiedOrientation(blackcar(1)) modifiedOrientation(blackcar(2)) modifiedOrientation(blackcar(3)) modifiedOrientation(redcar(1)) modifiedOrientation(redcar(2)) modifiedOrientation(redcar(3)) modifiedSegment(blackcar(1))=seg_bc modifiedSegment(blackcar(2))=seg_cd modifiedSegment(blackcar(3))=seg_cd modifiedSegment(redcar(1))=seg_ac modifiedSegment(redcar(2))=seg_ac modifiedSegment(redcar(3))=seg_cd nextSegment(blackcar(2))=seg_cd node(blackcar(2))=c positiveOrientation(blackcar(1)) positiveOrientation(blackcar(2)) positiveOrientation(blackcar(3)) positiveOrientation(redcar(1)) positiveOrientation(redcar(2)) positiveOrientation(redcar(3)) segment(blackcar(1))=seg_bc segment(blackcar(2))=seg_bc segment(blackcar(3))=seg_cd segment(redcar(1))=seg_ac segment(redcar(2))=seg_ac segment(redcar(3))=seg_cd speed(blackcar(1))=0 speed(blackcar(2))=0 speed(blackcar(3))=1 speed(redcar(1))=1 speed(redcar(2))=1 speed(redcar(3))=1 varsigmaAhead(blackcar(2),blackcar(1)) varsigmaAhead(blackcar(3),redcar(3)) varsigmaAhead(redcar(2),redcar(1)) varsigmaAhead(redcar(3),blackcar(2))

        ACTIONS:  chooseSegment(redcar(2),seg_cd)

        4:  ahead(blackcar(2),blackcar(1)) ahead(blackcar(3),blackcar(2)) ahead(blackcar(3),redcar(2)) ahead(blackcar(3),redcar(3)) ahead(redcar(2),redcar(1)) ahead(redcar(3),blackcar(2)) ahead(redcar(3),redcar(2)) distance(blackcar(1))=4 distance(blackcar(2))=6 distance(blackcar(3))=4 distance(redcar(1))=4 distance(redcar(2))=6 distance(redcar(3))=2 maxDistance(blackcar(1))=5 maxDistance(blackcar(2))=1 maxDistance(blackcar(3))=5 maxDistance(redcar(1))=5 maxDistance(redcar(2))=1 maxDistance(redcar(3))=3 maxSpeed(blackcar(1))=1 maxSpeed(blackcar(2))=1 maxSpeed(blackcar(3))=1 maxSpeed(redcar(1))=1 maxSpeed(redcar(2))=1 maxSpeed(redcar(3))=1 modifiedDistance(blackcar(1))=4 modifiedDistance(blackcar(2))=0 modifiedDistance(blackcar(3))=4 modifiedDistance(redcar(1))=4 modifiedDistance(redcar(2))=0 modifiedDistance(redcar(3))=2 modifiedOrientation(blackcar(1)) modifiedOrientation(blackcar(2)) modifiedOrientation(blackcar(3)) modifiedOrientation(redcar(1)) modifiedOrientation(redcar(2)) modifiedOrientation(redcar(3)) modifiedSegment(blackcar(1))=seg_bc modifiedSegment(blackcar(2))=seg_cd modifiedSegment(blackcar(3))=seg_cd modifiedSegment(redcar(1))=seg_ac modifiedSegment(redcar(2))=seg_cd modifiedSegment(redcar(3))=seg_cd nextSegment(blackcar(2))=seg_cd nextSegment(redcar(2))=seg_cd node(blackcar(2))=c node(redcar(2))=c positiveOrientation(blackcar(1)) positiveOrientation(blackcar(2)) positiveOrientation(blackcar(3)) positiveOrientation(redcar(1)) positiveOrientation(redcar(2)) positiveOrientation(redcar(3)) segment(blackcar(1))=seg_bc segment(blackcar(2))=seg_bc segment(blackcar(3))=seg_cd segment(redcar(1))=seg_ac segment(redcar(2))=seg_ac segment(redcar(3))=seg_cd speed(blackcar(1))=1 speed(blackcar(2))=1 speed(blackcar(3))=1 speed(redcar(1))=0 speed(redcar(2))=0 speed(redcar(3))=1 varsigmaAhead(blackcar(2),blackcar(1)) varsigmaAhead(blackcar(3),redcar(3)) varsigmaAhead(redcar(2),redcar(1)) varsigmaAhead(redcar(3),blackcar(2)) varsigmaAhead(redcar(3),redcar(2)) willLeave(blackcar(2))

        5:  ahead(blackcar(2),redcar(2)) ahead(blackcar(3),blackcar(2)) ahead(blackcar(3),redcar(2)) ahead(blackcar(3),redcar(3)) ahead(redcar(2),redcar(1)) ahead(redcar(3),blackcar(2)) ahead(redcar(3),redcar(2)) distance(blackcar(1))=5 distance(blackcar(2))=1 distance(blackcar(3))=5 distance(redcar(1))=4 distance(redcar(2))=6 distance(redcar(3))=3 maxDistance(blackcar(1))=6 maxDistance(blackcar(2))=2 maxDistance(blackcar(3))=6 maxDistance(redcar(1))=5 maxDistance(redcar(2))=1 maxDistance(redcar(3))=4 maxSpeed(blackcar(1))=1 maxSpeed(blackcar(2))=1 maxSpeed(blackcar(3))=1 maxSpeed(redcar(1))=1 maxSpeed(redcar(2))=1 maxSpeed(redcar(3))=1 modifiedDistance(blackcar(1))=5 modifiedDistance(blackcar(2))=1 modifiedDistance(blackcar(3))=5 modifiedDistance(redcar(1))=4 modifiedDistance(redcar(2))=0 modifiedDistance(redcar(3))=3 modifiedOrientation(blackcar(1)) modifiedOrientation(blackcar(2)) modifiedOrientation(blackcar(3)) modifiedOrientation(redcar(1)) modifiedOrientation(redcar(2)) modifiedOrientation(redcar(3)) modifiedSegment(blackcar(1))=seg_bc modifiedSegment(blackcar(2))=seg_cd modifiedSegment(blackcar(3))=seg_cd modifiedSegment(redcar(1))=seg_ac modifiedSegment(redcar(2))=seg_cd modifiedSegment(redcar(3))=seg_cd nextSegment(redcar(2))=seg_cd node(redcar(2))=c positiveOrientation(blackcar(1)) positiveOrientation(blackcar(2)) positiveOrientation(blackcar(3)) positiveOrientation(redcar(1)) positiveOrientation(redcar(2)) positiveOrientation(redcar(3)) segment(blackcar(1))=seg_bc segment(blackcar(2))=seg_cd segment(blackcar(3))=seg_cd segment(redcar(1))=seg_ac segment(redcar(2))=seg_ac segment(redcar(3))=seg_cd speed(blackcar(1))=1 speed(blackcar(2))=1 speed(blackcar(3))=1 speed(redcar(1))=0 speed(redcar(2))=0 speed(redcar(3))=1 varsigmaAhead(blackcar(2),redcar(2)) varsigmaAhead(blackcar(3),redcar(3)) varsigmaAhead(redcar(2),redcar(1)) varsigmaAhead(redcar(3),blackcar(2))

        ACTIONS:  chooseSegment(blackcar(1),seg_cd)

        6:  ahead(blackcar(2),blackcar(1)) ahead(blackcar(2),redcar(2)) ahead(blackcar(3),blackcar(1)) ahead(blackcar(3),blackcar(2)) ahead(blackcar(3),redcar(2)) ahead(blackcar(3),redcar(3)) ahead(redcar(2),redcar(1)) ahead(redcar(3),blackcar(1)) ahead(redcar(3),blackcar(2)) ahead(redcar(3),redcar(2)) distance(blackcar(1))=6 distance(blackcar(2))=2 distance(blackcar(3))=6 distance(redcar(1))=4 distance(redcar(2))=6 distance(redcar(3))=4 maxDistance(blackcar(1))=1 maxDistance(blackcar(2))=3 maxDistance(blackcar(3))=7 maxDistance(redcar(1))=5 maxDistance(redcar(2))=1 maxDistance(redcar(3))=5 maxSpeed(blackcar(1))=1 maxSpeed(blackcar(2))=1 maxSpeed(blackcar(3))=1 maxSpeed(redcar(1))=1 maxSpeed(redcar(2))=1 maxSpeed(redcar(3))=1 modifiedDistance(blackcar(1))=0 modifiedDistance(blackcar(2))=2 modifiedDistance(blackcar(3))=6 modifiedDistance(redcar(1))=4 modifiedDistance(redcar(2))=0 modifiedDistance(redcar(3))=4 modifiedOrientation(blackcar(1)) modifiedOrientation(blackcar(2)) modifiedOrientation(blackcar(3)) modifiedOrientation(redcar(1)) modifiedOrientation(redcar(2)) modifiedOrientation(redcar(3)) modifiedSegment(blackcar(1))=seg_cd modifiedSegment(blackcar(2))=seg_cd modifiedSegment(blackcar(3))=seg_cd modifiedSegment(redcar(1))=seg_ac modifiedSegment(redcar(2))=seg_cd modifiedSegment(redcar(3))=seg_cd nextSegment(blackcar(1))=seg_cd nextSegment(redcar(2))=seg_cd node(blackcar(1))=c node(redcar(2))=c positiveOrientation(blackcar(1)) positiveOrientation(blackcar(2)) positiveOrientation(blackcar(3)) positiveOrientation(redcar(1)) positiveOrientation(redcar(2)) positiveOrientation(redcar(3)) segment(blackcar(1))=seg_bc segment(blackcar(2))=seg_cd segment(blackcar(3))=seg_cd segment(redcar(1))=seg_ac segment(redcar(2))=seg_ac segment(redcar(3))=seg_cd speed(blackcar(1))=0 speed(blackcar(2))=1 speed(blackcar(3))=1 speed(redcar(1))=1 speed(redcar(2))=1 speed(redcar(3))=1 varsigmaAhead(blackcar(2),blackcar(1)) varsigmaAhead(blackcar(2),redcar(2)) varsigmaAhead(blackcar(3),redcar(3)) varsigmaAhead(redcar(2),redcar(1)) varsigmaAhead(redcar(3),blackcar(2)) willLeave(redcar(2))

        7:  ahead(blackcar(2),blackcar(1)) ahead(blackcar(2),redcar(2)) ahead(blackcar(3),blackcar(1)) ahead(blackcar(3),blackcar(2)) ahead(blackcar(3),redcar(2)) ahead(blackcar(3),redcar(3)) ahead(redcar(2),blackcar(1)) ahead(redcar(3),blackcar(1)) ahead(redcar(3),blackcar(2)) ahead(redcar(3),redcar(2)) distance(blackcar(1))=6 distance(blackcar(2))=3 distance(blackcar(3))=7 distance(redcar(1))=5 distance(redcar(2))=1 distance(redcar(3))=5 maxDistance(blackcar(1))=1 maxDistance(blackcar(2))=4 maxDistance(blackcar(3))=8 maxDistance(redcar(1))=6 maxDistance(redcar(2))=2 maxDistance(redcar(3))=6 maxSpeed(blackcar(1))=1 maxSpeed(blackcar(2))=1 maxSpeed(blackcar(3))=1 maxSpeed(redcar(1))=1 maxSpeed(redcar(2))=1 maxSpeed(redcar(3))=1 modifiedDistance(blackcar(1))=0 modifiedDistance(blackcar(2))=3 modifiedDistance(blackcar(3))=7 modifiedDistance(redcar(1))=5 modifiedDistance(redcar(2))=1 modifiedDistance(redcar(3))=5 modifiedOrientation(blackcar(1)) modifiedOrientation(blackcar(2)) modifiedOrientation(blackcar(3)) modifiedOrientation(redcar(1)) modifiedOrientation(redcar(2)) modifiedOrientation(redcar(3)) modifiedSegment(blackcar(1))=seg_cd modifiedSegment(blackcar(2))=seg_cd modifiedSegment(blackcar(3))=seg_cd modifiedSegment(redcar(1))=seg_ac modifiedSegment(redcar(2))=seg_cd modifiedSegment(redcar(3))=seg_cd nextSegment(blackcar(1))=seg_cd node(blackcar(1))=c positiveOrientation(blackcar(1)) positiveOrientation(blackcar(2)) positiveOrientation(blackcar(3)) positiveOrientation(redcar(1)) positiveOrientation(redcar(2)) positiveOrientation(redcar(3)) segment(blackcar(1))=seg_bc segment(blackcar(2))=seg_cd segment(blackcar(3))=seg_cd segment(redcar(1))=seg_ac segment(redcar(2))=seg_cd segment(redcar(3))=seg_cd speed(blackcar(1))=0 speed(blackcar(2))=1 speed(blackcar(3))=1 speed(redcar(1))=1 speed(redcar(2))=1 speed(redcar(3))=1 varsigmaAhead(blackcar(2),redcar(2)) varsigmaAhead(blackcar(3),redcar(3)) varsigmaAhead(redcar(2),blackcar(1)) varsigmaAhead(redcar(3),blackcar(2))

        ACTIONS:  chooseSegment(redcar(1),seg_cd)

        8:  ahead(blackcar(2),blackcar(1)) ahead(blackcar(2),redcar(1)) ahead(blackcar(2),redcar(2)) ahead(blackcar(3),blackcar(1)) ahead(blackcar(3),blackcar(2)) ahead(blackcar(3),redcar(1)) ahead(blackcar(3),redcar(2)) ahead(blackcar(3),redcar(3)) ahead(redcar(2),blackcar(1)) ahead(redcar(2),redcar(1)) ahead(redcar(3),blackcar(1)) ahead(redcar(3),blackcar(2)) ahead(redcar(3),redcar(1)) ahead(redcar(3),redcar(2)) distance(blackcar(1))=6 distance(blackcar(2))=4 distance(blackcar(3))=8 distance(redcar(1))=6 distance(redcar(2))=2 distance(redcar(3))=6 maxDistance(blackcar(1))=1 maxDistance(blackcar(2))=5 maxDistance(blackcar(3))=9 maxDistance(redcar(1))=1 maxDistance(redcar(2))=3 maxDistance(redcar(3))=7 maxSpeed(blackcar(1))=1 maxSpeed(blackcar(2))=1 maxSpeed(blackcar(3))=1 maxSpeed(redcar(1))=1 maxSpeed(redcar(2))=1 maxSpeed(redcar(3))=1 modifiedDistance(blackcar(1))=0 modifiedDistance(blackcar(2))=4 modifiedDistance(blackcar(3))=8 modifiedDistance(redcar(1))=0 modifiedDistance(redcar(2))=2 modifiedDistance(redcar(3))=6 modifiedOrientation(blackcar(1)) modifiedOrientation(blackcar(2)) modifiedOrientation(blackcar(3)) modifiedOrientation(redcar(1)) modifiedOrientation(redcar(2)) modifiedOrientation(redcar(3)) modifiedSegment(blackcar(1))=seg_cd modifiedSegment(blackcar(2))=seg_cd modifiedSegment(blackcar(3))=seg_cd modifiedSegment(redcar(1))=seg_cd modifiedSegment(redcar(2))=seg_cd modifiedSegment(redcar(3))=seg_cd nextSegment(blackcar(1))=seg_cd nextSegment(redcar(1))=seg_cd node(blackcar(1))=c node(redcar(1))=c positiveOrientation(blackcar(1)) positiveOrientation(blackcar(2)) positiveOrientation(blackcar(3)) positiveOrientation(redcar(1)) positiveOrientation(redcar(2)) positiveOrientation(redcar(3)) segment(blackcar(1))=seg_bc segment(blackcar(2))=seg_cd segment(blackcar(3))=seg_cd segment(redcar(1))=seg_ac segment(redcar(2))=seg_cd segment(redcar(3))=seg_cd speed(blackcar(1))=1 speed(blackcar(2))=1 speed(blackcar(3))=1 speed(redcar(1))=0 speed(redcar(2))=1 speed(redcar(3))=1 varsigmaAhead(blackcar(2),redcar(2)) varsigmaAhead(blackcar(3),redcar(3)) varsigmaAhead(redcar(2),blackcar(1)) varsigmaAhead(redcar(2),redcar(1)) varsigmaAhead(redcar(3),blackcar(2)) willLeave(blackcar(1))

        9:  ahead(blackcar(1),redcar(1)) ahead(blackcar(2),blackcar(1)) ahead(blackcar(2),redcar(1)) ahead(blackcar(2),redcar(2)) ahead(blackcar(3),blackcar(1)) ahead(blackcar(3),blackcar(2)) ahead(blackcar(3),redcar(1)) ahead(blackcar(3),redcar(2)) ahead(blackcar(3),redcar(3)) ahead(redcar(2),blackcar(1)) ahead(redcar(2),redcar(1)) ahead(redcar(3),blackcar(1)) ahead(redcar(3),blackcar(2)) ahead(redcar(3),redcar(1)) ahead(redcar(3),redcar(2)) distance(blackcar(1))=1 distance(blackcar(2))=5 distance(blackcar(3))=9 distance(redcar(1))=6 distance(redcar(2))=3 distance(redcar(3))=7 maxDistance(blackcar(1))=2 maxDistance(blackcar(2))=6 maxDistance(blackcar(3))=10 maxDistance(redcar(1))=1 maxDistance(redcar(2))=4 maxDistance(redcar(3))=8 maxSpeed(blackcar(1))=1 maxSpeed(blackcar(2))=1 maxSpeed(blackcar(3))=1 maxSpeed(redcar(1))=1 maxSpeed(redcar(2))=1 maxSpeed(redcar(3))=1 modifiedDistance(blackcar(1))=1 modifiedDistance(blackcar(2))=5 modifiedDistance(blackcar(3))=9 modifiedDistance(redcar(1))=0 modifiedDistance(redcar(2))=3 modifiedDistance(redcar(3))=7 modifiedOrientation(blackcar(1)) modifiedOrientation(blackcar(2)) modifiedOrientation(blackcar(3)) modifiedOrientation(redcar(1)) modifiedOrientation(redcar(2)) modifiedOrientation(redcar(3)) modifiedSegment(blackcar(1))=seg_cd modifiedSegment(blackcar(2))=seg_cd modifiedSegment(blackcar(3))=seg_cd modifiedSegment(redcar(1))=seg_cd modifiedSegment(redcar(2))=seg_cd modifiedSegment(redcar(3))=seg_cd nextSegment(redcar(1))=seg_cd node(redcar(1))=c positiveOrientation(blackcar(1)) positiveOrientation(blackcar(2)) positiveOrientation(blackcar(3)) positiveOrientation(redcar(1)) positiveOrientation(redcar(2)) positiveOrientation(redcar(3)) segment(blackcar(1))=seg_cd segment(blackcar(2))=seg_cd segment(blackcar(3))=seg_cd segment(redcar(1))=seg_ac segment(redcar(2))=seg_cd segment(redcar(3))=seg_cd speed(blackcar(1))=1 speed(blackcar(2))=1 speed(blackcar(3))=1 speed(redcar(1))=0 speed(redcar(2))=1 speed(redcar(3))=1 varsigmaAhead(blackcar(1),redcar(1)) varsigmaAhead(blackcar(2),redcar(2)) varsigmaAhead(blackcar(3),redcar(3)) varsigmaAhead(redcar(2),blackcar(1)) varsigmaAhead(redcar(3),blackcar(2))

        10:  ahead(blackcar(1),redcar(1)) ahead(blackcar(2),blackcar(1)) ahead(blackcar(2),redcar(1)) ahead(blackcar(2),redcar(2)) ahead(blackcar(3),blackcar(1)) ahead(blackcar(3),blackcar(2)) ahead(blackcar(3),redcar(1)) ahead(blackcar(3),redcar(2)) ahead(blackcar(3),redcar(3)) ahead(redcar(2),blackcar(1)) ahead(redcar(2),redcar(1)) ahead(redcar(3),blackcar(1)) ahead(redcar(3),blackcar(2)) ahead(redcar(3),redcar(1)) ahead(redcar(3),redcar(2)) distance(blackcar(1))=2 distance(blackcar(2))=6 distance(blackcar(3))=10 distance(redcar(1))=6 distance(redcar(2))=4 distance(redcar(3))=8 maxDistance(blackcar(1))=3 maxDistance(blackcar(2))=7 maxDistance(blackcar(3))=11 maxDistance(redcar(1))=1 maxDistance(redcar(2))=5 maxDistance(redcar(3))=9 maxSpeed(blackcar(1))=1 maxSpeed(blackcar(2))=1 maxSpeed(blackcar(3))=1 maxSpeed(redcar(1))=1 maxSpeed(redcar(2))=1 maxSpeed(redcar(3))=1 modifiedDistance(blackcar(1))=2 modifiedDistance(blackcar(2))=6 modifiedDistance(blackcar(3))=10 modifiedDistance(redcar(1))=0 modifiedDistance(redcar(2))=4 modifiedDistance(redcar(3))=8 modifiedOrientation(blackcar(1)) modifiedOrientation(blackcar(2)) modifiedOrientation(blackcar(3)) modifiedOrientation(redcar(1)) modifiedOrientation(redcar(2)) modifiedOrientation(redcar(3)) modifiedSegment(blackcar(1))=seg_cd modifiedSegment(blackcar(2))=seg_cd modifiedSegment(blackcar(3))=seg_cd modifiedSegment(redcar(1))=seg_cd modifiedSegment(redcar(2))=seg_cd modifiedSegment(redcar(3))=seg_cd nextSegment(redcar(1))=seg_cd node(redcar(1))=c positiveOrientation(blackcar(1)) positiveOrientation(blackcar(2)) positiveOrientation(blackcar(3)) positiveOrientation(redcar(1)) positiveOrientation(redcar(2)) positiveOrientation(redcar(3)) segment(blackcar(1))=seg_cd segment(blackcar(2))=seg_cd segment(blackcar(3))=seg_cd segment(redcar(1))=seg_ac segment(redcar(2))=seg_cd segment(redcar(3))=seg_cd speed(blackcar(1))=1 speed(blackcar(2))=1 speed(blackcar(3))=1 speed(redcar(1))=1 speed(redcar(2))=1 speed(redcar(3))=1 varsigmaAhead(blackcar(1),redcar(1)) varsigmaAhead(blackcar(2),redcar(2)) varsigmaAhead(blackcar(3),redcar(3)) varsigmaAhead(redcar(2),blackcar(1)) varsigmaAhead(redcar(3),blackcar(2)) willLeave(redcar(1))

        11:  ahead(blackcar(1),redcar(1)) ahead(blackcar(2),blackcar(1)) ahead(blackcar(2),redcar(1)) ahead(blackcar(2),redcar(2)) ahead(blackcar(3),blackcar(1)) ahead(blackcar(3),blackcar(2)) ahead(blackcar(3),redcar(1)) ahead(blackcar(3),redcar(2)) ahead(blackcar(3),redcar(3)) ahead(redcar(2),blackcar(1)) ahead(redcar(2),redcar(1)) ahead(redcar(3),blackcar(1)) ahead(redcar(3),blackcar(2)) ahead(redcar(3),redcar(1)) ahead(redcar(3),redcar(2)) distance(blackcar(1))=3 distance(blackcar(2))=7 distance(blackcar(3))=11 distance(redcar(1))=1 distance(redcar(2))=5 distance(redcar(3))=9 maxDistance(blackcar(1))=4 maxDistance(blackcar(2))=8 maxDistance(blackcar(3))=12 maxDistance(redcar(1))=2 maxDistance(redcar(2))=6 maxDistance(redcar(3))=10 maxSpeed(blackcar(1))=1 maxSpeed(blackcar(2))=1 maxSpeed(blackcar(3))=1 maxSpeed(redcar(1))=1 maxSpeed(redcar(2))=1 maxSpeed(redcar(3))=1 modifiedDistance(blackcar(1))=3 modifiedDistance(blackcar(2))=7 modifiedDistance(blackcar(3))=11 modifiedDistance(redcar(1))=1 modifiedDistance(redcar(2))=5 modifiedDistance(redcar(3))=9 modifiedOrientation(blackcar(1)) modifiedOrientation(blackcar(2)) modifiedOrientation(blackcar(3)) modifiedOrientation(redcar(1)) modifiedOrientation(redcar(2)) modifiedOrientation(redcar(3)) modifiedSegment(blackcar(1))=seg_cd modifiedSegment(blackcar(2))=seg_cd modifiedSegment(blackcar(3))=seg_cd modifiedSegment(redcar(1))=seg_cd modifiedSegment(redcar(2))=seg_cd modifiedSegment(redcar(3))=seg_cd positiveOrientation(blackcar(1)) positiveOrientation(blackcar(2)) positiveOrientation(blackcar(3)) positiveOrientation(redcar(1)) positiveOrientation(redcar(2)) positiveOrientation(redcar(3)) segment(blackcar(1))=seg_cd segment(blackcar(2))=seg_cd segment(blackcar(3))=seg_cd segment(redcar(1))=seg_cd segment(redcar(2))=seg_cd segment(redcar(3))=seg_cd speed(blackcar(1))=1 speed(blackcar(2))=1 speed(blackcar(3))=1 speed(redcar(1))=1 speed(redcar(2))=1 speed(redcar(3))=1 varsigmaAhead(blackcar(1),redcar(1)) varsigmaAhead(blackcar(2),redcar(2)) varsigmaAhead(blackcar(3),redcar(3)) varsigmaAhead(redcar(2),blackcar(1)) varsigmaAhead(redcar(3),blackcar(2))


Models      : 1+
Time        : 27.390
  Prepare   : 6.010
  Prepro.   : 7.440
  Solving   : 13.940

# ----------------------------------------------------------------------------------------------------------------------
# Cplus2ASP v1 
# ----------------------------------------------------------------------------------------------------------------------

cplus2asp.old --translator "cplus2asp.bin.old" scenario_altmerge.cp --grounder-solver "clingo"

The following queries were found in the input file(s):
0: Query 0, maxstep = 0..100
S: Perform satisfiability check (no query, maxstep=0)
X: Ignore these and do not run a query

Which query would you like to run? 0

% Running Query 0 with maxstep=0.
% Searching for 1 solution.
% warning: abAction/1 is never defined
% warning: attribute/1 is never defined
% warning: action_attribute/2 is never defined
% warning: inertial/1 is never defined
% warning: noconcurrency/0 is never defined

Models      : 0
Time        : 0.970
  Prepare   : 0.510
  Prepro.   : 0.460
  Solving   : 0.000
No solution.


% Running Query 0 with maxstep=1.
% Searching for 1 solution.
% warning: abAction/1 is never defined
% warning: attribute/1 is never defined
% warning: action_attribute/2 is never defined
% warning: inertial/1 is never defined
% warning: noconcurrency/0 is never defined

Models      : 0
Time        : 2.080
  Prepare   : 1.020
  Prepro.   : 1.060
  Solving   : 0.000
No solution.


% Running Query 0 with maxstep=2.
% Searching for 1 solution.
% warning: abAction/1 is never defined
% warning: attribute/1 is never defined
% warning: action_attribute/2 is never defined
% warning: inertial/1 is never defined
% warning: noconcurrency/0 is never defined

Models      : 0
Time        : 3.350
  Prepare   : 1.670
  Prepro.   : 1.680
  Solving   : 0.000
No solution.


% Running Query 0 with maxstep=3.
% Searching for 1 solution.
% warning: abAction/1 is never defined
% warning: attribute/1 is never defined
% warning: action_attribute/2 is never defined
% warning: inertial/1 is never defined
% warning: noconcurrency/0 is never defined

Models      : 0
Time        : 4.460
  Prepare   : 2.150
  Prepro.   : 2.310
  Solving   : 0.000
No solution.


% Running Query 0 with maxstep=4.
% Searching for 1 solution.
% warning: abAction/1 is never defined
% warning: attribute/1 is never defined
% warning: action_attribute/2 is never defined
% warning: inertial/1 is never defined
% warning: noconcurrency/0 is never defined

Models      : 0
Time        : 5.670
  Prepare   : 2.720
  Prepro.   : 2.950
  Solving   : 0.000
No solution.


% Running Query 0 with maxstep=5.
% Searching for 1 solution.
% warning: abAction/1 is never defined
% warning: attribute/1 is never defined
% warning: action_attribute/2 is never defined
% warning: inertial/1 is never defined
% warning: noconcurrency/0 is never defined

Models      : 0
Time        : 7.020
  Prepare   : 3.370
  Prepro.   : 3.650
  Solving   : 0.000
No solution.


% Running Query 0 with maxstep=6.
% Searching for 1 solution.
% warning: abAction/1 is never defined
% warning: attribute/1 is never defined
% warning: action_attribute/2 is never defined
% warning: inertial/1 is never defined
% warning: noconcurrency/0 is never defined

Models      : 0
Time        : 8.730
  Prepare   : 3.980
  Prepro.   : 4.670
  Solving   : 0.080
No solution.


% Running Query 0 with maxstep=7.
% Searching for 1 solution.
% warning: abAction/1 is never defined
% warning: attribute/1 is never defined
% warning: action_attribute/2 is never defined
% warning: inertial/1 is never defined
% warning: noconcurrency/0 is never defined

Models      : 0
Time        : 10.590
  Prepare   : 4.620
  Prepro.   : 5.390
  Solving   : 0.580
No solution.


% Running Query 0 with maxstep=8.
% Searching for 1 solution.
% warning: abAction/1 is never defined
% warning: attribute/1 is never defined
% warning: action_attribute/2 is never defined
% warning: inertial/1 is never defined
% warning: noconcurrency/0 is never defined

Models      : 0
Time        : 13.030
  Prepare   : 5.150
  Prepro.   : 6.120
  Solving   : 1.760
No solution.


% Running Query 0 with maxstep=9.
% Searching for 1 solution.
% warning: abAction/1 is never defined
% warning: attribute/1 is never defined
% warning: action_attribute/2 is never defined
% warning: inertial/1 is never defined
% warning: noconcurrency/0 is never defined

Models      : 0
Time        : 16.710
  Prepare   : 5.770
  Prepro.   : 6.900
  Solving   : 4.040
No solution.


% Running Query 0 with maxstep=10.
% Searching for 1 solution.
% warning: abAction/1 is never defined
% warning: attribute/1 is never defined
% warning: action_attribute/2 is never defined
% warning: inertial/1 is never defined
% warning: noconcurrency/0 is never defined

Models      : 0
Time        : 24.020
  Prepare   : 6.390
  Prepro.   : 7.670
  Solving   : 9.960
No solution.


% Running Query 0 with maxstep=11.
% Searching for 1 solution.
% warning: abAction/1 is never defined
% warning: attribute/1 is never defined
% warning: action_attribute/2 is never defined
% warning: inertial/1 is never defined
% warning: noconcurrency/0 is never defined
Solution: 1

        0:  ahead(blackcar(2),blackcar(1)) ahead(blackcar(3),blackcar(1)) ahead(blackcar(3),blackcar(2)) ahead(redcar(2),redcar(1)) ahead(redcar(3),redcar(1)) ahead(redcar(3),redcar(2)) distance(blackcar(1))=2 distance(blackcar(2))=4 distance(blackcar(3))=6 distance(redcar(1))=2 distance(redcar(2))=4 distance(redcar(3))=6 maxDistance(blackcar(1))=3 maxDistance(blackcar(2))=5 maxDistance(blackcar(3))=1 maxDistance(redcar(1))=3 maxDistance(redcar(2))=5 maxDistance(redcar(3))=1 maxSpeed(blackcar(1))=1 maxSpeed(blackcar(2))=1 maxSpeed(blackcar(3))=1 maxSpeed(redcar(1))=1 maxSpeed(redcar(2))=1 maxSpeed(redcar(3))=1 modifiedDistance(blackcar(1))=2 modifiedDistance(blackcar(2))=4 modifiedDistance(blackcar(3))=0 modifiedDistance(redcar(1))=2 modifiedDistance(redcar(2))=4 modifiedDistance(redcar(3))=0 modifiedOrientation(blackcar(1)) modifiedOrientation(blackcar(2)) modifiedOrientation(blackcar(3)) modifiedOrientation(redcar(1)) modifiedOrientation(redcar(2)) modifiedOrientation(redcar(3)) modifiedSegment(blackcar(1))=seg_bc modifiedSegment(blackcar(2))=seg_bc modifiedSegment(blackcar(3))=seg_cd modifiedSegment(redcar(1))=seg_ac modifiedSegment(redcar(2))=seg_ac modifiedSegment(redcar(3))=seg_cd nextSegment(blackcar(3))=seg_cd nextSegment(redcar(3))=seg_cd node(blackcar(3))=c node(redcar(3))=c positiveOrientation(blackcar(1)) positiveOrientation(blackcar(2)) positiveOrientation(blackcar(3)) positiveOrientation(redcar(1)) positiveOrientation(redcar(2)) positiveOrientation(redcar(3)) segment(blackcar(1))=seg_bc segment(blackcar(2))=seg_bc segment(blackcar(3))=seg_bc segment(redcar(1))=seg_ac segment(redcar(2))=seg_ac segment(redcar(3))=seg_ac speed(blackcar(1))=0 speed(blackcar(2))=0 speed(blackcar(3))=0 speed(redcar(1))=1 speed(redcar(2))=1 speed(redcar(3))=1 varsigmaAhead(blackcar(2),blackcar(1)) varsigmaAhead(blackcar(3),blackcar(2)) varsigmaAhead(redcar(2),redcar(1)) varsigmaAhead(redcar(3),redcar(2)) willLeave(redcar(3))

        1:  ahead(blackcar(2),blackcar(1)) ahead(blackcar(3),blackcar(1)) ahead(blackcar(3),blackcar(2)) ahead(redcar(2),redcar(1)) ahead(redcar(3),blackcar(3)) chooseSegment(redcar(2),seg_cd) distance(blackcar(1))=2 distance(blackcar(2))=4 distance(blackcar(3))=6 distance(redcar(1))=3 distance(redcar(2))=5 distance(redcar(3))=1 maxDistance(blackcar(1))=3 maxDistance(blackcar(2))=5 maxDistance(blackcar(3))=1 maxDistance(redcar(1))=4 maxDistance(redcar(2))=6 maxDistance(redcar(3))=2 maxSpeed(blackcar(1))=1 maxSpeed(blackcar(2))=1 maxSpeed(blackcar(3))=1 maxSpeed(redcar(1))=1 maxSpeed(redcar(2))=1 maxSpeed(redcar(3))=1 modifiedDistance(blackcar(1))=2 modifiedDistance(blackcar(2))=4 modifiedDistance(blackcar(3))=0 modifiedDistance(redcar(1))=3 modifiedDistance(redcar(2))=5 modifiedDistance(redcar(3))=1 modifiedOrientation(blackcar(1)) modifiedOrientation(blackcar(2)) modifiedOrientation(blackcar(3)) modifiedOrientation(redcar(1)) modifiedOrientation(redcar(2)) modifiedOrientation(redcar(3)) modifiedSegment(blackcar(1))=seg_bc modifiedSegment(blackcar(2))=seg_bc modifiedSegment(blackcar(3))=seg_cd modifiedSegment(redcar(1))=seg_ac modifiedSegment(redcar(2))=seg_ac modifiedSegment(redcar(3))=seg_cd nextSegment(blackcar(3))=seg_cd node(blackcar(3))=c positiveOrientation(blackcar(1)) positiveOrientation(blackcar(2)) positiveOrientation(blackcar(3)) positiveOrientation(redcar(1)) positiveOrientation(redcar(2)) positiveOrientation(redcar(3)) segment(blackcar(1))=seg_bc segment(blackcar(2))=seg_bc segment(blackcar(3))=seg_bc segment(redcar(1))=seg_ac segment(redcar(2))=seg_ac segment(redcar(3))=seg_cd speed(blackcar(1))=0 speed(blackcar(2))=0 speed(blackcar(3))=0 speed(redcar(1))=1 speed(redcar(2))=1 speed(redcar(3))=1 varsigmaAhead(blackcar(2),blackcar(1)) varsigmaAhead(blackcar(3),blackcar(2)) varsigmaAhead(redcar(2),redcar(1)) varsigmaAhead(redcar(3),blackcar(3))

        2:  ahead(blackcar(2),blackcar(1)) ahead(blackcar(3),blackcar(1)) ahead(blackcar(3),blackcar(2)) ahead(redcar(2),redcar(1)) ahead(redcar(3),blackcar(3)) ahead(redcar(3),redcar(2)) distance(blackcar(1))=2 distance(blackcar(2))=4 distance(blackcar(3))=6 distance(redcar(1))=4 distance(redcar(2))=6 distance(redcar(3))=2 maxDistance(blackcar(1))=3 maxDistance(blackcar(2))=5 maxDistance(blackcar(3))=1 maxDistance(redcar(1))=5 maxDistance(redcar(2))=1 maxDistance(redcar(3))=3 maxSpeed(blackcar(1))=1 maxSpeed(blackcar(2))=1 maxSpeed(blackcar(3))=1 maxSpeed(redcar(1))=1 maxSpeed(redcar(2))=1 maxSpeed(redcar(3))=1 modifiedDistance(blackcar(1))=2 modifiedDistance(blackcar(2))=4 modifiedDistance(blackcar(3))=0 modifiedDistance(redcar(1))=4 modifiedDistance(redcar(2))=0 modifiedDistance(redcar(3))=2 modifiedOrientation(blackcar(1)) modifiedOrientation(blackcar(2)) modifiedOrientation(blackcar(3)) modifiedOrientation(redcar(1)) modifiedOrientation(redcar(2)) modifiedOrientation(redcar(3)) modifiedSegment(blackcar(1))=seg_bc modifiedSegment(blackcar(2))=seg_bc modifiedSegment(blackcar(3))=seg_cd modifiedSegment(redcar(1))=seg_ac modifiedSegment(redcar(2))=seg_cd modifiedSegment(redcar(3))=seg_cd nextSegment(blackcar(3))=seg_cd nextSegment(redcar(2))=seg_cd node(blackcar(3))=c node(redcar(2))=c positiveOrientation(blackcar(1)) positiveOrientation(blackcar(2)) positiveOrientation(blackcar(3)) positiveOrientation(redcar(1)) positiveOrientation(redcar(2)) positiveOrientation(redcar(3)) segment(blackcar(1))=seg_bc segment(blackcar(2))=seg_bc segment(blackcar(3))=seg_bc segment(redcar(1))=seg_ac segment(redcar(2))=seg_ac segment(redcar(3))=seg_cd speed(blackcar(1))=1 speed(blackcar(2))=1 speed(blackcar(3))=1 speed(redcar(1))=0 speed(redcar(2))=0 speed(redcar(3))=1 varsigmaAhead(blackcar(2),blackcar(1)) varsigmaAhead(blackcar(3),blackcar(2)) varsigmaAhead(redcar(2),redcar(1)) varsigmaAhead(redcar(3),blackcar(3)) varsigmaAhead(redcar(3),redcar(2)) willLeave(blackcar(3))

        3:  ahead(blackcar(2),blackcar(1)) ahead(blackcar(3),redcar(2)) ahead(redcar(2),redcar(1)) ahead(redcar(3),blackcar(3)) ahead(redcar(3),redcar(2)) chooseSegment(blackcar(2),seg_cd) distance(blackcar(1))=3 distance(blackcar(2))=5 distance(blackcar(3))=1 distance(redcar(1))=4 distance(redcar(2))=6 distance(redcar(3))=3 maxDistance(blackcar(1))=4 maxDistance(blackcar(2))=6 maxDistance(blackcar(3))=2 maxDistance(redcar(1))=5 maxDistance(redcar(2))=1 maxDistance(redcar(3))=4 maxSpeed(blackcar(1))=1 maxSpeed(blackcar(2))=1 maxSpeed(blackcar(3))=1 maxSpeed(redcar(1))=1 maxSpeed(redcar(2))=1 maxSpeed(redcar(3))=1 modifiedDistance(blackcar(1))=3 modifiedDistance(blackcar(2))=5 modifiedDistance(blackcar(3))=1 modifiedDistance(redcar(1))=4 modifiedDistance(redcar(2))=0 modifiedDistance(redcar(3))=3 modifiedOrientation(blackcar(1)) modifiedOrientation(blackcar(2)) modifiedOrientation(blackcar(3)) modifiedOrientation(redcar(1)) modifiedOrientation(redcar(2)) modifiedOrientation(redcar(3)) modifiedSegment(blackcar(1))=seg_bc modifiedSegment(blackcar(2))=seg_bc modifiedSegment(blackcar(3))=seg_cd modifiedSegment(redcar(1))=seg_ac modifiedSegment(redcar(2))=seg_cd modifiedSegment(redcar(3))=seg_cd nextSegment(redcar(2))=seg_cd node(redcar(2))=c positiveOrientation(blackcar(1)) positiveOrientation(blackcar(2)) positiveOrientation(blackcar(3)) positiveOrientation(redcar(1)) positiveOrientation(redcar(2)) positiveOrientation(redcar(3)) segment(blackcar(1))=seg_bc segment(blackcar(2))=seg_bc segment(blackcar(3))=seg_cd segment(redcar(1))=seg_ac segment(redcar(2))=seg_ac segment(redcar(3))=seg_cd speed(blackcar(1))=1 speed(blackcar(2))=1 speed(blackcar(3))=1 speed(redcar(1))=0 speed(redcar(2))=0 speed(redcar(3))=1 varsigmaAhead(blackcar(2),blackcar(1)) varsigmaAhead(blackcar(3),redcar(2)) varsigmaAhead(redcar(2),redcar(1)) varsigmaAhead(redcar(3),blackcar(3))

        4:  ahead(blackcar(2),blackcar(1)) ahead(blackcar(3),blackcar(2)) ahead(blackcar(3),redcar(2)) ahead(redcar(2),redcar(1)) ahead(redcar(3),blackcar(2)) ahead(redcar(3),blackcar(3)) ahead(redcar(3),redcar(2)) distance(blackcar(1))=4 distance(blackcar(2))=6 distance(blackcar(3))=2 distance(redcar(1))=4 distance(redcar(2))=6 distance(redcar(3))=4 maxDistance(blackcar(1))=5 maxDistance(blackcar(2))=1 maxDistance(blackcar(3))=3 maxDistance(redcar(1))=5 maxDistance(redcar(2))=1 maxDistance(redcar(3))=5 maxSpeed(blackcar(1))=1 maxSpeed(blackcar(2))=1 maxSpeed(blackcar(3))=1 maxSpeed(redcar(1))=1 maxSpeed(redcar(2))=1 maxSpeed(redcar(3))=1 modifiedDistance(blackcar(1))=4 modifiedDistance(blackcar(2))=0 modifiedDistance(blackcar(3))=2 modifiedDistance(redcar(1))=4 modifiedDistance(redcar(2))=0 modifiedDistance(redcar(3))=4 modifiedOrientation(blackcar(1)) modifiedOrientation(blackcar(2)) modifiedOrientation(blackcar(3)) modifiedOrientation(redcar(1)) modifiedOrientation(redcar(2)) modifiedOrientation(redcar(3)) modifiedSegment(blackcar(1))=seg_bc modifiedSegment(blackcar(2))=seg_cd modifiedSegment(blackcar(3))=seg_cd modifiedSegment(redcar(1))=seg_ac modifiedSegment(redcar(2))=seg_cd modifiedSegment(redcar(3))=seg_cd nextSegment(blackcar(2))=seg_cd nextSegment(redcar(2))=seg_cd node(blackcar(2))=c node(redcar(2))=c positiveOrientation(blackcar(1)) positiveOrientation(blackcar(2)) positiveOrientation(blackcar(3)) positiveOrientation(redcar(1)) positiveOrientation(redcar(2)) positiveOrientation(redcar(3)) segment(blackcar(1))=seg_bc segment(blackcar(2))=seg_bc segment(blackcar(3))=seg_cd segment(redcar(1))=seg_ac segment(redcar(2))=seg_ac segment(redcar(3))=seg_cd speed(blackcar(1))=0 speed(blackcar(2))=0 speed(blackcar(3))=1 speed(redcar(1))=1 speed(redcar(2))=1 speed(redcar(3))=1 varsigmaAhead(blackcar(2),blackcar(1)) varsigmaAhead(blackcar(3),blackcar(2)) varsigmaAhead(blackcar(3),redcar(2)) varsigmaAhead(redcar(2),redcar(1)) varsigmaAhead(redcar(3),blackcar(3)) willLeave(redcar(2))

        5:  ahead(blackcar(2),blackcar(1)) ahead(blackcar(3),blackcar(2)) ahead(blackcar(3),redcar(2)) ahead(redcar(2),blackcar(2)) ahead(redcar(3),blackcar(2)) ahead(redcar(3),blackcar(3)) ahead(redcar(3),redcar(2)) chooseSegment(redcar(1),seg_cd) distance(blackcar(1))=4 distance(blackcar(2))=6 distance(blackcar(3))=3 distance(redcar(1))=5 distance(redcar(2))=1 distance(redcar(3))=5 maxDistance(blackcar(1))=5 maxDistance(blackcar(2))=1 maxDistance(blackcar(3))=4 maxDistance(redcar(1))=6 maxDistance(redcar(2))=2 maxDistance(redcar(3))=6 maxSpeed(blackcar(1))=1 maxSpeed(blackcar(2))=1 maxSpeed(blackcar(3))=1 maxSpeed(redcar(1))=1 maxSpeed(redcar(2))=1 maxSpeed(redcar(3))=1 modifiedDistance(blackcar(1))=4 modifiedDistance(blackcar(2))=0 modifiedDistance(blackcar(3))=3 modifiedDistance(redcar(1))=5 modifiedDistance(redcar(2))=1 modifiedDistance(redcar(3))=5 modifiedOrientation(blackcar(1)) modifiedOrientation(blackcar(2)) modifiedOrientation(blackcar(3)) modifiedOrientation(redcar(1)) modifiedOrientation(redcar(2)) modifiedOrientation(redcar(3)) modifiedSegment(blackcar(1))=seg_bc modifiedSegment(blackcar(2))=seg_cd modifiedSegment(blackcar(3))=seg_cd modifiedSegment(redcar(1))=seg_ac modifiedSegment(redcar(2))=seg_cd modifiedSegment(redcar(3))=seg_cd nextSegment(blackcar(2))=seg_cd node(blackcar(2))=c positiveOrientation(blackcar(1)) positiveOrientation(blackcar(2)) positiveOrientation(blackcar(3)) positiveOrientation(redcar(1)) positiveOrientation(redcar(2)) positiveOrientation(redcar(3)) segment(blackcar(1))=seg_bc segment(blackcar(2))=seg_bc segment(blackcar(3))=seg_cd segment(redcar(1))=seg_ac segment(redcar(2))=seg_cd segment(redcar(3))=seg_cd speed(blackcar(1))=0 speed(blackcar(2))=0 speed(blackcar(3))=1 speed(redcar(1))=1 speed(redcar(2))=1 speed(redcar(3))=1 varsigmaAhead(blackcar(2),blackcar(1)) varsigmaAhead(blackcar(3),redcar(2)) varsigmaAhead(redcar(2),blackcar(2)) varsigmaAhead(redcar(3),blackcar(3))

        6:  ahead(blackcar(2),blackcar(1)) ahead(blackcar(3),blackcar(2)) ahead(blackcar(3),redcar(1)) ahead(blackcar(3),redcar(2)) ahead(redcar(2),blackcar(2)) ahead(redcar(2),redcar(1)) ahead(redcar(3),blackcar(2)) ahead(redcar(3),blackcar(3)) ahead(redcar(3),redcar(1)) ahead(redcar(3),redcar(2)) distance(blackcar(1))=4 distance(blackcar(2))=6 distance(blackcar(3))=4 distance(redcar(1))=6 distance(redcar(2))=2 distance(redcar(3))=6 maxDistance(blackcar(1))=5 maxDistance(blackcar(2))=1 maxDistance(blackcar(3))=5 maxDistance(redcar(1))=1 maxDistance(redcar(2))=3 maxDistance(redcar(3))=7 maxSpeed(blackcar(1))=1 maxSpeed(blackcar(2))=1 maxSpeed(blackcar(3))=1 maxSpeed(redcar(1))=1 maxSpeed(redcar(2))=1 maxSpeed(redcar(3))=1 modifiedDistance(blackcar(1))=4 modifiedDistance(blackcar(2))=0 modifiedDistance(blackcar(3))=4 modifiedDistance(redcar(1))=0 modifiedDistance(redcar(2))=2 modifiedDistance(redcar(3))=6 modifiedOrientation(blackcar(1)) modifiedOrientation(blackcar(2)) modifiedOrientation(blackcar(3)) modifiedOrientation(redcar(1)) modifiedOrientation(redcar(2)) modifiedOrientation(redcar(3)) modifiedSegment(blackcar(1))=seg_bc modifiedSegment(blackcar(2))=seg_cd modifiedSegment(blackcar(3))=seg_cd modifiedSegment(redcar(1))=seg_cd modifiedSegment(redcar(2))=seg_cd modifiedSegment(redcar(3))=seg_cd nextSegment(blackcar(2))=seg_cd nextSegment(redcar(1))=seg_cd node(blackcar(2))=c node(redcar(1))=c positiveOrientation(blackcar(1)) positiveOrientation(blackcar(2)) positiveOrientation(blackcar(3)) positiveOrientation(redcar(1)) positiveOrientation(redcar(2)) positiveOrientation(redcar(3)) segment(blackcar(1))=seg_bc segment(blackcar(2))=seg_bc segment(blackcar(3))=seg_cd segment(redcar(1))=seg_ac segment(redcar(2))=seg_cd segment(redcar(3))=seg_cd speed(blackcar(1))=1 speed(blackcar(2))=1 speed(blackcar(3))=1 speed(redcar(1))=0 speed(redcar(2))=1 speed(redcar(3))=1 varsigmaAhead(blackcar(2),blackcar(1)) varsigmaAhead(blackcar(3),redcar(2)) varsigmaAhead(redcar(2),blackcar(2)) varsigmaAhead(redcar(2),redcar(1)) varsigmaAhead(redcar(3),blackcar(3)) willLeave(blackcar(2))

        7:  ahead(blackcar(2),redcar(1)) ahead(blackcar(3),blackcar(2)) ahead(blackcar(3),redcar(1)) ahead(blackcar(3),redcar(2)) ahead(redcar(2),blackcar(2)) ahead(redcar(2),redcar(1)) ahead(redcar(3),blackcar(2)) ahead(redcar(3),blackcar(3)) ahead(redcar(3),redcar(1)) ahead(redcar(3),redcar(2)) chooseSegment(blackcar(1),seg_cd) distance(blackcar(1))=5 distance(blackcar(2))=1 distance(blackcar(3))=5 distance(redcar(1))=6 distance(redcar(2))=3 distance(redcar(3))=7 maxDistance(blackcar(1))=6 maxDistance(blackcar(2))=2 maxDistance(blackcar(3))=6 maxDistance(redcar(1))=1 maxDistance(redcar(2))=4 maxDistance(redcar(3))=8 maxSpeed(blackcar(1))=1 maxSpeed(blackcar(2))=1 maxSpeed(blackcar(3))=1 maxSpeed(redcar(1))=1 maxSpeed(redcar(2))=1 maxSpeed(redcar(3))=1 modifiedDistance(blackcar(1))=5 modifiedDistance(blackcar(2))=1 modifiedDistance(blackcar(3))=5 modifiedDistance(redcar(1))=0 modifiedDistance(redcar(2))=3 modifiedDistance(redcar(3))=7 modifiedOrientation(blackcar(1)) modifiedOrientation(blackcar(2)) modifiedOrientation(blackcar(3)) modifiedOrientation(redcar(1)) modifiedOrientation(redcar(2)) modifiedOrientation(redcar(3)) modifiedSegment(blackcar(1))=seg_bc modifiedSegment(blackcar(2))=seg_cd modifiedSegment(blackcar(3))=seg_cd modifiedSegment(redcar(1))=seg_cd modifiedSegment(redcar(2))=seg_cd modifiedSegment(redcar(3))=seg_cd nextSegment(redcar(1))=seg_cd node(redcar(1))=c positiveOrientation(blackcar(1)) positiveOrientation(blackcar(2)) positiveOrientation(blackcar(3)) positiveOrientation(redcar(1)) positiveOrientation(redcar(2)) positiveOrientation(redcar(3)) segment(blackcar(1))=seg_bc segment(blackcar(2))=seg_cd segment(blackcar(3))=seg_cd segment(redcar(1))=seg_ac segment(redcar(2))=seg_cd segment(redcar(3))=seg_cd speed(blackcar(1))=1 speed(blackcar(2))=1 speed(blackcar(3))=1 speed(redcar(1))=0 speed(redcar(2))=1 speed(redcar(3))=1 varsigmaAhead(blackcar(2),redcar(1)) varsigmaAhead(blackcar(3),redcar(2)) varsigmaAhead(redcar(2),blackcar(2)) varsigmaAhead(redcar(3),blackcar(3))

        8:  ahead(blackcar(2),blackcar(1)) ahead(blackcar(2),redcar(1)) ahead(blackcar(3),blackcar(1)) ahead(blackcar(3),blackcar(2)) ahead(blackcar(3),redcar(1)) ahead(blackcar(3),redcar(2)) ahead(redcar(2),blackcar(1)) ahead(redcar(2),blackcar(2)) ahead(redcar(2),redcar(1)) ahead(redcar(3),blackcar(1)) ahead(redcar(3),blackcar(2)) ahead(redcar(3),blackcar(3)) ahead(redcar(3),redcar(1)) ahead(redcar(3),redcar(2)) distance(blackcar(1))=6 distance(blackcar(2))=2 distance(blackcar(3))=6 distance(redcar(1))=6 distance(redcar(2))=4 distance(redcar(3))=8 maxDistance(blackcar(1))=1 maxDistance(blackcar(2))=3 maxDistance(blackcar(3))=7 maxDistance(redcar(1))=1 maxDistance(redcar(2))=5 maxDistance(redcar(3))=9 maxSpeed(blackcar(1))=1 maxSpeed(blackcar(2))=1 maxSpeed(blackcar(3))=1 maxSpeed(redcar(1))=1 maxSpeed(redcar(2))=1 maxSpeed(redcar(3))=1 modifiedDistance(blackcar(1))=0 modifiedDistance(blackcar(2))=2 modifiedDistance(blackcar(3))=6 modifiedDistance(redcar(1))=0 modifiedDistance(redcar(2))=4 modifiedDistance(redcar(3))=8 modifiedOrientation(blackcar(1)) modifiedOrientation(blackcar(2)) modifiedOrientation(blackcar(3)) modifiedOrientation(redcar(1)) modifiedOrientation(redcar(2)) modifiedOrientation(redcar(3)) modifiedSegment(blackcar(1))=seg_cd modifiedSegment(blackcar(2))=seg_cd modifiedSegment(blackcar(3))=seg_cd modifiedSegment(redcar(1))=seg_cd modifiedSegment(redcar(2))=seg_cd modifiedSegment(redcar(3))=seg_cd nextSegment(blackcar(1))=seg_cd nextSegment(redcar(1))=seg_cd node(blackcar(1))=c node(redcar(1))=c positiveOrientation(blackcar(1)) positiveOrientation(blackcar(2)) positiveOrientation(blackcar(3)) positiveOrientation(redcar(1)) positiveOrientation(redcar(2)) positiveOrientation(redcar(3)) segment(blackcar(1))=seg_bc segment(blackcar(2))=seg_cd segment(blackcar(3))=seg_cd segment(redcar(1))=seg_ac segment(redcar(2))=seg_cd segment(redcar(3))=seg_cd speed(blackcar(1))=0 speed(blackcar(2))=1 speed(blackcar(3))=1 speed(redcar(1))=1 speed(redcar(2))=1 speed(redcar(3))=1 varsigmaAhead(blackcar(2),blackcar(1)) varsigmaAhead(blackcar(2),redcar(1)) varsigmaAhead(blackcar(3),redcar(2)) varsigmaAhead(redcar(2),blackcar(2)) varsigmaAhead(redcar(3),blackcar(3)) willLeave(redcar(1))

        9:  ahead(blackcar(2),blackcar(1)) ahead(blackcar(2),redcar(1)) ahead(blackcar(3),blackcar(1)) ahead(blackcar(3),blackcar(2)) ahead(blackcar(3),redcar(1)) ahead(blackcar(3),redcar(2)) ahead(redcar(1),blackcar(1)) ahead(redcar(2),blackcar(1)) ahead(redcar(2),blackcar(2)) ahead(redcar(2),redcar(1)) ahead(redcar(3),blackcar(1)) ahead(redcar(3),blackcar(2)) ahead(redcar(3),blackcar(3)) ahead(redcar(3),redcar(1)) ahead(redcar(3),redcar(2)) distance(blackcar(1))=6 distance(blackcar(2))=3 distance(blackcar(3))=7 distance(redcar(1))=1 distance(redcar(2))=5 distance(redcar(3))=9 maxDistance(blackcar(1))=1 maxDistance(blackcar(2))=4 maxDistance(blackcar(3))=8 maxDistance(redcar(1))=2 maxDistance(redcar(2))=6 maxDistance(redcar(3))=10 maxSpeed(blackcar(1))=1 maxSpeed(blackcar(2))=1 maxSpeed(blackcar(3))=1 maxSpeed(redcar(1))=1 maxSpeed(redcar(2))=1 maxSpeed(redcar(3))=1 modifiedDistance(blackcar(1))=0 modifiedDistance(blackcar(2))=3 modifiedDistance(blackcar(3))=7 modifiedDistance(redcar(1))=1 modifiedDistance(redcar(2))=5 modifiedDistance(redcar(3))=9 modifiedOrientation(blackcar(1)) modifiedOrientation(blackcar(2)) modifiedOrientation(blackcar(3)) modifiedOrientation(redcar(1)) modifiedOrientation(redcar(2)) modifiedOrientation(redcar(3)) modifiedSegment(blackcar(1))=seg_cd modifiedSegment(blackcar(2))=seg_cd modifiedSegment(blackcar(3))=seg_cd modifiedSegment(redcar(1))=seg_cd modifiedSegment(redcar(2))=seg_cd modifiedSegment(redcar(3))=seg_cd nextSegment(blackcar(1))=seg_cd node(blackcar(1))=c positiveOrientation(blackcar(1)) positiveOrientation(blackcar(2)) positiveOrientation(blackcar(3)) positiveOrientation(redcar(1)) positiveOrientation(redcar(2)) positiveOrientation(redcar(3)) segment(blackcar(1))=seg_bc segment(blackcar(2))=seg_cd segment(blackcar(3))=seg_cd segment(redcar(1))=seg_cd segment(redcar(2))=seg_cd segment(redcar(3))=seg_cd speed(blackcar(1))=0 speed(blackcar(2))=1 speed(blackcar(3))=1 speed(redcar(1))=1 speed(redcar(2))=1 speed(redcar(3))=1 varsigmaAhead(blackcar(2),redcar(1)) varsigmaAhead(blackcar(3),redcar(2)) varsigmaAhead(redcar(1),blackcar(1)) varsigmaAhead(redcar(2),blackcar(2)) varsigmaAhead(redcar(3),blackcar(3))

        10:  ahead(blackcar(2),blackcar(1)) ahead(blackcar(2),redcar(1)) ahead(blackcar(3),blackcar(1)) ahead(blackcar(3),blackcar(2)) ahead(blackcar(3),redcar(1)) ahead(blackcar(3),redcar(2)) ahead(redcar(1),blackcar(1)) ahead(redcar(2),blackcar(1)) ahead(redcar(2),blackcar(2)) ahead(redcar(2),redcar(1)) ahead(redcar(3),blackcar(1)) ahead(redcar(3),blackcar(2)) ahead(redcar(3),blackcar(3)) ahead(redcar(3),redcar(1)) ahead(redcar(3),redcar(2)) distance(blackcar(1))=6 distance(blackcar(2))=4 distance(blackcar(3))=8 distance(redcar(1))=2 distance(redcar(2))=6 distance(redcar(3))=10 maxDistance(blackcar(1))=1 maxDistance(blackcar(2))=5 maxDistance(blackcar(3))=9 maxDistance(redcar(1))=3 maxDistance(redcar(2))=7 maxDistance(redcar(3))=11 maxSpeed(blackcar(1))=1 maxSpeed(blackcar(2))=1 maxSpeed(blackcar(3))=1 maxSpeed(redcar(1))=1 maxSpeed(redcar(2))=1 maxSpeed(redcar(3))=1 modifiedDistance(blackcar(1))=0 modifiedDistance(blackcar(2))=4 modifiedDistance(blackcar(3))=8 modifiedDistance(redcar(1))=2 modifiedDistance(redcar(2))=6 modifiedDistance(redcar(3))=10 modifiedOrientation(blackcar(1)) modifiedOrientation(blackcar(2)) modifiedOrientation(blackcar(3)) modifiedOrientation(redcar(1)) modifiedOrientation(redcar(2)) modifiedOrientation(redcar(3)) modifiedSegment(blackcar(1))=seg_cd modifiedSegment(blackcar(2))=seg_cd modifiedSegment(blackcar(3))=seg_cd modifiedSegment(redcar(1))=seg_cd modifiedSegment(redcar(2))=seg_cd modifiedSegment(redcar(3))=seg_cd nextSegment(blackcar(1))=seg_cd node(blackcar(1))=c positiveOrientation(blackcar(1)) positiveOrientation(blackcar(2)) positiveOrientation(blackcar(3)) positiveOrientation(redcar(1)) positiveOrientation(redcar(2)) positiveOrientation(redcar(3)) segment(blackcar(1))=seg_bc segment(blackcar(2))=seg_cd segment(blackcar(3))=seg_cd segment(redcar(1))=seg_cd segment(redcar(2))=seg_cd segment(redcar(3))=seg_cd speed(blackcar(1))=1 speed(blackcar(2))=1 speed(blackcar(3))=1 speed(redcar(1))=1 speed(redcar(2))=1 speed(redcar(3))=1 varsigmaAhead(blackcar(2),redcar(1)) varsigmaAhead(blackcar(3),redcar(2)) varsigmaAhead(redcar(1),blackcar(1)) varsigmaAhead(redcar(2),blackcar(2)) varsigmaAhead(redcar(3),blackcar(3)) willLeave(blackcar(1))

        11:  ahead(blackcar(2),blackcar(1)) ahead(blackcar(2),redcar(1)) ahead(blackcar(3),blackcar(1)) ahead(blackcar(3),blackcar(2)) ahead(blackcar(3),redcar(1)) ahead(blackcar(3),redcar(2)) ahead(redcar(1),blackcar(1)) ahead(redcar(2),blackcar(1)) ahead(redcar(2),blackcar(2)) ahead(redcar(2),redcar(1)) ahead(redcar(3),blackcar(1)) ahead(redcar(3),blackcar(2)) ahead(redcar(3),blackcar(3)) ahead(redcar(3),redcar(1)) ahead(redcar(3),redcar(2)) distance(blackcar(1))=1 distance(blackcar(2))=5 distance(blackcar(3))=9 distance(redcar(1))=3 distance(redcar(2))=7 distance(redcar(3))=11 maxDistance(blackcar(1))=2 maxDistance(blackcar(2))=6 maxDistance(blackcar(3))=10 maxDistance(redcar(1))=4 maxDistance(redcar(2))=8 maxDistance(redcar(3))=12 maxSpeed(blackcar(1))=1 maxSpeed(blackcar(2))=1 maxSpeed(blackcar(3))=1 maxSpeed(redcar(1))=1 maxSpeed(redcar(2))=1 maxSpeed(redcar(3))=1 modifiedDistance(blackcar(1))=1 modifiedDistance(blackcar(2))=5 modifiedDistance(blackcar(3))=9 modifiedDistance(redcar(1))=3 modifiedDistance(redcar(2))=7 modifiedDistance(redcar(3))=11 modifiedOrientation(blackcar(1)) modifiedOrientation(blackcar(2)) modifiedOrientation(blackcar(3)) modifiedOrientation(redcar(1)) modifiedOrientation(redcar(2)) modifiedOrientation(redcar(3)) modifiedSegment(blackcar(1))=seg_cd modifiedSegment(blackcar(2))=seg_cd modifiedSegment(blackcar(3))=seg_cd modifiedSegment(redcar(1))=seg_cd modifiedSegment(redcar(2))=seg_cd modifiedSegment(redcar(3))=seg_cd positiveOrientation(blackcar(1)) positiveOrientation(blackcar(2)) positiveOrientation(blackcar(3)) positiveOrientation(redcar(1)) positiveOrientation(redcar(2)) positiveOrientation(redcar(3)) segment(blackcar(1))=seg_cd segment(blackcar(2))=seg_cd segment(blackcar(3))=seg_cd segment(redcar(1))=seg_cd segment(redcar(2))=seg_cd segment(redcar(3))=seg_cd speed(blackcar(1))=1 speed(blackcar(2))=1 speed(blackcar(3))=1 speed(redcar(1))=1 speed(redcar(2))=1 speed(redcar(3))=1 varsigmaAhead(blackcar(2),redcar(1)) varsigmaAhead(blackcar(3),redcar(2)) varsigmaAhead(redcar(1),blackcar(1)) varsigmaAhead(redcar(2),blackcar(2)) varsigmaAhead(redcar(3),blackcar(3))


Models      : 1+
Time        : 25.000
  Prepare   : 6.980
  Prepro.   : 8.460
  Solving   : 9.560


# ----------------------------------------------------------------------------------------------------------------------
# CCALC 
# ----------------------------------------------------------------------------------------------------------------------

?- time(loadf 'traffic-benchmark.cp').
% loading file /usr/local/lib/ccalc/macros.std
% loading file /home/jbabb1/workspace/cplus2asp/tests/benchmarks/traffic-benchmark.cp
% in transition mode...
% 1338 atoms, 114078 rules, 604980 clauses (86994 new atoms)
% Grounding time: 134.46 seconds
% Completion time: 39.13 seconds
% Total time: 173.59 seconds
% 1,691,847,743 inferences, 173.600 CPU in 174.124 seconds (100% CPU, 9745667 Lips)
true.

?- time(query 0).
% Shifting atoms and clauses... done. (0.00 seconds)
% After shifting: 44010 atoms (including new atoms), 298284 clauses
% Writing input clauses... done.  (0.98 seconds)
% Calling relsat 2.0... done.
% Reading output file(s) from SAT solver... done.
% Solution time: 1 seconds (prep 1 seconds, search 0 seconds)

No solution with maxstep 0.

% Shifting atoms and clauses... done. (0.00 seconds)
% After shifting: 88332 atoms (including new atoms), 604980 clauses
% Writing input clauses... done.  (1.96 seconds)
% Calling relsat 2.0... done.
% Reading output file(s) from SAT solver... done.
% Solution time: 1 seconds (prep 1 seconds, search 0 seconds)

No solution with maxstep 1.

% Shifting atoms and clauses... done. (0.00 seconds)
% After shifting: 132654 atoms (including new atoms), 911676 clauses
% Writing input clauses... done.  (3.75 seconds)
% Calling relsat 2.0... done.
% Reading output file(s) from SAT solver... done.
% Solution time: 3 seconds (prep 3 seconds, search 0 seconds)

No solution with maxstep 2.

% Shifting atoms and clauses... done. (0.01 seconds)
% After shifting: 176976 atoms (including new atoms), 1218372 clauses
% Writing input clauses... done.  (5.50 seconds)
% Calling relsat 2.0... done.
% Reading output file(s) from SAT solver... done.
% Solution time: 4 seconds (prep 4 seconds, search 0 seconds)

No solution with maxstep 3.

% Shifting atoms and clauses... done. (0.00 seconds)
% After shifting: 221298 atoms (including new atoms), 1525068 clauses
% Writing input clauses... done.  (7.30 seconds)
% Calling relsat 2.0... done.
% Reading output file(s) from SAT solver... done.
% Solution time: 5 seconds (prep 5 seconds, search 0 seconds)

No solution with maxstep 4.

% Shifting atoms and clauses... done. (0.00 seconds)
% After shifting: 265620 atoms (including new atoms), 1831764 clauses
% Writing input clauses... done.  (9.01 seconds)
% Calling relsat 2.0... done.
% Reading output file(s) from SAT solver... done.
% Solution time: 7 seconds (prep 7 seconds, search 0 seconds)

No solution with maxstep 5.

% Shifting atoms and clauses... done. (0.00 seconds)
% After shifting: 309942 atoms (including new atoms), 2138460 clauses
% Writing input clauses... done.  (10.83 seconds)
% Calling relsat 2.0... done.
% Reading output file(s) from SAT solver... done.
% Solution time: 8 seconds (prep 8 seconds, search 0 seconds)

No solution with maxstep 6.

% Shifting atoms and clauses... done. (0.01 seconds)
% After shifting: 354264 atoms (including new atoms), 2445156 clauses
% Writing input clauses... done.  (12.56 seconds)
% Calling relsat 2.0... done.
% Reading output file(s) from SAT solver... done.
% Solution time: 16 seconds (prep 16 seconds, search 0 seconds)

No solution with maxstep 7.

% Shifting atoms and clauses... done. (0.01 seconds)
% After shifting: 398586 atoms (including new atoms), 2751852 clauses
% Writing input clauses... done.  (14.40 seconds)
% Calling relsat 2.0... done.
% Reading output file(s) from SAT solver... done.
% Solution time: 19 seconds (prep 19 seconds, search 0 seconds)

No solution with maxstep 8.

% Shifting atoms and clauses... done. (0.01 seconds)
% After shifting: 442908 atoms (including new atoms), 3058548 clauses
% Writing input clauses... done.  (16.09 seconds)
% Calling relsat 2.0... done.
% Reading output file(s) from SAT solver... done.
% Solution time: 24 seconds (prep 24 seconds, search 0 seconds)

No solution with maxstep 9.

% Shifting atoms and clauses... done. (0.01 seconds)
% After shifting: 487230 atoms (including new atoms), 3365244 clauses
% Writing input clauses... done.  (17.90 seconds)
% Calling relsat 2.0... done.
% Reading output file(s) from SAT solver... done.
% Solution time: 33 seconds (prep 33 seconds, search 0 seconds)

No solution with maxstep 10.

% Shifting atoms and clauses... done. (0.01 seconds)
% After shifting: 531552 atoms (including new atoms), 3671940 clauses
% Writing input clauses... done.  (19.66 seconds)
% Calling relsat 2.0... done.
% Reading output file(s) from SAT solver... done.
% Solution time: 585 seconds (prep 584 seconds, search 1 seconds)

length(seg_ac)=6  length(seg_bc)=6  length(seg_cd)=12  speedLimit(seg_ac)=1  speedLimit(seg_bc)=1  speedLimit(seg_cd)=1  topSpeed(blackcar(1))=1  topSpeed(blackcar(2))=1  topSpeed(blackcar(3))=1  topSpeed(redcar(1))=2  topSpeed(redcar(2))=2  topSpeed(redcar(3))=2  startNode(seg_ac)=a  startNode(seg_bc)=b  startNode(seg_cd)=c  endNode(seg_ac)=c  endNode(seg_bc)=c  endNode(seg_cd)=d

0:  willLeave(blackcar(3))  positiveOrientation(blackcar(1))  positiveOrientation(blackcar(2))  positiveOrientation(blackcar(3))  positiveOrientation(redcar(1))  positiveOrientation(redcar(2))  positiveOrientation(redcar(3))  distance(blackcar(1))=2  distance(blackcar(2))=4  distance(blackcar(3))=6  distance(redcar(1))=2  distance(redcar(2))=4  distance(redcar(3))=6  segment(blackcar(1))=seg_bc  segment(blackcar(2))=seg_bc  segment(blackcar(3))=seg_bc  segment(redcar(1))=seg_ac  segment(redcar(2))=seg_ac  segment(redcar(3))=seg_ac  nextSegment(blackcar(3))=seg_cd  nextSegment(redcar(3))=seg_cd  modifiedOrientation(blackcar(1))  modifiedOrientation(blackcar(2))  modifiedOrientation(blackcar(3))  modifiedOrientation(redcar(1))  modifiedOrientation(redcar(2))  modifiedOrientation(redcar(3))  ahead(blackcar(2), blackcar(1))  ahead(blackcar(3), blackcar(1))  ahead(blackcar(3), blackcar(2))  ahead(redcar(2), redcar(1))  ahead(redcar(3), redcar(1))  ahead(redcar(3), redcar(2))  varsigmaAhead(blackcar(2), blackcar(1))  varsigmaAhead(blackcar(3), blackcar(2))  varsigmaAhead(redcar(2), redcar(1))  varsigmaAhead(redcar(3), redcar(2))  speed(blackcar(1))=1  speed(blackcar(2))=1  speed(blackcar(3))=1  speed(redcar(1))=0  speed(redcar(2))=0  speed(redcar(3))=0  modifiedDistance(blackcar(1))=2  modifiedDistance(blackcar(2))=4  modifiedDistance(blackcar(3))=0  modifiedDistance(redcar(1))=2  modifiedDistance(redcar(2))=4  modifiedDistance(redcar(3))=0  maxSpeed(blackcar(1))=1  maxSpeed(blackcar(2))=1  maxSpeed(blackcar(3))=1  maxSpeed(redcar(1))=1  maxSpeed(redcar(2))=1  maxSpeed(redcar(3))=1  maxDistance(blackcar(1))=3  maxDistance(blackcar(2))=5  maxDistance(blackcar(3))=1  maxDistance(redcar(1))=3  maxDistance(redcar(2))=5  maxDistance(redcar(3))=1  node(blackcar(3))=c  node(redcar(3))=c  modifiedSegment(blackcar(1))=seg_bc  modifiedSegment(blackcar(2))=seg_bc  modifiedSegment(blackcar(3))=seg_cd  modifiedSegment(redcar(1))=seg_ac  modifiedSegment(redcar(2))=seg_ac  modifiedSegment(redcar(3))=seg_cd

1:  positiveOrientation(blackcar(1))  positiveOrientation(blackcar(2))  positiveOrientation(blackcar(3))  positiveOrientation(redcar(1))  positiveOrientation(redcar(2))  positiveOrientation(redcar(3))  distance(blackcar(1))=3  distance(blackcar(2))=5  distance(blackcar(3))=1  distance(redcar(1))=2  distance(redcar(2))=4  distance(redcar(3))=6  segment(blackcar(1))=seg_bc  segment(blackcar(2))=seg_bc  segment(blackcar(3))=seg_cd  segment(redcar(1))=seg_ac  segment(redcar(2))=seg_ac  segment(redcar(3))=seg_ac  nextSegment(redcar(3))=seg_cd  modifiedOrientation(blackcar(1))  modifiedOrientation(blackcar(2))  modifiedOrientation(blackcar(3))  modifiedOrientation(redcar(1))  modifiedOrientation(redcar(2))  modifiedOrientation(redcar(3))  ahead(blackcar(2), blackcar(1))  ahead(blackcar(3), redcar(3))  ahead(redcar(2), redcar(1))  ahead(redcar(3), redcar(1))  ahead(redcar(3), redcar(2))  varsigmaAhead(blackcar(2), blackcar(1))  varsigmaAhead(blackcar(3), redcar(3))  varsigmaAhead(redcar(2), redcar(1))  varsigmaAhead(redcar(3), redcar(2))  speed(blackcar(1))=1  speed(blackcar(2))=1  speed(blackcar(3))=1  speed(redcar(1))=0  speed(redcar(2))=0  speed(redcar(3))=0  modifiedDistance(blackcar(1))=3  modifiedDistance(blackcar(2))=5  modifiedDistance(blackcar(3))=1  modifiedDistance(redcar(1))=2  modifiedDistance(redcar(2))=4  modifiedDistance(redcar(3))=0  maxSpeed(blackcar(1))=1  maxSpeed(blackcar(2))=1  maxSpeed(blackcar(3))=1  maxSpeed(redcar(1))=1  maxSpeed(redcar(2))=1  maxSpeed(redcar(3))=1  maxDistance(blackcar(1))=4  maxDistance(blackcar(2))=6  maxDistance(blackcar(3))=2  maxDistance(redcar(1))=3  maxDistance(redcar(2))=5  maxDistance(redcar(3))=1  node(redcar(3))=c  modifiedSegment(blackcar(1))=seg_bc  modifiedSegment(blackcar(2))=seg_bc  modifiedSegment(blackcar(3))=seg_cd  modifiedSegment(redcar(1))=seg_ac  modifiedSegment(redcar(2))=seg_ac  modifiedSegment(redcar(3))=seg_cd

ACTIONS:  chooseSegment(blackcar(2), seg_cd)

2:  willLeave(redcar(3))  positiveOrientation(blackcar(1))  positiveOrientation(blackcar(2))  positiveOrientation(blackcar(3))  positiveOrientation(redcar(1))  positiveOrientation(redcar(2))  positiveOrientation(redcar(3))  distance(blackcar(1))=4  distance(blackcar(2))=6  distance(blackcar(3))=2  distance(redcar(1))=2  distance(redcar(2))=4  distance(redcar(3))=6  segment(blackcar(1))=seg_bc  segment(blackcar(2))=seg_bc  segment(blackcar(3))=seg_cd  segment(redcar(1))=seg_ac  segment(redcar(2))=seg_ac  segment(redcar(3))=seg_ac  nextSegment(blackcar(2))=seg_cd  nextSegment(redcar(3))=seg_cd  modifiedOrientation(blackcar(1))  modifiedOrientation(blackcar(2))  modifiedOrientation(blackcar(3))  modifiedOrientation(redcar(1))  modifiedOrientation(redcar(2))  modifiedOrientation(redcar(3))  ahead(blackcar(2), blackcar(1))  ahead(blackcar(3), blackcar(2))  ahead(blackcar(3), redcar(3))  ahead(redcar(2), redcar(1))  ahead(redcar(3), redcar(1))  ahead(redcar(3), redcar(2))  varsigmaAhead(blackcar(2), blackcar(1))  varsigmaAhead(blackcar(3), blackcar(2))  varsigmaAhead(blackcar(3), redcar(3))  varsigmaAhead(redcar(2), redcar(1))  varsigmaAhead(redcar(3), redcar(2))  speed(blackcar(1))=0  speed(blackcar(2))=0  speed(blackcar(3))=1  speed(redcar(1))=1  speed(redcar(2))=1  speed(redcar(3))=1  modifiedDistance(blackcar(1))=4  modifiedDistance(blackcar(2))=0  modifiedDistance(blackcar(3))=2  modifiedDistance(redcar(1))=2  modifiedDistance(redcar(2))=4  modifiedDistance(redcar(3))=0  maxSpeed(blackcar(1))=1  maxSpeed(blackcar(2))=1  maxSpeed(blackcar(3))=1  maxSpeed(redcar(1))=1  maxSpeed(redcar(2))=1  maxSpeed(redcar(3))=1  maxDistance(blackcar(1))=5  maxDistance(blackcar(2))=1  maxDistance(blackcar(3))=3  maxDistance(redcar(1))=3  maxDistance(redcar(2))=5  maxDistance(redcar(3))=1  node(blackcar(2))=c  node(redcar(3))=c  modifiedSegment(blackcar(1))=seg_bc  modifiedSegment(blackcar(2))=seg_cd  modifiedSegment(blackcar(3))=seg_cd  modifiedSegment(redcar(1))=seg_ac  modifiedSegment(redcar(2))=seg_ac  modifiedSegment(redcar(3))=seg_cd

3:  positiveOrientation(blackcar(1))  positiveOrientation(blackcar(2))  positiveOrientation(blackcar(3))  positiveOrientation(redcar(1))  positiveOrientation(redcar(2))  positiveOrientation(redcar(3))  distance(blackcar(1))=4  distance(blackcar(2))=6  distance(blackcar(3))=3  distance(redcar(1))=3  distance(redcar(2))=5  distance(redcar(3))=1  segment(blackcar(1))=seg_bc  segment(blackcar(2))=seg_bc  segment(blackcar(3))=seg_cd  segment(redcar(1))=seg_ac  segment(redcar(2))=seg_ac  segment(redcar(3))=seg_cd  nextSegment(blackcar(2))=seg_cd  modifiedOrientation(blackcar(1))  modifiedOrientation(blackcar(2))  modifiedOrientation(blackcar(3))  modifiedOrientation(redcar(1))  modifiedOrientation(redcar(2))  modifiedOrientation(redcar(3))  ahead(blackcar(2), blackcar(1))  ahead(blackcar(3), blackcar(2))  ahead(blackcar(3), redcar(3))  ahead(redcar(2), redcar(1))  ahead(redcar(3), blackcar(2))  varsigmaAhead(blackcar(2), blackcar(1))  varsigmaAhead(blackcar(3), redcar(3))  varsigmaAhead(redcar(2), redcar(1))  varsigmaAhead(redcar(3), blackcar(2))  speed(blackcar(1))=0  speed(blackcar(2))=0  speed(blackcar(3))=1  speed(redcar(1))=1  speed(redcar(2))=1  speed(redcar(3))=1  modifiedDistance(blackcar(1))=4  modifiedDistance(blackcar(2))=0  modifiedDistance(blackcar(3))=3  modifiedDistance(redcar(1))=3  modifiedDistance(redcar(2))=5  modifiedDistance(redcar(3))=1  maxSpeed(blackcar(1))=1  maxSpeed(blackcar(2))=1  maxSpeed(blackcar(3))=1  maxSpeed(redcar(1))=1  maxSpeed(redcar(2))=1  maxSpeed(redcar(3))=1  maxDistance(blackcar(1))=5  maxDistance(blackcar(2))=1  maxDistance(blackcar(3))=4  maxDistance(redcar(1))=4  maxDistance(redcar(2))=6  maxDistance(redcar(3))=2  node(blackcar(2))=c  modifiedSegment(blackcar(1))=seg_bc  modifiedSegment(blackcar(2))=seg_cd  modifiedSegment(blackcar(3))=seg_cd  modifiedSegment(redcar(1))=seg_ac  modifiedSegment(redcar(2))=seg_ac  modifiedSegment(redcar(3))=seg_cd

ACTIONS:  chooseSegment(redcar(2), seg_cd)

4:  willLeave(blackcar(2))  positiveOrientation(blackcar(1))  positiveOrientation(blackcar(2))  positiveOrientation(blackcar(3))  positiveOrientation(redcar(1))  positiveOrientation(redcar(2))  positiveOrientation(redcar(3))  distance(blackcar(1))=4  distance(blackcar(2))=6  distance(blackcar(3))=4  distance(redcar(1))=4  distance(redcar(2))=6  distance(redcar(3))=2  segment(blackcar(1))=seg_bc  segment(blackcar(2))=seg_bc  segment(blackcar(3))=seg_cd  segment(redcar(1))=seg_ac  segment(redcar(2))=seg_ac  segment(redcar(3))=seg_cd  nextSegment(blackcar(2))=seg_cd  nextSegment(redcar(2))=seg_cd  modifiedOrientation(blackcar(1))  modifiedOrientation(blackcar(2))  modifiedOrientation(blackcar(3))  modifiedOrientation(redcar(1))  modifiedOrientation(redcar(2))  modifiedOrientation(redcar(3))  ahead(blackcar(2), blackcar(1))  ahead(blackcar(3), blackcar(2))  ahead(blackcar(3), redcar(2))  ahead(blackcar(3), redcar(3))  ahead(redcar(2), redcar(1))  ahead(redcar(3), blackcar(2))  ahead(redcar(3), redcar(2))  varsigmaAhead(blackcar(2), blackcar(1))  varsigmaAhead(blackcar(3), redcar(3))  varsigmaAhead(redcar(2), redcar(1))  varsigmaAhead(redcar(3), blackcar(2))  varsigmaAhead(redcar(3), redcar(2))  speed(blackcar(1))=1  speed(blackcar(2))=1  speed(blackcar(3))=1  speed(redcar(1))=0  speed(redcar(2))=0  speed(redcar(3))=1  modifiedDistance(blackcar(1))=4  modifiedDistance(blackcar(2))=0  modifiedDistance(blackcar(3))=4  modifiedDistance(redcar(1))=4  modifiedDistance(redcar(2))=0  modifiedDistance(redcar(3))=2  maxSpeed(blackcar(1))=1  maxSpeed(blackcar(2))=1  maxSpeed(blackcar(3))=1  maxSpeed(redcar(1))=1  maxSpeed(redcar(2))=1  maxSpeed(redcar(3))=1  maxDistance(blackcar(1))=5  maxDistance(blackcar(2))=1  maxDistance(blackcar(3))=5  maxDistance(redcar(1))=5  maxDistance(redcar(2))=1  maxDistance(redcar(3))=3  node(blackcar(2))=c  node(redcar(2))=c  modifiedSegment(blackcar(1))=seg_bc  modifiedSegment(blackcar(2))=seg_cd  modifiedSegment(blackcar(3))=seg_cd  modifiedSegment(redcar(1))=seg_ac  modifiedSegment(redcar(2))=seg_cd  modifiedSegment(redcar(3))=seg_cd

5:  positiveOrientation(blackcar(1))  positiveOrientation(blackcar(2))  positiveOrientation(blackcar(3))  positiveOrientation(redcar(1))  positiveOrientation(redcar(2))  positiveOrientation(redcar(3))  distance(blackcar(1))=5  distance(blackcar(2))=1  distance(blackcar(3))=5  distance(redcar(1))=4  distance(redcar(2))=6  distance(redcar(3))=3  segment(blackcar(1))=seg_bc  segment(blackcar(2))=seg_cd  segment(blackcar(3))=seg_cd  segment(redcar(1))=seg_ac  segment(redcar(2))=seg_ac  segment(redcar(3))=seg_cd  nextSegment(redcar(2))=seg_cd  modifiedOrientation(blackcar(1))  modifiedOrientation(blackcar(2))  modifiedOrientation(blackcar(3))  modifiedOrientation(redcar(1))  modifiedOrientation(redcar(2))  modifiedOrientation(redcar(3))  ahead(blackcar(2), redcar(2))  ahead(blackcar(3), blackcar(2))  ahead(blackcar(3), redcar(2))  ahead(blackcar(3), redcar(3))  ahead(redcar(2), redcar(1))  ahead(redcar(3), blackcar(2))  ahead(redcar(3), redcar(2))  varsigmaAhead(blackcar(2), redcar(2))  varsigmaAhead(blackcar(3), redcar(3))  varsigmaAhead(redcar(2), redcar(1))  varsigmaAhead(redcar(3), blackcar(2))  speed(blackcar(1))=1  speed(blackcar(2))=1  speed(blackcar(3))=1  speed(redcar(1))=0  speed(redcar(2))=0  speed(redcar(3))=1  modifiedDistance(blackcar(1))=5  modifiedDistance(blackcar(2))=1  modifiedDistance(blackcar(3))=5  modifiedDistance(redcar(1))=4  modifiedDistance(redcar(2))=0  modifiedDistance(redcar(3))=3  maxSpeed(blackcar(1))=1  maxSpeed(blackcar(2))=1  maxSpeed(blackcar(3))=1  maxSpeed(redcar(1))=1  maxSpeed(redcar(2))=1  maxSpeed(redcar(3))=1  maxDistance(blackcar(1))=6  maxDistance(blackcar(2))=2  maxDistance(blackcar(3))=6  maxDistance(redcar(1))=5  maxDistance(redcar(2))=1  maxDistance(redcar(3))=4  node(redcar(2))=c  modifiedSegment(blackcar(1))=seg_bc  modifiedSegment(blackcar(2))=seg_cd  modifiedSegment(blackcar(3))=seg_cd  modifiedSegment(redcar(1))=seg_ac  modifiedSegment(redcar(2))=seg_cd  modifiedSegment(redcar(3))=seg_cd

ACTIONS:  chooseSegment(blackcar(1), seg_cd)

6:  willLeave(redcar(2))  positiveOrientation(blackcar(1))  positiveOrientation(blackcar(2))  positiveOrientation(blackcar(3))  positiveOrientation(redcar(1))  positiveOrientation(redcar(2))  positiveOrientation(redcar(3))  distance(blackcar(1))=6  distance(blackcar(2))=2  distance(blackcar(3))=6  distance(redcar(1))=4  distance(redcar(2))=6  distance(redcar(3))=4  segment(blackcar(1))=seg_bc  segment(blackcar(2))=seg_cd  segment(blackcar(3))=seg_cd  segment(redcar(1))=seg_ac  segment(redcar(2))=seg_ac  segment(redcar(3))=seg_cd  nextSegment(blackcar(1))=seg_cd  nextSegment(redcar(2))=seg_cd  modifiedOrientation(blackcar(1))  modifiedOrientation(blackcar(2))  modifiedOrientation(blackcar(3))  modifiedOrientation(redcar(1))  modifiedOrientation(redcar(2))  modifiedOrientation(redcar(3))  ahead(blackcar(2), blackcar(1))  ahead(blackcar(2), redcar(2))  ahead(blackcar(3), blackcar(1))  ahead(blackcar(3), blackcar(2))  ahead(blackcar(3), redcar(2))  ahead(blackcar(3), redcar(3))  ahead(redcar(2), redcar(1))  ahead(redcar(3), blackcar(1))  ahead(redcar(3), blackcar(2))  ahead(redcar(3), redcar(2))  varsigmaAhead(blackcar(2), blackcar(1))  varsigmaAhead(blackcar(2), redcar(2))  varsigmaAhead(blackcar(3), redcar(3))  varsigmaAhead(redcar(2), redcar(1))  varsigmaAhead(redcar(3), blackcar(2))  speed(blackcar(1))=0  speed(blackcar(2))=1  speed(blackcar(3))=1  speed(redcar(1))=1  speed(redcar(2))=1  speed(redcar(3))=1  modifiedDistance(blackcar(1))=0  modifiedDistance(blackcar(2))=2  modifiedDistance(blackcar(3))=6  modifiedDistance(redcar(1))=4  modifiedDistance(redcar(2))=0  modifiedDistance(redcar(3))=4  maxSpeed(blackcar(1))=1  maxSpeed(blackcar(2))=1  maxSpeed(blackcar(3))=1  maxSpeed(redcar(1))=1  maxSpeed(redcar(2))=1  maxSpeed(redcar(3))=1  maxDistance(blackcar(1))=1  maxDistance(blackcar(2))=3  maxDistance(blackcar(3))=7  maxDistance(redcar(1))=5  maxDistance(redcar(2))=1  maxDistance(redcar(3))=5  node(blackcar(1))=c  node(redcar(2))=c  modifiedSegment(blackcar(1))=seg_cd  modifiedSegment(blackcar(2))=seg_cd  modifiedSegment(blackcar(3))=seg_cd  modifiedSegment(redcar(1))=seg_ac  modifiedSegment(redcar(2))=seg_cd  modifiedSegment(redcar(3))=seg_cd

7:  positiveOrientation(blackcar(1))  positiveOrientation(blackcar(2))  positiveOrientation(blackcar(3))  positiveOrientation(redcar(1))  positiveOrientation(redcar(2))  positiveOrientation(redcar(3))  distance(blackcar(1))=6  distance(blackcar(2))=3  distance(blackcar(3))=7  distance(redcar(1))=5  distance(redcar(2))=1  distance(redcar(3))=5  segment(blackcar(1))=seg_bc  segment(blackcar(2))=seg_cd  segment(blackcar(3))=seg_cd  segment(redcar(1))=seg_ac  segment(redcar(2))=seg_cd  segment(redcar(3))=seg_cd  nextSegment(blackcar(1))=seg_cd  modifiedOrientation(blackcar(1))  modifiedOrientation(blackcar(2))  modifiedOrientation(blackcar(3))  modifiedOrientation(redcar(1))  modifiedOrientation(redcar(2))  modifiedOrientation(redcar(3))  ahead(blackcar(2), blackcar(1))  ahead(blackcar(2), redcar(2))  ahead(blackcar(3), blackcar(1))  ahead(blackcar(3), blackcar(2))  ahead(blackcar(3), redcar(2))  ahead(blackcar(3), redcar(3))  ahead(redcar(2), blackcar(1))  ahead(redcar(3), blackcar(1))  ahead(redcar(3), blackcar(2))  ahead(redcar(3), redcar(2))  varsigmaAhead(blackcar(2), redcar(2))  varsigmaAhead(blackcar(3), redcar(3))  varsigmaAhead(redcar(2), blackcar(1))  varsigmaAhead(redcar(3), blackcar(2))  speed(blackcar(1))=0  speed(blackcar(2))=1  speed(blackcar(3))=1  speed(redcar(1))=1  speed(redcar(2))=1  speed(redcar(3))=1  modifiedDistance(blackcar(1))=0  modifiedDistance(blackcar(2))=3  modifiedDistance(blackcar(3))=7  modifiedDistance(redcar(1))=5  modifiedDistance(redcar(2))=1  modifiedDistance(redcar(3))=5  maxSpeed(blackcar(1))=1  maxSpeed(blackcar(2))=1  maxSpeed(blackcar(3))=1  maxSpeed(redcar(1))=1  maxSpeed(redcar(2))=1  maxSpeed(redcar(3))=1  maxDistance(blackcar(1))=1  maxDistance(blackcar(2))=4  maxDistance(blackcar(3))=8  maxDistance(redcar(1))=6  maxDistance(redcar(2))=2  maxDistance(redcar(3))=6  node(blackcar(1))=c  modifiedSegment(blackcar(1))=seg_cd  modifiedSegment(blackcar(2))=seg_cd  modifiedSegment(blackcar(3))=seg_cd  modifiedSegment(redcar(1))=seg_ac  modifiedSegment(redcar(2))=seg_cd  modifiedSegment(redcar(3))=seg_cd

ACTIONS:  chooseSegment(redcar(1), seg_cd)

8:  willLeave(blackcar(1))  positiveOrientation(blackcar(1))  positiveOrientation(blackcar(2))  positiveOrientation(blackcar(3))  positiveOrientation(redcar(1))  positiveOrientation(redcar(2))  positiveOrientation(redcar(3))  distance(blackcar(1))=6  distance(blackcar(2))=4  distance(blackcar(3))=8  distance(redcar(1))=6  distance(redcar(2))=2  distance(redcar(3))=6  segment(blackcar(1))=seg_bc  segment(blackcar(2))=seg_cd  segment(blackcar(3))=seg_cd  segment(redcar(1))=seg_ac  segment(redcar(2))=seg_cd  segment(redcar(3))=seg_cd  nextSegment(blackcar(1))=seg_cd  nextSegment(redcar(1))=seg_cd  modifiedOrientation(blackcar(1))  modifiedOrientation(blackcar(2))  modifiedOrientation(blackcar(3))  modifiedOrientation(redcar(1))  modifiedOrientation(redcar(2))  modifiedOrientation(redcar(3))  ahead(blackcar(2), blackcar(1))  ahead(blackcar(2), redcar(1))  ahead(blackcar(2), redcar(2))  ahead(blackcar(3), blackcar(1))  ahead(blackcar(3), blackcar(2))  ahead(blackcar(3), redcar(1))  ahead(blackcar(3), redcar(2))  ahead(blackcar(3), redcar(3))  ahead(redcar(2), blackcar(1))  ahead(redcar(2), redcar(1))  ahead(redcar(3), blackcar(1))  ahead(redcar(3), blackcar(2))  ahead(redcar(3), redcar(1))  ahead(redcar(3), redcar(2))  varsigmaAhead(blackcar(2), redcar(2))  varsigmaAhead(blackcar(3), redcar(3))  varsigmaAhead(redcar(2), blackcar(1))  varsigmaAhead(redcar(2), redcar(1))  varsigmaAhead(redcar(3), blackcar(2))  speed(blackcar(1))=1  speed(blackcar(2))=1  speed(blackcar(3))=1  speed(redcar(1))=0  speed(redcar(2))=1  speed(redcar(3))=1  modifiedDistance(blackcar(1))=0  modifiedDistance(blackcar(2))=4  modifiedDistance(blackcar(3))=8  modifiedDistance(redcar(1))=0  modifiedDistance(redcar(2))=2  modifiedDistance(redcar(3))=6  maxSpeed(blackcar(1))=1  maxSpeed(blackcar(2))=1  maxSpeed(blackcar(3))=1  maxSpeed(redcar(1))=1  maxSpeed(redcar(2))=1  maxSpeed(redcar(3))=1  maxDistance(blackcar(1))=1  maxDistance(blackcar(2))=5  maxDistance(blackcar(3))=9  maxDistance(redcar(1))=1  maxDistance(redcar(2))=3  maxDistance(redcar(3))=7  node(blackcar(1))=c  node(redcar(1))=c  modifiedSegment(blackcar(1))=seg_cd  modifiedSegment(blackcar(2))=seg_cd  modifiedSegment(blackcar(3))=seg_cd  modifiedSegment(redcar(1))=seg_cd  modifiedSegment(redcar(2))=seg_cd  modifiedSegment(redcar(3))=seg_cd

9:  positiveOrientation(blackcar(1))  positiveOrientation(blackcar(2))  positiveOrientation(blackcar(3))  positiveOrientation(redcar(1))  positiveOrientation(redcar(2))  positiveOrientation(redcar(3))  distance(blackcar(1))=1  distance(blackcar(2))=5  distance(blackcar(3))=9  distance(redcar(1))=6  distance(redcar(2))=3  distance(redcar(3))=7  segment(blackcar(1))=seg_cd  segment(blackcar(2))=seg_cd  segment(blackcar(3))=seg_cd  segment(redcar(1))=seg_ac  segment(redcar(2))=seg_cd  segment(redcar(3))=seg_cd  nextSegment(redcar(1))=seg_cd  modifiedOrientation(blackcar(1))  modifiedOrientation(blackcar(2))  modifiedOrientation(blackcar(3))  modifiedOrientation(redcar(1))  modifiedOrientation(redcar(2))  modifiedOrientation(redcar(3))  ahead(blackcar(1), redcar(1))  ahead(blackcar(2), blackcar(1))  ahead(blackcar(2), redcar(1))  ahead(blackcar(2), redcar(2))  ahead(blackcar(3), blackcar(1))  ahead(blackcar(3), blackcar(2))  ahead(blackcar(3), redcar(1))  ahead(blackcar(3), redcar(2))  ahead(blackcar(3), redcar(3))  ahead(redcar(2), blackcar(1))  ahead(redcar(2), redcar(1))  ahead(redcar(3), blackcar(1))  ahead(redcar(3), blackcar(2))  ahead(redcar(3), redcar(1))  ahead(redcar(3), redcar(2))  varsigmaAhead(blackcar(1), redcar(1))  varsigmaAhead(blackcar(2), redcar(2))  varsigmaAhead(blackcar(3), redcar(3))  varsigmaAhead(redcar(2), blackcar(1))  varsigmaAhead(redcar(3), blackcar(2))  speed(blackcar(1))=1  speed(blackcar(2))=1  speed(blackcar(3))=1  speed(redcar(1))=0  speed(redcar(2))=1  speed(redcar(3))=1  modifiedDistance(blackcar(1))=1  modifiedDistance(blackcar(2))=5  modifiedDistance(blackcar(3))=9  modifiedDistance(redcar(1))=0  modifiedDistance(redcar(2))=3  modifiedDistance(redcar(3))=7  maxSpeed(blackcar(1))=1  maxSpeed(blackcar(2))=1  maxSpeed(blackcar(3))=1  maxSpeed(redcar(1))=1  maxSpeed(redcar(2))=1  maxSpeed(redcar(3))=1  maxDistance(blackcar(1))=2  maxDistance(blackcar(2))=6  maxDistance(blackcar(3))=10  maxDistance(redcar(1))=1  maxDistance(redcar(2))=4  maxDistance(redcar(3))=8  node(redcar(1))=c  modifiedSegment(blackcar(1))=seg_cd  modifiedSegment(blackcar(2))=seg_cd  modifiedSegment(blackcar(3))=seg_cd  modifiedSegment(redcar(1))=seg_cd  modifiedSegment(redcar(2))=seg_cd  modifiedSegment(redcar(3))=seg_cd

10:  willLeave(redcar(1))  positiveOrientation(blackcar(1))  positiveOrientation(blackcar(2))  positiveOrientation(blackcar(3))  positiveOrientation(redcar(1))  positiveOrientation(redcar(2))  positiveOrientation(redcar(3))  distance(blackcar(1))=2  distance(blackcar(2))=6  distance(blackcar(3))=10  distance(redcar(1))=6  distance(redcar(2))=4  distance(redcar(3))=8  segment(blackcar(1))=seg_cd  segment(blackcar(2))=seg_cd  segment(blackcar(3))=seg_cd  segment(redcar(1))=seg_ac  segment(redcar(2))=seg_cd  segment(redcar(3))=seg_cd  nextSegment(redcar(1))=seg_cd  modifiedOrientation(blackcar(1))  modifiedOrientation(blackcar(2))  modifiedOrientation(blackcar(3))  modifiedOrientation(redcar(1))  modifiedOrientation(redcar(2))  modifiedOrientation(redcar(3))  ahead(blackcar(1), redcar(1))  ahead(blackcar(2), blackcar(1))  ahead(blackcar(2), redcar(1))  ahead(blackcar(2), redcar(2))  ahead(blackcar(3), blackcar(1))  ahead(blackcar(3), blackcar(2))  ahead(blackcar(3), redcar(1))  ahead(blackcar(3), redcar(2))  ahead(blackcar(3), redcar(3))  ahead(redcar(2), blackcar(1))  ahead(redcar(2), redcar(1))  ahead(redcar(3), blackcar(1))  ahead(redcar(3), blackcar(2))  ahead(redcar(3), redcar(1))  ahead(redcar(3), redcar(2))  varsigmaAhead(blackcar(1), redcar(1))  varsigmaAhead(blackcar(2), redcar(2))  varsigmaAhead(blackcar(3), redcar(3))  varsigmaAhead(redcar(2), blackcar(1))  varsigmaAhead(redcar(3), blackcar(2))  speed(blackcar(1))=1  speed(blackcar(2))=1  speed(blackcar(3))=1  speed(redcar(1))=1  speed(redcar(2))=1  speed(redcar(3))=1  modifiedDistance(blackcar(1))=2  modifiedDistance(blackcar(2))=6  modifiedDistance(blackcar(3))=10  modifiedDistance(redcar(1))=0  modifiedDistance(redcar(2))=4  modifiedDistance(redcar(3))=8  maxSpeed(blackcar(1))=1  maxSpeed(blackcar(2))=1  maxSpeed(blackcar(3))=1  maxSpeed(redcar(1))=1  maxSpeed(redcar(2))=1  maxSpeed(redcar(3))=1  maxDistance(blackcar(1))=3  maxDistance(blackcar(2))=7  maxDistance(blackcar(3))=11  maxDistance(redcar(1))=1  maxDistance(redcar(2))=5  maxDistance(redcar(3))=9  node(redcar(1))=c  modifiedSegment(blackcar(1))=seg_cd  modifiedSegment(blackcar(2))=seg_cd  modifiedSegment(blackcar(3))=seg_cd  modifiedSegment(redcar(1))=seg_cd  modifiedSegment(redcar(2))=seg_cd  modifiedSegment(redcar(3))=seg_cd

11:  positiveOrientation(blackcar(1))  positiveOrientation(blackcar(2))  positiveOrientation(blackcar(3))  positiveOrientation(redcar(1))  positiveOrientation(redcar(2))  positiveOrientation(redcar(3))  distance(blackcar(1))=3  distance(blackcar(2))=7  distance(blackcar(3))=11  distance(redcar(1))=1  distance(redcar(2))=5  distance(redcar(3))=9  segment(blackcar(1))=seg_cd  segment(blackcar(2))=seg_cd  segment(blackcar(3))=seg_cd  segment(redcar(1))=seg_cd  segment(redcar(2))=seg_cd  segment(redcar(3))=seg_cd  modifiedOrientation(blackcar(1))  modifiedOrientation(blackcar(2))  modifiedOrientation(blackcar(3))  modifiedOrientation(redcar(1))  modifiedOrientation(redcar(2))  modifiedOrientation(redcar(3))  ahead(blackcar(1), redcar(1))  ahead(blackcar(2), blackcar(1))  ahead(blackcar(2), redcar(1))  ahead(blackcar(2), redcar(2))  ahead(blackcar(3), blackcar(1))  ahead(blackcar(3), blackcar(2))  ahead(blackcar(3), redcar(1))  ahead(blackcar(3), redcar(2))  ahead(blackcar(3), redcar(3))  ahead(redcar(2), blackcar(1))  ahead(redcar(2), redcar(1))  ahead(redcar(3), blackcar(1))  ahead(redcar(3), blackcar(2))  ahead(redcar(3), redcar(1))  ahead(redcar(3), redcar(2))  varsigmaAhead(blackcar(1), redcar(1))  varsigmaAhead(blackcar(2), redcar(2))  varsigmaAhead(blackcar(3), redcar(3))  varsigmaAhead(redcar(2), blackcar(1))  varsigmaAhead(redcar(3), blackcar(2))  speed(blackcar(1))=1  speed(blackcar(2))=1  speed(blackcar(3))=1  speed(redcar(1))=1  speed(redcar(2))=1  speed(redcar(3))=1  modifiedDistance(blackcar(1))=3  modifiedDistance(blackcar(2))=7  modifiedDistance(blackcar(3))=11  modifiedDistance(redcar(1))=1  modifiedDistance(redcar(2))=5  modifiedDistance(redcar(3))=9  maxSpeed(blackcar(1))=1  maxSpeed(blackcar(2))=1  maxSpeed(blackcar(3))=1  maxSpeed(redcar(1))=1  maxSpeed(redcar(2))=1  maxSpeed(redcar(3))=1  maxDistance(blackcar(1))=4  maxDistance(blackcar(2))=8  maxDistance(blackcar(3))=12  maxDistance(redcar(1))=2  maxDistance(redcar(2))=6  maxDistance(redcar(3))=10  modifiedSegment(blackcar(1))=seg_cd  modifiedSegment(blackcar(2))=seg_cd  modifiedSegment(blackcar(3))=seg_cd  modifiedSegment(redcar(1))=seg_cd  modifiedSegment(redcar(2))=seg_cd  modifiedSegment(redcar(3))=seg_cd


% 699,020,065 inferences, 537.310 CPU in 1281.508 seconds (42% CPU, 1300962 Lips)
true.



