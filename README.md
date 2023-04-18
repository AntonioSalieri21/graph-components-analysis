# Algorithms_Project
My project on Algotihms

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
