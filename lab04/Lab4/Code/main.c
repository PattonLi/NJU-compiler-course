#include <stdio.h>
#include "Tree.h"
#include "semantic.h"
#include "intercode.h"
#include "objectcode.h"

extern int yyrestart(FILE* f);
extern int yyparse();
extern void printTree(Node* root, int depth);
extern Node* root;
extern int lexError;
extern int synError;
extern int semError;

int main(int argc, char** argv) {
    if (argc <= 1)
        return 1;
    FILE* f = fopen(argv[1], "r");
    if (!f) {
        perror(argv[1]);
        return 1;
    }
    yyrestart(f);
    yyparse();
    if (root != NULL && lexError == 0 && synError == 0) {
        // printTree(root, 0);
        semanticAnalyse(root);
        if (semError == 0) {
            //翻译中间代码
            translateProgram(root);
            if (argc == 4) {
                printInterCodes(argv[3]);
                printObjectCodes(argv[2]);
            }
            else if (argc == 3)
                printObjectCodes(argv[2]);
        }
    }
    return 0;
}