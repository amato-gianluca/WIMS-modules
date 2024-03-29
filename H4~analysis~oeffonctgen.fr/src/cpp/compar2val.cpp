target=compar2val

#include "header.inc"
#include "lang_titles.inc"


# TODO : am�liorer le tableau de variations en s'inspirant de exploitabvar.oef

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


%% comparaison
\text{slt=\(<)}
\text{sgt=\(>)}
\text{choixcomp=inferieur �,sup�rieur �,on ne peut pas savoir}
\text{choixcomp=<,>,on ne peut pas savoir}

\matrix{symb = \(\searrow),\(\nearrow),\(\searrow)
\(\nearrow),\(\searrow),\(\nearrow)}
\text{variations = \(\nearrow),\(\searrow)}
\text{monotone = \(\nearrow),\(\searrow)}

%% choix du sens de variation
\integer{cas=random(1,2)}
\integer{cas2=random(1..4)}

%% cas pour d�terminer sens de variation
%% cas 2 pour d�terminer si borne infinie ou pas
%% cas2=1 +inf, =2 -inf =3 ou4 born�e
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
 \integer{y3=\y3=\y1?\y3+1}
 \integer{y4=\y3-random(1..10)}
 \integer{y4=\y4=\y1?\y4-1}
 \integer{y4=\y4=\y2?\y4-1}
 }
 {
 \integer{y2=\y1+random(1..10)}
 \integer{y3=\y2-random(1..10)}
 \integer{y3=\y3=\y1?\y3-1}
 \integer{y4=\y3+random(1..10)}
 \integer{y4=\y4=\y1?\y4+1}
 \integer{y4=\y4=\y2?\y4+1}
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
  \if{\cas2=1}
   {
     \text{d1=\(+\infty)}
     \text{crog=&#93;}
     \integer{y1=1000}
   }
   {
     \text{d1=\y1}
     \text{crog=&#91;}
   }
 \text{d2=\y2}
 \text{d3=\y3}
 \if{\cas2=2}
  {
    \text{d4=\(-\infty)}
    \text{crod=&#91;}
    \integer{y4=-1000}
  }
  {
    \text{d4=\y4}
    \text{crod=&#93;}
  }
 }
 {
     \text{pos=bottom,top,bottom,top}
  \if{\cas2=2}
   {
     \text{d1=\(-\infty)}
     \text{crog=&#93;}
     \integer{y1=-1000}
   }
   {
     \text{d1=\y1}
     \text{crog=&#91;}
   }
 \text{d3=\y3}
 \text{d2=\y2}
  \if{\cas2=1}
   {
     \text{d4=\(+\infty)}
     \text{crod=&#91;}
     \integer{y4=1000}
   }
   {
     \text{d4=\y4}
     \text{crod=&#93;}
   }
 }
%% Pr�paration des questions

\real{e0=\x1}
\real{e1=randint(\x1*10..\x2*9)/10+0.1}
\real{e1=\e1>=\x2?((\x1)+(\x2))/2}
\real{e2=\x2}
\real{e3=randint(\x2*10..\x3*9)/10+0.1}
\real{e3=\e3>=\x3?((\x2)+(\x3))/2}
\real{e4=\x3}
\real{e5=randint(\x3*10..\x4*9)/10+0.1}
\real{e5=\e5>=\x4?((\x3)+(\x4))/2}
\real{e6=\x4}

\text{qxl=}
\text{qyl=}
\text{indql=}
#q1  a retirer si x1 inf
\real{qx=\e0}
\real{qy=\e1}
\integer{indq=\cas=1?2:1}
\text{qxl=wims (append item \qx to \qxl)}
\text{qyl=wims (append item f(\qy) to \qyl)}
\text{indql=wims (append item \indq to \indql)}
#q2
\real{qx=\e1}
\real{qy=\e2}
\integer{indq=\cas=1?2:1}
\text{qxl=wims (append item \qx to \qxl)}
\text{qyl=wims (append item f(\qy) to \qyl)}
\text{indql=wims (append item \indq to \indql)}
#q3
\real{qx=\e2}
\real{qy=\e3}
\integer{indq=\cas=1?1:2}
\text{qxl=wims (append item \qx to \qxl)}
\text{qyl=wims (append item f(\qy) to \qyl)}
\text{indql=wims (append item \indq to \indql)}
#q4
\real{qx=\e3}
\real{qy=\e4}
\integer{indq=\cas=1?1:2}
\text{qxl=wims (append item \qx to \qxl)}
\text{qyl=wims (append item f(\qy) to \qyl)}
\text{indql=wims (append item \indq to \indql)}
#q5
\real{qx=\e4}
\real{qy=\e5}
\integer{indq=\cas=1?2:1}
\text{qxl=wims (append item \qx to \qxl)}
\text{qyl=wims (append item f(\qy) to \qyl)}
\text{indql=wims (append item \indq to \indql)}
#q6 a retirer si x4 inf
\real{qx=\e5}
\real{qy=\e6}
\integer{indq=\cas=1?2:1}
\text{qxl=wims (append item \qx to \qxl)}
\text{qyl=wims (append item f(\qy) to \qyl)}
\text{indql=wims (append item \indq to \indql)}
#q7 a retirer si x1 inf
\real{qx=\e0}
\real{qy=\e3}
\if{\cas=1}
  {\integer{indq=\y3>\y1?3:2}}
  {\integer{indq=\y3<\y1?3:1}}
\text{qxl=wims (append item \qx to \qxl)}
\text{qyl=wims (append item f(\qy) to \qyl)}
\text{indql=wims (append item \indq to \indql)}
#q8  a retirer si x1 inf
\real{qx=\e0}
\real{qy=\e5}
\if{\cas=1}
  {
   \if{\y1>\y3}{\integer{indq=2}}
   {\integer{indq=\y1<\y4?1:3}}
  }
  {
   \if{\y1<\y3}{\integer{indq=1}}
   {\integer{indq=\y1>\y4?2:3}}
  }
\text{qxl=wims (append item \qx to \qxl)}
\text{qyl=wims (append item f(\qy) to \qyl)}
\text{indql=wims (append item \indq to \indql)}
#q9
\real{qx=\e1}
\real{qy=\e3}
\integer{indq=3}
\text{qxl=wims (append item \qx to \qxl)}
\text{qyl=wims (append item f(\qy) to \qyl)}
\text{indql=wims (append item \indq to \indql)}
#q10
\real{qx=\e3}
\real{qy=\e5}
\integer{indq=3}
\text{qxl=wims (append item \qx to \qxl)}
\text{qyl=wims (append item f(\qy) to \qyl)}
\text{indql=wims (append item \indq to \indql)}
#q11
\real{qx=\e1}
\real{qy=\e4}
\if{\cas=1}
    {\integer{indq=\y1<\y3?1:3}}
    {\integer{indq=\y1>\y3?2:3}}
\text{qxl=wims (append item \qx to \qxl)}
\text{qyl=wims (append item f(\qy) to \qyl)}
\text{indql=wims (append item \indq to \indql)}
#q12 a retirer si x4 inf
\real{qx=\e3}
\real{qy=\e6}
\if{\cas=1}
  {\integer{indq=\y2<\y4?3:2}}
  {\integer{indq=\y2>\y4?3:1}}
\text{qxl=wims (append item \qx to \qxl)}
\text{qyl=wims (append item f(\qy) to \qyl)}
\text{indql=wims (append item \indq to \indql)}
#q13 a retirer si x4 inf
\real{qx=\e1}
\real{qy=\e6}
\if{\cas=1}
  {
   \if{\y2>\y4}{\integer{indq=2}}
   {\integer{indq=\y1<\y4?1:3}}
  }
  {
   \if{\y2<\y4}{\integer{indq=1}}
   {\integer{indq=\y1>\y4?2:3}}
  }
\text{qxl=wims (append item \qx to \qxl)}
\text{qyl=wims (append item f(\qy) to \qyl)}
\text{indql=wims (append item \indq to \indql)}
#q14 a retirer si x1 inf
\real{qx=\e1}
\real{qy=\y1}
\integer{indq=\cas=1?1:2}
\text{qxl=wims (append item \qx to \qxl)}
\text{qyl=wims (append item \qy to \qyl)}
\text{indql=wims (append item \indq to \indql)}
#q15
\real{qx=\e1}
\real{qy=\y2}
\integer{indq=\cas=1?2:1}
\text{qxl=wims (append item \qx to \qxl)}
\text{qyl=wims (append item \qy to \qyl)}
\text{indql=wims (append item \indq to \indql)}
#q16
\real{qx=\e1}
\real{qy=\y3}
\if{\cas=1}
    {\integer{indq=\y1<\y3?1:3}}
    {\integer{indq=\y1>\y3?2:3}}
\text{qxl=wims (append item \qx to \qxl)}
\text{qyl=wims (append item \qy to \qyl)}
\text{indql=wims (append item \indq to \indql)}
#q17 a retirer si x4 inf
\real{qx=\e1}
\real{qy=\y4}
\if{\cas=1}
  {
   \if{\y2>\y4}{\integer{indq=2}}
   {\integer{indq=\y1<\y4?1:3}}
  }
  {
   \if{\y2<\y4}{\integer{indq=1}}
   {\integer{indq=\y1>\y4?2:3}}
  }
\text{qxl=wims (append item \qx to \qxl)}
\text{qyl=wims (append item \qy to \qyl)}
\text{indql=wims (append item \indq to \indql)}

\if{\crog=&#93;}
 { \text{il1=shuffle(5)}
   \integer{offset1=1}
   \text{il2=shuffle(5)}
   \integer{offset2=8}
   \text{il3=shuffle(3)}
   \integer{offset3=14}
 }
 { \if{\crod=&#91;}
   { \text{il1=shuffle(5)}
     \integer{offset1=0}
     \text{il2=shuffle(5)}
     \integer{offset2=6}
     \text{il3=shuffle(3)}
     \integer{offset3=13}
   }
   { \text{il1=shuffle(6)}
     \integer{offset1=0}
     \text{il2=shuffle(7)}
     \integer{offset2=6}
     \text{il3=shuffle(4)}
     \integer{offset3=13}
   }
 }

\integer{i1=\il1[1]+\offset1}
\text{qx1=\qxl[\i1]}
\text{qy1=\qyl[\i1]}
\integer{indq1=\indql[\i1]}
\integer{i2=\il2[1]+\offset2}
\integer{i2=11}
\text{qx2=\qxl[\i2]}
\text{qy2=\qyl[\i2]}
\integer{indq2=\indql[\i2]}
\integer{i3=\il3[1]+\offset3}
\text{qx3=\qxl[\i3]}
\text{qy3=\qyl[\i3]}
\integer{indq3=\indql[\i3]}
\text{trace=\i1 \i2 \i3 \y1 \y4}
\text{trace=}


%% enonc� de l'exo %%


#include "lang.inc"

\statement{
<p>
Soit \(f) une fonction d�finie sur \crog \x1;\x4 \crod dont le
tableau des variations est donn� ci-dessous
</p>
<table class="wimscenter wimsnoborder tab_var">
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
On cherche � comparer certaines images par \(f).

<ul>
<li> \(f(\qx1)) \embed{reply1}  \(\qy1)
</li><li>
\(f(\qx2)) \embed{reply2}  \(\qy2)
</li><li>
 \(f(\qx3)) \embed{reply3} \(\qy3)
</li></ul>

\trace}

\answer{\(f(\qx1)) et \(\qy1)}{\indq1;\choixcomp}{type=menu}
\answer{\(f(\qx2)) et \(\qy2)}{\indq2;\choixcomp}{type=menu}
\answer{\(f(\qx3)) et \(\qy3)}{\indq3;\choixcomp}{type=menu}
