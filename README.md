# AlgoTech

## Teile und Herrsche

- [x] [Anzahl der nicht-negativen](#Anzahl-der-nicht-negativen)
- [ ] Anzahl von Vertauschungen in einer „unsortierten“ Liste
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
- [ ] Summe der Einträge
- [ ] Viterbi

### Anzahl der nicht-negativen
```
def count_none_negative(N, left, right) {
        // Base
        if (left >= right) {
            return N[left] >= 0? 1 : 0
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
f(n) = O(log n)
Fall 1 --> O(n) (???)
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
b=2
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
a = 2
b=2
𝛼 = 1
f(n)= O(1)
Fall 1 --> Θ(n)
```

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
    left_sum = count_none_negative(N, left, center);
    right_sum = count_none_negative(N, center + 1, right);
    
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
- [ ] A*-Algorithmus
- [ ] Approximate bin packing
- [ ] Clustering (based on MST)
- [ ] Delaunay via Lawson
- [ ] ~~Dijkstra~~ (Skript)
- [ ] Flüsse in Netzwerken (Ford/Fulkerson/Dinic)
- [ ] ~~Fraktionales Rucksackproblem~~ (Skript)
- [ ] Horn Formeln
- [ ] ~~Huffman-Coding~~ (Skript)
- [ ] ~~Job Scheduling~~ (Skript)
- [ ] Kartenfärbung
- [ ] ~~Kruskal (minimal aufspannender Baum)~~
- [ ] Marching algorithms
- [ ] Min-Cut (Max-Flow)
- [ ] Partition Problem (not optimal)
- [ ] ~~Prim (minimal aufspannender Baum)~~
- [ ] Set cover (not optimal)
- [ ] Shortest common superstring
- [ ] Springerproblem
- [ ] ~~Wechselgeld~~