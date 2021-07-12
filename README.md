# AlgoTech
Das Ziel dieses Repositories ist die Klausurvorbereitung für Algorithmentechnik an der HTWG.

Wer dazu beitragen möchte, möge den Kontakt suchen oder das Repo forken.

Die Algorithmen, die im Skript stehen, sowie die, die wir für zu komplex für die Klausur halten, sind hier explizit nicht aufgenommen.

## O-Notations Mengenbeweise
### o(f) ⊂ O(f)
```
g ∈ o(f)

\forall c > 0 \exists n_0 \forall n > n_0 : 0 < |g(n)| <= c * |f(n)|

=> \exists c > 0 \exists n_0 \forall n > n_0 : 0 < |g(n)| <= c * |f(n)|

<=> g ∈ O(f)
```

Tipps:
- Gleiches Prinzip für \omega ⊂ \Omega
- O(f) ⊂ o(f) zu widerlegen, indem von Existenzquantor nicht auf Allquantor geschlossen werden kann

### \Theta(f) ⊂ O(f)
```
g ∈ \Theta(f)

\exists c1, c2, n_0 \forall n >= n_0 : 0 <= c1 |g(n)| <= |f(n)| <= c2 |g(n)|

=> \exists c1, n_0 \forall n >= n_0 : 0 <= |f(n)| <= c2 |g(n)|

<=> g ∈ O(f)
```

Tipps:
- Gleiches Prinzip für \Theta(f) ⊂ \Omega(f)
- O(f) ⊂ \Theta(f) zu widerlegen, indem weitere Bedingung (z.B. c2) nicht einfach hinzugefügt werden kann

## Teile und Herrsche

