# Algorithms_Project
Project written for Algorithms 2 in college.

Zadání
1 Průměr a poloměr grafu
Problém
Máte dán neorientovaný graf 𝐺. Každý vrchol grafu 𝐺 je označen celým nezáporným číslem. Vaším
úkolem v tomto zadání je:
1. Navrhnout vhodnou reprezentaci grafu 𝐺 v paměti a umět načíst graf 𝐺, z textového souboru ve
výše uvedeném formátu, do této reprezentace.
2. Najít největší komponentu 𝐾 v grafu 𝐺. Definici komponenty lze nalézt například v [1], kapitola 2.2.
3. Vypočítat průměr a poloměr komponenty 𝐾. Jak je definován průměr a poloměr grafu se dozvíte
například v [1], kapitola 2.3.
Ukázka
Ukázkový graf 𝐺 na obrázku 1 je tvořen dvěma komponentami. První komponenta obsahuje čtyři vrcholy {0, … , 3} a druhá komponenta obsahuje šest vrcholů {4, … , 9} a jde tedy o hledanou největší komponentu 𝐾. Nejprve podle [1] spočteme excentricity jednotlivých vrcholů komponenty 𝐾. Výsledky
jsou uvedeny v tabulce 1. Odtud tedy 𝑑𝑖𝑎𝑚(𝐾 ) = 3 a 𝑟𝑎𝑑(𝐾 ) = 2.
Implementace
• Graf 𝐺 je uložen v textovém souboru, kdy na každém řádku je vždy uložena dvojice celých nezáporných čísel 𝑖 a 𝑗 oddělených jednou mezerou. Čísla 𝑖 a 𝑗 představují vrcholy grafu mezi kterými
existuje hrana. Uložení ukázkového grafu 𝐺 v textovém souboru je opět vidět na obrázku 1.
• Je nutné počítat s tím, že hrany mohou být uloženy v textovém souboru zcela nahodile, nelze
předpokládat, že jsou nějak systematicky uspořádány.
• Dále graf 𝐺 může být i dosti rozsáhlý, tj. stovky tisíc vrcholů a miliony hran.
• Vámi implementovanou aplikaci otestujte nejen na malém ukázkovém grafu z obrázku 1, ale i na
všech ostatních testovacích grafech.
• Výsledek vypište na standardní výstup.

Assignment
1. Graph Diameter and Radius
Problem
You are given an undirected graph 𝐺. Each vertex in the graph 𝐺 is labeled with a non-negative integer. Your task in this assignment is:
1. Design a suitable representation of the graph 𝐺 in memory and be able to load the graph 𝐺 from a text file in the above-mentioned format into this representation.
2. Find the largest component 𝐾 in the graph 𝐺. The definition of a component can be found, for example, in [1], chapter 2.2.
3. Calculate the diameter and radius of component 𝐾. The definition of graph diameter and radius can be found, for example, in [1], chapter 2.3.
Example
The sample graph 𝐺 in Figure 1 consists of two components. The first component contains four vertices {0, … , 3}, and the second component contains six vertices {4, … , 9}, which is the sought-after largest component 𝐾. First, according to [1], we calculate the eccentricities of individual vertices of component 𝐾. The results are shown in Table 1. Therefore, 𝑑𝑖𝑎𝑚(𝐾) = 3, and 𝑟𝑎𝑑(𝐾) = 2.
Implementation
• The graph 𝐺 is stored in a text file, where on each line, a pair of non-negative integers 𝑖 and 𝑗 separated by a single space is stored. The numbers 𝑖 and 𝑗 represent vertices of the graph connected by an edge. The storage of the sample graph 𝐺 in a text file is again visible in Figure 1.
• It is necessary to consider that edges may be stored in the text file completely randomly, and it cannot be assumed that they are systematically ordered.
• Furthermore, the graph 𝐺 can be quite extensive, i.e., hundreds of thousands of vertices and millions of edges.
• Test your implemented application not only on a small sample graph from Figure 1 but also on all other test graphs.
• Print the result to standard output.
