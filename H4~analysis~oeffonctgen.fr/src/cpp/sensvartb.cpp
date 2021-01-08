target=sensvartb

#include "header.inc"
#include "lang_titles.inc"

\css{<style>
table.tab_var {margin-left:auto;margin-right:auto;
   border:solid 1px black;}
table.tab_var tr, table.tab_var td, table.tab_var th {
   padding:7pt;margin-top:10px; margin-bottom:10px;
   text-align:center; border-collapse:collapse; min-width:10pt;
   }
table.tab_var th { border:solid 1px black}
table.tab_var tr { border:solid 1px black}
</style>
}

%% couleur des grilles
\text{gridcolor=lightblue}

%% Choix de 4 points dans le cadre
\integer{x0=random(-4..-2)}
\integer{x1=\x0+random(1..3)}
\integer{x2=\x1+random(1..3)}
\integer{x3=\x2+1}
\integer{c=random(1..3)*random(1,-1)}
\integer{d=random(-2..2)}

\matrix{symb = \(\searrow),\(\nearrow),\(\searrow)
\(\nearrow),\(\searrow),\(\nearrow)}
\text{variations = \(\nearrow),\(\searrow)}
\text{monotone = \(\nearrow),\(\searrow)}

%% choix du sens de variation
\integer{cas=random(1,2)}
\integer{i1=\cas=1?1:2}
\integer{i2=\cas=1?2:1}
\text{c_f=\cas=1?1,2,1:2,1,2}
\text{monotone=\symb[\cas;]}

%% choix des valeurs de x
\integer{x1=random(-10..10)}
\integer{x2=\x1+random(1..10)}
\integer{x3=\x2+random(1..10)}
\integer{x4=\x3+random(1..10)}
\text{xl=\x1,\x2,\x3,\x4}


%% choix des valeurs de f(x)
\integer{y1=random(-10..10)}
\if{\cas=1}
 {
 \integer{y2=\y1-random(1..10)}
 \integer{y3=\y2+random(1..10)}
 \integer{y4=\y3-random(1..10)}
 }
 {
 \integer{y2=\y1+random(1..10)}
 \integer{y3=\y2-random(1..10)}
 \integer{y4=\y3+random(1..10)}
 }
\text{yl=\y1,\y2,\y3,\y4}
\text{indl=shuffle(4)}
%% on choisit la question image de \xl[\indl[1]]
%% et on veut tester la compr�hension
%% on veut \yl[indl[2]]=\xl[\indl[1]]
\integer{rep1=\yl[\indl[1]]}
\integer{offset=\xl[\indl[1]]-\yl[\indl[2]]}
\integer{y1=\y1+\offset}
\integer{y2=\y2+\offset}
\integer{y3=\y3+\offset}
\integer{y4=\y4+\offset}
\integer{rep1=\rep1+\offset}

\if{\cas=1}
 {
  \text{pos=top,bottom,top,bottom}
 }
 {
   \text{pos=bottom,top,bottom,top}
 }

 \text{d1=\y1}
 \text{d2=\y2}
 \text{d3=\y3}
 \text{d4=\y4}
%% Choix des intervalles
\matrix{interval=\x1,\x2
\x2,\x3
\x3,\x4
\x1,\x3
\x2,\x4}

%% Pr�paration des r�ponses
\text{replist=non monotone, croissante, d�croissante}
\if{\cas=1}
 { \text{goodrep=3,2,3,1,1}}
 { \text{goodrep=2,3,2,1,1}}

%% Pr�paration des questions
\text{indl=shuffle(5)}
\text{q1=\interval[\indl[1];]}
\text{q2=\interval[\indl[2];]}
\text{q3=\interval[\indl[3];]}
\text{q4=\interval[\indl[4];]}
\text{q5=\interval[\indl[5];]}

%% enonc� de l'exo %%



#include "lang.inc"

\statement{
<p>
Soit \(f) une fonction d�finie sur &#91; \x1;\x4 &#93; dont le
tableau des variations est donn� ci-dessous
</p>
<table class="wimscenter wimsborder var_tab">
<tr>
  <th style="width:15%;"> \(x)</th>
      <td style="width:15%;text-align:left"> \x1</td>
      <td style="width:8%;"></td>
      <td style="width:15%;">\x2</td>
      <td style="width:8%;"></td>
      <td style="width:15%;">\x3</td>
      <td style="width:8%;"></td>
      <td style="width:15%;text-align:right">\x4</td>
</tr><tr>
  <th valign="middle" style="width:15%;" >\(f(x))</th>
     <td style="width:15%;text-align:left" valign="\pos[1]"> \d1 </td>
     <td style="width:8%;"> \monotone[1] </td>
     <td style="width:15%;" valign="\pos[2]"> \d2 </td>
     <td style="width:8%;"> \monotone[2]  </td>
     <td style="width:15%;" valign="\pos[3]"> \d3 </td>
     <td style="width:8%;"> \monotone[3] </td>
     <td style="width:15%;text-align:right" valign="\pos[4]"> \d4 </td>
   </tr>
</table>

Votre r�ponse :
<ul><li>
sur &#91;\q1[1];\q1[2]&#93;, \(f) est \embed{reply1}
</li><li>
sur &#91;\q2[1];\q2[2]&#93;, \(f) est \embed{reply2}
</li><li>
sur &#91;\q3[1];\q3[2]&#93;, \(f) est \embed{reply3}
</li><li>
sur &#91;\q4[1];\q4[2]&#93;, \(f) est \embed{reply4}
</li><li>
sur &#91;\q5[1];\q5[2]&#93;, \(f) est \embed{reply5}
</li></ul>

}
%% soumission de r�ponse %%
\answer{ \(f) est:}{\goodrep[\indl[1]];\replist}{type=menu}
\answer{ \(f) est:}{\goodrep[\indl[2]];\replist}{type=menu}
\answer{ \(f) est:}{\goodrep[\indl[3]];\replist}{type=menu}
\answer{ \(f) est:}{\goodrep[\indl[4]];\replist}{type=menu}
\answer{ \(f) est:}{\goodrep[\indl[5]];\replist}{type=menu}
