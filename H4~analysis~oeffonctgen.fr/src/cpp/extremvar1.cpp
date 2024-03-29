target=extremvar1

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

\if{\cas=1}{
  \text{pos=top,bottom,top,bottom}
  \if{\cas2=1}{
     \text{d1=\(+\infty)}
     \text{crog=&#93;}
   }{
     \text{d1=\y1}
     \text{crog=&#91;}
   }
  \text{d2=\y2}
  \text{d3=\y3}
  \if{\cas2=2}{
    \text{d4=\(-\infty)}
    \text{crod=&#91;}
   }{
    \text{d4=\y4}
    \text{crod=&#93;}
   }
}{
  \text{pos=bottom,top,bottom,top}
  \if{\cas2=2}{
     \text{d1=\(-\infty)}
     \text{crog=&#93;}
   }{
     \text{d1=\y1}
     \text{crog=&#91;}
   }
  \text{d3=\y3}
  \text{d2=\y2}
  \if{\cas2=1}
   {
     \text{d4=\(+\infty)}
     \text{crod=&#91;}
   }
   {
     \text{d4=\y4}
     \text{crod=&#93;}
   }
 }
%% Choix des intervalles
\matrix{interval=\x1,\x2
\x2,\x3
\x3,\x4
\x1,\x3
\x2,\x4}

%% Pr�paration des r�ponses
\text{choixrepM= oui, non } %% major�e
\text{choixrepm= oui, non } %% minor�e
\text{borne2=minimum}
\text{replist=non monotone, croissante, d�croissante}
\if{\cas=1}
 {
 \integer{ymin=\y2<\y4?\y2:\y4}
 \integer{ymax=\y1<\y3?\y3:\y1}
 \integer{xmin=\y2<\y4?\x2:\x4}
 \integer{xmax=\y1<\y3?\x3:\x1}
 \integer{valb=\ymax}
 \integer{valbx=\xmax}
 \integer{valb2=\ymin}
 \integer{valbx2=\xmin}
 \if{\cas2>2}
  {
   \text{borne=maximum}
   \integer{indrepM=1}
   \integer{indrepm=1}
   \text{mstep2=r3,r4}
   \text{mstep3=r5,r6}
  }
  {
   \text{mstep3=}
   \if{\cas2=1}
     {
      \integer{indrepM=2}
      \integer{indrepm=1}
      \text{borne=minimum}
      \text{mstep2=r3,r4}
     \integer{valb=\valb2}
     \integer{valbx=\valbx2}
     }
     {
      \integer{indrepM=1}
      \integer{indrepm=2}
      \text{borne=maximum}
      \text{mstep2=r3,r4}
     }
  }
}
{
%% cas = 2
 \integer{ymin=\y1<\y3?\y1:\y3}
 \integer{ymax=\y2<\y4?\y4:\y2}
 \integer{xmin=\y1<\y3?\x1:\x3}
 \integer{xmax=\y2<\y4?\x4:\x2}
 \integer{valb=\ymax}
 \integer{valbx=\xmax}
 \integer{valb2=\ymin}
 \integer{valbx2=\xmin}
 \if{\cas2>2}
  {
   \text{borne=maximum}
   \integer{indrepM=1}
   \integer{indrepm=1}
   \text{mstep2=r3,r4}
   \text{mstep3=r5,r6}
  }
  {
   \text{mstep3=}
   \if{\cas2=1}
     {
      \integer{indrepM=2}
      \integer{indrepm=1}
      \text{borne=minimum}
      \text{mstep2=r3,r4}
     \integer{valb=\valb2}
     \integer{valbx=\valbx2}
     }
     {
      \integer{indrepM=1}
      \integer{indrepm=2}
      \text{borne=maximum}
      \text{mstep2=r3,r4}
     }
  }
}
%% Pr�paration des questions
\text{indl=shuffle(5)}
\text{q1=\interval[\indl[1];]}
\text{q2=\interval[\indl[2];]}
\text{q3=\interval[\indl[3];]}
\text{q4=\interval[\indl[4];]}
\text{q5=\interval[\indl[5];]}

%% enonc� de l'exo %%
\text{\mstep=r1,r2}
\nextstep{\mstep}



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
  <th valign="middle" style="width:15%;">\(f(x))</th>
     <td style="width:15%;text-align:left" valign="\pos[1]"> \d1 </td>
     <td style="width:8%;"> \monotone[1] </td>
     <td style="width:15%;" valign="\pos[2]"> \d2 </td>
     <td style="width:8%;"> \monotone[2]  </td>
     <td style="width:15%;" valign="\pos[3]"> \d3 </td>
     <td style="width:8%;"> \monotone[3] </td>
     <td style="width:15%;text-align:right" valign="\pos[4]"> \d4 </td>
      </tr>
</table>
<p>
On cherche � �tudier ses extrema �ventuels.</p>


\if{\step=1}{\(f) admet un maximum global: \embed{r1}<br />
\(f) admet un minimum global:\embed{r2}
}
{
   \if{\step=2}
   { \(f) atteint son \borne : \embed{r3}<br />
en \(x)= \embed{r4}
   }
   {\(f) atteint son minimum : \embed{r5}<br />
en \(x)= \embed{r6}
   }
}
}
\if{\step=2}{\text{mstep=\mstep2}}
{ \if{\step=3}{\text{mstep=\mstep3}}{\text{mstep=}}

}

\answer{\(f) admet un maximum}{\indrepM;\choixrepM}{type=menu}
\answer{\(f) admet un minimum}{\indrepm;\choixrepm}{type=menu}
\answer{\borne}{\valb}{type=numeric}
\answer{abscisse du \borne}{\valbx}{type=numeric}
\answer{\borne2}{\valb2}{type=numeric}
\answer{abscisse du \borne2}{\valbx2}{type=numeric}