- [x] [Anzahl der nicht-negativen](#Anzahl-der-nicht-negativen)
- [x] [Anzahl von Vertauschungen in einer unsortierten Liste](#Anzahl-von-Vertauschungen-in-einer-unsortierten-Liste)
- [x] [Binärdarstellung](#Binärdarstellung)
- [ ] ~~Binäre Suche~~ (Skript)
- [ ] ~~Dichtestes Punktepaar~~ (Skript)
- [ ] ~~Divide-and-conquer eigenvalue algorithm~~ (zu kompliziert)
- [ ] ~~FFT (Fast Fourier Transformation)~~ (zu kompliziert)
- [x] [GGT](#GGT)
- [x] [GGT mehrere Zahlen](#GGT-mehrere-Zahlen)
- [ ] Intergration mit Trapezregel
- [ ] ~~Introsort (introspective Quicksort)~~ (Skript)
- [ ] ~~Karatsuba (Langzahl-Multiplikation)~~ (Skript)
- [ ] ~~Konvexe Hülle (via common tangents)~~ (Skript)
- [ ] k-t größtes Element (selection problem)
- [x] [Maximale-konsekutive Teilfolge](#Maximale-konsekutive-Teilfolge)
- [x] [Maximum](#Maximum)
- [ ] Max-Suche in unimodaler Liste
- [x] [Median](#Median)
- [ ] ~~Merge-Sort~~ (Skript)
- [x] [MinMax-Finding](#MinMax-Finding)
- [ ] Polynom Multiplikation
- [x] [Potenzieren](#Potenzieren)
- [ ] Quad-Trees
- [ ] ~~Quick-Sort~~ (Skript)
- [ ] Quick-Sort mit median of three (needs also median-of-3-killer)
- [ ] Sequence alignment
- [ ] Skyline
- [ ] ~~Strassen (Matrix-Multiplikation)~~ (Skript)
- [x] [Summe der Beträge (nicht-negativen)](#Summe-der-Beträge)
- [x] [Summe der Einträge](#Summe-der-Einträge)
- [ ] Viterbi

### Anzahl der nicht-negativen
```
def count_none_negative(N, left, right) {
    // Base
    if (left >= right) {
        return N[left] >= 0 ? 1 : 0
    }

    // Divide
    center = (left + right) / 2
    left_nn = count_none_negative(N, left, center)
    right_nn = count_none_negative(N, center + 1, right)
    
    // Conquer
    return left_nn + right_nn
}
```

Laufzeitanalyse:
```
a = 2
b = 2
𝛼 = 1
f(n) = O(1)
Fall 1 --> T(n) = Θ(n)
```

### Anzahl von Vertauschungen in einer unsortierten Liste
```
def MergeAndCount(A, li, m, re) {
    int i, j, k, n
    int aux[2]
    for (i=m+1; i > li; i--){
        aux[i-1] = a[i-1]
    }
    for (j=m; j<re; j++){
            aux[re+m-j] = a[j+1]
    }
    n = 0
    for (k=li, k<= re; k++) {
        if (aux[j] < aux[i]){
            a[k] = aux[j--]
            if (i<=m){
                n+= m-i+1
            }
        }
        else {
            a[k] = aux[i++]
        }
    }
}

def NumberofInversions(X, li, re){
    if (re<=li){
        return 0
    }
    m = (li+re)/2
    n1 = NumberofInversions(X, li, m)
    n2 = NumberofInversions(X, m+1, re)
    n3 = MergeAndCount (x, li, m, re)
    return n1 + n2 + n3
}
```

### Binärdarstellung
```
def get_binary(zahl) {
        // Base
	if (zahl == 0 || zahl == 1) {
            return String(zahl)
        }
		
        // Divide
		 rest = bin(zahl / 2)
		
        // Conquer
		return rest + String(zahl%2)
    }
```
Laufzeitanalyse:
```
a = 1
b = 2
𝛼 = 0
f(n) = O(1)
Fall 2a0 --> Θ(log 𝑛)
```

### GGT
```
def ggt(A, B) {
    if (A < B) {
        return ggt(B, A)
    }
    
    // Base
    if (A % B == 0) {
        return B
    }

    // Divide & Conquer
    return ggt(A % B , B)
}
```
Laufzeitanalyse:
```
a = 1
b = 2 (Jeder rekursive Schritt verkleinert die größere Zahl mindestens um Faktor 2)
𝛼 = 0
f(n) = O(1)
Fall 2a0 --> Θ(log 𝑛)
```

### GGT mehrere Zahlen
```
def ggt_multiple(N, left, right) {	
    // Base
    if (right - left <= 1) {
        return ggt(N[left], N[right])
    }
    
    // Divide
    center = (left + right) / 2
    left_ggt = ggt_multiple(N, left, center)
    right_ggt = ggt_multiple(N, center+1, right)
    
    // Conquer
    return ggt(left_ggt, right_ggt)
}
```
Laufzeitanalyse:
```
a = 2
b = 2
𝛼 = 1
f(N) = O(log n) => (Hängt nicht von N ab und verhält sich daher wie O(1))
Fall 2 --> O(N)
=> Gesamtlaufzeit: O(N*log n)
```
### Maximum
```
def max(N, left, right) {
    // Base
    if (left >= right) {
        return N[left]
    }

    // Divide
    center = (left + right) / 2
    left_max = max(N, left, center)
    right_max = max(N, center + 1, right)
    
    // Conquer
    if (left_max >= right_max) {
        return left_max
    }
    else {
        return right_max
    }
}
```
Laufzeitanalyse:
```
a = 2
b = 2
𝛼 = 1
f(n) = O(1)
Fall 1 --> O(n)
```

### Median
```
def median_of_medians(N) {
    // Base
    if (N.length <= 5) {
        N.sort()
        final_mediandex = N.length / 2
        final_median = N[final_mediandex]
        return final_median
    }
    
    // Divide & Conquer
    all_sublists = []
    for (i = 0; i < N.length; i+= 5){
        if (i+5 <= N.length) {
            sublist = N[i:i+4]
            all_sublists.append(sublist)
        }
        else {
            sublist = N[i:N.length-1]
            all_sublists.append(sublist)
        }
    }
    all_medians = []
    for (j = 0; j < all_sublists.length; j++) {
        all_sublists[j].sort()
        mediandex = all_sublists[j].length/2
        all_medians.append(all_sublists[j][mediandex])
    }
    median_of_medians(all_medians)
}
```
Laufzeitanalyse:
```
a = 1
b=5
𝛼 = 0
f(n)= O(n)
Fall 3 --> Θ(n)
```

### MinMax-Finding
```
def find_min_max(N, left, right) {
    // Base Case
    if (left >= right) {
        return [N[left], N[left]]; 
    }        

    // Divide
    center = (left + right) / 2;
    left_mm = find_min_max(N, left, center);
    right_mm = find_min_max(N, center+1, right);

    // Conquer
    min_max[2];
    min_max[0] = max(left_mm[0], right_mm[0]);
    min_max[1] = min(left_mm[1], right_mm[1]);

    return min_max;
}
```
Laufzeitanalyse:
```
a = 2
b = 2
𝛼 = 1
f(n)= O(1)
Fall 1 --> Θ(n)
```

### Potenzieren
```
def power(base, exp) {
    //Base case
    if (base == 0) {
        return 1;
    }
    if (exp == 1) {
        return base;
    }

    // Divide & Conquer
    half_power = power(base, exp / 2);
    result = half_power * half_power;
    
    // Wenn Exponent ungerade, multipliziere die Basis einmal zusätzlich, da beim Halbieren abgerundet wurde
    if (exp % 2 ) {
        result *= base;
    }
    return result;
}
```
Laufzeitanalyse:
```
a = 1
b = 2
𝛼 = 0
f(n)= O(1)
Fall 2a --> Θ(log n)
```

### k-t größtes Element
Naiv: Liste mit MergeSort sortieren und dann das k(-1)-te Element nehmen. Laufzeit: O(n log n)

Eine Alternative ist QuickSelect. Das ist wie QuickSort, nur dass man aufhört, sobald das Pivot Element das k-te Element ist (da das Pivot Element immer direkt an die richtige Stelle gesetzt wird, und dann der Rest entsprechend partitioniert wird.

![GeeksforGeeks Artikel](https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/)

### Maximale-konsekutive Teilfolge
```
def max_sequence(N, left, right) {
    // Base
    if (left>=right) {
        return N[left] > 0 ? N[left] : 0
    }
    
    // Divide
    center = (left + right) / 2;
    lmidmax = 0;
    left_sum = 0;
    for (i = center; i>= left, i--) {
        left_sum += N[i]
        lmidmax = (lmidmax > left_sum) ? lmidmax : left_sum
    }
    rmidmax = 0;
    right_sum = 0;
    for (i = center+1; i<= right, i++) {
        right_sum += N[i]
        rmidmax = (rmidmax > right_sum) ? rmidmax : right_sum
    }
    left_max = max_sequence(left, center)
    right_max = max_sequence(center+1, right)

    // Conquer
    lmidtotal = lmidmax + rmidmax
    if ((lmidtotal) >= left_max && (lmidtotal) >= right_max) {
        return (lmidtotal)
    }
    else if (left_max >= right_max) {
        return left_max
    }
    else {
        return right_max
    }
}
```
Laufzeitanalyse:
```
a = 2
b = 2
𝛼 = 1
f(n) = O(n)
Fall 2a0 --> Θ(log 𝑛)
```

### Summe der Beträge
```
def sum_abs(N, left, right) {    
    // Base
    if (left >= right) {
        if (N[left] < 0) {
            return (-1 * N[left])
        }
        else {
            return N[left];
        }
    }
    
    // Divide
    center = (left + right) / 2;
    left_sum = sum_abs(N, left, center);
    right_sum = sum_abs(N, center + 1, right);
    
    // Conquer
    return left_sum + right_sum;
}
```
Laufzeitanalyse:
```
a = 2
b = 2
𝛼 = 1
f(n) = O(1)
Fall 1 --> T(n) = Θ(n)
```

### Summe der Einträge
```
def sum_total(N, left, right) {    
    // Base
    if (left >= right) {
        return N[left];
    }
    
    // Divide
    center = (left + right) / 2;
    left_sum = sum_total(N, left, center);
    right_sum = sum_total(N, center + 1, right);
    
    // Conquer
    return left_sum + right_sum;
}
```
Laufzeitanalyse:
```
a = 2
b = 2
𝛼 = 1
f(n) = O(1)
Fall 1 --> T(n) = Θ(n)
```

## Greedy
- [x] [A*-Algorithmus](#A*-Algorithmus)
- [x] [Approximate bin packing](#Approximate-bin-packing)
- [ ] Clustering (based on MST)
- [ ] Delaunay via Lawson
- [ ] ~~Dijkstra~~ (Skript)
- [x] [Flüsse in Netzwerken (Ford/Fulkerson/Dinic)](#Flüsse-in-Netzwerken)
- [ ] ~~Fraktionales Rucksackproblem~~ (Skript)
- [ ] Horn Formeln
- [ ] ~~Huffman-Coding~~ (Skript)
- [ ] ~~Job Scheduling~~ (Skript)
- [x] [Kartenfärbung](#Kartenfärbung)
- [ ] ~~Kruskal (minimal aufspannender Baum)~~
- [x] [Marching algorithms](#Marching)
- [x] [Min-Cut Max-Flow] (#Min-Cut-Max-Flow)
- [x] [Partition Problem](#Partition-problem)
- [ ] ~~Prim (minimal aufspannender Baum)~~
- [ ] Set cover
- [x] [Shortest common superstring](#Shortest-common-superstring)
- [x] [Springerproblem kein Schachfeld](#Springerproblem-kein-Schachfeld)
- [ ] ~~Wechselgeld~~

### A*-Algorithmus
![Gute Erklärung auf YouTube](https://www.youtube.com/watch?v=-L-WgKMFuhE)

### Approximate bin packing
```
k = Anzahl an Behältnissen (Obergrenze)
u = maximale Gewicht aller Behältnisse (immer gleich)
[n1,n2,n3] = Einzelgewichte der Gegenstände

1. Sortiere die Objekte nach absteigendem Gewicht
2. Füge die Objekte der Reihe nach ein, sodass jedes in den ersten Behälter gegeben wird, in dem noch genug Platz ist.
3. Falls in keinem der bereits geöffneten Behälter genügend Platz ist, öffne einen neuen.
4. Falls die Anzahl an Behälnissen kleiner oder gleich k ist, dann passt es. Sonst nicht.
```

### Flüsse in Netzwerken

```
1. total_flow = 0
2. Für jeden Pfad von s nach t
    3. addiere den Flow des Pfades zu total_flow
4. Gib total_flow zurück
```
[GeeksforGeeks Artikel](https://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/)

### Kartenfärbung
```
def map_col(N[][]) {
    number_of_countries = N[0].length
    result = [number_of_countries]

    // iterate all countries
    for(i = 0; i < number_of_countries; i++) {
        
        // iterate all neighbours of the country i
        for (j = 0; j < number_of_countries; j++) {
            if(i != j && N[i][j] == 1) { 
                result[i] = // pick a color, that none of the neighbors has
            }
        }
    }
}
```

### Marching
```
def march(landscape, location, step_size, error_tolerance = 3) {
    if(step_size < error_tolerance) {
        return location
    }

    option_a = location - step_size
    option_b = location + step_size

    if(option_a.height > option_b.height) {
        if(option_a.height > location) {
            march(landscape, option_a, step_size)
        } else {
            march(landscape, location, step_size/2)
        }
    } else {
        if(option_b.height > location) {
            march(landscape, option_b, step_size)
        } else {
            march(landscape, location, step_size/2)
        }
    }
}
```

### Min-Cut Max-Flow
Ähnlich oder gleich zu [Flüsse in Netzwerken](#Flüsse-in-Netzwerken)

### Partition Problem
```
def partition(numbers) {
    numbers.sortDescending()
    p1 = [l[0]]
    p2 = []
    
    for(i = 1; i < numbers.length; i++) {
        p1_total = 0;
        for(ip1 = 0; ip1 < p1.length; ip1++) {
            p1_total += ip1
        }
        p2_total = 0;
        for(ip2 = 0; ip2 < p2.length; ip2++) {
            p2_total += ip2
        }
        if(p1_total < p2_total) {
            p1.add(i)
        } else {
            p2.add(i)
        }
    }
}
```

### Shortest common superstring
```
def shortest_common_superstring(S) {
    superstring = ""
    S.sortDescendingByLength()

    for (i = 0; i < S.length; i++) {
        string = S[i]
        
        if(!superstring.contains(string)) {
            superstring += string
        }
    }
    return superstring;
}
```
Laufzeitanalyse:
```
O(n), falls die contains() Methode konstante Laufzeit hat
```

Dieser Algorithmus ist u.U. weit vom Optimum entfernt (aber funktioniert).

### Springerproblem kein Schachfeld
```
def jump(N) {
    jump = 0
    nextJumpPosition = 0
    i = 0
    while (i < N.length -1) {
        farthest = i + N[i]
        if (farthest >= N.length -1){
            return jump++
        }
        start = i + 1
        end = i + N[i]
        for (let j = start; j <= end; j++){
            if (j + N[j] >= farthest){
                farthest = j + N[j]
                nextJumpPosition = j
            }
        }
        jump += 1
        i = nextJumpPosition
    }
}
```

## Dynamisches Programm
- [ ] ~~0-1-Rucksackproblem~~ (Skript)
- [ ] Ähnliche Summe
- [ ] ~~Alle kürzesten Wege (Floyd)~~ (Skript)
- [ ] Approximation von Pi mit n-gon
- [ ] ~~Binomialkoeffizienten~~
- [x] [Catalan-Zahlen](#Catalan-Zahlen)
- [ ] Context free language recognition
- [ ] deBoor
- [ ] deCasteljau
- [ ] ~~Editierabstand~~ (Skript)
- [ ] ~~Fibonacci-Zahlen~~ (Skript)
- [ ] Independent sets in trees
- [ ] ~~Kettenmultiplikation von Matrizen~~
- [ ] Kürzester Weg eines Springers
- [ ] Längste aufsteigende Teilfolge
- [x] [Längste gemeinsame Teilfolge](#Längste-gemeinsame-Teilfolge)
- [ ] Minimale Triangulierung eines konvexen Vielecks
- [ ] Minimum weight triangulation of simple polygon (MWT)
- [ ] Neville-Aitken-Verfahren
- [ ] Newton-Interpolation
- [ ] Optimale binäre Suchbäume
- [x] [Partition problem](#partition-problem)
- [ ] Rekursion
- [x] [Subset-sum](#subset-sum)
- [ ] Summe von Produkten
- [ ] Zahlen-Dreieck

### Catalan-Zahlen
```
def catalan(n) {
    if (n == 0 || n == 1) {
        return 1
    }
 
    // Table to store results of subproblems
    res = [n+1]
 
    // Initialize first two values in table
    res[0] = 1
    res[1] = 1
 
    // Fill entries in res[] using recursive formula
    for(i = 2, i <= n, i++) {
        for(j = 0; j < i; j++) {
            res[i] += res[j] * res[i-j-1]
	}
    }
    return res[n]
}
```

Laufzeitanalyse:
```
2 Schleifen ineinander, jeweils n Wiederholung => O(n^2)
```

Formel für Catalan Zahlen steht im Skript!

Rekursiv (nur als Referenz, schlechte Laufzeit)
```
def catalan(n) {
    if (n <= 1) {
        return 1
    }
    res = 0
    for(int i = 0; i < n; i++) {
        res += catalan(i) * catalan(n-i-1)
    }
    return res
}
```

### Längste gemeinsame Teilfolge
```
def lcs(X, Y, m, n):
    // declaring the matrix for storing the values
    L = [m + 1][n + 1]

    // iterate over each cell
    for(i = 0; i < m + 1; i++) {
        for(j = 0; j < n + 1; j++) {
            
            // initialize first column and row with zeros
            if (i == 0 || j == 0) {
                L[i][j] = 0
            } else if (X[i-1] == Y[j-1]) {
                // chars are equal -> take top-left and increase by 1
                L[i][j] = L[i-1][j-1] + 1
            } else {
                // chars are unequal -> take max of top and left
                L[i][j] = max(L[i-1][j], L[i][j-1])
            } 
        }    
    }
            
    // L[m][n] contains the length of LCS of X[0..n-1] & Y[0..m-1]
    return L[m][n]
```

Rekursiv (nur als Referenz, schlechte Laufzeit)
```
def lcs(X, Y, m, n):
    if (m == 0 || n == 0) {
       return 0
    } else if (X[m-1] == Y[n-1]) {
        return 1 + lcs(X, Y, m-1, n-1)
    } else {
        return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n))
    }
```

### Partition problem
```
1. Summe über alle Elemente berechnen
2. Ist die Summe ungerade?
    3. Ja, dann return false
    4. Nein, dann rufe Subset sum(Summe/2) auf
```
Tipp: Das Partitionsproblem ist lässt sich auf das subset sum Problem reduzieren,
da eine gleichmäßige Partitionierung immer erfolgreich ist, wenn die Hälfte der Summe aus den Elementen gebildet werden kann. Genau das prüft die subset sum.

### Subset-sum
```
isSubsetSum(set, n, sum) = isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1])

Base Cases:
isSubsetSum(set, n, sum) = false, if sum > 0 and n == 0
isSubsetSum(set, n, sum) = true, if sum == 0 
```

![](https://i1.wp.com/algorithms.tutorialhorizon.com/files/2015/05/Subset-Sum-Problem.jpg)

Rekursionsschritt von: https://www.geeksforgeeks.org/subset-sum-problem-dp-25/

## Backtracking
- [ ] Aufsteigende Türme auf den ersten m Reihen
- [x] [Binpacking](#Binpacking)
- [ ] ~~Damenproblem~~ (Skript)
- [ ] ~~Färben von Graphen~~ (Skript)
- [ ] Hamiltonian cycle
- [ ] Hamiltonian path
- [ ] Labyrinth
- [ ] Partitionierung einer natürlichen Zahl
- [x] [Springerproblem](#Springerproblem)
- [ ] Subset Sum
- [ ] Sudoku
- [ ] Testmusterkompaktierung
- [ ] Traveling sales man
- [ ] Türme auf den ersten m Reihen
- [x] [Türmeproblem](#Türmeproblem)
- [ ] Turnpike reconstruction

### Binpacking
```
1. Gehe über alle Gegenstände G
    2. Gehe über alle Eimer E
        3. Passt G in E?
            4. Wenn ja, tu es rein
            5. Wenn nein
                6. Steht noch ein Eimer, in den G hinein passt, zur Verfügung?
                    7. Ja, dann tu es hinein
                        8. Ist der Lösungsvektor vollständig?
                            9. Wenn ja, gib das Ergebnis aus
                    10. Nein, dann nimm den vorherigen Gegenstand wieder raus
                        11. Dieser Gegenstand ist nun das neue G, fahre damit bei Schritt 2 fort

```

### Springerproblem
```
Wenn alle Felder besucht wurden, gib das Ergebnis aus
Probiere rekursiv (nach Tiefensuche) alle Möglichkeiten aus
    Wenn die Möglichkeit nicht zur Lösung führt, gehe einen Schritt im Entscheidungsbaum zurück, und probiere eine der anderen Möglichkeiten
    Wenn eine Möglichkeit nicht funktioniert, gib false zurück
Wenn die letzte getestete Möglichkeit nicht funktioniert, gib 0 zurück
```

### Travelling Salesman
```
Probiere jeden möglichen Pfad aus und speichere das Minimum.
```

Laufzeitanalyse:
```
O(n!), da erst n viele Städte zur Auswahl stehen, dann n-1 viele, dann n-2 viele etc.
```

### Türmeproblem
```
1. Erzeuge Lösungsvektor mit [-1]
2. Solange Lösungsvektor nicht leer ist, wiederhole:
    3. Solange der folgende Vorschlag noch nicht valide ist:
        4. Vorschlag: Rücke 1 nach rechts
        5. Ist dieser Vorschlag valide?
            6. Wenn ja, ist der Lösungsvektor vollständig?
                7. Wenn ja, gib das Ergebnis aus (und/oder zähle die Anzahl der Lösungen)
                8. Wenn nein, lösche den Vorschlag aus dem Lösungsvektor und verändere den vorherigen Vorschlag
            9. Wenn nein, lösche den Vorschlag aus dem Lösungsvektor
```
Tipp: Gleiches Vorgehen wie beim Damenproblem, nur die Bedrohungsprüfung ist anders.
