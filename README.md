# OOP_PapildomaUzduotis
std::string ir asociatyvių konteinerių naudojimas

### Diegimo instrukcija (Windows/Linux platformoms):

#### Windows:

1. Parsisiųskite naujausią release'ą

2. Programai būtina [MinGW](http://www.mingw.org/) aplinka.

3. Programos paleidimui (terminale):

   1. Įsitikinkite, kad esate tame pačiame aplanke kaip ir source kodas
   2. Parašykite komandą ` mingw32-make `  (sukompiliuoja ir sulinkina kodą)
   3. Parašykite komandą ` mingw32-make run ` (paleidžia paleidžiamąjį failą)

5. Norėdami išvalyti sukurtus failus naudokite komandą`mingw32-make clean` 

#### Unix:

1. Parsisiųskite naujausią release'ą
2. Programos paleidimui (terminale):
   1. Įsitikinkite, kad esate tame pačiame aplanke kaip ir source kodas
   2. Parašykite komandą ` make `  (sukompiliuoja ir sulinkina kodą)
   3. Parašykite komandą `make run ` (paleidžia paleidžiamąjį failą)
4. Norėdami išvalyti sukurtus failus naudokite komandą `make clean` 

Jei naujai sukurtas main paleidžiamasis failas nepasileidžia, Terminale padarykite jį paleidžiamuoju - komanda `chmod a+x main`

## Programos funkcionalumas

1. Programa suskaičiuoja, kiek kartų buvo paminėtas žodis tekste (pavyzdinis tekstas (`tekstas.txt`) yra iš Wikipedijos apie [Kernavę](https://lt.wikipedia.org/wiki/Kernav%C4%97), 1039 žodžiai) ir, jei jis kartojasi, išveda jį į failą `rez.txt` tvarka: 

   ```
   kiekis žodis
   ```

   ![image-20200614231755076](C:\Users\aidas\AppData\Roaming\Typora\typora-user-images\image-20200614231755076.png)

2. Sukuria cross-reference tipo lentelę, kurioje nurodoma kiek kartų atitinkamas žodis kartojosi. Lentelė pasiekiama faile `xref.txt`

![image-20200614232135174](C:\Users\aidas\AppData\Roaming\Typora\typora-user-images\image-20200614232135174.png)

Paveikslėlis tik nedidelė failo iškarpa.

3. Taip pat iš teksto yra išrenkami URL adresai, prasidedantys pilnuoju (http/https) arba trumpuoju (www) keliu.

   ![image-20200614232331424](C:\Users\aidas\AppData\Roaming\Typora\typora-user-images\image-20200614232331424.png)