#include "lang_fr.inc"
\if{\lang=it}{
#include "lang_it.inc"
}

\if{\confparm1=2}{
\text{ou=\vee}
\text{et=\wedge}
}{
\text{ou=\;\name_ou\;}
\text{et=\;\name_et\;}
}