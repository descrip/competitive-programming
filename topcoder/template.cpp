#include <bits/stdc++.h>
using namespace std;

struct ${ClassName} {

${<foreach Method.Params p}
  ${p.Type} ${p.Name}; 
${<end}

  ${Method.ReturnType} ${Method.Name}(${Method.Params}) {
${<foreach Method.Params p}
    this->${p.Name} = ${p.Name}; 
${<end}
    return ${Method.ReturnType;ZeroValue};
  }
};

${CutBegin}
/* Greed Testing Code {{{ */
${<TestCode}
/* }}} */
${CutEnd}
