target=asympt1hv

#include "header.inc"
#include "lang_titles.inc"




\integer{a = randint(-5..5)}
\integer{b = randint(1..5)*random(-1,1)}
\text{droite = texmath(pari(\b*x+\a))}
\text{inf1 = random(- \infty, + \infty)}
\text{inf2 = random(- \infty, + \infty)}
\integer{choix = randint(1,3,4)}

\text{etape2 = \choix < 3 ? :reply2}
\steps{reply1
\etape2}

\text{limite = item(\choix,\(\displaystyle{\lim_{x \to \inf1} f(x) = \inf2}),
\(\displaystyle{\lim_{x \to \inf1} f(x) - (\droite) = \inf2}),
\(\displaystyle{\lim_{x \to \inf1} f(x) = \a}),
\(\displaystyle{\lim_{x \to \a} f(x) = \inf1}),
\(\displaystyle{\lim_{x \to \inf1} f(x)  - (\droite)  = 0})
)}

\text{rep = item(\choix,2,2,1,1,1)}
\text{equation = item(\choix - 2,y = \a,x = \a,y = \droite)}
\text{equation = \equation, x,y}



#include "lang.inc"

\statement{On consid�re une fonction \(f) de courbe repr�sentative \(C) dans un rep�re orthogonal.
<br/>On admet que \limite .
\if{\step = 1}{
<br/>Peut-on en d�duire que la courbe \(C) admet une droite asymptote ?\embed{reply1}}
\if{\step = 2}{<br/>On peut en d�duire que la courbe \(C) admet une droite asymptote d'�quation : \embed{reply2}
}
}

\answer{}{\rep;oui,non}{type = radio}
\answer{Droite asymptote}{\equation}{type = equation}
